import Text.Parsec
import Text.Parsec.String (Parser)
import Text.Parsec.Char (char, digit, newline, spaces)
import Text.Parsec.Combinator (many1, eof)
import Control.Applicative ((<*), (<$>), (<*>), (*>), (<$))

data Program = Program [Name] Name [Command] deriving Show
data Command = Assign Name Expr | If BoolExpr [Command] [Command] | While BoolExpr [Command] | For Command BoolExpr Command [Command] | Null deriving Show
data Expr = Num Int | Var Name | BinOp Op Expr Expr deriving Show
data BoolExpr = BoolConst Bool | Not BoolExpr | And BoolExpr BoolExpr | LessThan Expr Expr | Equal Expr Expr deriving Show
type Name = String
data Op = Plus | Minus | Mult | Div deriving Show

fileName :: Parser String
fileName = many anyChar <* eof

program :: Parser Program
program = do
    string "input:"
    names <- name `sepBy` char ','
    newline
    string "output:"
    outputName <- name
    newline >> newline
    block <- many command
    return $ Program names outputName block

name :: Parser Name
name = choice $ map string ["x", "y", "z", "j"]

expr :: Parser Expr
expr = chainl1 term (plusOp <|> minusOp)
  where
    term = chainl1 factor (multOp <|> divOp)
    factor = choice [Num <$> read <$> many1 digit, Var <$> name, char '(' *> expr <* char ')']
    plusOp = BinOp Plus <$ char '+'
    minusOp = BinOp Minus <$ char '-'
    multOp = BinOp Mult <$ char '*'
    divOp = BinOp Div <$ char '/'

command :: Parser Command
command = choice [try assign, try ifStatement, try whileLoop, try forLoop, try nullCommand]

assign :: Parser Command
assign = do
    n <- name
    string ":="
    e <- expr
    newline
    return $ Assign n e

ifStatement :: Parser Command
ifStatement = do
    string "if"
    spaces
    b <- boolExpr
    newline
    string "{"
    newline
    c1 <- many command
    newline
    string "}"
    newline
    string "else"
    newline
    string "{"
    newline
    c2 <- many command
    newline
    string "}"
    newline
    return $ If b c1 c2

whileLoop :: Parser Command
whileLoop = do
    string "while"
    spaces
    b <- boolExpr
    newline
    string "{"
    newline
    c <- many command
    newline
    string "}"
    newline
    return $ While b c

forLoop :: Parser Command
forLoop = do
    string "for"
    spaces
    a <- assign
    char ';'
    b <- boolExpr
    char ';'
    u <- assign
    newline
    string "{"
    newline
    c <- many command
    newline
    string "}"
    newline
    return $ For a b u c

nullCommand :: Parser Command
nullCommand = string "pass" >> newline >> return Null

boolExpr :: Parser BoolExpr
boolExpr = chainl1 term (andOp)
  where
    term = choice [try (string "T" >> return (BoolConst True)), try (string "F" >> return (BoolConst False)), try (char '!' >> boolExpr), try (char '(' *> boolExpr <* char ')'), try (string "==" >> Equal <$> expr <*> expr), try (string "<" >> LessThan <$> expr <*> expr)]
    andOp = And <$ char '&'

main :: IO ()
main = do
    putStrLn "Enter filename:"
    fileName <- getLine
    fileContent <- readFile fileName
    case parse program "" fileContent of
        Left err -> print err
        Right prog -> print prog
