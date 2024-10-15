testCases = int(input())

def find(a, groups):
    if(groups[a]!=a):
        groups[a] = find(groups[a], groups)
    return groups[a]

def union(a,b,groups, lenghs):
    #print(f'Vou juntar {a} com {b}')
    #print(groups)
    #print(lenghs)
    fatherA = find(a,groups)
    fatherB = find(b,groups)
    if(fatherA == fatherB):
        return groups, lenghs,lenghs[fatherA]
    if(lenghs[fatherA] > lenghs[fatherB]):
        groups[fatherB] = fatherA
        lenghs[fatherA]+= lenghs[fatherB]
        return groups, lenghs,lenghs[fatherA]
    else:
        groups[fatherA] = fatherB
        lenghs[fatherB]+= lenghs[fatherA]
        return groups, lenghs,lenghs[fatherB]



for _ in range(testCases):
    n,m = [int(x) for x in input().split()]
    groups = {}
    lenghs = {}
    maxLeght = 1
    for i in range(n+1):
        groups[i] = i
        lenghs[i] = 1
    for _ in range(m):
        friendA,friendB = [int(x) for x in input().split()]
        groups, lenghs,newLenght = union(friendA,friendB,groups,lenghs)
        maxLeght = max(maxLeght, newLenght)
    print(maxLeght)

