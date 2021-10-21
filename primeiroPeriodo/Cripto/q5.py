from itertools import combinations
def combinacoes_mdc(lista):
    lista = combinations(lista,2)
    for item in lista:
        resultado = mdc(item[0], item[1])
        if(resultado !=1):
            print(f'o fator comum entre\nn1:{item[0]}\nn2:{item[1]}\nfoi {resultado}\no outro fator do primeiro numero é {int(item[0]/resultado)}\ne o outro fator do segundo é {int(item[1]/resultado)}')
            break

#a questão só trata de valores inteiros então n vou validar a entrata
def mdc(a,b):
    return b if not a%b else mdc(b,a%b)


lista = [68397633165470058274884361378645822467587248043012077070501,
 290216330211198637784379813527744010595500946558768017267121,
 245841236512478852752909734912575581815967630033049838269083]

combinacoes_mdc(lista)