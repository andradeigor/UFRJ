

def pieceToUse(pieces, toFill,indexToFill, pieceIndex):
    if(pieces[pieceIndex][0] == toFill[indexToFill]):
        return pieces[pieceIndex], "left"
    if(pieces[pieceIndex][2] == toFill[indexToFill]):
        return pieces[pieceIndex], "right"
    return None
def game(pieces, left, right, gap):
    if(gap ==1):
        for piece in pieces:
            if(left[2] == piece[0] and right[0] == piece[2] or left[2] == piece[2] and right[0] == piece[0]):
                return "YES"
        return "NO"
    
    for i in range(len(pieces)):
        piece = pieceToUse(pieces, left, 2, i)
        if not piece:
            continue
        newPieces = pieces[::]
        newPieces.remove(piece[0])
        if(piece[1] == "left"):
            res = game(newPieces, piece[0], right,gap-1)
        else:
            res = game(newPieces, piece[0][1] + ' ' + piece[0][0], right,gap-1)
        if(res == "YES"):
            return "YES"
    return "NO"

while True:
    n = int(input())
    if(n==0):
        break
    m = int(input())
    left = input()
    right = input()
    pieces = []
    usedPieces = set()
    for i in range(m):
        piece = input()
        pieces.append(piece)
    print(game(pieces, left, right,n))

