typedef int elem;

typedef struct no {
    elem info;
    struct no *esq, *dir;
} No;

typedef struct {
    No *raiz;
} ABB;

void cria(ABB *a);
void destroi(ABB *a);
int vazia(ABB a);
void imprime(ABB a);
int altura(ABB a);
void preOrdem(ABB a);
void emOrdem(ABB a);
void posOrdem(ABB a);
int busca(ABB a, elem x);
int insercao(ABB *a, elem x);
int remocao(ABB *a, elem x);
