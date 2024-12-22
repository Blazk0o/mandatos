#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 1024

// Función head
int head(int N) {
	char buffer[LEN];
	int contador = 0;

	// mientras que las lineas no lleguen a N y no sean vacias se muestran por pantalla
    	while ((contador < N) && (fgets(buffer, LEN, stdin) != NULL)) {
        	printf("%s", buffer);
        	contador++;
	}
	return 0;
}

// Función tail
int tail(int N) {
	char **lines = malloc(N * sizeof(char*));  // reserva memoria para almacenar N punteros a las lineas
	int contador = 0;
	char buffer[LEN];
	int start;
	int numlins;


	// inicias las lineas a null para evitar acceso a memoria no iniciada
	for (int i = 0; i < N; i++) {
        	lines[i] = NULL;
	}

	// Lees por entrada estandar las lineas
	while (fgets(buffer, LEN, stdin) != NULL) {
        // Liberas la línea anterior si ya existe
        	if (lines[contador % N] != NULL) {
            		free(lines[contador % N]);
        	}
        	lines[contador % N] = strdup(buffer);  // metes la linea al array
        	contador++;
	}
	
	
	// imprimes las últimas N líneas o todas si hay menos de N
    	// si este contador vale mas que N o lo mismo hace la resta del contador de posiciones del array y lo resta a la cantidad que quiere mostrar y pone el inicio
    	if (contador >= N) {  
	 	start = contador % N;
	} else {
    		start = 0;
	}
    
    
    	//si este contador vale menos que N saca el numero de lineas
	if (contador < N) {  
		numlins = contador; 
	} 
	else{ 
		numlins = N; 
	}
	
	// imprime las ultimas N lineas
	for (int i = 0; i < numlins; i++) {
        	printf("%s", lines[(start + i) % N]);	//imprime las lineas desde start en adelante
	}

	// liberas las lineas 
	for (int i = 0; i < N; i++) {
        	if (lines[i] != NULL) {
            		free(lines[i]);
		}
	}
	free(lines);

	return 0;
}

// Función compare_lengths
int compare_lengths(const void *a, const void *b) {
  	  return strlen(*(const char**)b) - strlen(*(const char**)a);//ordena de mayor a menor longitud
}

// Función longlines
int longlines(int N) {
	char **lines = NULL;  // puntero a puntero para guardar las líneas
	int line_count = 0;
	char buffer[LEN];
	int limite;

	// Lees las lineas de entrada estandar
	while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        	lines = realloc(lines, (line_count + 1) * sizeof(char*));  // cambias el array
        	lines[line_count++] = strdup(buffer);  // copias la línea al array
	}

	// ordenas descendentemente las lineas
	qsort(lines, line_count, sizeof(char*), compare_lengths);

	// imprimes las n lineas habiendo menos que N
    	if (line_count < N) {
    		limite = line_count;
	} else {
    		limite = N;
	}

    
	for (int i = 0; i < limite; i++) {
		printf("%s", lines[i]);
        	free(lines[i]);  // liberas cada linea luego de usarla
	}

	// liberas todo
    	free(lines);

	return 0;
}



