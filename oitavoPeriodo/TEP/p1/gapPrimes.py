def crivo(N):
    numbers = []
    A = [True] * (N+1)
    A[0] = A[1] = False
    for value, prime in enumerate(A):
        if prime:
            numbers.append(value)
            for i in range(value**2, N+1, value):
                A[i] = False
    return numbers
def binary_search(arr, x):
    low = 0
    high = len(arr) - 1
    mid = 0
 
    while low <= high:
 
        mid = (high + low) // 2
 
       
        if arr[mid] < x:
            low = mid + 1
 
        elif arr[mid] > x:
            high = mid - 1
 
        else:
            return mid
 
    return mid

primesArr = crivo(1299710)
primesSet = set(primesArr)
while True:
    target = int(input())
    if(target ==0):
        break
    if(target in primesSet):
        print(0)
        continue
    pointer = binary_search(primesArr, target)
    gap = 0
    if(primesArr[pointer]> target):
        #print(f'{target}: {primesArr[pointer]} {primesArr[pointer-1]}')
        gap = primesArr[pointer] - primesArr[pointer-1]
    else:
        #print(f'{target}: {primesArr[pointer+1]} {primesArr[pointer]}')
        gap = primesArr[pointer+1] - primesArr[pointer]
    print(gap)