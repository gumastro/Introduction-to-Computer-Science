#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "tad.h"

struct no {
  elem info;
  bool flag;
  struct no *ant;
  struct no *prox;
};

void cria(Lista *l) {
  l->ini = NULL;
  l->fim = NULL;

  return;
}

int insere(Lista *l, elem x) {
  No *p;
  // cria no
  p = (No *) malloc(sizeof(No));

  if (p==NULL) {
    return 1;
  }

  // atribui valores
  p->info = x;
  p->ant = NULL;
  p->prox = NULL;
  p->flag = false;

  // atualiza encadeamento
  if (l->ini == NULL) {
    l->ini = p;
  }

  else {
    l->fim->prox = p;
    p->ant = l->fim;
  }

  l->fim = p;

  return 0;
}

void imprime(Lista l) {
  No *p;
  p = l.ini;
  while (p != NULL) {
//    printf("%d ", p->info);
    p = p->prox;
  }
//  printf("\n");

  return;
}

void percorre(Lista* L, No *p, int goal, int* x, int D) {

  if (p->prox == NULL)  return;
  // No *p;
  // p = L->ini;
  int i = p->info;
//  printf("i: %d\n", p->info);

  if (p->flag == false) {
    p->flag = true;
//    printf("p->info: %d | flag: %d\n", p->info, p->flag);

    while (p->prox != NULL && i != (goal*2)) {
    //  printf("andou\n");
      if (goal*2 > pow(2, D)-1) return;
      if (p->prox != NULL) {
        p = p->prox;
        i = p->info;
      }
    *x = p->info;
    //  printf("*i = %d\n", i);
    }
  }
  else if (p->flag == true) {

    p->flag = false;
//    printf("*p->info: %d | flag: %d\n", p->info, p->flag);
    while (p != NULL && i != ((goal*2)+1)) {
      if ((goal*2)+1 > pow(2, D)-1) return;
      p = p->prox;
      i = p->info;
    }
    *x = p->info;
  }
//  printf("aq %d %d\n", p->info, p->flag);

  if (p->prox != NULL) percorre(L, p, p->info, x, D);

  return;
}
