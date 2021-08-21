def mdcReverso(k,a=0,b=3,c=0):
    a = b*2 + c
    return (a,b) if not k else mdcReverso(k-1,0,a,b)


print(mdcReverso(3))