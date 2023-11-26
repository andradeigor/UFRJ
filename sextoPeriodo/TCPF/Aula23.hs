module Aula23 where

data Bla where
  Ble :: Bla
  Bli :: Bla
  Blo :: Bla
  Fun :: Bla -> Bla -> Bla
  deriving (Show, Eq)
  -- Ã© o magma livremente gerado por 3 elementos
  -- nÃ£o Ã© associativo!

data Cla where
  Cle :: Cla
  Cli :: Cla
  Clo :: Cla
  Gun :: Cla -> Cla -> Cla
  deriving Show
  -- nÃ£o Ã© o magma livremente gerado por 3 elementos
  -- como fazer satisfazer associatividade? Dando uma implmentaÃ§Ã£o de Eq!

toList :: Cla -> [Cla]
toList Cle = [Cle]
toList Cli = [Cli]
toList Clo = [Clo]
toList (Gun x y) = (toList x) ++ (toList y)

instance Eq Cla where
  Cle == Cle = True
  Cle == _   = False
  Cli == Cli = True
  Cli == _   = False
  Clo == Clo = True
  Clo == _   = False
  x   == y   = (toList x) == (toList y)

data Natural = Zero | Suc Natural
  deriving (Eq, Show)

data Dla = Dle | Hun Dla
  deriving (Eq, Show)