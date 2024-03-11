#ifndef COLORS_H  
#define COLORS_H

#define RESET "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

#include "utils.h"

const char* obterCor(int numero) {
	
    switch(numero) {
        case 1:
            return BLACK;
        case 2:
            return RED;
        case 3:
            return GREEN;
        case 4:
            return YELLOW;
        case 5:
            return BLUE;
        case 6:
            return PURPLE;
        case 7:
            return CYAN;
        case 8:
        default:
            return WHITE; // Retorna uma string vazia se o número não corresponder a nenhuma cor
    }
}

const char* obterCorAleatoria() {
    return obterCor(randint(1,8));
}

#endif