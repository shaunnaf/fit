sumlf::(Int->Bool)->Int->Int->Int
sumlf p a b | a == b = if p a then a else 0
            | a>b = error "Invalid Interval"
            | otherwise = (if p a then a else 0) + sumlf p (a+1) b

factors :: Int ->[Int]
factors n = [x| x<-[1..n],n `mod` x == 0]

multTable :: Int ->[[Int]]
multTable n = [[x,x*2..x*n] | x <- [1..n]]

concat :: [[a]] -> [a]
concat [] = []
concat (xs:xss) = xs ++ (Main.concat xss) -- работает только через Main.concat

isPrime k = if k > 1 then null [ x | x <- [2..k - 1], k `mod` x == 0] else False

longList::[Integer]
longList = [x |x <- [1..],isPrime x]