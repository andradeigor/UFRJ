def isDivisible(numberInText):
    sum = 0
    hasZero = False
    Pair = 0
    for i in numberInText:
        digit =int(i) 
        sum+= digit
        if(digit%2 ==0):
            Pair +=1
        if(not hasZero and digit==0):
            hasZero=True
    return sum%3 ==0 and hasZero and Pair>1

n = int(input())

for _ in range(n):
    number = input()
    Disible = isDivisible(number)
    print("red" if Disible else "cyan") 