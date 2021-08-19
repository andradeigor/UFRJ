def mdc(a,b):
    if(a==0):
        return b
    if(b==0):
        return a
    a,b = abs(a),abs(b)
    c = a%b
    if(c != 0):
        mdc(b,c)
    return c

print(mdc(36,26))
