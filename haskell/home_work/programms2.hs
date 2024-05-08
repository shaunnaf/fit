import Control.Monad.Except
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

data Command = Null|
               Assign Name Expr |
               For Command BoolExpr Command [Command]

data ExecErr = DivisionByZero |
               UnsetVariable Name |
               UnsetInput Name |
               NoOutput |
               ReadErr
               deriving (Show, Eq)

-- Псевдоним для удобства использования
type EnvState = State Env

-- Проверка, существует ли переменная в окружении
getVar :: Name -> EnvState (Either ExecErr Integer)
getVar name = do
    env <- get
    case M.lookup name env of
        Just val -> return (Right val)
        Nothing -> return (Left (UnsetVariable name))

-- Оценка выражения
evalExpr :: Expr -> EnvState (Either ExecErr Integer)
evalExpr (Num n) = return (Right n)
evalExpr (Var name) = getVar name
evalExpr (Bin op expr1 expr2) = do
    val1 <- evalExpr expr1
    val2 <- evalExpr expr2
    case (val1, val2) of
        (Right v1, Right v2) -> case op of
            Add -> return (Right (v1 + v2))
            Mul -> return (Right (v1 * v2))
            Sub -> return (Right (v1 - v2))
            Div -> if v2 /= 0
                      then return (Right (v1 `div` v2))
                      else return (Left DivisionByZero)
        _ -> return $ Left ReadErr
evalExpr (If boolExpr expr1 expr2) = do
    cond <- evalBoolExpr boolExpr
    if cond
        then evalExpr expr1
        else evalExpr expr2
evalExpr (Let name expr1 expr2) = do
    val <- evalExpr expr1
    case val of
        Right v -> do
            modify (M.insert name v)
            evalExpr expr2
        Left err -> return (Left err)

-- Оценка булевого выражения
evalBoolExpr :: BoolExpr -> EnvState Bool
evalBoolExpr (BVal b) = return b
evalBoolExpr (And expr1 expr2) = do
    val1 <- evalBoolExpr expr1
    val2 <- evalBoolExpr expr2
    return (val1 && val2)
evalBoolExpr (Not expr) = do
    val <- evalBoolExpr expr
    return (not val)
evalBoolExpr (Equal expr1 expr2) = do
    val1 <- evalExpr expr1
    val2 <- evalExpr expr2
    case (val1, val2) of
        (Right v1, Right v2) -> return (v1 == v2)
        _ -> return False
evalBoolExpr (Less expr1 expr2) = do
    val1 <- evalExpr expr1
    val2 <- evalExpr expr2
    case (val1, val2) of
        (Right v1, Right v2) -> return (v1 < v2)
        _ -> return False

-- Выполнение команды
execCommand :: Command -> ExceptT ExecErr EnvState ()
execCommand Null = return ()
execCommand (Assign name expr) = do
    val <- lift $ evalExpr expr
    case val of
        Right v -> lift $ modify (M.insert name v)
        Left err -> throwError err
execCommand (For initCmd condCmd updateCmd bodyCmds) = do
    execCommand initCmd
    loop
    where
        loop = do
            cond <- lift $ evalBoolExpr condCmd
            if cond
                then do
                    mapM_ execCommand bodyCmds
                    execCommand updateCmd
                    loop
                else return ()

-- Выполнение программы
exec :: Program -> ExceptT ExecErr EnvState Integer
exec (Program _ outputVar commands) = do
    mapM_ execCommand commands
    env <- lift get
    case M.lookup outputVar env of
        Just val -> return val
        Nothing -> throwError NoOutput


p1 :: Program
p1 = Program  {
    input = ["x", "y", "q", "r"],
    output = "r",
    commands = [
        Assign "qy" (Bin Mul (Var "q") (Var "y")),
        Assign "x" (Bin Add (Var "qy") (Var "r"))
    ]
}


env1 :: Env
env1 = M.fromList [("x", 10), ("y", 5), ("q", 2), ("r", 3)]