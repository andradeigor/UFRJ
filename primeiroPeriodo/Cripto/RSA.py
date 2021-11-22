from random import randrange
from collections import deque


códigos_para_símbolos = {111: '0', 112: '1', 113: '2', 114: '3', 115: '4',
116: '5', 117: '6', 118: '7', 119: '8', 121: '9', 122: '=', 123: '+',
124: '-', 125: '/', 126: '*', 127: 'a', 128: 'b', 129: 'c', 131: 'd',
132: 'e', 133: 'f', 134: 'g', 135: 'h', 136: 'i', 137: 'j', 138: 'k',
139: 'l', 141: 'm', 142: 'n', 143: 'o', 144: 'p', 145: 'q', 146: 'r',
147: 's', 148: 't', 149: 'u', 151: 'v', 152: 'w', 153: 'x', 154: 'y',
155: 'z', 156: 'á', 157: 'à', 158: 'â', 159: 'ã', 161: 'é', 162: 'ê',
163: 'í', 164: 'ó', 165: 'ô', 166: 'õ', 167: 'ú', 168: 'ç', 169: 'A',
171: 'B', 172: 'C', 173: 'D', 174: 'E', 175: 'F', 176: 'G', 177: 'H',
178: 'I', 179: 'J', 181: 'K', 182: 'L', 183: 'M', 184: 'N', 185: 'O',
186: 'P', 187: 'Q', 188: 'R', 189: 'S', 191: 'T', 192: 'U', 193: 'V',
194: 'W', 195: 'X', 196: 'Y', 197: 'Z', 198: 'Á', 199: 'À', 211: 'Â',
212: 'Ã', 213: 'É', 214: 'Ê', 215: 'Í', 216: 'Ó', 217: 'Ô', 218: 'Õ',
219: 'Ú', 221: 'Ç', 222: ',', 223: '.', 224: '!', 225: '?', 226: ';',
227: ':', 228: '_', 229: '(', 231: ')', 232: '"', 233: '#', 234: '$',
235: '%', 236: '@', 237: ' ', 238: '\n'}

símbolos_para_códigos = {'0': 111, '1': 112, '2': 113, '3': 114, '4': 115,
'5': 116, '6': 117, '7': 118, '8': 119, '9': 121, '=': 122, '+': 123,
'-': 124, '/': 125, '*': 126, 'a': 127, 'b': 128, 'c': 129, 'd': 131,
'e': 132, 'f': 133, 'g': 134, 'h': 135, 'i': 136, 'j': 137, 'k': 138,
'l': 139, 'm': 141, 'n': 142, 'o': 143, 'p': 144, 'q': 145, 'r': 146,
's': 147, 't': 148, 'u': 149, 'v': 151, 'w': 152, 'x': 153, 'y': 154,
'z': 155, 'á': 156, 'à': 157, 'â': 158, 'ã': 159, 'é': 161, 'ê': 162,
'í': 163, 'ó': 164, 'ô': 165, 'õ': 166, 'ú': 167, 'ç': 168, 'A': 169,
'B': 171, 'C': 172, 'D': 173, 'E': 174, 'F': 175, 'G': 176, 'H': 177,
'I': 178, 'J': 179, 'K': 181, 'L': 182, 'M': 183, 'N': 184, 'O': 185,
'P': 186, 'Q': 187, 'R': 188, 'S': 189, 'T': 191, 'U': 192, 'V': 193,
'W': 194, 'X': 195, 'Y': 196, 'Z': 197, 'Á': 198, 'À': 199, 'Â': 211,
'Ã': 212, 'É': 213, 'Ê': 214, 'Í': 215, 'Ó': 216, 'Ô': 217, 'Õ': 218,
'Ú': 219, 'Ç': 221, ',': 222, '.': 223, '!': 224, '?': 225, ';': 226,
':': 227, '_': 228, '(': 229, ')': 231, '"': 232, '#': 233, '$': 234,
'%': 235, '@': 236, ' ': 237, '\n': 238}




def parte_ímpar(m):
  k = 0
  q = m
  while q%2 == 0:
    k += 1
    q //= 2
  return k,q

def Bezout(dividendo,divisor,x1=1,x2=0,y1=0,y2=1):# REFAZER
    quociente,resto = divmod(dividendo, divisor)
    return (divisor, x2,y2) if not resto else Bezout(divisor, resto,x2,(x1-x2*quociente), y2,(y1-y2*quociente )) 

def teste_Miller_Rabin(n,b):
  k, q = parte_ímpar(n-1)
  x = pow(b, q, n)
  if x == 1 or x == n-1:
    return True
  contador = 0
  while True:
    x = pow(x,2,n)
    
    contador += 1
    if x == 1:
      return False
    if contador == k:
      return False
    if x == n-1:
      return True


def gera_primos(n):
    while True:
        num = randrange((10**n)+1,10**(n+2),2)
        bases_testadas =0
        while bases_testadas <10:
            base = randrange(2, num-1)
            if( not teste_Miller_Rabin(num, base) ):
                break
            bases_testadas +=1
        if(bases_testadas>=10):
            return num


def gera_chaves():
  while True:
    p = gera_primos(75)
    q = gera_primos(75)
    n = p*q
    phi = (p-1)*(q-1)
    e=3
    while True:
      mdc, d,_ = Bezout(e,phi)
      if(mdc !=1 or d<0):
        e+=2
        continue
      break
    _,inversoP,_ = Bezout(p,q)
    _,inversoQ,_ = Bezout(q,p)
    return p,q,n,e,d,inversoP, inversoQ
    

def encripta(texto, n, e):

  numeros = [str(símbolos_para_códigos[x]) for x in texto]
  numerosString = ''.join(numeros)
  blocos = deque()
  base = 0
  for index in range(1,len(numerosString)+1):
    if(len(numerosString[base:index]) > len(str(n//10**2))):
      blocos.append(int(numerosString[base:index]))
      base = index
  blocos.append(int(numerosString[base:]))
  for i in range(len(blocos)):
    bloco = blocos.popleft()
    blocos.append(pow(bloco,e,n))
  return blocos

def descriptar(blocos, n, d):
  blocos_descriptados = [str(pow(x,d,n)) for x in blocos]
  numerosString = ''.join(blocos_descriptados)
  textoDescriptado = ""
  base = 0
  for index in range(1,len(numerosString)+1):
    if(index%3==0):
      temp = códigos_para_símbolos[int(numerosString[base:index])] 
      textoDescriptado +=temp
      base = index
  return textoDescriptado
def descriptarTCR(blocos,n,d,p,q,inversoQ):
  dp = pow(d,1,p-1)
  dq = pow(d,1,q-1)
  numerosString = ""
  textoDescriptado = ""
  for bloco in blocos:
    parte1 = pow(bloco,dp,p)
    parte2 = pow(bloco,dq,q)
    subase = (inversoQ * (parte1 - parte2)) % p
    numerosString += str(parte2 + subase * q)
  base = 0
  for index in range(1,len(numerosString)+1):
    if(index%3==0):
      temp = códigos_para_símbolos[int(numerosString[base:index])] 
      textoDescriptado +=temp
      base = index
  return textoDescriptado


p,q,n,e,d,inversoP,inversoQ = gera_chaves()






