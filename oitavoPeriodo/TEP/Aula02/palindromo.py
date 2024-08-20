reversed = {
"A":"A",
"E": "3",
"H": "H",
"I": "I",
"J": "L",
"L": "J",
"M": "M",
"O": "O",
"S": "2",
"T": "T",
"U": "U",
"V": "V",
"W": "W",
"X": "X",
"Y": "Y",
"Z": "5",
"1": "1",
"2": "S",
"3": "E",
"5": "Z",
"8": "8"
}

def resolve():
    while(True):
        try:
            text = input()
            isPalin = True
            isMirror = True
            
            for i in range(len(text)//2):
                if(isPalin):
                    isPalin = text[i] == text[len(text)-1-i]
            for i in range(len(text)):
                if(isMirror):
                    isMirror = False if text[len(text)-1-i] not in reversed else text[i] == reversed[text[len(text)-1-i]]
           
            if(isPalin and isMirror):
                print(f'{text} -- is a mirrored palindrome.')
                print()
            elif(not isPalin and not isMirror):
                print(f'{text} -- is not a palindrome.')
                print()
            elif(not isPalin and isMirror):
                print(f'{text} -- is a mirrored string.')
                print()
            else:
                print(f"{text} -- is a regular palindrome.")
                print()
        except EOFError:
            break
        
        

resolve()
