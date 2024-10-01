from math import isqrt

def odd(n):
    k = n**2
    N = (k+1)//2
    if(n<=1):
        print(-1)
        return 
    print(int(isqrt(((N+n)*(N-n)))),N )

def even(n):
    m = n//2
    if(n<=2):
        print(-1)
        return
    n = 1
    print(m**2-n**2, m**2+n**2)

n = int(input())
if(n%2==0):
    even(n)
else:
    odd(n)
