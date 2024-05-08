module Program where

import qualified Data.Map as M
import Control.Monad.Trans.State
import Control.Monad.Trans.Class
import Control.Monad.Trans.Except
import Control.Monad.IO.Class


data Expr = Num Integer | 
            Var Name |
            Bin Op Expr Expr | 
            If BoolExpr Expr Expr |
            Let Name Expr Expr

data Op = Add | Mul | Sub | Div

data BoolExpr = BVal Bool |
                And BoolExpr BoolExpr |
                Not BoolExpr |
                Equal Expr Expr |
                Less Expr Expr             

type Name = String

data Command =  Null|
                Assign Name Expr | 
                IfC 
                    BoolExpr -- условие
                    [Command]  -- then
                    [Command] | -- else
                While 
                    BoolExpr -- условие
                    [Command] | -- тело цикла
                For 
                    Command -- блок инициализации
                     BoolExpr -- условие
                    Command -- оператор
                    [Command]| -- тело цикла
                Read Name | 
                Write String Expr

type Env = M.Map Name Integer

data Program = Program {
    input :: [Name], -- входные переменные
    output :: Name, -- выходная переменная
    commands :: [Command] -- список команд    
}


data ExecErr =  DivisionByZero |  -- деление на ноль
                UnsetVariable Name |  -- использование не определенной переменной
                UnsetInput Name |  -- переменная объявлена входной, но ее значение не определено
                NoOutput | -- значение выходной переменной не определено
                ReadErr -- ошибка чтения
    deriving (Show, Eq)

execComand = undefined

exec = undefined

p1io :: Program
p1io = Program
    []
    "r"                                      
    [
        Read "x",
        Read "y",
        Assign "q" (Bin Div (Var "x") (Var "y")),   
        Assign "qy" (Bin Mul (Var "y") (Var "q")),  
        Assign "r" (Bin Sub (Var "x") (Var "qy")),   
        Write "answ=" (Var "r")
    ]