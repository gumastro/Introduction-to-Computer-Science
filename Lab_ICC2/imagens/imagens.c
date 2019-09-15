#include <stdio.h>
#include "tree.h"


int main(int argc, char const *argv[]) {

  int N; // quantidade de casos teste a serem tratados
  struct _node* raiz_1;
  struct _node* raiz_2;

  scanf("%d", &N);

  char input_1[N][256];
  char input_2[N][256];

  // Lê as entradas
  for (int i = 0; i < N; i++) {
    scanf("%s%s", input_1[i], input_2[i]);
  }

  raiz_1 = cria_filho();
  raiz_2 = cria_filho();

  int i, total;

  for (int z = 0; z < N; z++) {
    i = 0;
    insere_node(input_1[z], &i, raiz_1);
    i = 0;
    insere_node(input_2[z], &i, raiz_2);

    junta_arvores(raiz_1, raiz_2);

    total = 0;
    total = percorre_arvore(raiz_1, total, 1024);
    printf("%d %d pixels pretos.\n", z+1, total);
  }


  return 0;
}
