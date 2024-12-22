#!/bin/bash

# Compilamos el archivo de la librería
gcc -Wall -Wextra -c libreria.c

# Creamos la librería estática
ar rcs libreria.a libreria.o

# Compilamos el programa de prueba, enlazando con la librería
gcc -Wall -Wextra test.c -o test -L. -l:libreria.a

# Limpiamos los archivos objeto intermedios
rm libreria.o

