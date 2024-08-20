
def resolve():
    cases = []
    possibleLight = set(["A","B","C","D","E","F","G","H","I","J","K","L"])
    possibleHeavy = set(["A","B","C","D","E","F","G","H","I","J","K","L"])
    isLight = False
    for _ in range(3):
        cases.append(input().split(" "))
    for case in cases:
        if(case[2] == "even"):
            possibleLight -=  set(case[0] + case[1])
            possibleHeavy -=  set(case[0] + case[1])
        if(case[2]=="up"):
            possibleLight =  possibleLight.intersection(set(case[1]))
            possibleHeavy = possibleHeavy.intersection(set(case[0]))
        if(case[2] =="down"):
            possibleLight =  possibleLight.intersection(set(case[0]))
            possibleHeavy = possibleHeavy.intersection(set(case[1]))
    if(len(possibleLight) > 0):
        print(f"{possibleLight.pop()} is the counterfeit coin and it is light.")
    else:
        print(f"{possibleHeavy.pop()} is the counterfeit coin and it is heavy.")


testes = int(input())

for _ in range(testes):
    resolve()