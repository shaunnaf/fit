squash :: (a -> a -> b) -> [a] -> [b]
squash _ [] = []          
squash _ [_] = []        
squash f (x:xs@(y:_)) = f x y : squash f xs

repeatEveryElem :: Int -> [a] -> [a]
repeatEveryElem _ [] = []
repeatEveryElem n (x:xs) = replicate n x ++ repeatEveryElem n xs

findDuplicates :: [Integer] -> [[Integer]]
findDuplicates xs = findDups (sort xs)
  where
    sort :: [Integer] -> [Integer]
    sort [] = []
    sort (x:xs) = insert x (sort xs)

    insert :: Integer -> [Integer] -> [Integer]
    insert x [] = [x]
    insert x (y:ys)
      | x <= y    = x : y : ys
      | otherwise = y : insert x ys

    findDups :: [Integer] -> [[Integer]]
    findDups [] = []
    findDups [x] = []
    findDups (x:y:xs)
      | x == y    = findDups' (x : [y]) xs
      | otherwise = findDups (y:xs)

    findDups' :: [Integer] -> [Integer] -> [[Integer]]
    findDups' acc [] = [acc]
    findDups' acc (x:xs)
      | head acc == x = findDups' (x : acc) xs
      | otherwise     = acc : findDups (x:xs)

lst :: [String]
lst = iterateNext [""] where
  iterateNext xs = let next = concatMap (\s -> map (\c -> s ++ [c]) "abc") xs
                   in xs ++ iterateNext next

containsAllDigitsOnes :: Integer -> Bool
containsAllDigitsOnes n = all (\d -> elem d digits) ['1'..'9']
  where
    digits = show n

substrings :: String -> [String]
substrings s = [substring i j s | i <- [0..length s], j <- [i+1..length s]]
  where
    substring start end str = take (end - start) (drop start str)
