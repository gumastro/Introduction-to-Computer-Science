#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

void cria(ABB *a) {
    a->raiz = NULL; // cria uma arvore vazia
    return;
}

void destroiSub(No *p) {
    if (p == NULL)
        return;
    destroiSub(p->esq); // destroi subarvore esquerda
    destroiSub(p->dir); // destroi subarvore direita
    free(p); // apaga o raiz da subarvore
    return;
}

void destroi(ABB *a) {
    destroiSub(a->raiz); // inicia recursao
    a->raiz = NULL;
    return;
}

int vazia(ABB a) {
    return a.raiz == NULL;
}

void imprimeSub(No *p) {
    printf("{");
    if (p != NULL) {
        printf("%d, ", p->info);
        imprimeSub(p->esq);
        printf(", ");
        imprimeSub(p->dir);
    }
    printf("}");
    return;
}

void imprime(ABB a) {
    imprimeSub(a.raiz);
    printf("\n");
    return;
}

int alturaSub(No *p) {
    int aesq, adir;
    if (p == NULL)
        return 0; // arvore nula
    aesq = alturaSub(p->esq); // altura da subarvore esquerda
    adir = alturaSub(p->dir); // altura da subarvore direita
    return (aesq > adir)? aesq + 1 : adir + 1;
}

int altura(ABB a) {
    return alturaSub(a.raiz); // inicia recursao
}

void preOrdemSub(No *p) {
    if (p != NULL) {
        printf("%d ", p->info); // processa antes de varrer subarvores
        preOrdemSub(p->esq); // varre lado esquerdo
        preOrdemSub(p->dir); // varre lado direito
    }
    return;
}

void preOrdem(ABB a) {
    preOrdemSub(a.raiz); // inicia recursao
    printf("\n");
    return;
}

void emOrdemSub(No *p) {
    if (p != NULL) {
        emOrdemSub(p->esq); // varre lado esquerdo
        printf("%d ", p->info); // processa entre uma subarvore e a outra
        emOrdemSub(p->dir); // varre lado direito
    }
    return;
}

void emOrdem(ABB a) {
    emOrdemSub(a.raiz); // inicia recursao
    printf("\n");
    return;
}

void posOrdemSub(No *p) {
    if (p != NULL) {
        posOrdemSub(p->esq); // varre lado esquerdo
        posOrdemSub(p->dir); // varre lado direito
        printf("%d ", p->info); // processa apos subarvores
    }
    return;
}

void posOrdem(ABB a) {
    posOrdemSub(a.raiz); // inicia recursao
    printf("\n");
    return;
}

int buscaSub(No *p, elem x) {
    if (p == NULL)
        return 0; // nao achou
    if (p->info == x)
        return 1; // achou
    return (x < p->info) ? buscaSub(p->esq, x) : buscaSub(p->dir, x);
}

int busca(ABB a, elem x) {
    return buscaSub(a.raiz, x); // inicia recursao
}

No *criaNo(elem info, No *esq, No *dir) {
    No *nova = malloc(sizeof(No));
    if (nova != NULL) {
        nova->info = info;
        nova->esq = esq;
        nova->dir = dir;
    }
    return nova;
}

int insercaoSub(No **p, elem x) {
    // p => No **; *p => No *; **p => No
    if (*p == NULL) {
        *p = criaNo(x, NULL, NULL); // insere
        return *p == NULL; // erro de memoria ou sucesso
    }
    if ((*p)->info == x)
        return 1; // erro, achou
    return (x < (*p)->info) ? insercaoSub(&((*p)->esq), x) : insercaoSub(&((*p)->dir), x);
}

int insercao(ABB *a, elem x) {
    return insercaoSub(&(a->raiz), x); // inicia recursao
}

int remocaoSub(No **p, elem x) {
    // p => No **; *p => No *; **p => No
    int numFilhos = 0;
    No *aux, *paiAux;
    if (*p == NULL)
        return 1; // erro, elemento nao existe
    if ((*p)->info == x) { // achou, entao remove
        if ((*p)->esq != NULL)
            numFilhos++;
        if ((*p)->dir != NULL)
            numFilhos++;
        switch (numFilhos) {
            case 0: // nenhum filho
                free(*p); // apaga
                *p = NULL; // atualiza encadeamento
                return 0;
            case 1: // um filho
                aux = *p;
                *p = ((*p)->esq != NULL) ? (*p)->esq : (*p)->dir; // atualiza encadeamento
                free(aux);
                return 0;
            case 2: // dois filhos
                // acha maior filho na subarvore esquerda (aux)
                aux = (*p)->esq;
                paiAux = *p;
                while (aux->dir != NULL) {
                    paiAux = aux;
                    aux = aux->dir;
                }
                (*p)->info = aux->info; // copia info
                return (paiAux->esq == aux) ? remocaoSub(&(paiAux->esq),aux->info) : remocaoSub(&(paiAux->dir),aux->info); // apaga aux e atualiza encadeamento
        }
    }
    return (x < (*p)->info) ? remocaoSub(&((*p)->esq), x) : remocaoSub(&((*p)->dir), x);
}

int remocao(ABB *a, elem x) {
    return remocaoSub(&(a->raiz), x); // inicia recursao
}
