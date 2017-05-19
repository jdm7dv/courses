-- Examples 3.27

a @@ b = a * 2 + b

(@@@) a b = a * 2 + b

main = do
    print $ 3 @@ 4
    print $ (@@@) 3 4
    print $ gcd 8 12
    print $ 8 `gcd` 12
