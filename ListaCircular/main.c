#include <stdio.h>
#include <stdlib.h>
#include "ListaCircular.h"

int main(){
    Lista *li;
    li = criar_lista();
    int vazia = lista_vazia(li);
    struct objeto obja;
    obja.id = 1;
    struct objeto objb;
    objb.id = 4;
    struct objeto objc;
    objc.id = 2;
    int x = inserir_inicio_lista(li, obja);
    int y = inserir_final_lista(li, objb);
    int z = inserir_lista_ordenada(li, objc);
    int tamanho = tamanho_lista(li);
    printf("Tamanho atual da lista: %d \n", tamanho);
    int remov =  remover_lista(li, 1);
    struct objeto objr;
    if(remov == 1){
        tamanho = tamanho_lista(li);
        printf("Tamanho atual da lista: %d \n", tamanho);
        int i = consultar_pos_lista(li, 1, &objr);
        if(i == 1){
            printf("Aluno de id: %d encontrado\n", objr.id);
        }
    }else{
        printf("Falha ao remover item \n");
        int i = consultar_obj_lista(li, 2, &objr);
        if(i == 1){
            printf("Aluno de id: %d encontrado\n", objr.id);
        }
        
    }

    return 0;
}