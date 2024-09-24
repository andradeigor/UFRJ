
import sys

input = sys.stdin.read
data = [int(x) for x in input().split()]

resFinal =[]
for k in data:
    y = k+1
    res = []
    while y <= (2*k+1):
        if(k*y%(y-k)==0):
            res.append(f'1/{k} = 1/{k*y//(y-k)} + 1/{y}')
        y +=1     
    resFinal.append(res)
for res in resFinal:
    print(len(res))
    for response in res:
        print(response)