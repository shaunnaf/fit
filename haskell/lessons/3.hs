sum_all :: Double -> Double -> Double
sum_all b q | abs(q)<1 = b/(1-q)
            | otherwise = error "|q|>=1"

findn :: Double -> Double -> Double -> Int
findn b q eps | abs (b-sum_all b q) < eps = 1
              | otherwise = 1 +findn(b*q) q eps


doTwice :: (Int -> Int) -> Int -> Int
doTwice f x = f(f x)

plus1 :: Int -> Int
plus1 x = x + 1

baz = doTwice plus1 7

sumlnts :: Int -> Int -> Int
sumlnts a b =  if a<b then a+sumlnts(a+1) b else b

sumSquares :: Int -> Int -> Int
sumSquares a b = if a<b then a*a+sumSquares(a+1) b else b*b

higherOrderSum :: (Int -> Int) -> Int -> Int -> Int
higherOrderSum f a b | a > b = 0
                     | a ==b = f b
                     | otherwise = f a+ higherOrderSum f (a+1) b