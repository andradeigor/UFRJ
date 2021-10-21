
def altamenteCompostos(numero, dict):
    for i in range(1,numero):
        if( dict[numero]<= dict[i]):
            return False
    return True

def divisoresPositivos(numero):
    divisores =0
    for num in range(1,numero+1):#começa pelo 1 e vai até numero, +1 por conta do off by one
        if(numero%num==0):
            divisores+=1
    return divisores

def aux(n):
    dicDivisores = {}
    listaAltamenteCompostos = []R
    for i in range(1,n+1):#começa pelo 1 e vai até numero, +1 por conta do off by one
        divisores = divisoresPositivos(i)
        dicDivisores[i] = divisores
        AltamenteComposto = altamenteCompostos(i,dicDivisores)
        if(AltamenteComposto):
            listaAltamenteCompostos.append(i)
    print(listaAltamenteCompostos)
    print(f'A quantidade de numeros altamente compostos até {n} é {len(listaAltamenteCompostos)}')

def main():
    numeros = int(input("por favor digita um >>NUMERO NATURAL MAIOR QUE ZERO<<(NAO VOU VALIDAR ISSO): "))
    aux(numeros)

if __name__ == "__main__":
    main()