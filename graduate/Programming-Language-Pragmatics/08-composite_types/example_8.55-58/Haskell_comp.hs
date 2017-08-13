-- Example 8.58

comp = [i * i | i <- [1..100], i `mod` 2 == 1]

main = do
    print comp
