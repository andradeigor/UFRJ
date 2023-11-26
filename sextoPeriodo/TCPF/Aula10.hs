module Aula10 where

w :: Num a => a
w = 3

fun1 :: Integer -> Integer
fun1 0 = 100
fun1 (-50) = 1600000
fun1 x = x * 3

fun2 :: [Integer] -> Integer
fun2 [] = 0
fun2 (cab:corpo) = cab^2

type Lista :: * -> *
data Lista a = Vazia | Cons a (Lista a)
--  deriving Show

instance Show a => Show (Lista a) where
  show :: Show a => Lista a -> String
  show Vazia = ""
  show (Cons valor_a Vazia) = show valor_a
  show (Cons valor_a (lista_a)) = (show valor_a) ++ " SEP " ++ (show lista_a)

x = Cons 1 $ Cons 2 $ Cons 3 Vazia
y = Cons "Hugo " $ Cons "Nobrega" Vazia

data Lista2 a where
  Vazia2 :: Lista2 a
  Cons2 :: a -> Lista2 a -> Lista2 a
  deriving Show

z = Cons2 1 $ Cons2 2 Vazia2

-- condicionais

sinal :: Integer -> String
sinal 0 = "Zero"
sinal x = if (x < 0)
  then "Negativo"
  else "Positivo"

sinal2 :: Integer -> String
sinal2 x = case x < 0 of
  True  -> "Negativo"
  False -> case x == 0 of
    True  -> "Zero"
    False -> "Positivo"

sinal3 :: Integer -> String
sinal3 x = case compare x 0 of
  LT -> "Negativo"
  EQ -> "Zero"
  _  -> "Positivo"

sinal4 :: Integer -> String
sinal4 x
  | x < 0 = "Negativo"
  | x == 0 = "Zero"
  | otherwise = "Positivo"

--

data ArvBin a where
  Folha :: ArvBin a
  No :: a -> ArvBin a -> ArvBin a -> ArvBin a
  deriving (Show, Eq, Functor)
-- exercÃ­cio: escreva sua instance Show mais bonitinha!

-- instance Functor ArvBin where
--   fmap _ Folha = Folha
--   fmap f (No valor_a arv_esq arv_dir) = No (f valor_a) (fmap f arv_esq) (fmap f arv_dir)


t = No 65 (Folha) (No 3 (No 0 Folha Folha) Folha)
s = No 65 (Folha) (No 3 (No 0 Folha Folha) Folha)
u = No "Hugo" Folha Folha

-- exercÃ­cio: definir o tipo dos nÃºmeros naturais!