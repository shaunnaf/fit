module UporovDaniil where

data Tree a = Empty | Node a (Tree a) (Tree a)
    deriving (Show, Read, Eq)
data Step = StepLeft | StepRight
    deriving (Show, Eq)

mapTree :: (a -> b) -> Tree a -> Tree b
mapTree _ Empty = Empty
mapTree f (Node x left right) = Node (f x) (mapTree f left) (mapTree f right)

allValues :: (a -> Bool) -> Tree a -> Bool
allValues _ Empty = True
allValues condition (Node x left right) =
    condition x && allValues condition left && allValues condition right

walk :: [Step] -> Tree a -> Maybe a
walk [] (Node x _ _) = Just x
walk [] Empty = Nothing
walk (StepLeft:rest) (Node _ left _) = walk rest left
walk (StepRight:rest) (Node _ _ right) = walk rest right
walk _ Empty = Nothing

makeTrees :: Int -> [Tree Char]
makeTrees 0 = [Empty]
makeTrees n = [Node 'x' left right | i <- [0 .. n - 1], left <- makeTrees i, right <- makeTrees (n - 1 - i)]