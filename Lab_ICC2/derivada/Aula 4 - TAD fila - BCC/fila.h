#define TamFila 100

typedef char elem;

typedef struct fila {
    elem vet[TamFila];
    int ini, fim, total;
} Fila;

void cria(Fila* f);
void esvazia(Fila* f);
int estaVazia(Fila f);
int estaCheia(Fila f);
int entra(Fila* f, elem x);
int sai(Fila* f, elem* x);
