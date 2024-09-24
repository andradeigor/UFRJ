

try:
    n = int(input())

    for c in range(n):
        lines = []
        lines.append(input())
        lines.append(input())
        lines.append(input())
        counter = {'X':0,'O':0,'.':0}
        XWin = False
        OWin = False
        #if(c==107 or c==108):
        #    print(c)
        #    for line in lines:
        #        print(line)
        #    print("=" * 50)
        for line in lines:
            for i in line:
                counter[i]+=1
            if(line[0] == 'O' and line[1] == 'O' and line[2] == 'O'):
                OWin = True
            if(line[0] == 'X' and line[1] == 'X' and line[2] == 'X'):
                XWin = True
        if(lines[0][0] == 'O' and lines[1][1] == 'O' and lines[2][2] == 'O'):
                OWin = True
        if(lines[0][0] == 'X' and lines[1][1] == 'X' and lines[2][2] == 'X'):
                XWin = True
        if(lines[2][0] == 'O' and lines[1][1] == 'O' and lines[0][2] == 'O'):
                OWin = True
        if(lines[2][0] == 'X' and lines[1][1] == 'X' and lines[0][2] == 'X'):
                XWin = True
        
        if(lines[0][0] == 'X' and lines[1][0] == 'X' and lines[2][0] == 'X'):
                XWin = True
        
        if(lines[0][1] == 'X' and lines[1][1] == 'X' and lines[2][1] == 'X'):
                XWin = True
        
        if(lines[0][2] == 'X' and lines[1][2] == 'X' and lines[2][2] == 'X'):
                XWin = True

        if(lines[0][0] == 'O' and lines[1][0] == 'O' and lines[2][0] == 'O'):
                OWin = True
        
        if(lines[0][1] == 'O' and lines[1][1] == 'O' and lines[2][1] == 'O'):
                OWin = True
        
        if(lines[0][2] == 'O' and lines[1][2] == 'O' and lines[2][2] == 'O'):
                OWin = True

        if(counter['O']> counter['X'] or counter['X']>counter['O']+1 or (XWin and counter['O']== counter['X']) or (OWin and counter['X'] > counter['O']) ):
            print("no")
            input()
            continue
        if(XWin and OWin):
            print("no")
            input()
            continue
        
        print('yes')
        input()
except EOFError:
     pass