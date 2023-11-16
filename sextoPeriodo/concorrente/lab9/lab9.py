from multiprocessing.pool import Pool
from multiprocessing import cpu_count
import time
from math import sqrt
#funcao que sera executada de forma concorrente
def ehPrimo(interval):
    start,end = interval
    primesFound = 0
    for n in range(start,end):
        isCompost = False
        if (n<=1): 
            continue
        elif (n==2): 
            primesFound+= 1
            continue
        elif (n%2==0): 
            continue
        for i in range(3,int(sqrt(n)+1),2):
            if(n%i==0): 
                isCompost=True
                break
        if isCompost == False: 
            primesFound+=1
    return primesFound

if __name__ == '__main__':
    start = time.time()
    N = 1000
    pool = Pool() #por default, cria um processo distinto para cada processador da maquina
    spacing = N//cpu_count()
    numbers = [(i*spacing, (i+1) * spacing if i+1 != cpu_count() else N+1) for i in range(cpu_count())]
    #map aceita uma funcao e um objeto iteravel, o pool pega cada valor do objeto iteravel e passa para um processo disponivel no poll que aplica a funcao sobre esse valor
    results = pool.map(ehPrimo, numbers)
    print(sum(results))
    end = time.time()
    print('work took {} seconds'.format(end - start))
