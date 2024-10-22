from collections import deque
       


try:
    while True:
        n, m = map(int, input().split())
        land = [input().strip() for _ in range(n)]
        landI, landJ = map(int, input().split())
        landMark = land[landI][landJ]
        visited = set()
        biggest = 0

        def possibleToGo(i, j):
            possibleMoves = []
            directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
            for di, dj in directions:
                ni, nj = i + di, j + dj
                if (
                0 <= ni and ni < len(land) 
                and 0 <= nj 
                and nj < len(land[0]) 
                and land[ni][nj] == landMark):
                    possibleMoves.append((ni, nj))
            
            if(j+1 == len((land[0])) and land[i][0] == landMark):
                possibleMoves.append((i,0))
            if(j-1 == -1 and land[i][-1]) == landMark:
                possibleMoves.append((i,len(land[0])-1))
            return possibleMoves
        def bfs(i,j):
            queue = deque([(i,j)])
            size = 0
            visited.add((i,j))
            while queue:
                ni,nj = queue.popleft()
                size+=1
                moves = possibleToGo(ni,nj)
                for move in moves:
                    if move not in visited:
                        queue.append(move)
                        visited.add(move)      
            return size


     
        bfs(landI, landJ)
  

        for i in range(n):
            for j in range(m):
                if (i, j) not in visited and land[i][j] == landMark:
                    newSize = bfs(i, j)
                    
                    biggest = max(biggest,newSize)

        print(biggest)
   
        input()
except EOFError:
    pass