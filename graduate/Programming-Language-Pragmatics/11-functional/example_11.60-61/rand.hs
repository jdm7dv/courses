-- Examples 11.60 and 11.61

import System.Random ( mkStdGen, StdGen, random, randomIO )

twoRandomInts :: StdGen -> ([Integer], StdGen)
  -- type signature: twoRandomInts is a function that takes an
  -- StdGen (the state of the RNG) and returns a tuple containing
  -- a list of Integers and a new StdGen.
twoRandomInts gen = let
      (rand1, gen2) = random gen
      (rand2, gen3) = random gen2
  in ([rand1, rand2], gen3)

main = let
      gen = mkStdGen 123              -- new RNG, seeded with argument
      ints = fst (twoRandomInts gen)  -- extract first element
  in print ints                          -- of returned tuple
    
twoMoreRandomInts :: IO [Integer]
  -- twoMoreRandomInts returns a list of Integers.  It also
  -- implicitly accepts, and returns, all the state of the IO monad.
twoMoreRandomInts = do
  rand1 <- randomIO
  rand2 <- randomIO
  return [rand1, rand2]

main2 = do
  moreInts <- twoMoreRandomInts
  print moreInts
