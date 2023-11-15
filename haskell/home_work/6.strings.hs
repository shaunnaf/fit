import Data.Char
import Data.List

f1 :: String -> Bool
f1 w = w == reverse w

firstFunction :: String -> Bool
firstFunction str = f1 $ map toLower str

removePunc xs = [ x | x <- xs, not (x `elem` ",.?!-:;\"\'") ]

deleteSpaces :: String -> String
deleteSpaces = foldr (\(x:xs) -> (x :) . (xs ++)) [] . words

helpMe :: String -> Bool
helpMe str = firstFunction $ deleteSpaces str

secondFunction :: String -> Bool
secondFunction str = helpMe $ removePunc str

anagrams :: String -> [String] -> [String]
anagrams word possibleWords = map (filter (\c -> toLower c == toLower head word)) possibleWords