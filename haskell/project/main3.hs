import System.Random (StdGen, newStdGen, randomR)
import Graphics.Gloss.Interface.IO.Game

data Tetromino = Long | TwoLeft | TwoRight | Square | TwoUnderTwoUpper | TwoUpperTwoUnder | MiddleUpper
  deriving (Enum, Bounded, Show)

data Color = Red | Green | Blue
  deriving (Show, Eq)

type Grid = [[Maybe Color]]

data GameState = GameState {
  grid :: Grid,
  currentTetromino :: Tetromino,
  currentColor :: Color,
  currentPos :: (Int, Int),
  nextTetromino :: Tetromino,
  nextColor :: Color,
  rng :: StdGen,
  isPaused :: Bool,
  score :: Int,
  highScore :: Int,
  speed :: Int
} deriving Show

initialState :: StdGen -> IO GameState
initialState gen = do
  let (nextTetromino, nextColor, newGen) = randomTetromino gen
  return GameState {
    grid = replicate 21 (replicate 10 Nothing),
    currentTetromino = nextTetromino,
    currentColor = nextColor,
    currentPos = (4, 0),
    nextTetromino = nextTetromino,
    nextColor = nextColor,
    rng = newGen,
    isPaused = True,
    score = 0,
    highScore = 0, -- загрузить из файла, если нужно
    speed = 1
  }

randomTetromino :: StdGen -> (Tetromino, Color, StdGen)
randomTetromino gen = (tetromino, color, newGen)
  where
    (index, newGen) = randomR (fromEnum (minBound :: Tetromino), fromEnum (maxBound :: Tetromino)) gen
    tetromino = toEnum index
    color = case randomR (0, 2) newGen of
      (0, gen') -> (Red, gen')
      (1, gen') -> (Green, gen')
      (2, gen') -> (Blue, gen')

gameLoop :: IO ()
gameLoop = do
  gen <- newStdGen
  state <- initialState gen
  playIO (InWindow "Tetris" (300, 600) (100, 100)) black 10 state draw handleEvent updateGame

handleEvent :: Event -> GameState -> IO GameState
handleEvent (EventKey (Char 'p') Down _ _) state = return state { isPaused = not (isPaused state) }
handleEvent (EventKey (SpecialKey KeyLeft) Down _ _) state = return $ moveLeft state
handleEvent (EventKey (SpecialKey KeyRight) Down _ _) state = return $ moveRight state
handleEvent (EventKey (SpecialKey KeyDown) Down _ _) state = return $ moveDown state
handleEvent (EventKey (SpecialKey KeyUp) Down _ _) state = return $ rotateTetromino state
handleEvent _ state = return state

updateGame :: Float -> GameState -> IO GameState
updateGame _ state = if isPaused state then return state else return $ updateState state

draw :: GameState -> IO Picture
draw state = return $ pictures [drawGrid (grid state), drawTetromino (currentTetromino state) (currentColor state) (currentPos state)]

-- Добавьте функции для отрисовки сетки и текущей фигуры

drawGrid :: Grid -> Picture
drawGrid grid = pictures [translate (fromIntegral x * 20) (fromIntegral y * 20) $ drawCell cell | (y, row) <- zip [0..] grid, (x, cell) <- zip [0..] row]

drawCell :: Maybe Color -> Picture
drawCell Nothing = color black $ rectangleSolid 20 20
drawCell (Just Red) = color red $ rectangleSolid 20 20
drawCell (Just Green) = color green $ rectangleSolid 20 20
drawCell (Just Blue) = color blue $ rectangleSolid 20 20

drawTetromino :: Tetromino -> Color -> (Int, Int) -> Picture
drawTetromino tetromino color (x, y) = pictures [translate (fromIntegral (x + dx) * 20) (fromIntegral (y + dy) * 20) $ drawCell (Just color) | (dx, dy) <- tetrominoShape tetromino]

tetrominoShape :: Tetromino -> [(Int, Int)]
tetrominoShape Long = [(0,0), (1,0), (2,0), (3,0)]
tetrominoShape Square = [(0,0), (1,0), (0,1), (1,1)]
tetrominoShape TwoLeft = [(0,0), (1,0), (1,1), (2,1)]
tetrominoShape TwoRight = [(0,1), (1,1), (1,0), (2,0)]
tetrominoShape TwoUnderTwoUpper = [(1,0), (2,0), (0,1), (1,1)]
tetrominoShape TwoUpperTwoUnder = [(0,0), (1,0), (1,1), (2,1)]
tetrominoShape MiddleUpper = [(1,0), (0,1), (1,1), (2,1)]

