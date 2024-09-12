from math import sqrt 


def findFirstDivisor(n):
    for i in range(2,int(sqrt(abs(n)))+1):
        if(n%i==0):
            return i
    return n



while True:
    n = int(input())
    if(n==0):
        break
    n = abs(n)
    div = findFirstDivisor(n)
    quo = n//div

    divs = set()
    divs.add(div)
    #caso de um numero primo, o "primeiro" divisor é ele msm
    if(quo ==1):
        print(-1)
        continue
    while quo !=1:
         div = findFirstDivisor(quo)
         divs.add(div)
         quo = quo//div
    print(div if len(divs) > 1 else -1)

