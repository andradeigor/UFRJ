def Bezout(dividendo,divisor,x1=1,x2=0,y1=0,y2=1):# REFAZER
    quociente,resto = divmod(dividendo, divisor)
    return (divisor, x2,y2) if not resto else Bezout(divisor, resto,x2,(x1-x2*quociente), y2,(y1-y2*quociente )) 
        

print(Bezout(561,1995))