import time
start = time.time()
def aux(n,inicio=2,):
    lista = n
    removed = False
    for numero in range(inicio*inicio,lista[-1]+1,inicio):
        if(numero in lista):
            removed = True
            lista.remove(numero)
    if(removed):
        aux(lista,inicio+1)
    return lista

def primos(n):
    numeros = list(range(2,n+1))
    listadeprimos = aux(numeros)
    end = time.time()
    print(end-start)
primos(10**8)