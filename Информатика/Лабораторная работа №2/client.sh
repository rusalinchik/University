#!/bin/bash

PORT=1234
HOST=127.0.0.1
echo "Введите сообщение для отправки серверу:"
read TEKST
echo "$TEKST" | nc $HOST $PORT
