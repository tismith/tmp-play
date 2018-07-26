module Main where
fib 1 = 1
fib 2 = 1
fib n = fib (n-1) + fib (n-2)
main = putStrLn $ "Fib 5:" ++ (show $ fib 5)
