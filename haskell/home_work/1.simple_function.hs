first :: Double -> Double
first x = (x^2)/(1+x)

second :: Double -> Double
second x = sqrt(3*x-(x^3))

third :: Double -> Double
third x = logBase 10 (x^2-21)

fourth :: Double -> Double
fourth x = logBase 2(logBase 3(logBase 4(x)))

fifth :: Double -> Double
fifth x = sqrt(sin(2*x)) - sqrt(sin(3*x))

distance :: Double -> Double -> Double -> Double -> Double
distance x1 y1 x2 y2 = sqrt((x2-x1)^2 + (y2-y1)^2)

leap :: Int -> Bool
leap x = ((x `rem` 400)==0 || ((x `rem` 100) /= 0 && (x `rem` 4) == 0))