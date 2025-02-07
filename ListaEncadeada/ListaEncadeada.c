#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

struct elemento{
    struct objeto dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

Lista* criar_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void liberar_lista(Lista* li){
    if(li != NULL){
        Elem* no;
        while ((*li) != NULL){
            no = *li;
            *li = (no)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista *li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

int inserir_lista_inicio(Lista* li, struct objeto obj){
    if(li == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = obj;
    no->prox = (*li);
    *li = no;
    return 1;
}

int inserir_lista_final(Lista* li, struct objeto obj){
    if(li == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = obj;
    no->prox = NULL;
    if((*li) == NULL){
        *li = no;
    }else{
        Elem* aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int inserir_lista_ordenada(Lista* li, struct objeto obj){
    if(li == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = obj;
    if(lista_vazia(li)){
        no->prox = (*li);
        *li = no;
        return 1;
    }
    else{
        Elem *ant, *atual = *li;
        while (atual != NULL && atual -> dados.id < obj.id){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }
    }
    return 1;
}

int remover_lista_inicio(Lista *li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;
    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remover_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;
    Elem *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    if(no = no->prox){
        *li = no->prox;
    }else{
        ant->prox = no->prox;
    }
    free(no);
    return 1;
}

int remover_lista(Lista *li, int id){
    if(li == NULL)
        return 0;
    Elem *ant, *no = *li;
    while (no != NULL && no->dados.id != id){
        ant = no;
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    if(no == *li){
        *li = no->prox;
    }else{
        ant->prox = no->prox;
    }
    free(no);
    return 1;
}

int consulta_lista_pos(Lista* li, int pos, struct objeto *obj){
    if(li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL){
        return 0;
    }else{
        *obj = no->dados;
        return 1;
    }
}

int consulta_lista_valor(Lista *li, int valor, struct objeto *obj){
    if(li == NULL)
        return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.id != valor){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }else{
        *obj = no->dados;
        return 1;
    }
}