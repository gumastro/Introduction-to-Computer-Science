#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash_v2.h"

int buscaSub(No *p, elem x) {

  if (p == NULL) {
    return 0; // não achou
  }

  if (p->info == x) {
    return 1; // achou
  }

  return (x < p->info)? buscaSub(p->esq, x) : buscaSub(p->dir, x);
}

int busca (ABB arv, elem x) {
  return buscaSub(arv.raiz, x);
}

int acha(ABB* t, int key) {

	if (key < 0) return -1;
	int pos;

	pos = key%100;

  return busca((t[pos]), key);
}

No *criaNo(elem info, No *esq, No *dir) {

  No *nova = (No*)malloc(sizeof(No));

  if (nova != NULL) {
    nova->info = info;
    nova->esq = esq;
    nova->dir = dir;
  }

  return nova;
}

void cria(ABB *arv) {
  // cria árvore vazia
  arv->raiz = NULL;

  return;
}

ABB* create_hash_table() {

	ABB* t = malloc(100 * sizeof(ABB));

  for(int i = 0; i < 100; i++) {
    cria(&t[i]);
    //t[i] = malloc(sizeof(ABB));
  }

	return t;
}

int insercaoSub(No **p, elem x) {
  // p => No**; *p => No*; **p => No

  if (*p == NULL) {
    *p = criaNo(x, NULL, NULL); // insere
    return *p == NULL; // erro de memória (1) ou sucesso (0)
  }

  if ((*p)->info == x) {
    return 1; // erro -> ACHOU
  }

  return (x < (*p)->info)? insercaoSub(&((*p)->esq), x) : insercaoSub(&((*p)->dir), x);
}

int insercao(ABB *arv, elem x) {

  return insercaoSub(&(arv->raiz), x); // inicia recursão
}

int insert(ABB* t, int key) {

	if (key < 0) return -1;
	int pos;

	pos = key%100;
  insercao((&t[pos]), key);

  return 0;
}

int remocaoSub(No **p, elem x) {
  // p => No**; *p => No*; **p => No

  int numFilhos = 0;
  No *aux, *paiAux;

  if (*p == NULL) {
    return 1; // ERRO, elemento não existe
  }

  if ((*p)->info == x) { // achou, então remove

    // verifica quantos filhos tem
    if ((*p)->esq != NULL) {
      numFilhos++;
    }
    if ((*p)->dir != NULL) {
      numFilhos++;
    }

    switch (numFilhos) {
      case 0:
        free(*p); // apaga
        *p = NULL; // atualiza encadeamento
      return 0;

      case 1:
        aux = *p;
        *p = ((*p)->esq != NULL)? (*p)->esq : (*p)->dir; // atualiza encadeamento
        free(aux);
      return 0;

      case 2:
        // outdated: acha maior filho na subárvore esquerda (aux)
        // updated: acha menor filho na subárvore direita
        aux = (*p)->dir;
        paiAux = *p;
        while (aux->esq != NULL) {
          paiAux = aux;
          aux = aux->esq;
        }
        (*p)->info = aux->info; // copia info
      return (paiAux->esq == aux)? remocaoSub(&(paiAux->esq), aux->info) : remocaoSub(&(paiAux->dir), aux->info); // apaga aux e atualiza encadeamento
    }
  }

  return (x < (*p)->info)? remocaoSub(&((*p)->esq), x) : remocaoSub(&((*p)->dir), x);
}

int remocao(ABB *arv, elem x) {

  return remocaoSub(&(arv->raiz), x); // inicia recursao
}

int tira(ABB* t, int key) {

	if (key < 0) return -1;
	int pos;

	pos = key%100;

  return remocao((&t[pos]), key);
}

void emOrdemSub(No *p, ABB arv) {
  // ERD

  if (p != NULL) {
    emOrdemSub(p->esq, arv); // varre lado esquerdo
    // processa entre uma subárvore e outra
    if ((arv.raiz->esq != NULL || arv.raiz->dir != NULL) && p->info != arv.raiz->info) printf("%d, ", p->info);
    else printf("%d", p->info);
    emOrdemSub(p->dir, arv); // varre lado direito

  }

  return;
}

void emOrdem(ABB arv) {
  if(arv.raiz->esq != NULL || arv.raiz->dir != NULL) printf("(");
  emOrdemSub(arv.raiz, arv); // inicia recursão
  if(arv.raiz->esq != NULL || arv.raiz->dir != NULL) printf(")");

  return;
}

void imprimeSub(No *p) {
  printf("(");
  if (p != NULL) {
    printf("%d, ", p->info);
    imprimeSub(p->esq);
    printf(", ");
    imprimeSub(p->dir);
  }
  printf(")");

  return;
}

void imprime(ABB arv) {
  imprimeSub(arv.raiz);
  printf("\n");

  return;
}
