#!/bin/bash
if [ $# -eq 0 ]
then
  echo "Parâmetros precisam ser passados"
  echo "use -s para pesquisar por uma palavra no dicionario"
  echo "use -i para inserir uma palavra no dicionario"
  echo "use -r para remover uma palavra do dicionario"
  exit 1
fi


i=$1
palavra=()
IFS=" "
p1=($*)
p2=(${p1[@]:1})

adicionar(){
  p3=(${p2[@]:1})
  echo "${p3[*]}"
  chave=${p2[0]}
  for p in "${p3[@]}"
  do
    $(echo "$chave:$p" >> dicionario.txt)
  done
}

procurar(){
  chave=${p2[0]}
  results=($(grep ^$chave dicionario.txt | cut -d":" -f2))
  echo "Aqui está a lista de valores que você possui para essa chave:"
  echo ""
  echo "${results[*]}"


}

case "$i" in
    -search|-s ) procurar 
    ;;
    -insert|-i) adicionar 
    ;;
    -remove|-r) echo 3
    ;;
    *) echo "nada foi feito" 
    ;;
  esac

