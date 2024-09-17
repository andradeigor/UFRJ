
def gcd(a,b):
    return b if a%b == 0 else gcd(b, a%b)


n = int(input())
for _ in range(n):
    ns = [int(x) for x in ' '.join(input().split()).split(" ")]
    ns.sort(reverse=True)
    maxGcd = gcd(ns[0], ns[1])
    for i in range(len(ns)):
        if(ns[i] < maxGcd):
                continue
        for j in range(i+1, len(ns)):
            if(ns[j] < maxGcd):
                continue
            maxGcd = max(maxGcd,gcd(ns[i],ns[j]))
    print(maxGcd)