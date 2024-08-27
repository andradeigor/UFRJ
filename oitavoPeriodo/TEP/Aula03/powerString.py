from math import sqrt
def divisors(n):
    divs = [1]
    for i in range(2,int(sqrt(n))+1):
        if n%i == 0:
            divs.extend([i,n/i])
    divs.extend([n])
    return list(set(divs))
while True:
    text = input()
    if(text == "."):
        break
    divisores = divisors(len(text))
    divisores.sort()
    skipeds = 0
    for divisor in divisores:
        divisor = int(divisor)
        skip = False
        substring = text[0:divisor]
        for i in range(0,len(text), divisor):
            if(substring != text[i:i+divisor]):
                #print(f'{substring} e {text[i:i+divisor]}')
                skip = True
                break
        if(skip):
            continue
        print(len(text)//divisor)
        break
