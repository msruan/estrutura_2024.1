#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include "No.hpp"
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
#ifndef NO_HPP
#define NO_HPP

#include <stdio.h>
#define if
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
#endif

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

			// if(ehNulo(novo))
			// 	exit(1);//vsf se tu tentar passar algo nulo
			
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

		int calcularAlturaArvore(No *no){

			if(ehNulo(no))
				return 0;

			int quant = 1;
			int left = calcularQtdNos(no->left);
			int right = calcularQtdNos(no->right);

			if(left>right)//quero q o pai saiba qual ramo dele tem mais filhos
				quant += left;
			else 
				quant += right;

			return quant;
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
	    
	    void posordem(No *no){ //Esquerda -> Direita -> Rai
			
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