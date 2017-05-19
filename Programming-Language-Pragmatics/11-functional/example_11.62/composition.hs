-- Example 11.62
-- map, sequence_, and putStr are built-in;
-- we have to use different names here

putStr2 :: String -> IO ()          -- redefine putStr
    -- function from strings to sequences of null-typed actions
putStr2 s = sequence2 (map2 putChar s)

map2 :: (a->b) -> [a] -> [b]        -- redefine map
map2 f [] = []                              -- base case
map2 f (h:t) = f h : map2 f t               -- tail recursive case
                                                -- ':' is like cons in Scheme

sequence2 :: [IO ()] -> IO ()       -- redefine sequence_
sequence2 [] = return ()                    -- base case
sequence2 (a:more) = do a; sequence2 more   -- tail recursive case

main = do putStr2 "hi, "
          putStr2 "mom\n"           -- note indentation
          sequence2 (map2 putStr2 [show 1, show 2, show 3])
          putStr2 "\n"
