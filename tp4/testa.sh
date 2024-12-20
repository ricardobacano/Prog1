#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "numero incorreto de parâmetros"
    echo "Uso: $0 <opcao>"
    echo "   -- opcao = 1 : testa o programa sem se preocupar com vazamentos de memoria"
    echo "   -- opcao = 2 : teste completo do programa"
    exit 1;
fi

TIPO_TESTE=$1

if [ ${TIPO_TESTE} == 1 ]; then
    COMANDO="./tp4"
elif [ ${TIPO_TESTE} == 2 ]; then
    COMANDO="valgrind --leak-check=full ./tp4"
else
    echo "opcao incorreta"
    echo "   -- opcao = 1 : testa o programa sem se preocupar com vazamentos de memoria"
    echo "   -- opcao = 2 : teste completo do programa"
    exit 1;
fi

eval "${COMANDO}" | diff - saida_esperada.txt
