--
-- EPITECH PROJECT, 2020
-- B-FUN-300-BDX-3-1-funPoolDay1-quentin.garcia
-- File description:
-- my.hs
--

mySucc :: Int -> Int
mySucc  n = n + 1

myIsNeg :: Int -> Bool
myIsNeg x
        | x < 0 = True
        | x >= 0 = False

myAbs :: Int -> Int
myAbs x
        | x < 0 = -x
        | x >= 0 = x

myMin :: Int -> Int -> Int
myMin x y
        | x < y = x
        | x > y = y

myMax :: Int -> Int -> Int
myMax x y
        | x < y = y
        | x > y = x

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead (x:xs) = x

myTail :: [a] -> [a]
myTail (x:xs) = xs