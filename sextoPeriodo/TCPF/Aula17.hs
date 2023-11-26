module Aula17 where

data NaoLista a = Vazia | Unit a | Conc (NaoLista a) (NaoLista a)
  deriving (Show)

paraLista :: NaoLista a -> [a]
paraLista Vazia = []
paraLista (Unit a) = [a]
paraLista (Conc bla ble) = (paraLista bla) ++ (paraLista ble)

instance Eq a => Eq (NaoLista a) where
  nl0 == nl1 = (paraLista nl0) == (paraLista nl1)

data ExemploG = Constante | Op ExemploG
   deriving (Show, Eq)

-- exemplo de Magma Livre

data MagmaLivre a = Folha a | Raiz (MagmaLivre a) (MagmaLivre a)
  deriving (Show, Eq)

instance Functor MagmaLivre where
  fmap fun (Folha a) = Folha (fun a)
  fmap fun (Raiz m_esq m_dir) =
    Raiz (fmap fun m_esq) (fmap fun m_dir)