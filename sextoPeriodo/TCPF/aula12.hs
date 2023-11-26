module Aula12 where
import Aula11
import Aula10
import Data.Foldable

foldNat :: (b -> b) -> b -> Natural -> b
foldNat _ base Zero    = base
foldNat f base (Suc x) = f $ foldNat f base x

somaFold = foldNat Suc
produtoFold x = foldNat (somaFold x) Zero
-- produtoFold x = foldNat (somarFold x) Zero
potenciaFold x = foldNat (produtoFold x) (Suc Zero)
-- potenciaFold x y = foldNat (produtoFold x) (Suc Zero) y

foldArv :: (a -> e -> e -> e) -> e -> ArvBin a -> e
foldArv _ base Folha             = base
foldArv f base (No raiz esq dir) =
  f raiz
    (foldArv f base esq)
    (foldArv f base dir)

instance Foldable ArvBin where
  foldr :: (a -> b -> b) -> b -> ArvBin a -> b
  foldr _ base Folha             = base
  -- foldr f base (No raiz esq dir) =
  --   f
  --   raiz
  --   (foldr f (foldr f base dir) esq)
  foldr f base (No raiz esq dir) =
    let t1 = foldr f base dir
    in let t2 = foldr f t1 esq
    in f raiz t2
    
    

arvParaList :: ArvBin a -> [a]
arvParaList Folha = []
arvParaList (No raiz esq dir) = raiz : ((arvParaList esq) ++ (arvParaList dir))

arvParaListFold :: ArvBin a -> [a]
arvParaListFold = foldr (:) []

v = No 10 (No 5 (Folha) (No 6 Folha Folha)) (No 20 (No 15 Folha Folha) (No 100 Folha Folha))