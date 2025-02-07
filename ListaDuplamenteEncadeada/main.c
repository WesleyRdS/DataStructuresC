#include <stdio.h>
#include <stdlib.h>
#include "ListaDpEncadeada.h"

int main(){
    Lista *li;
    li = criar_lista();
    struct objeto obj;
    obj.id = 1;
    struct objeto objb;
    objb.id = 4;
    int x = inserir_final_lista(li,obj);
    int y = inserir_lista_ordenada(li, objb);
    printf("O tamanho da lista é %d\n", tamanho_lista(li));
    int z = remover_lista(li, 4);
    printf("O tamanho da lista é %d\n", tamanho_lista(li));
    struct objeto objc;
    int w = consulta_lista_pos(li, 1, &objc);
    if(w == 1)
         printf("O objeto de id %d\n", objc.id);
    return 0;
}
