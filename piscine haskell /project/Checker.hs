--
-- EPITECH PROJECT, 2021
-- push_swap_checker
-- File description:
-- Checker
--

import System.Environment
import System.IO
import Text.Read
import Data.List
import System.Exit

isSorted::(Ord a) => [a] -> Bool
isSorted [] = True
isSorted [x] = True
isSorted (x:y:xs) = x <= y && isSorted (y:xs)

manager::([Integer], [Integer])-> String
manager (l_a, []) | isSorted(l_a) == True = "OK"
                  | otherwise = "KO"
manager _ = "KO"

getArgsInt::[String] -> [Integer]
getArgsInt [] = []
getArgsInt (x:xs) = read x : getArgsInt xs

convert :: String -> [String]
convert xs = case break (== ' ') xs of
    (ls, "") -> [ls]
    (ls, x:rs) -> ls : convert rs

sab::[Integer] -> [Integer]
sab a | length a < 2 = a
sab (x:xs:rest) = xs:x:rest

pa::[Integer] -> [Integer] -> ([Integer], [Integer])
pa a [] = (a, [])
pa a (x:xs) = (x:a, xs)

pb::[Integer] -> [Integer] -> ([Integer], [Integer])
pb [] b = ([], b)
pb (x:xs) b = (xs, x:b)

ra::[a] -> [a]
ra [] = []
ra (x : xs) = xs ++ [x]

rb::[b] -> [b]
rb [] = []
rb (x:xs) = xs ++ [x]

rra::[a] -> [a]
rra [] = []
rra (x:xs) = (last xs:init (x:xs))

rrb::[b] -> [b]
rrb [] = []
rrb (x:xs) = (last xs:init (x:xs))

loop:: ([Integer], [Integer]) -> [String] -> String
loop (l_a, l_b) [] = manager $ (l_a, l_b)
loop (l_a, l_b) (x:xs) | isSubsequenceOf x "sa" = loop (sab l_a, l_b) xs
                       | isSubsequenceOf x "sb" = loop (l_a, sab l_b) xs
                       | isSubsequenceOf x "sc" = loop (sab l_a, sab l_b) xs
                       | isSubsequenceOf x "pa" = loop (pa l_a l_b) xs
                       | isSubsequenceOf x "pb" = loop (pb l_a l_b) xs
                       | isSubsequenceOf x "ra" = loop (ra l_a, l_b) xs
                       | isSubsequenceOf x "rb" = loop (l_a, ra l_b) xs
                       | isSubsequenceOf x "rr" = loop (ra l_a, rb l_b) xs
                       | isSubsequenceOf x "rra" = loop (rra l_a, l_b) xs
                       | isSubsequenceOf x "rrb" = loop (l_a, rrb l_b) xs
                       | isSubsequenceOf x "rrr" = loop (rra l_a, rrb l_b) xs
                       | otherwise = loop (l_a, l_b) xs

check_return::String -> ExitCode
check_return a | a == "KO" = ExitFailure 84
               | otherwise = ExitSuccess

main = do
        args <- getArgs
        string_flags <- getLine
        let l_a = getArgsInt args
        let l_b = []
        let tab_string_flags = convert string_flags
        let return = loop (l_a, l_b) tab_string_flags
        putStrLn $ return
        let exit = check_return return
        exitWith (exit)