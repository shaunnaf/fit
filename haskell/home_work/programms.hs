import Control.Monad.State
import qualified Data.Map as M

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
type Env = M.Map Name Integer

data Program = Program {
    input :: [Name],
    output :: Name,
    commands :: [Command]
}

data Command = Null |
               Assign Name Expr |
               For Command BoolExpr Command [Command]

execCommand :: Command -> State Env ()
execCommand Null = return ()
execCommand (Assign name expr) = do
    env <- get
    let val = evalExpr expr env
    put $ M.insert name val env
execCommand (For initCmd condCmd updateCmd bodyCmds) = do
    execCommand initCmd
    loop
    where
        loop = do
            cond <- evalBoolExpr condCmd <$> get
            if cond
                then do
                    mapM_ execCommand bodyCmds
                    execCommand updateCmd
                    loop
                else return ()

evalExpr :: Expr -> Env -> Integer
evalExpr (Num n) _ = n
evalExpr (Var name) env = case M.lookup name env of
                            Just val -> val
                            Nothing -> error $ "Variable " ++ name ++ " not found."
evalExpr (Bin op expr1 expr2) env =
    let val1 = evalExpr expr1 env
        val2 = evalExpr expr2 env
    in case op of
        Add -> val1 + val2
        Mul -> val1 * val2
        Sub -> val1 - val2
        Div -> val1 `div` val2
evalExpr (If boolExpr expr1 expr2) env =
    if evalBoolExpr boolExpr env
    then evalExpr expr1 env
    else evalExpr expr2 env
evalExpr (Let name expr1 expr2) env =
    let val = evalExpr expr1 env
    in evalExpr expr2 (M.insert name val env)

evalBoolExpr :: BoolExpr -> Env -> Bool
evalBoolExpr (BVal b) _ = b
evalBoolExpr (And expr1 expr2) env =
    evalBoolExpr expr1 env && evalBoolExpr expr2 env
evalBoolExpr (Not expr) env = not (evalBoolExpr expr env)
evalBoolExpr (Equal expr1 expr2) env =
    evalExpr expr1 env == evalExpr expr2 env
evalBoolExpr (Less expr1 expr2) env =
    evalExpr expr1 env < evalExpr expr2 env

exec :: Program -> State Env Integer
exec (Program _ outputVar commands) = do
    mapM_ execCommand commands
    env <- get
    case M.lookup outputVar env of
        Just val -> return val
        Nothing -> error $ "Output variable " ++ outputVar ++ " not found."

env1 :: Env
env1 = M.fromList [("x", 10), ("y", 5), ("q", 2), ("r", 3)]

p1 :: Program
p1 = Program {
    input = ["x", "y", "q", "r"],
    output = "r",
    commands = [
        Assign "q" (Bin Div (Var "x") (Var "y")),
        Assign "qy" (Bin Mul (Var "q") (Var "y")),
        Assign "x" (Bin Add (Var "qy") (Var "r"))
    ]
}



