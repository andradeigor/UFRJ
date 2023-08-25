def maiores(lista,n):
	#retorna todos os valores da lista original maiores que o N
	lista=lista+[n]
	list.sort(lista)
	indice=list.index(lista,n)
	sub=lista[indice+1:]
	repetições=list.count(sub,n)
	if repetições !=0:
		sub= sub[repetições:]
	return sub

frase='o menino camarao'
palavra='comeu'
pos=3
def alterafrase(frase,palavra,pos):
    """recebe uma frase,palavra e posicao. Caso a palavra ja exista na frase, ela é substituida por ela mesma"""
    """str,str,int->str"""
    palavras=str.split(frase)
    if palavra in palavras:
        i=list.index(palavras,palavra)
        palavras[i]=str.upper(palavras[i])
    else:
        list.insert(palavras,pos,palavra)
    return str.join(" ",palavras)
print(alterafrase(frase,palavra,pos))


print(maiores([5,3,2,1,2,6,6,5,8,9],6))