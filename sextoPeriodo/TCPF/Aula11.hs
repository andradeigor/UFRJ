module Aula11 where
import Data.List


-- Listas!

numeros_ate_10 = [0..10]
pares_ate_10 = [0, 2 .. 10]

-- ++ concatena

-- Strings sÃ£o listas de caracterest

f _ = ""

-- !!

-- take, takeWhile, filter, zip, map, fold

-- funÃ§Ãµes anÃ´nimas

naturais = [0..]
pares = filter even naturais
outroPares = map (*2) naturais
maisOutroPares = [ 2*x | x <- naturais ]
maisAindaOutrosPares = [ x | x <- naturais, even x ]

henrique = zip naturais pares

somaLista :: [Integer] -> Integer
somaLista = foldr (+) 0

prodLista :: [Integer] -> Integer
prodLista = foldr (*) 1

meufoldr :: (a -> b -> b) -> b -> [a] -> b
meufoldr _ base []     = base
meufoldr f base (x:xs) = f x (meufoldr f base xs)

meufoldl :: (b -> a -> b) -> b -> [a] -> b
meufoldl _ base []     = base
meufoldl f base (x:xs) = meufoldl f (f base x) xs

-- reconstruindo uma lista usando fold!

naturaisr = foldr (:) [] naturais

-- flip: "troca a ordem dos argumentos"
naturaisl = foldl (\ corpo cab -> corpo ++ [cab]) [] naturais

--- NÃºmeros de Peano

data Natural where
  Zero :: Natural
  Suc :: Natural -> Natural
  deriving (Show, Eq)

somar :: Natural -> Natural -> Natural
somar x Zero    = x
somar x (Suc y) = Suc $ somar x y

produtor :: Natural -> Natural -> Natural
produtor x Zero    = Zero
produtor x (Suc y) = somar (produtor x y) x

potenciar :: Natural -> Natural -> Natural
potenciar x Zero    = Suc Zero
potenciar x (Suc y) = produtor (potenciar x y) x

-- desafio: escrever o "fold" genÃ©rico que poderia ser usado em cada caso aqui

somal :: Natural -> Natural -> Natural
somal Zero y    = y
somal (Suc x) y = Suc $ somal x y