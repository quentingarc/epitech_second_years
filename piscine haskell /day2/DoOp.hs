--
-- EPITECH PROJECT, 2020
-- B-FUN-300-BDX-3-1-funPoolDay2-quentin.garcia
-- File description:
-- DoOp.hs
--


myElem :: Eq a => a -> [a] -> Bool
myElem nbr [] = False
myElem nbr (x : xs)
  | nbr == x = True
  | otherwise = myElem nbr xs

main :: IO ()
main = print (myElem 3 [1, 2, 3, 4, 5])