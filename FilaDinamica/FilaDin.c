#include <stdio.h> 
#include <stdlib.h>
#include "FilaDin.h"

struct fila{
    struct elemento *inicial;
    struct elemento *final;
};
struct elemento{
    struct objeto dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Fila* criar_fila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicial = NULL;
        fi->final = NULL;
    }
    return fi;
}

void liberar_fila(Fila* fi){
    if(fi != NULL){
        Elem* no;
        while(fi->inicial != NULL){
            no = fi->inicial;
            fi->inicial = fi->inicial->prox;
            free(no);
        }
        free(fi);
    }
}

int tamanho_fila(Fila* fi){
    if(fi == NULL)
        return 0;
    int cont = 0;
    Elem* no = fi->inicial;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int fila_vazia(Fila* fi){
    if(fi == NULL)
        return 1;
    if(fi->inicial == NULL)
        return 1;
    return 0;
}

int inserir_fila(Fila* fi, struct objeto obj){
    if(fi == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = obj;
    no->prox = NULL;
    if(fi->final == NULL) //fila vazia
        fi->inicial = no;
    else
        fi->final->prox = no;
    fi->final = no;
    return 1;
}

int remover_fila(Fila* fi){
    if(fi == NULL || fi->inicial == NULL)
        return 0;
    Elem* no = fi->inicial;
    fi->inicial = fi->inicial->prox;
    if(fi->inicial == NULL)
        fi->final = NULL;
    free(no);
    return 1;
}

int consultar_fila(Fila* fi, struct objeto *obj){
    if(fi == NULL || fi->inicial == NULL)
        return 0;
    *obj = fi->inicial->dados;
    return 1;
}