while True:
    l = int(input())
    if(l==0):
        break
    n = int(input())
    placesToCut = [int (x) for x in  input().split()] 
    
    def bestCut(n,placesToCut,l):
        memo = [[-1] * (n + 1) for _ in range(n + 1)]
        placesToCut = [0] + placesToCut + [l]
        placesToCut.sort()
        def recursion(i,j):
            if(i>j):
                return 0
            if(memo[i][j]!= -1):
                return memo[i][j]
            minCuts = float("inf")
            for k in range(i,j+1):
                res = (placesToCut[j+1] - placesToCut[i-1]) + recursion(i,k-1) + recursion(k+1,j)
                minCuts = min(minCuts, res)
            memo[i][j] - minCuts
            return minCuts
        return recursion(1,n)
    print(f'The minimum cutting is {bestCut(n,placesToCut,l)}.')