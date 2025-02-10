#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"

struct fila{
    int inicio, final, qtd;
    struct objeto dados[MAX];
};

Fila* criar_fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->qtd = 0;
        fi->inicio = 0;
        fi->final = 0;
    }
    return fi;
}

void liberar_fila(Fila* fi){
    free(fi);
}

int tamanho_fila(Fila* fi){
    if(fi == NULL)
        return -1;
    return fi->qtd;
}

int fila_cheia(Fila* fi){
    if(fi == NULL)
        return -1;
    if(fi->qtd == MAX)
        return 1;
    else
        return 0;
}

int fila_vazia(Fila* fi){
    if(fi == NULL) 
        return -1;
    if(fi->qtd == 0)
        return 1;
    else
        return 0;
}

int inserir_fila(Fila* fi, struct objeto obj){
    if(fi == NULL)
        return 0;
    if(fila_cheia(fi))
        return 0;
    fi->dados[fi->final] = obj;
    fi->final = (fi->final+1)%MAX;
    fi->qtd++;
    return 1;
}

int remover_fila(Fila* fi){
    if(fi == NULL || fila_vazia(fi))
        return 0;
    fi->inicio = (fi->inicio + 1)%MAX;
    fi->qtd--;
    return 1;
}

int consultar_fila(Fila* fi, struct objeto *obj){
    if(fi == NULL || fila_vazia(fi))
        return 0;
    *obj = fi->dados[fi->inicio];
    return 1;
}