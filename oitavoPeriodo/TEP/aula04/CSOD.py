lastSum = 0
def divisors(n):
    return [i for i in range(2, (n//2)+1) if n%i==0]

while True:
    text = input()
    if(text =="0"):
        break
    goal = int(text)
    if(goal<=2):
        print(0)
        continue
    sume = 0
    for i in range(3,goal+1):
        a = divisors(i)
        sume += sum(a)
    lastSum = sume
    print(sume)
    
