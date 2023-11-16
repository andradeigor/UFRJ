from multiprocessing.pool import Pool
from multiprocessing import cpu_count
import time
import sys  
from math import sqrt
#funcao que sera executada de forma concorrente
def ehPrimo(n):
    if (n<=1): return 0
    elif (n==2): return 1
    elif (n%2==0): return 0
    for i in range(3,int(sqrt(n)+1),2):
        if(n%i==0):return 0
    return 1

if __name__ == '__main__':
    start = time.time()
    if(len(sys.argv) <1):
        print("Digite o numero junto com o programa")
        sys.exit(0)
    
    N = int(sys.argv[1])
    pool = Pool() #por default, cria um processo distinto para cada processador da maquina
    numbers = list(range(1,N+1))
    #map aceita uma funcao e um objeto iteravel, o pool pega cada valor do objeto iteravel e passa para um processo disponivel no poll que aplica a funcao sobre esse valor
    results = pool.map(ehPrimo, numbers)
    print(f'De {1} até {N} nós temos {sum(results)} primos.')
    end = time.time()
    print('work took {} seconds'.format(end - start))
