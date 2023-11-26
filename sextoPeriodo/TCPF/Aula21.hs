module Aula21 where
import Aula10

-- TransformaÃ§Ãµes Naturais em Haskell

eta :: [t] -> [t]
eta []                     = []
-- eta (valor_t : lista_de_t) = [valor_t]
eta (valor_t : lista_de_t) = lista_de_t

eta' :: [t] -> [t]
eta' (x:y:z:w:cauda) = x:y:w:z:cauda
eta' _               = []

eta'' :: [t] -> ArvBin t
eta'' []        = Folha
eta'' (x:cauda) = No x Folha (eta'' cauda)

eta''' :: [t] -> ArvBin t
eta''' []             = Folha
eta''' [raiz,esq,dir] =
  No raiz
  (No esq Folha Folha)
  (No dir Folha Folha)
eta''' (ignora:cauda) = eta''' cauda

bla :: Integer
bla = bla -- loop infinito!