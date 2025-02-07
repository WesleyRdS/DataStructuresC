#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

int main(){
    Lista *li;
    li = criar_lista();
    struct objeto obj;
    obj.id = 1;
    int a = inserir_lista_inicio(li, obj);
    if(lista_vazia(li)){
        printf("Lista vazia!!\n");
    }
    int x = tamanho_lista(li);
    int y = consulta_lista_pos(li, 0, &obj);
    printf("%id\n",obj.id);
    liberar_lista(li);
    return 0;
}

