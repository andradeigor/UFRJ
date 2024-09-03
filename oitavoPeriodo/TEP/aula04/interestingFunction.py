from math import log10,floor
testes = int(input())
for _ in range(testes):
    nAndK = input()
    l,r = [int(x) for x in nAndK.split(" ")]
    sum = r-l
    if(r -l < 10):
        print(r-l)
        continue
    counts = floor(log10(r-l))
    sum += counts*2
    print(sum)