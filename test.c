#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libreria.h"


int main(int argc, char *argv[]) {
    	int N = 10;  
    
    	//menos argumentos de los necesarios
	if (argc < 2) {
        	fprintf(stderr, "Uso: %s -<función> [número de líneas]\n", argv[0]);
        	fprintf(stderr,"-head -tail -longlines\n");
        	return 1;
    	}

	//comprueba que N sea positivo
    	if (argc == 3) {
        	N = atoi(argv[2]);
        	if (N <= 0) {
        	    fprintf(stderr, "El número de líneas debe ser un entero positivo.\n");
        	    return 1;
        	}
    	}
    	//demasiados argumentos
    	if (argc > 3){
    		fprintf(stderr, "Uso: %s -<función> [número de líneas]\n", argv[0]);
        	fprintf(stderr,"-head -tail -longlines\n");
        	return 1;
    	}
    
	//comprueba que la funcion se nombre correctamente
    	if (strcmp(argv[1], "-head") == 0) {
        	head(N);
    	} else if (strcmp(argv[1], "-tail") == 0) {
        	tail(N);
    	} else if (strcmp(argv[1], "-longlines") == 0) {
        	longlines(N);
    	} else {
        	fprintf(stderr, "Función desconocida: %s\n", argv[1]);
        	fprintf(stderr,"-head -tail -longlines\n");
        	return 1;
    	}

    	return 0;
}

