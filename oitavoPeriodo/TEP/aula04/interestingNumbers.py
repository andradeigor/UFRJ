from math import floor
teste = int(input())
for i in range(teste):
    n = int(input())

    res = floor(n/10)
    if(str(n)[-1]=="9"):
        res +=1
    print(res)