def divisoresPositivos(numero):
    divisores =0
    for num in range(1,numero+1):#começa pelo 1 e vai até numero, +1 por conta do off by one
        if(numero%num==0):
            divisores+=1
    
    return divisores


print(divisoresPositivos(4))