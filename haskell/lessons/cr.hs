log2 :: Integer -> Integer
log2 n
  | n == 1    = 0
  | otherwise = 1 + log2 (n `div` 2)

factorial :: Integer -> Integer
factorial 0 = 1
factorial n = n*factorial(n-1)

cos1 :: Integer -> Double -> Double
cos1 k x =(((-1) ^ k) * (x ^ (2 * k))) / fromIntegral (factorial (2 * k))

cos2 :: Double -> Integer -> Double
cos2 x n = sum [cos1 k x | k <- [0..n]]

cos' :: Double -> Integer -> Double
cos' x n = cos2 x n

isPrime :: Integer -> Bool
isPrime n
    | n<2 = False
    | otherwise = all(\x -> n `mod` x/=0) [2.. intSqrt n]
    where
        intSqrt = floor . sqrt . fromIntegral


biggestPrime :: Integer -> Integer
biggestPrime n
  | n < 2     = 0
  | otherwise = find (n - 1)
  where
    find k
      | k < 2       = 0
      | isPrime k   = 1 + find(k-1)
      | otherwise   = find (k - 1)

findDoubleprime :: Integer -> (Integer, Integer)
findDoubleprime n = head [(p, p + 2) | p <- [n..], isPrime p && isPrime (p + 2)]

maxValue :: (Integer -> Integer -> Integer) -> Integer -> Integer
maxValue f n = maximum [f i (i + 1) | i <- [0..n-1]]