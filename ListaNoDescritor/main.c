#include <stdio.h>
#include <stdlib.h>
#include "ListaDinamicaNoDescritor.h"

int main(){
    Lista *li;
    li = criar_lista();
    struct objeto obja;
    obja.id = 1;
    struct objeto objb;
    objb.id = 4;
    struct objeto objc;
    objc.id = 2;
    int x = inserir_inicio_lista(li, obja);
    int y = inserir_final_lista(li, objb);
    int tamanho = tamanho_lista(li);
    printf("Tamanho atual da lista: %d \n", tamanho);
    int remov = remover_inicio_lista(li);
    if(remov == 1){
        tamanho = tamanho_lista(li);
        printf("Tamanho atual da lista: %d \n", tamanho);
    }
    return 0;
}