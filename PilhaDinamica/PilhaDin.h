struct objeto{
    int id;
    char dado[100];
};
typedef struct elemento* Pilha;

Pilha* criar_pilha();
void liberar_pilha(Pilha* pi);
int tamanho_pilha(Pilha* pi);
int pilha_vazia(Pilha* pi);
int inserir_pilha(Pilha* pi, struct objeto obj);
int remover_pilha(Pilha* pi);
int consultar_pilha(Pilha* pi, struct objeto* obj);