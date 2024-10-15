from collections import deque
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

def bfs(matriz, i,j):
    queue = deque([(i,j)])
    visited = set()
    while queue:
        node = queue.popleft()
        visited.add(node)
        possibleMoves = possibleToGo(matriz, node[0], node[1])
        #print(possibleMoves)
        for move in possibleMoves:
            if(move not in visited):
                queue.append(move)
    return visited         


try:
    while True:
        n, m = map(int, input().split())
        land = [input().strip() for _ in range(n)]
        landI, landJ = map(int, input().split())
        landMark = land[landI][landJ]
        
        booleanLand = [[cell == landMark for cell in line] for line in land]

        visited = set()
        biggest = 0

     
        mainLand = bfs(booleanLand, landI, landJ)
        visited = visited.union(mainLand)

        #print(visited)
        for i in range(n):
            for j in range(m):
                if (i, j) not in visited and booleanLand[i][j]:
                    newVisited = bfs(booleanLand, i, j)
                    #print(newVisited)
                    visited = visited.union(mainLand)
                    biggest = max(biggest, len(newVisited))

        print(biggest)
        input()
except EOFError:
    pass