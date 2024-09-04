from collections import deque
cenario = 0
while True:
    text = input()
    if(text == "0"):
        break
    cenario+=1
    Nteams = int(text)
    teams = []
    teamsAdded = {}
    teamsIndex = {}
    teamsQueueStatus = []
    teamsQueue = deque([])
    for teamIndex in range(Nteams):
        textTeam = input()
        textTeam = textTeam.split(" ")
        team = set()
        for i in range(int(textTeam[0])):
            teamsAdded[textTeam[i+1]] = teamIndex
        teamsQueueStatus.append(-1)

    print(f"Scenario #{cenario}")
    while True:
        text = input()
        if(text.startswith("STOP")):
            print("")
            break
        if(text.startswith("ENQUEUE")):
            text = text.split(" ")
            if(teamsQueueStatus[teamsAdded[text[1]]]==-1):
                teamsQueue.append(deque([text[1]]))
                #print(teamsAdded[text[1]])
                teamsQueueStatus[teamsAdded[text[1]]] = len(teamsQueue)-1
            else:
                teamIndex = teamsQueueStatus[teamsAdded[text[1]]]
                #print(teamsQueue)
                #print(teamIndex)
                teamsQueue[teamIndex].append(text[1])
            continue    
        if(text.startswith("DEQUEUE")):
            #print(f'Antes{teamsQueue}')
            #print(teamsQueue)
            item =teamsQueue[0].popleft() 
            print(item)
            if(len(teamsQueue[0])==0):
                teamsQueue.popleft()
                teamsQueueStatus[teamsAdded[item]] = -1
                for i in range(len(teamsQueueStatus)):
                    if(teamsQueueStatus[i]!=-1):
                       teamsQueueStatus[i] -=1 
            #print(f'Depois{teamsQueue}')
            
        

