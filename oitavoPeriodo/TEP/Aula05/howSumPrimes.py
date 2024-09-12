def crivo(N):
    numbers = set()
    A = [True] * (N+1)
    A[0] = A[1] = False
    for value, prime in enumerate(A):
        if prime:
            numbers.add(value)
            for i in range(value**2, N+1, value):
                A[i] = False
    return numbers

def resolve(n, numbers):
    for i in numbers:
        if n-i in numbers:
            return i,n-i


import sys

numbers = crivo(10000000)
input = sys.stdin.read
data = input().split()
for line in data:
    n = int(line)
    if(n==0):
        break
    if(n < 8):
        print('Impossible.')
        continue
    i=0
    if(n %2==0):
        res = resolve(n - 4, numbers)
        print(f'2 2 {res[0]} {res[1]}')
    else:
        res = resolve(n - 5, numbers)
        print(f'2 3 {res[0]} {res[1]}')    
  
