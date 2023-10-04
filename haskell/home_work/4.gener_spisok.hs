list2 :: [Int]
list2 = [1,5,2,(-2)]

list :: [Double]
list = [1.2,(-3.4),0,9]

head1 :: [a] -> a
head1 (x:_) = x

gcd1 :: Integer -> Integer -> Integer
gcd1 0 a = a
gcd1 b 0 = b
gcd1 a b = gcd1 b (a `mod` b)

gcd3 :: Integer -> Integer -> Integer -> Integer
gcd3 a b c = gcd1 a (gcd1 b c)

isPythagoreanTriple :: (Integer, Integer, Integer) -> Bool
isPythagoreanTriple (a, b, c) = a ^ 2 + b ^ 2 == c ^ 2

pifagor1 ::[[Integer]]
pifagor1 = [[x,y,z] | x <- [1..],y<-[1..((x^2)`div`2)],z<-[1..x+y],isPythagoreanTriple (x, y, z), x<y]

pifagor2 ::[[Integer]]
pifagor2 = [[x,y,z] | x <- [1..],y<-[1..((x^2)`div`2)],z<-[1..x+y],isPythagoreanTriple (x, y, z), x<y,gcd3 x y z<2]

cntDigits :: Integer->Integer
cntDigits 0 = 0
cntDigits n = 1 + cntDigits (div n 10)

sumDigits :: Integer->Integer->Integer
sumDigits 0 q = 0
sumDigits n q = d^q + sumDigits k q
   where
   d = mod n 10
   k = div n 10

isArmstrong :: Integer->Bool
isArmstrong n = n==(sumDigits n (cntDigits n))

armstrong::[Integer]
armstrong = [x |x <- [1..],isArmstrong x]

-- d:: Integer -> Integer
-- d n = n`div`2

-- isdel :: Integer -> Integer -> Integer
-- isdel n d = d
-- isdel n q = | n`div`q ==0 q+isdel n q+1
 --           otherwise isdel n q+1 

-- isdel2:: Integer -> Bool
-- isdel2 k = k==(isdel k 1)

-- perfect::[Integer]
-- perfect = [x |x <- [2,4..], isdel2 x]

