


def one(bookShelf,i,j,fake=False):
    global totalBooks
    if(not bookShelf[i][j]):
        totalBooks+=1
    bookShelf[i][j] = True
    if(not fake):
        print(totalBooks)
    return bookShelf, totalBooks

def two(bookShelf,i,j,fake=False):
    global totalBooks
    if(bookShelf[i][j]):
        totalBooks-=1
    bookShelf[i][j] = False
    #if(not fake):
        #print(totalBooks)
    return bookShelf, totalBooks

def three(bookShelf,i,fake=False):
    global totalBooks
    for j in range(len(bookShelf[i])):
        if(bookShelf[i][j]):
            totalBooks-=1
        else:
            totalBooks+=1
        bookShelf[i][j] = not bookShelf[i][j]
    #if(not fake):
        #print(totalBooks)
    return bookShelf, totalBooks

prevBookShelf = {}
positionsToSave = []
import sys
try:
    global totalBooks
    totalBooks = 0
    n,m,q = [int(x) for x in input().split(" ")]
    bookShelf = []
    input = sys.stdin.read
    commands = input().split("\n")[:-1]
    for index,command in enumerate(commands):
        if(command[0]=='4'):
            positionsToSave.append(int(command[2]))
    for _ in range(n):
        bookShelf.append([False] * m)
    if(0 in positionsToSave):
        prevBookShelf[0] = (bookShelf.copy(), 0)
    for i in range(q-1):
        op = commands[i].split(" ")
        if(op[0]=='1'):
            bookShelf,totalBooks = one(bookShelf, int(op[1])-1,int(op[2])-1)
            print(totalBooks, i)
        elif(op[0]=='2'):
            bookShelf,totalBooks = two(bookShelf, int(op[1])-1,int(op[2])-1)
        elif(op[0]=='3'):
            bookShelf,totalBooks = three(bookShelf, int(op[1])-1)
        elif(op[0]=='4'):
            if(op[1]=='0'):
                bookShelf = prevBookShelf[int(op[1])][0]
                totalBooks = prevBookShelf[int(op[1])][1]
            else:
                bookShelf = prevBookShelf[int(op[1])][0]
                totalBooks = prevBookShelf[int(op[1])][1]
            #print(prevBookShelf[int(op[1])])
            print(totalBooks)
        if(i!= 0 and (i) in positionsToSave):
            print(i, totalBooks)
            prevBookShelf[i] = (bookShelf.copy(), totalBooks)



except EOFError:
    pass