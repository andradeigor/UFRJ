while True:
    n = int(input())
    if(n==0):
        break
    ages = [0] * 101
    inputAges = [int(x) for x in input().split(" ")]
    for age in inputAges:
        ages[age] +=1
    res = ""
    for i in range(len(ages)):
        for j in range(ages[i]):
            res += f"{i} "
    print(res.strip())
