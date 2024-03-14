#include "../include/Arvore.hpp"
using namespace std;

int main(){
    srand(time(NULL));
	Arvore *arvore= new Arvore();
	
	// arvore->criarNos('G','C','V','Z','H','B');

	arvore->criarNos('C','A','E','F','D');

	

	// arvore->raiz = arvore->removerNo2(arvore->raiz,'C');

	// arvore->preordem(arvore->raiz);
	// arvore->removerNo(arvore->raiz,'G');
    // No *busca = arvore->buscaRecursiva(arvore->raiz,'G');
    // if(busca == NULL)
    //     cout << "Nao achei :/";
    // else 
    //     cout << "achei :P"<<busca->valor;

	arvore->posordem(arvore->raiz);
	arvore->posordemComPilha();
	cout << endl;
	arvore->extensao();
	// arvore->preordemComPilha();
	arvore->limpar(arvore->raiz);

	// cout << "A altura da árvore é: ";// << arvore->calcularAlturaArvore(arvore->raiz) << "\n";
	// cout << "A quantidade de nós é: " << arvore->calcularQtdNos(arvore->raiz) << "\n";
	// cout << "Eh cheia?: " << arvore->arvcheia() << "\n";
	// cout << "Eh completa? " << arvore->ehCompletaComRecursao(arvore->raiz) << "\n";
}

