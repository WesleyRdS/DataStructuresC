#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

struct lista{
    int qtd;
    struct Objeto dados[MAX];
};

Lista* cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL)
        li->qtd = 0;
    return li;
}

void libera_lista(Lista* li){
    free(li);
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return -1;
    else
        return li->qtd;
}

int lista_cheia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == MAX);
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qtd == 0);
}

int inserir_final_lista(Lista* li, struct Objeto obj){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    li->dados[li->qtd] = obj;
    li->qtd++;
    return 1;
}

int inserir_inicio_lista(Lista *li, struct Objeto obj){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    if(lista_vazia(li)){
        inserir_final_lista(li, obj);
        return 1;
    }
    int i;
    for(i = li->qtd - 1; i >=0; i--)
        li->dados[i + 1] = li->dados[i];
    li->dados[0] = obj;
    li->qtd++;
    return 1;
}

int inserir_lista_ordenada(Lista *li, struct Objeto obj){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    int k, i = 0;
    while(i<li->qtd && li->dados[i].id < obj.id)
        i++;
    
    for(k = li->qtd - 1; k >= i; k--)
        li->dados[k + 1] = li->dados[k];
    li->dados[i] = obj;
    li->qtd++;
    return 1;
}

int remover_final_lista(Lista *li){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    li->qtd--;
    return 1;
}

int remover_inicio_lista(Lista *li){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k = 0;
    for(k = 0; k < li->qtd - 1; k++)
        li->dados[k] = li->dados[k + 1];
    li->qtd--;
    return 1;
}

int remover_lista(Lista *li, int id){
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k, i = 0;
    while(i < li->qtd && li->dados[i].id != id)
        i++;
    if(i == li->qtd)
        return 0;
    for(k = i; k < li->qtd - 1; k++)
        li->dados[k] = li->dados[k + 1];
    li->qtd--;
    return 1;
}

int consultar_pos_lista(Lista* li, int pos, struct Objeto *obj){
    if(li == NULL || pos <= 0 || pos > li->qtd)
        return 0;
    *obj = li->dados[pos-1];
    return 1;
}

int consultar_id_lista(Lista* li, int id, struct Objeto *obj){
    if(li == NULL)
        return 0;
    int k,i = 0;
    while(i < li->qtd && li->dados[i].id != id)
        i++;
    if(i == li->qtd)
        return 0;
    *obj = li->dados[i];
    return 1;
}