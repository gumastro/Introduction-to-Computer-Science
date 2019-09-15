typedef int elem;

typedef struct no No;

typedef struct {
    No *ini, *fim;
} Lista;

void cria(Lista *l);
int insere(Lista *l, elem x);
void imprime(Lista l);
void percorre(Lista* L, No* p, int goal, int* x, int D);
