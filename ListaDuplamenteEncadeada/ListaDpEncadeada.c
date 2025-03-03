#include <stdio.h>
#include <stdlib.h>
#include "ListaDpEncadeada.h"

struct elemento{
    struct elemento *ant;
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

void liberar_lista(Lista *li){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
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
    if(li == NULL) // Não tem uma lista
        return 1;
    if(*li == NULL) // Se o conteudo da lista aponta pra null então a lista esta vazia
        return 1;
    return 0;
}

int inserir_inicio_lista(Lista* li, struct objeto obj){
    if(li == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = obj;
    no->prox = (*li);
    no->ant = NULL;
    if(*li != NULL)//Se a lista não estava vazia o anterior do antigo primeiro elemento passa a apontar para o novo
        (*li)->ant = no;
    *li = no; // O primeiro elemento se torna o novo
    return 1;
}

int inserir_final_lista(Lista* li, struct objeto obj){
    if(li == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = obj;
    no->prox = NULL;
    if((*li) == NULL){
        no->ant = NULL;
        *li = no;
    }else{
        Elem* aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
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
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    }else{
        Elem *ante, *atual = *li;
        while(atual != NULL && atual->dados.id < obj.id){
            ante = atual;
            atual = atual->prox;
        }
        if(atual == *li){ //Inserindo no inicio
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            if(atual != NULL)
                atual->ant = no;
        }
        return 1;
    }
}

int remover_inicio_lista(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;
    Elem *no = *li;
    *li = no->prox;
    if(no->prox != NULL)
        no->prox->ant = NULL;
    free(no);
    return 1;
}

int remover_final_lista(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;
    Elem *no = *li;
    while(no->prox != NULL)
        no = no->prox;
    if(no->ant == NULL)
        *li = no->prox;
    else
        no->ant->prox = NULL;
    free(no);
    return 1;
}

int remover_lista(Lista* li, int id){
    if(li == NULL)
        return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.id != id){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    if(no->ant == NULL)
        *li = no->prox;
    else
        no->ant->prox = no->prox;
    if(no->prox != NULL)
        no->prox->ant = no->ant;
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
    if(no == NULL)
        return 0;
    else{
        *obj = no->dados;
        return 1;
    }
}

int consulta_lista_id(Lista* li, int id, struct objeto *obj){
    if(li == NULL)
        return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.id != id){
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    else{
        *obj = no->dados;
        return 1;
    }
}