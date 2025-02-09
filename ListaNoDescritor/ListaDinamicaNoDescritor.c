#include <stdio.h>
#include <stdlib.h>
#include "ListaDinamicaNoDescritor.h"

struct elemento{
    struct objeto dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

struct descritor{
    struct elemento *inicio;
    struct elemento *final;
    int qtd;
};

Lista* criar_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        li->inicio = NULL;
        li->final = NULL;
        li->qtd = 0;
    }
    return li;
}
void liberar_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while((li->inicio) != NULL){
            no = li->inicio;
            li->inicio = li->inicio->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    return li->qtd;
}

int inserir_inicio_lista(Lista *li, struct objeto obj){
    if(li == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = obj;
    no->prox = li->inicio;
    if(li->inicio == NULL)
        li->final = no;
    li->inicio = no;
    li->qtd++;
    return 1;
}

int inserir_final_lista(Lista *li, struct objeto obj){
    if(li == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = obj;
    no->prox = NULL;
    if(li->inicio == NULL)
        li->inicio = no;
    else
        li->final->prox = no;
    li->final = no;
    li->qtd++;
    return 1;
}

int remover_inicio_lista(Lista* li){
    if(li == NULL)
        return 0;
    if(li->inicio == NULL)
        return 0;
    Elem* no = li->inicio;
    li->inicio = no->prox;
    free(no);
    if(li->inicio == NULL)
        li->final = NULL;
    li->qtd--;
    return 1;
}

int remover_final_lista(Lista* li){
    if(li == NULL)
        return 0;
    if(li->inicio == NULL)
        return 0;
    Elem *ant, *no = li->inicio;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    if(no == li->inicio){
        li->inicio == NULL;
        li->final == NULL;
    }else{
        ant->prox = no->prox;
        li->final = ant;
    }
    free(no);
    li->qtd--;
    return 1;
}