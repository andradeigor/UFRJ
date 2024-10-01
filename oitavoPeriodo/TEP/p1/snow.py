
testCase = int(input())
for _ in range(testCase):
    n = int(input())
    snowFlakes = {}
    snowFlakesArray = []
    maxLenght = 0
    for i in range(n):
        snowFlakesArray.append(int(input()))
    
    maxLenght = 0
    snowFlakes = set()
    for i in range(len(snowFlakesArray)):
        value = snowFlakesArray[i]
        if(value in snowFlakes):
            while(value != snowFlakesArray[i-len(snowFlakes)]):
                snowFlakes.remove(snowFlakesArray[i-len(snowFlakes)])
        else:
            snowFlakes.add(value)
        maxLenght = max(maxLenght, len(snowFlakes))
    if(n ==1):
        maxLenght = 1
    maxLenght = max(maxLenght, len(snowFlakes))
    print(maxLenght)


        

