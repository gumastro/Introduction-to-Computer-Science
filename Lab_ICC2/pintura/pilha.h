#define TamPilha 100
typedef int elem;
typedef struct pilha {
    elem vet[TamPilha];
    int topo;
} Pilha;

void cria_pilha(Pilha* p);

int push(Pilha* p, elem x, elem y);

int isEmpty(Pilha* p);

int pop(Pilha* p, elem* x, elem* y);

elem top(Pilha p, int* erro);

void empty(Pilha* p);

int iguais(Pilha p1, Pilha p2);

int see_top(Pilha* p, int* erro);
