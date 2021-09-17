def gerarUnd(lista):
    listaUnd = []
    especiais = [' ', '-', chr(39), '.','?', '/', '!', '$', '%', '(', ')', '*', '@']
    for letra in lista:
        adicionei = False
        for especial in especiais:
            if(letra == especial):
                listaUnd.append(letra)
                adicionei = True
        if(not adicionei):
            listaUnd.append("_")
    return listaUnd

print(''.join(gerarUnd(list("aloaloaloa------)?"))))