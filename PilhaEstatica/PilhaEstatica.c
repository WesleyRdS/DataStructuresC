#include <stdlib.h>
#include <stdio.h>
#include "PilhaEstatica.h"

struct pilha{
    int qtd;
    struct objeto dados[MAX];
};

Pilha* criar_pilha(){
    Pilha *pi;
    pi = (Pilha*) malloc(sizeof(struct pilha));
    if(pi != NULL)
        pi->qtd = 0;
    return pi;
}

void liberar_pilha(Pilha* pi){
    free(pi);
}

int tamanho_pilha(Pilha* pi){
    if(pi == NULL)
        return -1;
    else
        return pi->qtd;
}

int pilha_cheia(Pilha* pi){
    if(pi == NULL)
        return -1;
    return (pi->qtd == MAX);
}

int pilha_vazia(Pilha* pi){
    if(pi == NULL)
        return -1;
    return (pi->qtd == 0);
}

int remover_pilha(Pilha* pi){
    if(pi == NULL || pilha_vazia(pi))
        return 0;
    pi->qtd--;
    return 1;
}

int inserir_pilha(Pilha*pi, struct objeto obj){
    if(pi == NULL || pilha_cheia(pi))
        return 0;
    pi->dados[pi->qtd] = obj;
    pi->qtd++;
    return 1;
}

int consultar_pilha(Pilha* pi, struct objeto *obj){
    if(pi == NULL || pilha_vazia(pi))
        return 0;
    *obj = pi->dados[pi->qtd-1];
    return 1;
}