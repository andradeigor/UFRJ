def comulativeMedian(prev, n):
    prev.append(n)
    prev.sort()
    p = len(prev)
    if(p%2 !=0):
        return prev, prev[p//2]
    a1 = prev[p//2]
    return prev, (prev[p//2-1] + prev[p//2])//2 


try:
    arr = []
    while True:
        n = int(input())
        arr, median =comulativeMedian(arr, n) 
        print(median)

except EOFError:
    pass