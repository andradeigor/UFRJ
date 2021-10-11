import random
import time
import os
def gerarMatriz():
    linhas = []
    aux = []
    for j in range(2):
        for i in range(1,9):
            aux.append(i)
    for j in range(4):
        colunas = []
        for i in range(4):
            index = random.randint(0,len(aux)-1)
            colunas.append(aux[index])
            aux.remove(aux[index])
        linhas.append(colunas)
    return linhas

def geraMascara():
    asteriscos = []
    for j in range(4):
        auxiliar = []
        for i in range(4):
            auxiliar.append('*')
        asteriscos.append(auxiliar)
    return asteriscos

def printaMatriz(matriz):
    for linha in matriz:
        for n in linha:
            print(f"{n}  ", end=" ")
        print(" ")

def trocaElemento(mascara, matriz, linha, coluna):
    mascara[linha][coluna] = matriz[linha][coluna]
    return mascara

def compara(matriz, linha1, coluna1, linha2, coluna2):
    if(matriz[linha1][coluna1] == matriz[linha2][coluna2]):
        return True
    return False

def resetaElemento(mascara, linha1, coluna1, linha2, coluna2):
    mascara[linha1][coluna1] = '*'
    mascara[linha2][coluna2] = '*'
    return mascara

def verificaGame(mascara):
    for linha in mascara:
        for n in linha:
            if(n == '*'):
                return False
    return True
    

def main():
    matriz = gerarMatriz()
    printaMatriz(matriz)
    time.sleep(3)
    os.system('cls' if os.name == 'nt' else 'clear')
    mascara = geraMascara()
    while(True):
        printaMatriz(mascara)
        linha = int(input('Digite a linha desejada: '))
        coluna = int(input('Digite a coluna desejada: '))
        mascara = trocaElemento(mascara, matriz, linha, coluna)
        os.system('cls' if os.name == 'nt' else 'clear')
        printaMatriz(mascara)
        linha2 = int(input('Digite a linha desejada: '))
        coluna2 = int(input('Digite a coluna desejada: '))
        mascara = trocaElemento(mascara, matriz, linha2, coluna2)
        os.system('cls' if os.name == 'nt' else 'clear')
        printaMatriz(mascara)
        verifica = compara(matriz, linha, coluna, linha2, coluna2)
        if(not verifica):
            mascara = resetaElemento(mascara, linha, coluna, linha2, coluna2)
            time.sleep(1.5)
        os.system('cls' if os.name == 'nt' else 'clear')
        game = verificaGame(mascara)
        if(game):
            print('Você ganhou! Parabéns!')
            break
    

if __name__ == "__main__":
    main()