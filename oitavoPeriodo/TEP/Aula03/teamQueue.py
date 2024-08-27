from collections import deque
cenario = 0
while True:
    text = input()
    if(text == "0"):
        break
    cenario+=1
    Nteams = int(text)
    teams = []
    teamsAdded = []
    teamsQueue = []
    for i in range(Nteams):
        textTeam = input()
        textTeam = textTeam.split(" ")
        team = set()
        for i in range(int(textTeam[0])):
            team.add((textTeam[i+1]))
        teams.append(team)
    print(f"Scenario #{cenario}")
    while True:
        text = input()
        if(text == "STOP"):
            print("")
            break
        text = text.split(" ")
        if(text[0] == "ENQUEUE"):
            added = -1
            for index, teamAdded in enumerate(teamsAdded):
                if(text[1] in teamAdded):
                    added=index
                    break
            if(added == -1):
                for i in teams:
                    if(text[1] in i):
                        teamsAdded.append(i)
                teamsQueue.append(deque([text[1]]))
            else:
                teamsQueue[added].append(text[1])
        if(text[0] == "DEQUEUE"):
            for i in teamsQueue:
                if(len(i)==0):
                    continue
                print(i.popleft())
                break
        

