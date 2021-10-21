from random import randrange
def parte_ímpar(m):
  k = 0
  q = m
  while q%2 == 0:
    k += 1
    q //= 2
  return k,q



def teste_Miller_Rabin(n,b):
  k, q = parte_ímpar(n-1)
  x = pow(b, q, n)
  if x == 1 or x == n-1:
    return "teste inconclusivo"
  contador = 0
  while True:
    x = pow(x,2,n)
    
    contador += 1
    if x == 1:
      return "composto"
    if contador == k:
      return "composto"
    if x == n-1:
      return "teste inconclusivo"


def gera_primos(n):
    while True:
        num = randrange((10**n)+1,10**(n+2),2)
        bases_testadas =0
        while bases_testadas <10:
            base = randrange(2, num-1)
            if(teste_Miller_Rabin(num, base) == "composto"):
                break
            bases_testadas +=1
        if(bases_testadas>=10):
            return num
print(gera_primos(75))





