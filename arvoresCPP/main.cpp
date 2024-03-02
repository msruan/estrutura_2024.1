#include "classes/No.hpp"
#include "classes/Arvore.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>
#include "utils.h"
using namespace std;

int main(){
	Arvore *arvore= new Arvore();
	// while(true){
	// 	if(arvore->isEmpty())
	// 		string menu = gerar_menu("Arvores de Busca","Criar arvore, Sair");

	// }
	arvore->criaNo('A');
	// arvore->criaNo('D');
	// arvore->criaNo('Z');
	// arvore->criaNo('B');
	// arvore->preordem(arvore->raiz);
	arvore->limpar(arvore->raiz);
}