from sys import stdin 

def primeFactors(N):
    p,i = 2,1
    primfac = {}              
    while p*p<=N:          
        while N%p == 0:     
            if(p in primfac):
                return False
            primfac[p] = 1          
            N //= p        
        p,i = p+i,2
    if(N in primfac):
        return False
    if N > 1:
       primfac[N] = 1
    return primfac         

input = stdin.read
data = input().split()
for line in data:
    n = int(line)
    if(n==0):
        break
    if(n < 561):
        #print(f'{n} is normal.')
        continue
    impossivel = False
    fatoresPrimos = primeFactors(n)
    if(not fatoresPrimos or len(fatoresPrimos.keys()) ==1):
        #print(f'{n} is normal.')
        continue
    for i in fatoresPrimos.keys():
        if((n-1)%(i-1) !=0):
            #print(f'{n} is normal.')
            impossivel=True
            break
    if not impossivel:
        print(f"The number {n} is a Carmichael number.")