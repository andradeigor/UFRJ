totalBooks = 0

def runCommands(bookShelf, comands,q, deep=0):
    global totalBooks
    totalBooks = 0
    bookShelf = []
    for _ in range(n):
        bookShelf.append([False] * m)
    for i in range(q):
        op = comands[i].split(" ")
        if(op[0]=='1'):
            bookShelf = one(bookShelf, int(op[1])-1,int(op[2])-1, fake=True)
        elif(op[0]=='2'):
            bookShelf = two(bookShelf, int(op[1])-1,int(op[2])-1, fake=True)
        elif(op[0]=='3'):
            bookShelf = three(bookShelf, int(op[1])-1, fake=True)
        elif(op[0]=='4'):
            bookShelf = runCommands(bookShelf, commands, int(op[1]), deep+1)
    if(deep < 1):
        print(totalBooks)
    return bookShelf




def one(bookShelf,i,j,fake=False):
    global totalBooks
    if(not bookShelf[i][j]):
        totalBooks+=1
    bookShelf[i][j] = True
    if(not fake):
        print(totalBooks)
    return bookShelf

def two(bookShelf,i,j,fake=False):
    global totalBooks
    if(bookShelf[i][j]):
        totalBooks-=1
    bookShelf[i][j] = False
    if(not fake):
        print(totalBooks)
    return bookShelf

def three(bookShelf,i,fake=False):
    global totalBooks
    for j in range(len(bookShelf[i])):
        if(bookShelf[i][j]):
            totalBooks-=1
        else:
            totalBooks+=1
        bookShelf[i][j] = not bookShelf[i][j]
    if(not fake):
        print(totalBooks)
    return bookShelf

import sys
try:
    
        n,m,q = [int(x) for x in input().split(" ")]
        bookShelf = []
        input = sys.stdin.read
        commands = input().split("\n")
        for _ in range(n):
            bookShelf.append([False] * m)
        for i in range(q):
            op = commands[i].split(" ")
            commands.append(op)
            if(op[0]=='1'):
                bookShelf = one(bookShelf, int(op[1])-1,int(op[2])-1)
            elif(op[0]=='2'):
                bookShelf = two(bookShelf, int(op[1])-1,int(op[2])-1)
            elif(op[0]=='3'):
                bookShelf = three(bookShelf, int(op[1])-1)
            elif(op[0]=='4'):
                bookShelf = runCommands(bookShelf, commands, int(op[1]))
        


except EOFError:
    pass