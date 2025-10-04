#!/bin/bash

PORT=12345
echo "Сервер запущен."
while true
do
	tekst=$(nc -l -p $PORT)
	echo "Сообщение от клиента: $tekst"
	echo "Сообщение получено" | nc 127.0.0.1 $PORT
done
