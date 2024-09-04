def isSlump(word,pointer=0):
    if(word[pointer] != "D" and word[pointer] != "E"):
        return False,pointer+1
    if(word[pointer+1]!="F"):
        return False,pointer+2
    i = pointer+1
    while(i<len(word)):
        if(word[i]!="F"):
            break
        i+=1
    if(word[i]=="G"):
        return True,i+1
    return isSlump(word, i)

def isSlimp(word,pointer=0):
    if(word[pointer] != "A"):
        return False,pointer+1
    if(word[pointer+1]=="H"):
        return True,pointer+2
    
    condition, pointer = isSlimp(word, pointer+2) if word[pointer+1]=="B" else isSlump(word, pointer+1)
    return (condition, pointer+1) if condition and word[pointer]=="C" else (False, pointer+1)
    


nWords = int(input())
print("SLURPYS OUTPUT")
for i in range(nWords):
    word = input()
    condition1, pointer = isSlimp(word)
    condition2, pointer = isSlump(word, pointer)
    print("YES" if condition1 and condition2 and pointer == len(word) else "NO")
print("END OF OUTPUT")