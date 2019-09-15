#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

void cria(ABB *arv) {
  // cria árvore vazia
  arv->raiz = NULL;

  return;
}

void destroiSub(No *p) {

  if (p == NULL) {
    return;
  }

  destroiSub(p->esq); // destroi subárvore esq
  destroiSub(p->dir); // destroi subárvore dir
  free(p);

  return;
}

void destroi(ABB *arv) {
  destroiSub(arv->raiz); // inicia recursão
  arv->raiz = NULL;

  return;
}

int vazia(ABB arv) {
  // retorna 1 = árvore vazia
  // retorna 0 = árvore não vazia
  return arv.raiz == NULL;
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

int alturaSub(No *p) {
  int arv_esq, arv_dir;

  if (p == NULL) {
    return 0; // árvore nula
  }
  arv_esq = alturaSub(p->esq); // altura da subárvore esq
  arv_dir = alturaSub(p->dir); // altura da subárvore dir

  return (arv_esq > arv_dir)? arv_esq + 1 : arv_dir + 1;
}

int altura (ABB arv) {

  return alturaSub(arv.raiz); // inicia recursão
}

void preOrdemSub(No *p) {
  // RED

  if (p != NULL) {
    printf("%d ", p->info); // processa antes de varrer subárvores
    preOrdemSub(p->esq); // varre lado esquerdo
    preOrdemSub(p->dir); // varre lado direito
  }

  return;
}

void preOrdem(ABB arv) {
  preOrdemSub(arv.raiz); // inicia recursão
  printf("\n");

  return;
}

void emOrdemSub(No *p) {
  // ERD

  if (p != NULL) {
    emOrdemSub(p->esq); // varre lado esquerdo
    printf("%d ", p->info); // processa entre uma subárvore e outra
    emOrdemSub(p->dir); // varre lado direito

  }

  return;
}

void emOrdem(ABB arv) {
  emOrdemSub(arv.raiz); // inicia recursão
  printf("\n");

  return;
}

void posOrdemSub(No *p) {
  // EDR

  if (p != NULL) {
    posOrdemSub(p->esq); // varre lado esquerdo
    posOrdemSub(p->dir); // varre lado direito
    printf("%d ", p->info); // processa após subárvores
  }

  return;
}

void posOrdem(ABB arv) {
  posOrdemSub(arv.raiz); // inicia recursão
  printf("\n");

  return;
}

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

No *criaNo(elem info, No *esq, No *dir) {

  No *nova = (No*)malloc(sizeof(No));

  if (nova != NULL) {
    nova->info = info;
    nova->esq = esq;
    nova->dir = dir;
  }

  return nova;
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

void printLevel(No *p, int level) {

  if (p != NULL && level == 0) {
    printf("%d ", p->info);
  }
  else if (p != NULL) {
    printLevel(p->esq, level-1);
    printLevel(p->dir, level-1);
  }
}

void printElements(ABB arv) {
  int levelCount = altura(arv);
  for (int i = 0; i < levelCount; i++) {
    printLevel(arv.raiz, i);
  }
  printf("\n");
}
