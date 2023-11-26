data Natural where
  Zero :: Natural
  Suc :: Natural -> Natural
  deriving Eq

instance Show Natural where
    show :: Natural -> String
    show Zero = show 0
    show (Suc natural) = show (1 + read (show natural))

somar :: Natural -> Natural -> Natural
somar x Zero    = x
somar x (Suc y) = Suc $ somar x y

produto :: Natural -> Natural -> Natural
produto x Zero    = Zero
produto x (Suc y) = somar (produto x y) x

data Inteiro where
  Inteiro :: Natural -> Natural -> Inteiro
  deriving Eq

instance Show Inteiro where
    show :: Inteiro -> String
    show (Inteiro a b) = show a ++ "," ++ show b   

isomar :: Inteiro -> Inteiro ->Inteiro
isomar (Inteiro x1 y1) (Inteiro x2 y2)  = Inteiro (somar x1 x2) (somar y1 y2)

iproduto :: Inteiro -> Inteiro -> Inteiro 
iproduto (Inteiro x1 y1) (Inteiro x2 y2) = Inteiro (somar (produto x1 y2) (produto y1 x2)) (somar (produto x1 x2) (produto y1 y2))

class Anel x where
  f :: x->x->x
  g :: x->x->x
  i :: x->x
  z :: x
  u :: x

instance Anel Natural where
  z :: Natural
  z = Zero
  u :: Natural
  u = Suc Zero
  f :: Natural -> Natural -> Natural
  f = somar
  g :: Natural -> Natural -> Natural
  g = produto
   
instance Anel Inteiro where
  z :: Inteiro
  z = Inteiro Zero Zero
  u :: Inteiro
  u = Inteiro Zero (Suc Zero)
  f :: Inteiro -> Inteiro -> Inteiro
  f = isomar
  g :: Inteiro -> Inteiro -> Inteiro
  g = iproduto
  i :: Inteiro -> Inteiro
  i (Inteiro x y) = Inteiro y x 

data ArvBin a where
  Folha :: ArvBin a 
  No :: a -> ArvBin a -> ArvBin a -> ArvBin a 
  deriving (Show, Eq)

buscaNo :: Eq a => a -> ArvBin a -> Bool
buscaNo a Folha = False
buscaNo a (No b esq dir) =  a == b || (buscaNo a esq || buscaNo a dir)

data ArvBin2  where
  Folha2 :: ArvBin2 
  No2 :: Int -> ArvBin2 -> ArvBin2 -> ArvBin2 
  deriving (Show, Eq)

arvParaList :: ArvBin2 -> [Int]
arvParaList Folha2 = []
arvParaList (No2 raiz esq dir) = raiz : ((arvParaList esq) ++ (arvParaList dir))

isArrumada :: ArvBin2-> Bool
isArrumada Folha2 = True
isArrumada (No2 raiz Folha2 Folha2) = True
isArrumada (No2 raiz esq Folha2) = (raiz >= maximum(arvParaList esq)) && isArrumada esq
isArrumada (No2 raiz Folha2 dir) = (raiz <= minimum(arvParaList dir)) && isArrumada dir 
isArrumada (No2 raiz esq dir) = (raiz >= maximum(arvParaList esq)) && (raiz <= minimum(arvParaList dir)) && isArrumada esq && isArrumada dir
