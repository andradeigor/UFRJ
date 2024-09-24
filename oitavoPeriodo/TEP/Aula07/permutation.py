import sys

input = sys.stdin.read
data = input().split()
data = data[1::]

def swapElements(listLetters,i,j):
    listLetters[i],listLetters[j] = listLetters[j], listLetters[i]
    return listLetters

result = []
currentResults = set()
def deepPermutation(listLetters,inicio):
    if(inicio == len(listLetters)-1):
        word = "".join(listLetters[::])
        if(word not in currentResults):
            result.append(word)
        currentResults.add(word)
        return
    if(listLetters[inicio::] == list(listLetters[inicio] * (len(listLetters)-inicio))):
        word = "".join(listLetters[::])
        if(word not in currentResults):
            result.append(word)
        currentResults.add(word)
        return
    
    for i in range(inicio,len(listLetters)):
        swapElements(listLetters, i, inicio)
        deepPermutation(listLetters, inicio+1)
        swapElements(listLetters, i, inicio)

def permutation(word):
    baseWord = word
    baseList = list(baseWord)
    baseList.sort()
    baseWord ="".join(baseList) 
    deepPermutation(baseList, 0)



for word in data:
    permutation(word)
    result.sort()
    for i in result:
        print(i)
    print()
    result = []
    currentResults = set()