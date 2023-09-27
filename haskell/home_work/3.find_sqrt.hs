dx:: Double -> Double -> Double
dx a b = (b-a)/2

mid:: Double -> (Double -> Double)
mid a f = a + f


solver:: (Double -> Double) -> Double -> Double -> Double -> Double -> Double
solver f x eps a b | f a * f b <0 = error "a and b the same sign"
                   | f a == 0 = (sqrt (f x)) - a
                   | f b == 0 = (sqrt (f x)) - b
                   | b-a>eps = mid a (dx a b) solver(f x eps a b)
                   | f a * f b >= 0 = let b = mid a (dx a b)
                   | otherwise = let a = mid a (dx a b)
-- Так и не понял как передать функцию типа x^2 = 2^x в аргумент функции, надеюсь пойму на семинаре
-- Из-за этого я не могу даже проверить правильность работы программы
-- В целом логика программы должна быть правильной...хотя я уже ни в чем не уверен))
-- я переделал в 5 раз программу теперь она ругается на "|", оставим видимо так))