def validMoves(i,j, M,N):
    movesPossible = [(i+2,j+1),(i+2,j-1),(i+1,j+2),(i-1,j+2),(i+1,j-2),(i-1,j-2),(i-2,j-1),(i-2,j+1)]
    moves = []
    for move in movesPossible:
        if(move[0] >=M or move[0]<0):
            continue
        if(move[1] >= N or move[1] <0):
            continue
        moves.append(move)
    return moves


def resolve():
    while(True):
        entrada = input()
        if(entrada =="0 0"):
            break
            
        M,N = entrada.split(" ")
        M = int(M)
        N = int(N)
        K =0
        board = []
        for i in range(M):
            line = []
            for j in range(N):
                line.append("*")
            board.append(line)
        for j in range(N):
            for i in range(M):
                if(board[i][j] == "*"):
                    K+=1
                    moves = validMoves(i,j,M,N)
                    board[i][j] = "K"
                    for move in moves:
                        board[move[0]][move[1]] = "X"

        for line in board:
            print(line)
        print(f'{K} knights may be placed on a {M} row {N} column board.')
        print("-" * 50)

resolve()