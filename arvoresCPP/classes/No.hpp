#include <stdio.h>
#define Item char
class No{
    public:
		Item valor;
		No *left;
		No *right;
		No(Item n){
			valor=n;
			left=NULL;
			right=NULL;
		}
};

/*
    se atual nao nula
        compare com o valor da atual

            se novo maior que atual

                se direita for nula
                    direita recebe novo
                    quebre o loop
                senao
                    atual recebe direita
                    proxima volta
                    
            senao
                se esquerda for nula
                    esquerda recebe novo
                    quebre o loop
                senao
                    atual recebe esquerda
                    proxima volta

*/