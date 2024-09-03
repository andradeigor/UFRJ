testes = int(input())

for _ in range(testes):
    numbersOfNumbers = int(input())
    numbers = input()
    numbers = [int(x) for x in numbers.split(" ")]
    numbers.sort(reverse=True)
    hasOne = False
    hasZero = False
    hasDiferenceOfOne = False
    
    for i in range(0,len(numbers)-1):
        if(numbers[i] == 1 or  numbers[i+1] == 1):
            hasOne = True
        if(numbers[i] == 0 or  numbers[i+1] == 0):
            hasZero = True
        if(numbers[i] - numbers[i+1] == 1):
            hasDiferenceOfOne = True
    
    if(hasOne and hasZero):
        print("NO")
        continue
    if(hasOne and hasDiferenceOfOne):
        print("NO")
        continue
    print("YES")