def gcd(a,b):
    while ((a % b) > 0):
        R = a % b
        a = b
        b = R
    return b

def lcm(a,b):
  return (a * b) // gcd(a,b)

nAndK = input()
n,K = nAndK.split(" ")
n = int(n)
K = int(K)
possible = False
numbers = [int(x) for x in input().split(" ")]
currentLCM = numbers[0]
for number in numbers:
    currentLCM = gcd(K,lcm(currentLCM, number))
    if(pow(currentLCM,1,K)==0):
        possible = True
        break


print("Yes" if possible else "No")
