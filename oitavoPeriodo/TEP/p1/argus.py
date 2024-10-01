
from heapq import heapify, heappush, heappop 





heap = []
while True:
    commando = input()
    if(commando == '#'):
        break
    parts = commando.split()
    heap.append((int(parts[2]),int(parts[1]),int(parts[2])))
heapify(heap)
n = int(input())
for i in range(n):
    elementToRun = heappop(heap)
    print(elementToRun[1])
    heappush(heap, (elementToRun[0]+elementToRun[2], elementToRun[1],elementToRun[2]))

    
 
