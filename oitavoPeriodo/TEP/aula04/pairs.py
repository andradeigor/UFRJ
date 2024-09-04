testes = int(input())

for _ in range(testes):
    nArray = int(input())
    position = {}
    arr = []
    for i,n in enumerate(input().split(" ")):
        n = int(n)
        position[n] = i+1
        arr.append(n)
    arr.sort()
    res=0
    for i in range(len(arr)):
        ai = arr[i]
        for j in range(i+1,len(arr)):
            aj = arr[j]
            if(ai*aj == position[ai]+position[aj]):
                res+=1
            if(ai*aj - position[ai] > len(arr)):
                break
    print(res)