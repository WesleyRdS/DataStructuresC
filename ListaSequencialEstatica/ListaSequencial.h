#define MAX 100 //Tamanho maximo do vetor
struct Objeto{
    int id;
    char dados[100];
};

typedef struct lista Lista;

Lista* cria_lista();
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
int inserir_final_lista(Lista* li, struct Objeto obj);
int inserir_inicio_lista(Lista *li, struct Objeto obj);
int inserir_lista_ordenada(Lista *li, struct Objeto obj);
int remover_final_lista(Lista *li);
int remover_inicio_lista(Lista *li);
int remover_lista(Lista *li, int id);
int consultar_pos_lista(Lista* li, int pos, struct Objeto *obj);
int consultar_id_lista(Lista* li, int id, struct Objeto *obj);