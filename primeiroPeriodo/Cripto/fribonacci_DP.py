def fribonacci(n,memo={}):
    if n in memo:
        return memo[n]
    if(n<=1):
        return n
    memo[n] = fribonacci(n-2,memo) + fribonacci(n-1,memo)
    return memo[n]

print(fribonacci(50))