def Knuth(dividendo,divisor,x1=1,x2=0,y1=0,y2=1):# REFAZER
    quociente,resto = divmod(dividendo, divisor)
    print(resto)
    if(resto!=0):
        Knuth(divisor, resto,x2,(x1-x2*quociente), y2,(y1-y2*quociente ))

    result = (divisor, x2,y2)
    return result
        

senha = Knuth(36,26)

print(senha)