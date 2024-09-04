import heapq

def resolve():
    nCandies = int(input())
    arrCadies = [int(x) for x in input().split(" ")]

    arrCadies.sort(reverse=True)
    if(nCandies ==1):
        print("YES" if arrCadies[0]==1 else "NO")
        return
    print("NO" if arrCadies[0] - arrCadies[1]>1 else "YES")
teste = int(input())

for i in range(teste):
    resolve()
