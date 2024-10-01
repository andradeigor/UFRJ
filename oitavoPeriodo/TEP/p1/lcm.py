import math
def divisors(n):
    divs = [1]
    for i in range(2,int(math.sqrt(n))+1):
        if n%i == 0:
            divs.extend([int(i),int(n/i)])
    divs.extend([int(n)])
    return list(set(divs))

def gdp(a,b):
    return b if a%b ==0 else gdp(b, a%b)


while True:
    n = int(input())
    if n ==0:
        break
    divisores = divisors(n)
    res = set()
    for i in divisores:
        for j in divisores:
            mdc = gdp(abs(i), abs(j))
            if(int(i*j/mdc) == n):
                res.add((min(i,j), max(i,j)))
    print(f'{n} {len(res)}')