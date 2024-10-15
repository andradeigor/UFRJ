
def possibleToGo(matriz, i, j):
    possibleMoves = []
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    for di, dj in directions:
        ni, nj = i + di, j + dj
        if 0 <= ni and ni < len(matriz) and 0 <= nj and nj < len(matriz[0]) and matriz[ni][nj]:
            possibleMoves.append((ni, nj))
    
    # Considerando o wrap-around
    if(j+1 == len((matriz[0])) and matriz[i][0]):
        possibleMoves.append((i,0))
    if(j-1 == -1 and matriz[i][-1]):
        possibleMoves.append((i,len(matriz[0])-1))
    #print(possibleMoves)
    return possibleMoves

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



try:
    while True:
        n, m = map(int, input().split())
        land = [input().strip() for _ in range(n)]
        landI, landJ = map(int, input().split())
        landMark = land[landI][landJ]
        
        booleanLand = [[cell == landMark for cell in line] for line in land]
        groups = {}
        lenght = {}
        visited = set()
        biggest = 0
        for i in range(n):
            for j in range(m):
                groups[(i, j)] = (i, j)
                lenght[(i, j)] = 1
        for i in range(n):
            for j in range(m):
                if (i, j) not in visited and booleanLand[i][j]:
                    moves = possibleToGo(booleanLand, i,j)
                    for move in moves:
                        if move not in visited:
                            a = find(move, groups)
                            union(a,(i,j),groups, lenght)
                            visited.add(move)
        for i in groups.keys():
            groups[i] = find(i, groups)
        print(groups)
        input()
except EOFError:
    pass