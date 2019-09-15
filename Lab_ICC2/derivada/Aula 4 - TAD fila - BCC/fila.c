#include "fila.h"

void cria(Fila* f) {
    f->total = 0;
    f->ini = 0;
    f->fim = 0;
    return;
}

void esvazia(Fila* f) {
    cria(f);
    return;
}

int estaVazia(Fila f) {
    //return (f.total == 0);
    if (f.total == 0)
        return 1;
    return 0;
}

int estaCheia(Fila f) {
    //return (f.total == TamFila);
    if (f.total == TamFila)
        return 1;
    return 0;
}

int entra(Fila* f, elem x) {
    if (estaCheia(*f))
        return 1;
    f->vet[f->fim] = x;
    f->total++;
    if (f->fim == TamFila - 1)
        f->fim = 0;
    else
        f->fim++;
    return 0;
}

int sai(Fila* f, elem* x) {
    if (estaVazia(*f))
        return 1;
    *x = f->vet[f->ini];
    f->total--;
    if (f->ini == TamFila -1)
        f->ini = 0;
    else
        f->ini++;
    return 0;
}

