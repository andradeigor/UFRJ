testes = int(input())
for i in range(testes):
    palavra = input()

    seen = {}
    letrasNaStringPar = 0

    for i,letter in enumerate(palavra):
        if(letter not in seen):
            seen[letter] = i
        else:
            prev = seen[letter]
            letrasNaStringPar += 2
            seen = {}
    print(len(palavra) - letrasNaStringPar)
