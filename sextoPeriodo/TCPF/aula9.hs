module Aula9 where
x :: Integer
y = 2
x = 4

f :: Integer -> Integer
f a = a^2

g :: Integer -> Integer
g b = 3

h c = 3

fun :: Integer -> (Integer -> (Integer -> Integer))
fun arg1 arg2 arg3 = arg1 * arg2 * arg3

fun2 :: Integer -> Integer -> Integer
fun2 = fun 10

fun3 :: Integer -> Integer -> Integer
fun3 arg1 arg2 = arg1*arg2

fun4 :: String -> Integer
fun4 "Hugo" = 36
fun4 "TCPF" = 100
fun4 _ = 60

fibo :: Integer -> Integer
fibo 0 = 0
fibo 1 = 1
fibo n = (fibo (n-1)) + (fibo (n-2))

fibo_magico = 0 : 1 : (zipWith (+) fibo_magico (tail fibo_magico))

lista = [1, 4, 7, 16]
lista_de_fibos = map fibo lista

fibo_4 = lista_de_fibos !! 1 -- acesso de lista,
-- indexada comeÃ§ando 0

lista2 = 1 : (2 : [])

z = map fibo