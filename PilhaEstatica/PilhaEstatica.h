#define MAX 100
struct objeto{
    int id;
    char dados[100];
};
typedef struct pilha Pilha;

Pilha* criar_pilha();
void liberar_pilha(Pilha* pi);
int tamanho_pilha(Pilha* pi);
int pilha_cheia(Pilha* pi);
int pilha_vazia(Pilha* pi);
int remover_pilha(Pilha* pi);
int inserir_pilha(Pilha*pi, struct objeto obj);
int consultar_pilha(Pilha* pi, struct objeto *obj);