
import copy

def buttonPress(board, i,j):
    board[i][j] = not board[i][j]
    if(i+1 < len(board)):
        #print("abaixo")
        board[i+1][j] = not board[i+1][j]
    if(i-1 >=0):
        #print("acima")
        board[i-1][j] = not board[i-1][j]
    if(j+1 < len(board[0])):
        #print("direita")
        board[i][j+1] = not board[i][j+1]
    if(j-1 >=0):
        #print("esquerda")
        board[i][j-1] = not board[i][j-1]
    return board

def solver(board, moves):
    for i in range(1,len(board)):
        for j in range(len(board[0])):
            if(board[i-1][j]):
                moves+=1
                board = buttonPress(board, i,j)
    return board, moves
while True:
    boardName = input()
    if(boardName=='end'):
        break
    bestAttempt = 200
    board = []


    for i in range(10):
        line = input()
        lineBoard = [False if x=="#" else True for x in line]
        board.append(lineBoard)
 
    for i in range(1024):
        move = f'{i:010b}'
        boardRound = copy.deepcopy(board)
        attempt = True
        moves = 0
        for i in range(len(move)):
            if(move[i]=='1'):
                moves+=1
                boardRound = buttonPress(boardRound,0,i)

        boardRound,moves = solver(boardRound, moves)
        
        for lastRowItem in boardRound[-1]:
            if(lastRowItem):
                attempt = False
                break

        if(attempt):
            bestAttempt = min(bestAttempt,moves)
    
    print(f'{boardName.strip()} {bestAttempt}' if bestAttempt != float('inf') and moves < 100 else f'{boardName.strip()} -1')