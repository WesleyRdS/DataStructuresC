struct objeto
{
    int id;
    char dados[100];
};

typedef struct elemento* Lista;

Lista* criar_lista();
void liberar_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int inserir_inicio_lista(Lista* li, struct objeto obj);
int inserir_final_lista(Lista* li, struct objeto obj);
int inserir_lista_ordenada(Lista* li, struct objeto obj);
int remover_inicio_lista(Lista* li);
int remover_final_lista(Lista* li);
int remover_lista(Lista* li, int id);
int consultar_pos_lista(Lista* li, int pos, struct objeto *obj);
int consultar_obj_lista(Lista* li, int id, struct objeto *obj);