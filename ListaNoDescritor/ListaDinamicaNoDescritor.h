struct objeto
{
    int id;
    char dados[100];
};

typedef struct descritor Lista;

Lista* criar_lista();
void liberar_lista(Lista* li);
int tamanho_lista(Lista* li);
int inserir_inicio_lista(Lista *li, struct objeto obj);
int inserir_final_lista(Lista *li, struct objeto obj);
int remover_inicio_lista(Lista* li);
int remover_final_lista(Lista* li);
