from heapq import heappush,heappop


def getMinHandle(numbers, command, prints):
    if(len(numbers) ==0):
        heappush(numbers, int(command[1]))
        prints.append(f'insert {command[1]}')
        prints.append(f'getMin {command[1]}')
        return numbers,prints

    if(numbers[0] != int(command[1])):
        if(numbers[0] < int(command[1])):
            while(len(numbers)>0 and numbers[0]< int(command[1])):
                prints.append('removeMin')
                heappop(numbers)
            
        if(len(numbers)>0 and numbers[0]==int(command[1])):
            prints.append(f'getMin {command[1]}')
            return numbers,prints
        heappush(numbers, int(command[1]))
        prints.append(f'insert {command[1]}')
        prints.append(f'getMin {command[1]}')
        
    else:
        prints.append(f'getMin {command[1]}')
        
    return numbers,prints
            

def removeMinHandle(numbers, prints):
    if(len(numbers) ==0):
        prints.append(f'insert 1')
        prints.append(f'removeMin')
        return numbers, prints
    heappop(numbers)
    prints.append('removeMin')
    return numbers, prints 



def resolve():
    numberOfCommands = int(input())
    numbers = []
    prints = []
    for _ in range(numberOfCommands):
        command = input().split(" ")
        if(command[0]=="insert"):
            prints.append(f'insert {command[1]}')
            heappush(numbers, int(command[1]))
        if(command[0]=="removeMin"):
            numbers,prints = removeMinHandle(numbers, prints)
        if(command[0]=="getMin"):
            numbers,prints = getMinHandle(numbers,command, prints)

    print(len(prints))
    for i in prints:
        print(i)

    

resolve()