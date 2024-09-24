possibleMoves = []

board = [[]]

def buttonPress(board, i,j):
    board[i][j] = not board[i][j]
    if(i+1 < len(board)):
        board[i+1][j] = not board[i+1][j]
    if(i-1 < len(board) and i-1 >=0):
        board[i-1][j] = not board[i-1][j]
    if(j+1 < len(board[0])):
        board[i][j+1] = not board[i][j+1]
    if(j-1 < len(board[0]) and j-1 >=0):
        board[i][j-1] = not board[i][j-1]
    return board

def solver(board):
    for i in range(1,len(board)):
        for j in range(len(board[0])):
            if(board[i-1][j]):
                board = buttonPress(board, i,j)
    return board


for i in range(0,1024):
    move = f'{i:010b}'
    boardRound = board[:]
    for i in move:
        if(i=='1'):
            boardRound = buttonPress(boardRound,0,i)
    boardRound = solver(boardRound)
    
