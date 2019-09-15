typedef char elem;

typedef struct no No;

typedef struct {
  No *ini, *fim;
} Lista;

void cria(Lista *l);
int insere(Lista *l, elem x);
void finaliza(Lista *l);
void imprime(Lista l);
int tamanho(Lista *l);
int tamanho_rec(No *p);
int esta_na_lista(Lista l, elem x);
int esta_na_lista_rec(No *p, elem x);
int elimina(Lista *l, elem x);
int elimina2(Lista *l, elem x);
