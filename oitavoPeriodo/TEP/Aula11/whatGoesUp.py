arr = []
try:
    while True:
        n = int(input())
        arr.append(n)
except EOFError:
    pass


n = len(arr)
arr = [None] + arr  
M = [None]*(n+1)  
P = [None]*(n+1)
L = 0
for i in range(1,n+1):
    if L == 0 or arr[M[1]] >= arr[i]:
        j = 0
    else:
        lower = 1    
        high = L+1  
        while lower < high - 1:
            mid = (lower + high)//2
            if arr[M[mid]] < arr[i]:
                lower = mid
            else:
                high = mid
        j = lower

    P[i] = M[j]
    if j == L or arr[i] < arr[M[j+1]]:
        M[j+1] = i
        L = max(L,j+1)

res = []
possition = M[L]
while L > 0:
    res.append(arr[possition])
    possition = P[possition]
    L -= 1
print(len(res))
print('-')
for i in range(len(res)-1,-1,-1):
    print(res[i])

