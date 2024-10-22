def maximunGain(data):
    currentSum = 0
    maximumSum = float('-inf')
    j=0
    i=0
    while i < len(data):
        currentSum+= data[i]
        i +=1
        maximumSum = max(maximumSum,currentSum)
        while  j < i and currentSum<0:
            currentSum-= data[j]
            j+=1
    return maximumSum


while True:
    n = input()
    while n == '':
        n = input()
    n = int(n)
    if(n==0):
        break

    data = []
    while len(data) < n:
        currentSum = 0
        maximumSum = 0
        data.extend(map(int, input().split()))
    res = maximunGain(data)
    print(f'The maximum winning streak is {res}.' if res>0 else 'Losing streak.' )