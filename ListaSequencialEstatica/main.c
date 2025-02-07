#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "ListaSequencial.h"

int main(){
    Lista *li;
    li = cria_lista();
    struct Objeto obj;
    obj.id = 1;
    strcpy(obj.dados, "Ola mundo");
    int x = inserir_inicio_lista(li, obj);
    if(x == 1){
        int a = tamanho_lista(li);
        printf("%d\n", a);
    }
}
