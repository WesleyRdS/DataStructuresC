#include <stdio.h>
#include <stdlib.h>
#include "ListaCircular.h"

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
    if(li != NULL && *li != NULL){
        Elem *aux, *no = *li;
        while((*li) != no->prox){
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(no);
        free(li);
    }
}

int tamanho_lista(Lista* li){
    if(li == NULL || (*li) == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    do{
        cont++;
        no = no->prox;
    }while(no != (*li));
    return cont;

}

int lista_vazia(Lista* li){
    if(li == NULL && (*li) == NULL)
        return 1;
    else
        return 0;
}

int inserir_inicio_lista(Lista* li, struct objeto obj){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = obj;
    if((*li) == NULL){
        *li = no;
        no->prox = no;
    }else{
        Elem* aux = *li;
        while(aux->prox != (*li))
            aux = aux->prox;
        aux->prox = no;
        no->prox = *li;
        *li = no;
    }
    return 1;
}

int inserir_final_lista(Lista* li, struct objeto obj){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = obj;
    if((*li) == NULL){
        *li = no;
        no->prox = no;
    }else{
        Elem* aux = *li;
        while(aux->prox != (*li))
            aux = aux->prox;
        aux->prox = no;
        no->prox = *li;
    }
    return 1;
}

int inserir_lista_ordenada(Lista* li, struct objeto obj){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = obj;
    if((*li) == NULL){
        *li = no;
        no->prox = no;
        return 1;
    }else{
        if((*li)->dados.id > obj.id){ //verifica se no inicio o id do objeto na lista é maior que o id do objeto a ser inserido
            Elem *atual = *li;
            while(atual->prox != (*li))
                atual->prox;
            no->prox = *li;
            atual->prox = no;
            *li = no; //objeto se torna o inicio da lista
            return 1;
        }
        Elem *ant = *li, *atual = (*li)->prox;
        while(atual != (*li) && atual->dados.id < obj.id){
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = no;
        no->prox = atual;
        return 1;
    }
}

int remover_inicio_lista(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;
    if((*li) == (*li)->prox){
        free(*li);
        *li = NULL;
        return 1;
    }
    Elem *atual = *li;
    while(atual->prox != *li)
        atual = atual->prox;
    Elem *no = *li;
    atual->prox = no->prox;
    *li = no->prox;
    free(no);
    return 1;
}

int remover_final_lista(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;
    if((*li) == (*li)->prox){
        free(*li);
        *li = NULL;
        return 1;
    }
    Elem *ant, *no = *li;
    while(no->prox != (*li)){
        ant = no;
        no = no->prox;
    }
    ant->prox = no->prox;
    free(no);
    return 1;
}

int remover_lista(Lista* li, int id){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;
    Elem *no = *li;
    if(no->dados.id == id){
        if(no == no->prox){
            free(no);
            *li = NULL;
            return 1;
        }
        Elem *aux = (*li);
        while(aux->prox != (*li))
            aux = aux->prox;
        aux->prox = (*li)->prox;
        *li = (*li)->prox;
        free(no);
        return 1;
    }
    Elem *ant = no;
    no = no->prox;
    while(no != (*li) && no->dados.id != id){
        ant = no;
        no = no->prox;
    }
    if(no == *li)
        return 0;
    ant->prox = no->prox;
    free(no);
    return 1;
}

int consultar_pos_lista(Lista* li, int pos, struct objeto *obj){
    if(li == NULL || (*li) == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while(no->prox != (*li) && i < pos){
        no = no->prox;
        i++;
    }
    if(i != pos) 
        return 0;
    else{
        *obj = no->dados;
        return 1;
    }

}
int consultar_obj_lista(Lista* li, int id, struct objeto *obj){
    if(li == NULL || (*li) == NULL)
        return 0;
    Elem *no = (*li);
    while(no->prox != (*li) && no->dados.id != id)
        no = no->prox;
    if(no->dados.id != id)
        return 0;
    else{
        *obj = no->dados;
        return 1;
    }
}