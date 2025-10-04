#!/bin/bash

if (( $# !=2 )); then
	echo "Нужно ввести два числа"
	echo "Пример: ./multiply.sh"
	exit 1;
fi
n1=$1
n2=$2
result=$(( n1 *n2 ))
echo "Ответ: $n1 * $n2 = $result"

