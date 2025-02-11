struct objeto{
    int id;
    int dados[100];
};
typedef struct fila Fila;

Fila* criar_fila();
void liberar_fila(Fila* fi);
int tamanho_fila(Fila* fi);
int fila_vazia(Fila* fi);
int inserir_fila(Fila* fi, struct objeto obj);
int remover_fila(Fila* fi);
int consultar_fila(Fila* fi, struct objeto *obj);