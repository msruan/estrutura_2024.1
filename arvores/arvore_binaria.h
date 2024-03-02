#include <stdio.h>
#include <stdlib.h>
#define Item int

typedef struct arv {
    struct arv *left;
    Item item;
    struct arv *right;
} Arv;

Arv *gerarNo(Item item, Arv *left, Arv *right){
    Arv* novoNo = (Arv*) malloc (sizeof(Arv));
    novoNo->item = item; 
    novoNo->left = left;
    novoNo->right = right;
    return novoNo;
}