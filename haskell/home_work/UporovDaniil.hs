module FinalTest where

import Control.Monad.Trans.State
import GHC.Real (Ratio((:%)), (%))

data List a = Nil | Cons a (List a)
        deriving (Show)

replace :: List a -> Int -> (List Int, Int)
replace list start = replace' list start []

replace' :: List a -> Int -> [Int] -> (List Int, Int)
replace' Nil nextUnused uniqueValues = (Nil, nextUnused)
replace' (Cons _ xs) nextUnused uniqueValues =
    let (newList, newNextUnused) = replace' xs nextUnused uniqueValues
        newValue = findUnique newNextUnused uniqueValues
    in (Cons newValue newList, newValue)

findUnique :: Int -> [Int] -> Int
findUnique candidate uniqueValues =
    if candidate `elem` uniqueValues
        then findUnique (candidate + 1) uniqueValues
        else candidate


instance Functor List where
    fmap _ Nil = Nil
    fmap f (Cons x xs) = Cons (f x) (fmap f xs)

append :: List a -> List a -> List a
append Nil ys = ys
append (Cons x xs) ys = Cons x (append xs ys)

data Tree a = Empty | Node a (Tree a) (Tree a)
            deriving (Show)

leaves :: Tree a -> Int
leaves Empty = 0
leaves (Node _ Empty Empty) = 1
leaves (Node _ left right) = leaves left + leaves right


fullNodes :: Tree a -> Int
fullNodes Empty = 0
fullNodes (Node _ left right) = case(left,right) of
    (Node _ _ _, Node _ _ _) -> 1 +fullNodes left +fullNodes right
    _ -> fullNodes left + fullNodes right

data Op = Add | Mul | Sub | Div

data Expr = Num Rational |
            Var |
            Bin Op Expr Expr |
            Pow Expr Rational |
            Ln Expr


instance Show Op where
    show Add = " + "
    show Mul = " * "
    show Sub = " - "
    show Div = " / "

simplify :: Expr -> Expr
simplify (Bin op e1 e2) = simplify' (Bin op (simplify e1) (simplify e2))
simplify (Pow e n) = simplify' (Pow (simplify e) n)
simplify (Ln e) = simplify' (Ln (simplify e))
simplify e = e

apply :: Op -> Rational -> Rational -> Rational
apply Add = (+)
apply Sub = (-)
apply Mul = (*)
apply Div = (/)

instance Show Expr where
    show (Num n) = pretty n
    show Var = "x"
    show (Bin op e1 e2) = "(" ++ show e1 ++ show op ++ show e2 ++ ")"
    show (Pow e n) = show e ++ "^" ++ pretty n
    show (Ln e) = "Ln " ++ show e

pretty :: Rational -> String
pretty (a :% 1) = show a
pretty (a :% b)
    | a < 0 = "(-" ++ show (abs a) ++ "/" ++ show b ++ ")"
    | otherwise = "(" ++ show a ++ "/" ++ show b ++ ")"

derivative :: Expr -> Expr
derivative (Num _) = Num 0
derivative Var = Num 1
derivative (Bin op e1 e2) = case op of
    Add -> Bin Add (derivative e1) (derivative e2)
    Sub -> Bin Sub (derivative e1) (derivative e2)
    Mul -> Bin Add (Bin Mul e1' e2) (Bin Mul e1 e2') 
           where
               e1' = derivative e1
               e2' = derivative e2
    Div -> Bin Div (Bin Sub (Bin Mul e1' e2) (Bin Mul e1 e2')) (Pow e2 2)  
           where
               e1' = derivative e1
               e2' = derivative e2
derivative (Pow e n) = Bin Mul (Num n) (Bin Mul (Pow e (n - 1)) (derivative e))
derivative (Ln e) = Bin Div (derivative e) e

simplify' :: Expr -> Expr
simplify' (Bin op (Num x) (Num y)) = Num $ apply op x y
simplify' (Bin Add e1 (Num 0)) = e1
simplify' (Bin Add (Num 0) e1) = e1
simplify' (Bin Sub e1 (Num 0)) = e1
simplify' (Bin Sub (Num 0) e1) = e1
simplify' (Bin Mul e1 (Num 1)) = e1
simplify' (Bin Mul (Num 1) e1) = e1
simplify' (Bin Mul e1 (Num 0)) = Num 0
simplify' (Bin Mul (Num 0) e1) = Num 0
simplify' (Bin Div e1 (Num 1)) = e1
simplify' (Pow e1 1) = e1
simplify' (Pow e1 0) = Num 1
simplify' (Pow (Num m) (n :% 1)) = Num (m ^ n)
simplify' e = e

simplify' (Ln (Num 1)) = Num 0