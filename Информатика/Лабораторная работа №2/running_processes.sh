#!/bin/bash

echo "Список запущенных процессов:"
ps -e
echo
count=$(ps -e | wc -l)
count=$((count - 1))
echo "Количество запущенных процессов: $count"
