struct objeto{
    int id;
    char dados[100];
};

typedef struct elemento* Lista;

Lista* criar_lista();
void liberar_lista(Lista* li);
int tamanho_lista(Lista *li);
int lista_vazia(Lista* li);
int inserir_lista_inicio(Lista* li, struct objeto obj);
int inserir_lista_final(Lista* li, struct objeto obj);
int inserir_lista_ordenada(Lista* li, struct objeto obj);
int remover_lista_inicio(Lista *li);
int remover_lista_final(Lista* li);
int remover_lista(Lista *li, int id);
int consulta_lista_pos(Lista* li, int pos, struct objeto *obj);
int consulta_lista_valor(Lista *li, int valor, struct objeto *obj);