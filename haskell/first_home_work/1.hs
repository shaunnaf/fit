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
