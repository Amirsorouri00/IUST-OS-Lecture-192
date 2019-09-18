#!/bin/bash

echo "Before appending the file"
cat book.txt

echo "\n6- Learning Laravel 5\n">> book.txt
echo "After appending the file"
cat book.txt