#include <stdlib.h>
#include <stdio.h>
#include "PilhaDin.h"

struct elemento{
    struct objeto dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* criar_pilha(){
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
    {
        *pi = NULL;
    }
    return pi;
    
}

void liberar_pilha(Pilha* pi){
    if(pi != NULL){
        Elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int tamanho_pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    int cont = 0;
    Elem* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int pilha_vazia(Pilha* pi){
    if(pi == NULL)
        return -1;
    if(*pi == NULL)
        return 1;
    return 0;
}

int inserir_pilha(Pilha* pi, struct objeto obj){
    if(pi == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = obj;
    no->prox = (*pi);
    *pi = no;
    return 1;

}
int remover_pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}
int consultar_pilha(Pilha* pi, struct objeto* obj){
    if(pi == NULL || (*pi) == NULL)
        return 0;
    *obj = (*pi)->dados;
    return 1;
}