module Aula15 where

-- Coprodutos
data Coprod a b where
  Esq :: a -> Coprod a b
  Dir :: b -> Coprod a b
  deriving (Eq, Show)

f :: String -> Bool
f "Hugo" = True
f _ = False

g :: Integer -> Bool
g 36 = True
g _ = False

h :: Coprod String Integer -> Bool
h (Esq str) = f str
h (Dir int) = g int

x :: Coprod String Integer
x = Dir 2

y :: Coprod String Integer
y = Esq "Hugo"

-- Para produtos, poderÃ­amos ter < _ , _ >
-- prod :: (c -> a) -> (c -> b) -> (c -> Prod a b)

-- Alternativas de produtos em Haskell:

-- (1) Pares: (, )
-- projeÃ§Ãµes: fst, snd

par :: (String, Integer)
par = ("Hugo", 36)

-- (2) Records

data Prod a b = MkProd { proj_a::a, proj_b::b }
  deriving (Eq, Show)

outro_par :: Prod String Integer
outro_par = MkProd "Hugo" 36

-- para alterar, guardando com outro nome:

outro_par' :: Prod String Integer
outro_par' = outro_par { proj_b = 37 }

prod :: (c -> a) -> (c -> b) -> (c -> Prod a b)
prod f g = \ val_c -> MkProd {proj_a = f val_c, proj_b = g val_c}

k :: Bool -> String
k True = "Hugo"
k _ = "nÃ£o-Hugo"

j :: Bool -> Integer
j True = 36
j _ = 0