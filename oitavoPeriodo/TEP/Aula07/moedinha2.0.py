import copy

def toggle(board, i, j):
    board[i][j] = not board[i][j]
    if i > 0:
        board[i-1][j] = not board[i-1][j]  # Cima
    if i < 9:
        board[i+1][j] = not board[i+1][j]  # Baixo
    if j > 0:
        board[i][j-1] = not board[i][j-1]  # Esquerda
    if j < 9:
        board[i][j+1] = not board[i][j+1]  # Direita

def solve_from_second_row(board, moves):
    for i in range(1, 10): 
        for j in range(10):  
            if board[i-1][j]:  
                toggle(board, i, j)
                moves += 1
    return board, moves

def solve_lights(board):
    bestMoves = float('inf') 
    for fistRowMoves in range(1 << 10): 
        moves = 0
        tempBoard = copy.deepcopy(board)
        
        for j in range(10):
            #bit hack para resolver isso de forma sem tomar timeout
            if (fistRowMoves >> j) & 1:
                toggle(tempBoard, 0, j)
                moves += 1
        
        
        tempBoard, moves = solve_from_second_row(tempBoard, moves)
        
        if all(not cell for cell in tempBoard[-1]):
            bestMoves = min(bestMoves, moves) 
    
    return bestMoves if bestMoves != float('inf') and bestMoves<= 100 else -1  

# Leitura e processamento do input
while True:
    boardName = input()
    if boardName == 'end':
        break
    
    board = []
    for _ in range(10):
        line = input()
        board.append([True if c == 'O' else False for c in line]) 
    
    result = solve_lights(board)
    print(f'{boardName} {result}')