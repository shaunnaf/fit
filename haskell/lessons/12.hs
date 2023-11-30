readUntil :: (String -> Bool) -> IO[String]
readUntil f = do
    str <- getline
    if f str
        then return []
        else do
            strs <- readUntil f
            return (str : strs)

needCont :: IO Bool
needCont = do
    putStrLn "continue?"
    str<-getline
    return (str == "yes")

while :: IO Bool -> IO () -> IO()
while cond op = 