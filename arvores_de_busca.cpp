#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

// Definindo o tipo Item e a classe No antes de sua utilização
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

// Removendo definição desnecessária de 'if'
// #define if

class Arvore{
	public:
		No *raiz;
		int quantNos;
		int altura;

		Arvore(){
			raiz=NULL;
			quantNos=0;
			altura=0;
		}

		static int ehNulo(No* no){
			return no == NULL;
		}
		
		int isEmpty(){
	   		return (raiz==NULL);
		}
		
		void criaNo(Item item){

			No *novo= new No(item);
			inserirSemRecursao(novo);
		} 
		
		void inserirSemRecursao(No *novo){
			
			if(isEmpty())
				raiz = novo;

			else {
				No* atual = raiz;
				while(true){
					if(novo->valor>atual->valor){
						if(ehNulo(atual->right)){
							atual->right = novo;
							break;
						}
						else {
							atual = atual->right;
							continue;
						}
					}
					else {
						if(atual->left==NULL){
							atual->left = novo;
							break;
						}
						else {
							atual = atual->left;
							continue;
						}
					}
				}
			}
			altura++;
			quantNos++;
		}
		
		void inserirComRecursao(No* atual, No *novo){
			
			if(ehNulo(atual) or atual->valor == novo->valor){
				return;
			}

			else if(novo->valor > atual->valor){//right

				if(ehNulo(atual->right)){
					atual->right = novo;
				}
				else {
					inserirComRecursao(atual->right, novo);
				}

			}else {
				if(ehNulo(atual->left)){
					atual->left = novo;
				}
				else {
					inserirComRecursao(atual->left, novo);
				}
			}
		}
		
		int calcularQtdNos(No *no){

			if(ehNulo(no))
				return 0;

			int quant = 1;
			quant += calcularQtdNos(no->left);
			quant += calcularQtdNos(no->right);

			return quant;
		}

		int max(int a, int b){
			if(a > b)
				return a;
			else
				return b;
		}

		int calcularAlturaArvore(No *no){

			if(ehNulo(no))
				return 0;

			int left = calcularAlturaArvore(no->left); // Corrigindo chamada recursiva
			int right = calcularAlturaArvore(no->right); // Corrigindo chamada recursiva

			return 1 + max(left, right);
		}
		
		// int arvcompleta(){
			
		// }
		
		// int arvcheia(){
			
			
		// }
		// void reduce(){

		// }

		void preordem(No *no){// Raiz -> Esquerda -> Direita
			
			if(ehNulo(no)){
				return;
			}

			cout << no->valor;
			
			cout << " < ";
			preordem(no->left);
			cout << " > ";

			cout << " < ";
			preordem(no->right);
			cout << " >";
	    }
	    
	    void posordem(No *no){ //Esquerda -> Direita -> Raiz
			
			if(ehNulo(no)){
				cout << "NULL";
				return;
			}
			posordem(no->left);
			posordem(no->right);
			cout << no->valor;
		}
		
		void inordem(No *no){// Esquerda -> Raiz -> Direita
			
			if(ehNulo(no)){
				cout << "NULL";
				return;
			}
			inordem(no->left);
			cout << no->valor;
			inordem(no->right);
	    }

		void limpar(No* no){

			if(ehNulo(no))
				return;
			
			limpar(no->left);
			limpar(no->right);
			delete(no);
		}
};

int main(){
	Arvore *arvore= new Arvore();
	arvore->criaNo('G');
	arvore->criaNo('C');
	arvore->criaNo('A');
	arvore->criaNo('D');
	cout << "A altura da árvore é: " << arvore->calcularAlturaArvore(arvore->raiz);
	arvore->preordem(arvore->raiz);
	arvore->limpar(arvore->raiz);
}
