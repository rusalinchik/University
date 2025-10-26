#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Ошибка: требуется один аргумент N."
    exit 1
fi

N="$1"

if [ "$N" -le 0 ]; then
    echo "Ошибка: N должно быть положительным числом"
    exit 1
fi

OUTPUT="random_numbers.txt"
> "$OUTPUT"

for ((i=1; i<=N; i++)); do
    echo "$RANDOM" >> "$OUTPUT"
done

echo "Сгенерировано $N чисел в $OUTPUT."

SERVER="localhost"
PORT="4444"
echo "Отправка файла на сервер $SERVER:$PORT..."

# Проверка доступности netcat
if ! command -v nc &> /dev/null; then
    echo "Ошибка: netcat не установлен"
    exit 1
fi

nc "$SERVER" "$PORT" < "$OUTPUT"
if [ $? -eq 0 ]; then
    echo "Успех: файл отправлен."
else
    echo "Неудача: не удалось отправить файл."
    exit 2
fi

