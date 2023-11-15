or' :: [Bool] -> Bool
or' = foldr (||) False

all' :: (a -> Bool) -> [a] -> Bool
all' p = foldr (\x acc -> p x && acc) True

map' :: (a -> b) -> [a] -> [b]
map' f = foldr (\x acc -> f x : acc) []

concatMap' :: (a -> [b]) -> [a] -> [b]
concatMap' f = foldr (\x acc -> f x ++ acc) []

filter' :: (a -> Bool) -> [a] -> [a]
filter' p = foldr (\x acc -> if p x then x : acc else acc) []

partition' :: (a -> Bool) -> [a] -> ([a], [a])
partition' p = foldr (\x (ts, fs) -> if p x then (x : ts, fs) else (ts, x : fs)) ([], [])

unzip' :: [(a, b)] -> ([a], [b])
unzip' = foldr (\(x, y) (xs, ys) -> (x : xs, y : ys)) ([], [])

null' :: [a] -> Bool
null' = foldr (\_ _ -> False) True

intersperse' :: a -> [a] -> [a]
intersperse' sep = foldr (\x acc -> x : sep : acc) []

group' :: Eq a => [a] -> [[a]]
group' = foldr (\x acc -> if null acc || head (head acc) == x then (x : head acc) : tail acc else [x] : acc) []

-- 3 задание:
-- 1. Да, и f, и g имеют тип [a] -> a
-- 2. Примером может быть xs = [1, 2, 3]. Для этого списка f xs будет равно 1 - (2 - (3 - 0)) = 2,
-- в то время как g xs будет равно (((0 - 1) - 2) - 3) = -6. Следовательно, f xs не равно g xs.
-- 3. Примером может быть список ys = [1].
-- Для f операция сворачивания будет равна `1 - 0 = 1`.
-- Для g операция складывания также будет `1 - 0 = 1`.
-- Следовательно, f [1] == g [1].
-- 4. f [a, b, c] = a - (b - (c - 0)) = a - b + c
--    g [a, b, c] = ((0 - a) - b) - c = -a - b - c
-- Приравняем:
-- a - b + c = -a - b - c
-- 2a + 2b + 2c = 0
-- a + b + c = 0
-- Следовательно, множество значений удовлетворяющие данному уравнению сделает f[a,b,c]=g[a,b,c]

