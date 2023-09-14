factrorial :: Int -> Int
factrorial 0 = 1
factrorial n = if n < 0 then error "Negative!" else n*factrorial(n-1)

dfactorial :: Int -> Int
dfactorial 0 = 1
dfactorial 1 = 1
dfactorial n = if n < 0 then error "Negative!" else n*(dfactorial(n-2))

fibbonaci :: Int -> Int
fibbonaci 0 = 0
fibbonaci 1 = 1
fibbonaci n = if n<0 then error "Negative!" else fibbonaci(n-2)+fibbonaci(n-1)

summ :: Int -> Int
summ n = if n ==0 then 0 else summ(abs(n)`div`10)+(abs(n)`rem`10)

akkerman :: Int -> Int -> Int
akkerman 0 n = n+1
akkerman m 0 = akkerman (m-1) 1
akkerman m n = akkerman (m-1) (akkerman m (n-1))