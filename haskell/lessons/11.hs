power :: Int -> Int -> Int
power _ 0 = 1
power base stepen = base * power base(stepen-1)

factorial :: Integer -> Integer
factorial 0 = 1
factorial n = n * factorial (n - 1)

sin1 :: Integer -> Double -> Double
sin1 k x = fromIntegral ((-1) ^ k) * (x ^ (2 * k + 1)) / fromIntegral (factorial (2 * k + 1))

sin2 :: Double -> Integer -> Double
sin2 x n = sum [sin1 k x | k <- [0..n]]

sin' :: Double -> Integer -> Double
sin' x n = sin2 x n

isPrime :: Int -> Bool
isPrime n
  | n < 2     = False
  | otherwise = all (\x -> n `mod` x /= 0) [2..intSqrt n]
  where
    intSqrt = floor . sqrt . fromIntegral

decomposeIntoPrimes :: Int -> (Int, Int)
decomposeIntoPrimes n
  | n < 4 || n `mod` 2 /= 0 = error "должно быть больше или ровно 4 или кратно 2"
  | otherwise = findPrimes 2
  where
    findPrimes i
      | isPrime i && isPrime (n - i) = (i, n - i)
      | otherwise = findPrimes (i + 1)


findMax :: (Int -> Double) -> Int -> Double
findMax f n = maximum [f x | x <- [0..n]]

biggestPrime :: Integer -> Integer
biggestPrime n
  | n < 2     = error "должно быть больше 2."
  | otherwise = findLargestPrime (n - 1)
  where
    findLargestPrime k
      | k < 2            = error "нет простых."
      | isPrime k        = k
      | otherwise        = findLargestPrime (k - 1)
