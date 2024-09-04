from math import log10,floor,ceil
testes = int(input())
for _ in range(testes):
    nAndK = input()
    lText,rText = [x for x in nAndK.split(" ")]
    l,r = int(lText), int(rText)
    sum = r-l
    dif = r-l
    prev = 0
    baseSum = 1
    if(dif>=10):
        for i in range(0,dif+1,10):
            if(len(str(i))> len(str(prev)) and i>90):
                baseSum+=1
            sum+=baseSum
            prev = i


    #counts = ceil((r-l)/10)
    #sum +=counts

    

    print("-" * 50)
    #print(counts)
    print(f'{l} e {r} deram: {sum}')
    print(sum)