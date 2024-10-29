from collections import defaultdict
try:
    while True:
        graph = {}
        text = input()
        if(text==""):
            continue
        inter, roads = [int(x) for x in text.split()]
        addedRoads = set()
        for _ in range(roads):
            n,m = map(int,input().split())
            if(n not in graph):
                graph[n] = set()
            if(m not in graph):
                graph[m] = set()
            
            graph[n].add(m)
            graph[m].add(n)
            addedRoads.add(n)
            addedRoads.add(m)

        if(roads ==0 or roads%2!=0):
            print("Not Possible")
            continue

        visiteds = set()
        
        
        def dfs(node):
            visiteds.add(node)
            for neightbor in graph[node]:
                if neightbor not in visiteds:
                    dfs(neightbor)
        
        for node in graph.keys():
            dfs(node)
            break
           
        #print(visiteds, addedRoads)
        print("Possible" if len(visiteds) == len(addedRoads) else  "Not Possible")

except EOFError:
    pass
