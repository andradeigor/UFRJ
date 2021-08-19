import random
def divisaoReal(dividendo, divisor, ponto1,ponto2):
    quociente = random.randint(ponto1, ponto2)
    resto = dividendo - (quociente * divisor)
    if(abs(resto) > divisor):
        if(quociente * divisor > dividendo):
            divisaoReal(dividendo, divisor, ponto1, quociente)
        else:
            divisaoReal(dividendo, divisor, quociente, ponto2)
    elif(dividendo == (divisor*quociente + resto)): 
        print(quociente, resto)


def divisao(dividendo, divisor):
    divisaoReal(dividendo,divisor, 0, dividendo//2)



divisao(86,3)
