typedef int elem;

typedef struct _node {
  elem info;
  struct _node *esq, *dir;

} No;

typedef struct {
  No *raiz;

} ABB;

void cria(ABB *arv);
ABB* create_hash_table();
int insercaoSub(No **p, elem x);
int insercao(ABB *arv, elem x);
int insert(ABB* t, int key);
int acha(ABB* t, int key);
int remocaoSub(No **p, elem x);
int remocao(ABB *arv, elem x);
int tira(ABB* t, int key);
void emOrdemSub(No *p, ABB arv);
void emOrdem(ABB arv);
void imprimeSub(No *p);
void imprime(ABB arv);
