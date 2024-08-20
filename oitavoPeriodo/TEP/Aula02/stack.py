closes = {
    '(': ')',
    '[': ']',
}

def resolve():
    stack = []
    opens = closes.keys()
    text = input()
    for symbol in text:
        if symbol in opens:
            stack.append(symbol)
        else:
            if(len(stack) > 0 and closes[stack[-1]] == symbol):
                stack.pop()
            else:
                print("No")
                return
    if(len(stack) ==0):
        print("Yes")
        return
    print("No")

    
testes = int(input())
for i in range(testes):
    resolve()