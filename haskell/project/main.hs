{-# LANGUAGE RecordWildCards #-}

import Graphics.Gloss
import Graphics.Gloss.Interface.Pure.Game
import System.Random
import Data.List (transpose)

data Tetromino = I | O | T | S | Z | J | L deriving (Enum, Bounded, Show)

type TetrominoColor = Color

data GameState = GameState
  { grid :: [[Maybe TetrominoColor]]
  , currentTetromino :: Tetromino
  , currentColor :: TetrominoColor
  , currentPos :: (Int, Int)
  , currentRotation :: Int
  , nextTetromino :: Tetromino
  , nextColor :: TetrominoColor
  , rng :: StdGen
  , isPaused :: Bool
  , score :: Int
  , linesCleared :: Int
  } deriving Show

gridWidth, gridHeight, cellSize, screenWidth, screenHeight, offsetY :: Int
gridWidth = 10
gridHeight = 20
cellSize = 20
screenWidth = gridWidth * cellSize + 200
screenHeight = gridHeight * cellSize + 50
offsetY = -50

initialState :: StdGen -> GameState
initialState gen = GameState
  { grid = replicate gridHeight (replicate gridWidth Nothing)
  , currentTetromino = I
  , currentColor = tetrominoColor I
  , currentPos = (gridWidth `div` 2, gridHeight - 1)
  , currentRotation = 0
  , nextTetromino = O
  , nextColor = tetrominoColor O
  , rng = gen
  , isPaused = True
  , score = 0
  , highScore = 100
  , linesCleared = 0
  }

main :: IO ()
main = do
  gen <- newStdGen
  play display bgColor fps (initialState gen) draw handleKeys update
  where
    display = InWindow "Tetris" (screenWidth, screenHeight) (100, 100)
    bgColor = black
    fps = 2

draw :: GameState -> Picture
draw game@GameState{..}
  | isPaused  = translate 0 (fromIntegral offsetY) $ pictures [drawGrid grid, drawBorders, drawText, drawInfo game]
  | otherwise = translate 0 (fromIntegral offsetY) $ pictures [drawGrid grid, drawTetromino currentTetromino currentColor currentPos currentRotation, drawBorders, drawInfo game]
  where
    drawText = translate (-150) 100 $ scale 0.3 0.3 $ color white $ text "Press any key to start"

drawGrid :: [[Maybe TetrominoColor]] -> Picture
drawGrid grid = pictures [translate (fromIntegral x * fromIntegral cellSize) (fromIntegral y * fromIntegral cellSize) 
                          (color cellColor (rectangleSolid (fromIntegral cellSize) (fromIntegral cellSize))) 
                          | (y, row) <- zip [0..] grid, (x, cell) <- zip [0..] row, Just cellColor <- [cell]]

drawTetromino :: Tetromino -> TetrominoColor -> (Int, Int) -> Int -> Picture
drawTetromino tetromino col (x, y) rotation = pictures $ map drawCell (rotateShape (tetrominoShape tetromino) rotation)
  where
    drawCell (cx, cy) = translate (fromIntegral (x + cx) * fromIntegral cellSize) (fromIntegral (y + cy) * fromIntegral cellSize) $
                        color col $
                        rectangleSolid (fromIntegral cellSize) (fromIntegral cellSize)

drawBorders :: Picture
drawBorders = color white $ pictures [ line [(0, 0), (0, fromIntegral (gridHeight * cellSize))]
                                     , line [(fromIntegral (gridWidth * cellSize), 0), (fromIntegral (gridWidth * cellSize), fromIntegral (gridHeight * cellSize))]
                                     , line [(0, 0), (fromIntegral (gridWidth * cellSize), 0)]
                                     , line [(0, fromIntegral (gridHeight * cellSize)), (fromIntegral (gridWidth * cellSize), fromIntegral (gridHeight * cellSize))]
                                     ]

drawInfo :: GameState -> Picture
drawInfo GameState{..} = translate (fromIntegral (gridWidth * cellSize) + 20) 0 $ pictures
  [  translate 0 50 $ scale 0.15 0.15 $ color white $ text ("SCORE " ++ show score)
  , translate 0 0 $ scale 0.15 0.15 $ color white $ text ("LINE " ++ show linesCleared)
  , translate 0 (-50) $ scale 0.15 0.15 $ color white $ text "NEXT"
  , translate 50 (-100) $ drawTetromino nextTetromino nextColor (0, 0) 0
  ]

tetrominoShape :: Tetromino -> [(Int, Int)]
tetrominoShape I = [(0,0), (1,0), (2,0), (3,0)]
tetrominoShape O = [(0,0), (1,0), (0,1), (1,1)]
tetrominoShape T = [(0,0), (1,0), (2,0), (1,1)]
tetrominoShape S = [(0,0), (1,0), (1,1), (2,1)]
tetrominoShape Z = [(1,0), (2,0), (0,1), (1,1)]
tetrominoShape J = [(0,0), (0,1), (1,1), (2,1)]
tetrominoShape L = [(2,0), (0,1), (1,1), (2,1)]

tetrominoColor :: Tetromino -> Color
tetrominoColor I = cyan
tetrominoColor O = yellow
tetrominoColor T = magenta
tetrominoColor S = green
tetrominoColor Z = red
tetrominoColor J = blue
tetrominoColor L = orange

rotateShape :: [(Int, Int)] -> Int -> [(Int, Int)]
rotateShape shape rotation = map rotate shape 
  where
    rotate (x, y) = case rotation `mod` 4 of
                      0 -> (x, y)
                      1 -> (-y, x)
                      2 -> (-x, -y)
                      3 -> (y, -x)

canMove :: GameState -> (Int, Int) -> Bool
canMove game@GameState{..} (dx, dy) =
  all (\(x, y) -> x >= 0 && x < gridWidth && y >= 0 && y < gridHeight && grid !! y !! x == Nothing)
      [(x + dx, y + dy) | (x, y) <- map (addPos currentPos) (rotateShape (tetrominoShape currentTetromino) currentRotation)]
  where
    addPos (px, py) (sx, sy) = (px + sx, py + sy)

canRotate :: GameState -> Bool
canRotate game@GameState{..} =
  all (\(x, y) -> x >= 0 && x < gridWidth && y >= 0 && y < gridHeight && grid !! y !! x == Nothing)
      [(x, y) | (x, y) <- map (addPos currentPos) (rotateShape (tetrominoShape currentTetromino) (currentRotation + 1))]
  where
    addPos (px, py) (sx, sy) = (px + sx, py + sy)

handleKeys :: Event -> GameState -> GameState
handleKeys (EventKey key Down _ _) game@GameState{..}
  | isPaused  = game { isPaused = False }
  | otherwise = case key of
                  SpecialKey sk -> handleGameKeys sk game
                  _             -> game
handleKeys _ game = game

handleGameKeys :: SpecialKey -> GameState -> GameState
handleGameKeys KeyLeft  game = moveTetromino game (-1, 0)
handleGameKeys KeyRight game = moveTetromino game (1, 0)
handleGameKeys KeyDown  game = moveTetromino game (0, -1)
handleGameKeys KeyUp    game = rotateTetromino game
handleGameKeys _        game = game

moveTetromino :: GameState -> (Int, Int) -> GameState
moveTetromino game@GameState{..} (dx, dy)
  | canMove game (dx, dy) = game { currentPos = (x + dx, y + dy) }
  | otherwise = game
  where
    (x, y) = currentPos

rotateTetromino :: GameState -> GameState
rotateTetromino game@GameState{..}
  | canRotate game = game { currentRotation = currentRotation + 1 }
  | otherwise = game

update :: Float -> GameState -> GameState
update _ game@GameState{..}
  | isPaused  = game
  | otherwise = dropTetromino game

dropTetromino :: GameState -> GameState
dropTetromino game@GameState{..}
  | canMove game (0, -1) = game { currentPos = (x, y - 1) }
  | otherwise = clearLines $ game { grid = updateGrid grid (map (addPos currentPos) (rotateShape (tetrominoShape currentTetromino) currentRotation)) currentColor
                                  , currentTetromino = nextTetromino
                                  , currentColor = nextColor
                                  , currentPos = (gridWidth `div` 2, gridHeight - 1)
                                  , currentRotation = 0
                                  , nextTetromino = newTetromino
                                  , nextColor = newColor
                                  , rng = newGen
                                  , score = score + 10
                                  }
  where
    (x, y) = currentPos
    addPos (px, py) (sx, sy) = (px + sx, py + sy)
    (newTetromino, newColor, newGen) = randomTetromino rng

updateGrid :: [[Maybe TetrominoColor]] -> [(Int, Int)] -> TetrominoColor -> [[Maybe TetrominoColor]]
updateGrid g positions color = foldl (\gr (x, y) -> updateRow gr x y color) g positions

updateRow :: [[Maybe TetrominoColor]] -> Int -> Int -> TetrominoColor -> [[Maybe TetrominoColor]]
updateRow gr x y color = take y gr ++ [take x (gr !! y) ++ [Just color] ++ drop (x + 1) (gr !! y)] ++ drop (y + 1) gr

clearLines :: GameState -> GameState
clearLines game@GameState{..} = game { grid = newGrid, linesCleared = linesCleared + clearedLinesCount, score = score + clearedLinesCount * 100 }
  where
    (newGrid, clearedLinesCount) = clearFullLines grid
    clearFullLines g = let cleared = filter (any (== Nothing)) g
                           linesClearedCount = length g - length cleared
                           emptyLines = replicate linesClearedCount (replicate gridWidth Nothing)
                       in (cleared ++ emptyLines, linesClearedCount)

randomTetromino :: StdGen -> (Tetromino, TetrominoColor, StdGen)
randomTetromino gen = (tetromino, tetrominoColor tetromino, newGen)
  where
    (index, newGen) = randomR (fromEnum (minBound :: Tetromino), fromEnum (maxBound :: Tetromino)) gen
    tetromino = toEnum index
