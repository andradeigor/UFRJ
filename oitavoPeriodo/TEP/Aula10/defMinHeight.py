



n = int(input())
ans = []
for _ in range(n):
    nvertices = int(input())
    data = [int(x) for x in input().split()]
    lastSeen = -1
    height = 1
    for i in range(1,len(data)):
        if(data[i] < data[i-1]):
            height+=1
    print(height)

