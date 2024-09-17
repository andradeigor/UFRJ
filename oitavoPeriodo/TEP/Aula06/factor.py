def primeFactors(N):
    p,i = 2,1
    primfac = {}              
    while p*p<=N:          
        while N%p == 0:     
            if(p not in primfac):
                primfac[p] = 0          
            primfac[p] +=1
            N //= p        
        p,i = p+i,2
    if N > 1:
       primfac[N] = 1
    return primfac         


try:
    while True:
        n = int(input())
        fact = primeFactors(n)
        result = 0
        for number,factor in fact.items():
            result+= factor*number
        print(fact)
        print(result)

except EOFError:
    pass