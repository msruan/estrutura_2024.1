#include "../include/Arvore.hpp"
using namespace std;

int main(){
    srand(time(NULL));
	Arvore *arvore= new Arvore();
	arvore->criaNo('G');
	arvore->criaNo('C');

	
// 	arvore->criaNo('V');
// 	arvore->criaNo('Z');

	arvore->criaNo('H');
// 	arvore->criaNo('B');
// 	arvore->criaNo('C');
// 	arvore->criaNo('A');
// 	arvore->criaNo('E');
// 	arvore->criaNo('F');


	cout << "A altura da árvore é: ";// << arvore->calcularAlturaArvore(arvore->raiz) << "\n";
	cout << "A quantidade de nós é: " << arvore->calcularQtdNos(arvore->raiz) << "\n";
	cout << "Eh cheia?: " << arvore->arvcheia() << "\n";
// 	cout << "Eh completa? " << arvore->arvcompleta() << "\n";
	cout << "Eh completa? " << arvore->ehCompletaComRecursao(arvore->raiz) << "\n";
    No *busca = arvore->calcularMinimo(arvore->raiz);
    if(busca == NULL)
        cout << "Nao achei :((()))";
    else 
        cout << "achei é o "<<busca->valor;
	arvore->preordem(arvore->raiz);
	arvore->limpar(arvore->raiz);
}

