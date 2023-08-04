#!/bin/sh
if [ $# -eq 0 ]
then
  echo "Parâmetros precisam ser passados"
  echo "use -s para pesquisar por uma palavra no dicionario"
  echo "use -i para inserir uma palavra no dicionario"
  echo "use -r para remover uma palavra do dicionario"
  exit 1
fi
i=$1
palavras=${@:2}

adicionar(){
  chave=${palavras[@]}
  valores=("${palavras[@]:1}")
  echo $chave
  echo "Array recortado: ${valores[@]}"
  
  for p in $palavras
  do
    $(echo "$p">>./dicionario.txt)
  done

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
