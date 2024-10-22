n = int(input())
ans = []
for _ in range(n):
    nvertices = int(input())
    data = [int(x) for x in input().split()]
    lastSeen = -1
    height = 1
    leafs = 0
    levels = [[data[0]], []]
    if(len(data)<2):
        print(height)
        continue
    i = 1
    while i < len(data):
        if(leafs == len(levels[height-1])):
            height+=1
            leafs =0
            levels.append([data[i]])
        else:
            levels[height].append(data[i])
        i+=1
        while(i < len(data) and data[i]>data[i-1]):
            levels[height].append(data[i])
            i+=1
        leafs+=1
    print(len(levels)-1)

