from collections import deque
    
while True:    
    text = input()
    n, m = text.split(" ")
    if(int(n)==0 and int(m)==0):
        break
    graph = {}
    dependences = {}
    for i in range(1,(int(n))+1):
        graph[str(i)] = []
        dependences[str(i)] =0
    for _ in range(int(m)):
        text = input()
        i, j = text.split(" ")
        graph[i].append(j)
        dependences[j] +=1
    
    queue = deque([])
    for i in dependences.keys():
        if(dependences[i] ==0):
            queue.append(i)
    while queue:
        item = queue.popleft()
        print(item)
        for i in graph[item]:
            dependences[i] -=1
            if(dependences[i] ==0):
                queue.append(i)
    
