import sys 

def conjectura(number, initialNumber):
    new_number=0
    if(number%2)==0:
        new_number=number/2
    else:
        new_number=number*3+1
    print("Calculei e agora é {}".format(new_number))
    if(new_number!=1):
        conjectura(new_number,initialNumber)
    else:
        print("Terminei, o numero inicial foi {}".format(initialNumber))

try:
    conjectura(int(sys.argv[1]),int(sys.argv[1]) )
except:
    print("por favor, digite somente numeros inteiros")
