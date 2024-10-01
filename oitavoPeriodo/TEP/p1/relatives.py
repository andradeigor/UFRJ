from statistics import median
testCase = int(input())
for _ in range(testCase):
    inputList = input().split()
    relatives = int(inputList[0])
    streatNumbers = [int(x) for x in inputList[1::]]
    otimalDistance = int(median(streatNumbers))
    distance = 0
    for i in streatNumbers:
        distance+= abs(otimalDistance - i)
    print(distance)