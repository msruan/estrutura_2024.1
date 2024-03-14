#ifndef ARVORE_HPP
#define ARVORE_HPP

#include <stdio.h>
#include <stack>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include "colors.h"

#define Item char
using namespace std;

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

class Arvore{

	public:

		No *raiz;

		Arvore(){
			raiz=NULL;
		}

		void criarNo(Item item){

			No *novo= new No(item);
			inserirSemRecursao(novo);
		} 

		template<typename... Args>
		void criarNos(Args... args) {
			(this->criarNo(args), ...); // Fold expression para chamar o método com cada argumento
		}

		static int ehNulo(No* no){
			return no == NULL;
		}
		
		int isEmpty(){
	   		return (raiz==NULL);
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

		
        No* buscarSemRecursao(Item procurado){
            
            No* atual = raiz;
            while(atual !=NULL){

                if(atual->valor == procurado)
                    return atual;
                else if(procurado > atual->valor){
                    atual = atual->right;
                }else if(procurado < atual->valor ){
                    atual = atual->left;
                }
            }
            return NULL;
        }

        No* buscaRecursiva(No *arvore, Item procurado){
            
            if(arvore == NULL)
                return NULL;

            if(arvore->valor == procurado)
                return arvore;

            if(procurado > arvore->valor){
                return buscaRecursiva(arvore->right, procurado);
            }

            else if(procurado < arvore->valor){
                return buscaRecursiva(arvore->left, procurado);
            }
			return NULL;
        }

		int ehCompletaComRecursao(No* no) {
			
			if(isEmpty())
				return false;

			if(ehFolha(no))
				return true;

			if(temUmFilho(no)){
				return (ehPenultimoNivel(no));
			}

			if(temDoisFilhos(no)){
				bool completa = ehCompletaComRecursao(no->left);
				completa = completa && ehCompletaComRecursao(no->right);
				return completa;
			}
			return false;
		}

		No *removerNo(No* no, Item procurado){

			if(no == NULL)
				return NULL;

			if(no->valor == procurado){

				if(ehFolha(no)){
					free(no);
					return NULL;
				}

				else if(temUmFilho(no)){

					if(! (no->right==NULL)){
						
						Item valorMinimo = calcularMinimoValor(no->right);
						removerNo(no,valorMinimo);
						no->valor = valorMinimo;
					}
					else if(! (no->left==NULL)){
						
						Item valorMaximo = calcularMaximoValor(no->left);
						removerNo(no,valorMaximo);
						no->valor = valorMaximo;
					}
					
				}
				else  if(temDoisFilhos(no)){
						
					Item valorMinimo = calcularMinimoValor(no->right);
					removerNo(no,valorMinimo);
					no->valor = valorMinimo;
				}

			}else if(procurado > no->valor){
				no->right = removerNo(no->right,procurado);
			}

			else{
				no->left = removerNo(no->left,procurado);
			}
		}

		Item calcularMinimoValor(No *arvore){

            if(arvore == NULL)
                return NULL;
			
            while(arvore->left != NULL)
                arvore = arvore->left;

            return arvore->valor;
        }

		Item calcularMaximoValor(No *&arvore){

            if(arvore == NULL)
                return 0;

            else if(arvore->right == NULL){

				Item item = arvore->valor;
				free(arvore);
				arvore = NULL;
                return item;
			}

            else 
                return calcularMaximoValor(arvore->right);
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

			int left = calcularAlturaArvore(no->left); // Corrigindo chamada recursiva
			int right = calcularAlturaArvore(no->right); // Corrigindo chamada recursiva

			return 1 + max(left, right);
		}
		int minimoDeNos(){
			return 1 + (int) log(maximoDeNos());
		}

		int maximoDeNos(){
			return  pow(2,calcularAlturaArvore(raiz)) - 1;
		}
		
		int arvcheia(){
			return maximoDeNos() == calcularQtdNos(raiz);
		}

		void preordem(No *no){// Raiz -> Esquerda -> Direita
			
			if(ehNulo(no)){
				return;
			}
			string cor = obterCorAleatoria();

			cout << " " << no->valor << " ";
			
			cout << cor << " <" << RESET;
			preordem(no->left);
			cout << cor << "> " << RESET;


			cout << cor << " <" << RESET;
			preordem(no->right);
			cout << cor << "> " << RESET;
	    }
	    
	    void posordem(No *no){ //Esquerda -> Direita -> Raiz
			
			if(ehNulo(no)){
				return;
			}
			posordem(no->left);
			posordem(no->right);
			cout << no->valor;
		}

		void posordemComPilha(){ ///Esquerda -> Direita -> Raiz

			if(!isEmpty()){

				std::stack<No*> pilha;

				cout << endl<<"Coloquei "<< raiz->valor << " na pilha" << endl;
				pilha.push(raiz);
				pilha.push(raiz->right);
				pilha.push(raiz->left); 
				while(! pilha.empty()){

					No* no = pilha.top();
					pilha.pop();

					if(no->right != NULL)
						pilha.push(no->right);

					if(no->left != NULL)
						pilha.push(no->left);

					cout << no->valor;
				}
			}
		}

		void preordemComPilha(){ //Riz -> Esquerda -> Direita

			if(!isEmpty()){

				std::stack<No*> pilha;
				pilha.push(raiz);

				cout << endl<<"Coloquei "<< raiz->valor << " na pilha" << endl;

				while(! pilha.empty()){//Pilha -> C A E

					No* no = pilha.top();
					pilha.pop();

					if(no->right != NULL)
						pilha.push(no->right);

					if(no->left != NULL)
						pilha.push(no->left);

					cout << no->valor << endl;
				}
			}
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
			no = NULL;
		}

		
		
		int ehFolha(No* no){
			return(no->left == NULL && no->right == NULL);
		}

		int temUmFilho(No *no){

    		if(ehFolha(no))
				return false;
			return temDoisFilhos(no) == false;
		}

		int temDoisFilhos(No *no){

			if(ehFolha(no))
				return false;
			return not ehNulo(no->left) && not ehNulo(no->right);
		}

		int ehPenultimoNivel(No *no){

			if(not ehNulo(no->right) && ehFolha(no->right))
				return true;

			if(not ehNulo(no->left) && ehFolha(no->left))
				return true;
			
			return false;
		}

		void extensao(){
			queue<No*> fila;
			fila.push(raiz);
			while(!fila.empty()){
				No* no = fila.front();
				fila.pop();
				if(no->left!=NULL) fila.push(no->left);
				if(no->right!=NULL) fila.push(no->right);
				cout << no->valor;
			}
		}
};


// #include <stack>
// void preordemsem(No *arv){

//     stack<No*> p;
//     if(arv != NULL){
//         p.push(arv);
//         while(!p.empty()
//     }
// }



// se ( no nao tiver filhos)
                //     limpe no
                //     atualize o potneiro dele no pai como NULL

                // senao se ( so tiver um filho folha )

                //     se a direita NAO é nula:
                //         pegue minimo da dreita
                //         limpe o minimo da direita (lembre de deixalo como NULL)
                //         troque o valor do no a ser "removido" pelo valor 

                //     se a esquerda NAO é nula:
                //         pegue maximo da esquerda
                //         limpe o minimo da direita (lembre de deixalo como NULL)
                //         troque o valor do no a ser "removido" pelo valor 
            
                // senao (se tiver dois filhos)

                //     pegue minimo da dreita ou pegue maximo da esquerda
                //     limpe o escolhido (lembre de deixalo como NULL)
                //     troque o valor do no a ser "removido" pelo valor 
                    
#endif