def mdc(a,b):
    c = a%b
    return b if not c else mdc(b,c)

resultado = mdc(87,36)
print(resultado)