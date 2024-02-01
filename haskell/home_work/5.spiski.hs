merge :: (Ord a) => [a] -> [a] -> [a]
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys)
    | x < y = x : merge xs (y : ys)
    | otherwise = y : merge (x : xs) ys

selectiveMap :: (a -> Bool) -> (a -> a) -> [a] -> [a] 
selectiveMap p f xs = [if p x then f x else x | x <- xs]

collatz :: Int -> [Int]
collatz 0 = []
collatz 1 = [1]
collatz n | even n    = [n] ++ collatz (n `div` 2)
          | otherwise = [n] ++ collatz (3 * n + 1)

spread :: a -> [a] -> [[a]]
spread x [] = [[x]]
spread x (y:ys) = (x:y:ys) : (map (y:) (spread x ys))

permutations :: [a] -> [[a]]
permutations [] = [[]]
permutations (x:xs) = concat (map (spread x) (permutations xs))

subsequences :: [a] -> [[a]]
subsequences [] = [[]]
subsequences (x:xs) = [x:ys | ys <- subsequences xs] ++ subsequences xs