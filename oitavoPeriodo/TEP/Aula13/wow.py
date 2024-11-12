text = input()

totalW = 0



for i in range(1,len(text)):
    if(text[i]=='v' and text[i-1]=='v'):
        totalW+=1
totalVs = 0
total = 0
for i in range(1,len(text)):
    if(text[i]=='v' and text[i-1]=='v'):
        totalVs+=1
    if(text[i] =='o'):
        #print(totalVs, totalW)
        total += totalVs * (totalW- totalVs)

print(total)