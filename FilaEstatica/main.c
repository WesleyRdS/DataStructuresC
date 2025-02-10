#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"

int main(){
    Fila* fi;
    fi = criar_fila();
    if(fi == NULL)
        return -1;
    int num = 0;
    while(!fila_cheia(fi))
    {
        struct objeto obja;
        obja.id = num;
        inserir_fila(fi, obja);
        num++;
    }
    struct objeto obj;
    while (!fila_vazia(fi))
    {
        int x = consultar_fila(fi, &obj);
        if(x == 1){
            printf("%d", obj.id);
            remover_fila(fi);
        }
    }
    liberar_fila(fi);
    
    return 0;
}