#include <stdlib.h>
#include <stdio.h>
#include "PilhaEstatica.h"

int main(){
    Pilha *pi;
    pi = criar_pilha();
    int num = 0;
    while(!pilha_cheia(pi))
    {
        struct objeto obja;
        obja.id = num;
        inserir_pilha(pi, obja);
        num++;
    }
    struct objeto obj;
    while (!pilha_vazia(pi))
    {
        int x = consultar_pilha(pi, &obj);
        if(x == 1){
            printf("%d\n", obj.id);
            remover_pilha(pi);
        }
    }
    liberar_pilha(pi);
    return 0;
}