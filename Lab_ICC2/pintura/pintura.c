#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

typedef struct _tinta {
  int pos_x;
  int pos_y;
  char cor;

} T;


char** pinta_tudo(Pilha p, char** board, char color, char temp, long int altura, long int largura) {
  int x;
  int y;

  while (!isEmpty(&p)) {

    pop(&p, &y, &x);

    board[x][y] = color;
    //printf("board[%d][%d] = color\n", x, y);

    if ((x+1) < altura && board[x+1][y] == temp) {
      push(&p, x+1, y);
    }

    if ((x-1) >= 0 && board[x-1][y] == temp) {
      push(&p, x-1, y);
    }

    if ((y+1) < largura && board[x][y+1] == temp) {
      push(&p, x, y+1);
    }

    if ((y-1) >= 0 && board[x][y-1] == temp) {
      push(&p, x, y-1);
    }
  }

  return board;
}


int main(int argc, char const* argv[]) {

  long int altura, largura;

  scanf("%ld %ld", &altura, &largura);
  getchar();  // pega o \n

  char **pintura = (char**) calloc(altura, sizeof(char*));
  for (int i = 0; i < altura; i++ )  {
    pintura[i] = (char*) calloc(largura, sizeof(char));
  }
  Pilha p;

  cria_pilha(&p);

  for (int i = 0; i < altura; i++) {
    scanf("%[^\n]s", pintura[i]);
    getchar();  // pega o \n

  }

  int k = 0;
  int error, error2;
  char temp;
  T tinta[500];

  while (scanf("%d %d %c", &tinta[k].pos_x, &tinta[k].pos_y, &tinta[k].cor) != EOF) {
    push(&p, tinta[k].pos_x, tinta[k].pos_y);

    temp = pintura[tinta[k].pos_x][tinta[k].pos_y];

    pintura = pinta_tudo(p, pintura, tinta[k].cor, temp, altura, largura);
    pop(&p, &error, &error2);

    for (int i = 0; i < altura; i++) {
      for (int j = 0; j < largura; j++) {
        printf("%c", pintura[i][j]);
      }
      printf("\n");
    }

    k++;
  }

  for (int i = 0; i < altura; i++) {
    free(pintura[i]);
  }
  free(pintura);

  return 0;
}
