-- Example 11.63
-- Compile this with ghc and then run the resulting program -- e.g., via 
--      echo -n "foo" | ./simple
-- (not meant for use in the top-level ghci interpreter).

my_program :: String -> String

my_program s = s ++ s ++ "\n"   -- double the input and add return

main = interact my_program

