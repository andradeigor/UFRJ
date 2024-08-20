
def resolve():
    texto = input()
    anagrams = {}
    while( texto != "#"):

        words = texto.split()
        for word in words:
            lowerWord = word.lower()
            listaWord = list(lowerWord)
            listaWord.sort()
            sortedwordstring = "".join(listaWord)
            if(sortedwordstring not in anagrams):
                anagrams[sortedwordstring] = []
            anagrams[sortedwordstring].append(word)
        texto = input()
    res = []
    for value in anagrams.values():
        if(len(value) ==1):
           res.append( value[0])
    res.sort()
    for i in res:
        print(i)

resolve()
