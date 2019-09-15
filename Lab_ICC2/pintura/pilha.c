#include "pilha.h"

void cria_pilha(Pilha* p){
    p->topo = -1;
    return;
}

int push(Pilha* p, elem x, elem y){
    if (p->topo == TamPilha-1)
        return 1;
    p->topo++;
    p->vet[p->topo] = x;
    p->topo++;
    p->vet[p->topo] = y;
    return 0;
}

int isEmpty(Pilha* p) {
    return p->topo == -1;
}

int pop(Pilha* p, elem* x, elem* y) {
    if (isEmpty(p))
        return 1;
    *x = p->vet[p->topo];
    p->topo--;
    *y = p->vet[p->topo];
    p->topo--;
    return 0;
}

elem top(Pilha p, int* erro) {
    if (isEmpty(&p)) {
        *erro = 1;
        return -1;
    }
    *erro = 0;
    return p.vet[p.topo];
}

void empty(Pilha* p) {
    cria_pilha(p);
    return;
}

int iguais(Pilha p1, Pilha p2) {
    if (p1.topo != p2.topo)
        return 0;
    else
        for (int i=0; i<p1.topo; i++) {
            if (p1.vet[i] != p2.vet[i])
                return 0;
        }
    return 1;
}

// Verifica o elemento no topo da Pilha
int see_top(Pilha* p, int* erro) {
  if(isEmpty(p)) {
    *erro = 1;
    return 1;
  }
  *erro = 0;
  return p->vet[p->topo];
}
