#include <stdio.h>
#include <math.h>
#include "tad.h"

int main(int argc, char const *argv[]) {

  int D; // profundidade da árvore
  int I; // número de bolas
  Lista *L;

  cria(L);

  scanf("%d %d", &D, &I);

  for (int i = 0; i < (pow(2, D)-1); i++) {
    insere(L, (i+1));
  }

  int p;

  for (int i = 0; i < I; i++) {
    percorre(L, L->ini, 1, &p, D);
  }
  printf("%d\n", p);

  imprime(*L);

  return 0;
}
