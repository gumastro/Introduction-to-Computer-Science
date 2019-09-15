#include <stdio.h>
#include <stdlib.h>

int** matrix(int N, int M){                         // aloca a matriz do condomínio
  int** matriz = (int**)calloc(N, sizeof(int*));
    for ( int i = 0; i < N; i++ ){
      matriz[i] = (int*)calloc(M, sizeof(int));

    }

  return matriz;
}
/*
int** matrix_pos(int Q){                         // aloca a matriz da posição dos moradores
  int** pos = (int**)malloc(Q * sizeof(int*));
    for ( int i = 0; i < 2; i++ ){
      pos[i] = (int*)malloc(2 * sizeof(int));
    }

  return pos;
}
*/
void free_matrix(int linha, int** matriz){           // desaloca a matriz
  for ( int q = 0; q < linha; q++ ){
    free(matriz[q]);
  }
free(matriz);
}




int main(){

  int N, M, Q; /* N x M = dimensões do condomínio // Q = No de moradores que passaram pelo stand de vendas  */
  int i, j;

  scanf("%d%d%d", &N, &M, &Q);

  int** matriz = matrix(N, M);
//  int** pos = matrix_pos(Q);

  for ( int z = 0; z < Q; z++ ){
    scanf("%d%d", &i, &j);
    if (i < N && j < M && i >= 0 && j >= 0) matriz[i][j]++;
  }

  for ( int i = 0; i < N; i++ ){
    for ( int j = 0; j < M; j++ ){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  free_matrix(N, matriz);
//  free_matrix(Q, pos);

  return 0;
}
