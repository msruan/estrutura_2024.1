#ifndef UTILS_H  
#define UTILS_H

#include <stdlib.h>
int randint(int min, int max) {
    // Inicializa a semente para a função rand()
    
    // Gera um número aleatório no intervalo [min, max]
    int random_number = min + rand() % (max - min + 1);
    return random_number;
}

int max(int a, int b){

	if(a > b)
		return a;
	else
		return b;
}

#endif