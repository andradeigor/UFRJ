import re 

def matches(line, regexes):
    for regex in regexes:
        if(regex[0].match(line)):
            result = regex[0].match(line)
            corte = result.end()
            print(f'{regex[1]}: {result.group(0) if regex[1] != "SPACE" else "" }')
            return line[corte:]


#comentário 2


def main():
    nomeR = "[a-zA-Z_][a-zA-Z_0-9]*"
    spacesR = "\s+"
    numberR = "[0-9]+"
    operadorR = r"=|\.|\*|\(|\)|\[|\]|\+|\/|\-|\%|\:|,| >|\{|\}"
    comentarioR = r"#.* "
    stringR = r"r?\"(.*)\"|\'(.*)\'"    
    string = [re.compile(stringR),"STRING"]
    nome = [re.compile(nomeR),"NOME"]
    spaces = [re.compile(spacesR), "SPACE"]
    operador = [re.compile(operadorR), "OPERATOR"]
    number = [re.compile(numberR), "NUMBER"]
    comentario = [re.compile(comentarioR), "COMENTARIO"]
    regexes = [comentario,string, nome, spaces, operador,number ]
    with open('lexar.py') as f:
        lines = f.readlines()
    for line in lines:
        while(len(line)):
            line = matches(line, regexes)

if __name__ == "__main__":
    main()