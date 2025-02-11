#include <stdlib.h>
#include <stdio.h>
#include "FilaDin.h"

int main(){

    Fila *fi;
    fi = criar_fila();
    for(int i = 0; i < 50; i++){
        struct objeto obj;
        obj.id = i;
        int x = inserir_fila(fi, obj);
        if(x == 0)
            break;
    }
    int tamanho = tamanho_fila(fi);
    printf(" tamanho fila %d\n", tamanho);
    while(!fila_vazia(fi)){
        struct objeto objc;
        int consulta = consultar_fila(fi, &objc);
        if(consulta == 1){
            printf(" Antigo primeiro da fila tem o id %d\n", objc.id);
        }
        int remoção = remover_fila(fi);
        if(remoção == 1){
            consulta = consultar_fila(fi, &objc);
            if(consulta == 1)
                printf(" Novo primeiro da fila tem o id %d\n", objc.id);
        }
    }
    tamanho = tamanho_fila(fi);
    printf(" tamanho fila %d\n", tamanho);
    return 0;
}