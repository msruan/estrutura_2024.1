#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#define RESET "\033[0m"

const char* obterCor(int numero);
const char* obterCorAleatoria();

int randint(int min, int max) {
    // Inicializa a semente para a função rand()
    
    // Gera um número aleatório no intervalo [min, max]
    int random_number = min + rand() % (max - min + 1);
    return random_number;
}


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
		int tem1Filhos(No *no){

    		if(ehFolha(no))
				return false;
			return tem2filhos(no) == false;
		}

		int tem2filhos(No *no){

			if(ehFolha(no))
				return false;
			return not ehNulo(no->left) && not ehNulo(no->right);
		}

		int ehFolha(No* no){
			return(no->left == NULL && no->right == NULL);
		}

		int ehPenultimoNivel(No *no){

			if(not ehNulo(no->right) && ehFolha(no->right))
				return true;

			if(not ehNulo(no->left) && ehFolha(no->left))
				return true;
			
			return false;
		}
        No* buscaNAORecursiva(Item procurado){
            
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
        }


		int ehCompleta(No* no) {
			
			if(isEmpty())
				return false;

			if(ehFolha(no))
				return true;

			if(tem2filhos(no)){
				bool completa = ehCompleta(no->left);
				completa = completa && ehCompleta(no->right);
				return completa;
			}
			
			if(tem1Filhos(no)){
				if(not ehPenultimoNivel(no))
					return false;
				else 
					return  true;
			}

			return false;
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
        No* removerNo(No* , Item valor){
            /*minimo da direita e maximo da esquerda

                remover()

                se ( no nao tiver filhos)
                    limpe no
                    atualize o potneiro dele no pai como NULL

                senao se ( so tiver um filho folha )

                    se a direita NAO é nula:
                        pegue minimo da dreita
                        limpe o minimo da direita (lembre de deixalo como NULL)
                        troque o valor do no a ser "removido" pelo valor 

                    se a esquerda NAO é nula:
                        pegue maximo da esquerda
                        limpe o minimo da direita (lembre de deixalo como NULL)
                        troque o valor do no a ser "removido" pelo valor 
            
                senao (se tiver dois filhos)

                    pegue minimo da dreita ou pegue maximo da esquerda
                    limpe o escolhido (lembre de deixalo como NULL)
                    troque o valor do no a ser "removido" pelo valor 
                    



            */
        }



        No* calcularMinimo(No *arvore){

            if(arvore == NULL)
                return NULL;

            while(arvore->left != NULL)
                arvore = arvore->left;

            return arvore;

            // if(arvore == NULL)
            //     return NULL;

            // else if(arvore->left == NULL)
            //     return arvore;
            // else 
            //     return calcularMinimo(arvore->left);
        }

        No* calcularMaximo(No *arvore){

            if(arvore == NULL)
                return NULL;

            else if(arvore->right == NULL)
                return arvore;
            else 
                return calcularMinimo(arvore->right);
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
		int minimoDeNos(){
			return 1 + (int) log(maximoDeNos());
		}
		int maximoDeNos(){
			return  pow(2,calcularAlturaArvore(raiz)) - 1;
		}
		
		int arvcompleta(){
			int qtd = calcularQtdNos(raiz);
			return qtd <= minimoDeNos() && qtd >= maximoDeNos();
		}
		
		int arvcheia(){
			return maximoDeNos() == calcularQtdNos(raiz);
		}
		// void reduce(){

		// }
		
		int is_complete_tree() {
			if (isEmpty())
				return 1;

			int node_count = calcularQtdNos(raiz);
			int min_node_count = pow(2, calcularAlturaArvore(raiz)) - 1;

			return (node_count >= min_node_count);
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
			no = NULL;
		}

        
};

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

const char* obterCorAleatoria() {
    return obterCor(randint(1,8));
}


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
	cout << "Eh completa? " << arvore->ehCompleta(arvore->raiz) << "\n";
    No *busca = arvore->calcularMinimo(arvore->raiz);
    if(busca == NULL)
        cout << "Nao achei :((()))";
    else 
        cout << "achei é o "<<busca->valor;
	arvore->preordem(arvore->raiz);
	arvore->limpar(arvore->raiz);
}
// #include <stack>
// void preordemsem(No *arv){

//     stack<No*> p;
//     if(arv != NULL){
//         p.push(arv);
//         while(!p.empty()
//     }
// }
