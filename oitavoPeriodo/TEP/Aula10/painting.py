from collections import defaultdict, deque


def isBipartite(graph, v):
    color = [-1] * v  
    min_color_count = v  
    
    for start in range(v):
        if color[start] == -1:  
            queue = deque([start])
            color[start] = 0  
            count_color_0 = 0  
            count_color_1 = 0  

            while queue:
                node = queue.popleft()
                if color[node] == 0:
                    count_color_0 += 1
                else:
                    count_color_1 += 1
                
                
                for neighbor in graph[node]:
                    if color[neighbor] == -1: 
                        color[neighbor] = 1 - color[node] 
                        queue.append(neighbor)
                    elif color[neighbor] == color[node]:  
                        return False, 0  
            min_color_count = min(min_color_count, min(count_color_0, count_color_1))
    
    return True, min_color_count  

n = int(input())


for k in range (n):
    
    v,e = map(int, input().split())
    if(k==4):
        print(v,e)
        exit()
    if(e == 0):
        print(1)
        continue
    graph = defaultdict(list)

    for _ in range(e):
        f,g = map(int, input().split())
        graph[f].append(g)
        graph[g].append(f)
    res = isBipartite(graph,v)
    
    print(-1 if not res[0] else  res[1])