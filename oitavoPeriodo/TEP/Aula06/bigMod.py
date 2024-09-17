def potential(B,P,M,BinP):
    numbers = []
    res=1
 
    revBin = BinP[::-1]

    if(revBin[0]=='1'):
        numbers.append(B)
    for i in revBin[1::]:
        B = (B*B)%M
        if(i=='1'):
            numbers.append(B)
    for i in numbers:
        res = (res *i)%M
    return res




try:
    while True:
        B = int(input())
        P = int(input())
        M = int(input())
        print(potential(B,P,M,format(P, "08b")))
        space = input()
except EOFError:
    pass