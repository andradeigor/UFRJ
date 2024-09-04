from collections import Counter

def resolve():
    result = Counter(list(input()))
    if(len(result.values()) == 1):
        return 0
    return min(result.values()) if(result['0']!= result['1'] ) else result['0']-1
    
teste = int(input())

for i in range(teste):
    print(resolve())