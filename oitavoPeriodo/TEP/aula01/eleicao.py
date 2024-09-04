from collections import Counter

def resolve():
    votes = [int(x) for x in input().split(" ")]
    votesNumber = Counter(votes)
    bigger = max(votes)
    ans = []
    if(votesNumber[bigger]>1):
        for i in range(3):
            ans.append(str(bigger- votes[i]+1))
    else:
        for i in range(3):
            ans.append(str(bigger- votes[i]+1) if votes[i] != bigger else str(0))
    return " ".join(ans)
teste = int(input())

for i in range(teste):
    print(resolve())



    

