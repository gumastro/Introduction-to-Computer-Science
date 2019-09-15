/*
  Programa para verificar o balanceamento de nRec recursos em uma matriz (map) entre 2 jogadores
  Feito por:
    Gustavo Tuani Mastrobuono

  Aluno de Bacharelado de Ciências de Computação
    Universidade de São Paulo (USP) - São Carlos/SP

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void desaloca(int nRec, int** posRec, int** map){
  for ( int q = 0; q < nRec; q++){
    // desaloca as linhas da matriz
    free(posRec[q]);

  }
  // desaloca as colunas da matriz
  free(posRec);

  for ( int q = 0; q < 9; q++){
    // desaloca as linhas da matriz
    free(map[q]);

  }
  // desaloca as colunas da matriz
  free(map);
}

bool founded = false;
double floodfill( int posL, int posC, int** objetivo, int** map, int u ){
  // altera o caminho já preenchido de map de 0 para 2
  map[posL][posC] = 2;

  // verifica se alcançou o objetivo dado pela matriz com as coordenadas
  if (posL == objetivo[u][0] && posC == objetivo[u][1]){

    // altera o valor de bool e sai da função
    founded = true;
  }

  int dist = 1;
  // floodfill que calcula a distancia até o objetivo

  if (!founded && (posL+1 < 9) && map[posL+1][posC] == 0) dist += floodfill(posL+1, posC, objetivo, map, u); // Sul
  if (!founded && (posL-1 >= 0) && map[posL-1][posC] == 0) dist += floodfill(posL-1, posC, objetivo, map, u); // Norte
  if (!founded && (posC-1 >= 0) && map[posL][posC-1] == 0) dist += floodfill(posL, posC-1, objetivo, map, u); // Oeste
  if (!founded && (posC+1 < 9) && map[posL][posC+1] == 0) dist += floodfill(posL, posC+1, objetivo, map, u); // Leste

  return dist;

}

int** posRecc(int nRec){

  // aloca a matriz que armazenará as coordenadas dos recursos
  int **posRec = (int**) malloc (nRec * sizeof(int*) );
  for ( int z = 0; z < nRec; z++){
    posRec[z] = (int*) malloc (2 * sizeof(int));

  }

  for ( int x = 0; x < nRec; x++ ){
    // escaneia as coordenadas dos recursos e as coloca em uma matriz [nRec][2] (nRec nas linhas, X e Y nas colunas)
    scanf("%d", &posRec[x][0]);
    scanf("%d", &posRec[x][1]);

  }

  return posRec;
}

int main(){

  int pos1L = 0, pos1C = 0, pos2L = 0, pos2C = 0;
  double nRec = 0, P = 0;
  int** posRec = NULL;
  double Exp1 = 0, Exp2 = 0, E1 = 0, E2 = 0;

  // aloca a matriz que será o mapa
  int **map = (int**) malloc (9 * sizeof(int*) );
  for ( int k = 0; k < 9; k++){
    map[k] = (int*) malloc (9 * sizeof(int));

  }

  // percorre o mapa e conta quantos 0 (espaços transponíveis) existem
  for ( int l = 0; l < 9; l++ ){
    for ( int c = 0; c < 9; c++ ){
      scanf("%d", &map[l][c]);
      if ( map[l][c] == 0) P++;

    }
  }

  // escaneia a posição inicial dos jogadores 1 e 2
  scanf("%d%d", &pos1L, &pos1C);
  scanf("%d%d", &pos2L, &pos2C);
  // escaneia o número de recursos no mapa
  scanf("%lf", &nRec);

  // função que aloca espaço na memória heap e armazena as coordenadas dos recursos
  posRec = posRecc(nRec);

  for (int u = 0; u < nRec; u++) {
    // calcula a distância do jogador 1 até os recursos
    E1 += floodfill(pos1L, pos1C, posRec, map, u)/P;

    // retoma o valor inicial de bool
    founded = false;
    // altera o caminho já percorrido de map de 2 para 0
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if ( map[i][j] == 2 ) map[i][j] = 0;
      }
    }

    // calcula a distância do jogador 2 até os recursos
    E2 += floodfill(pos2L, pos2C, posRec, map, u)/P;

    // retoma o valor inicial de bool
    founded = false;
    // altera o caminho já percorrido de map de 2 para 0
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if ( map[i][j] == 2 ) map[i][j] = 0;
      }
    }
  }

  // Equação dada pelo exercício
  Exp1 = (1/nRec)*(E1);
  Exp2 = (1/nRec)*(E2);

  printf("%.6lf\n%.6lf\n", Exp1, Exp2);
  if ( fabs(Exp1 - Exp2) < 0.001 ) printf ("O mapa eh balanceado\n");

  else {
    if ( Exp1 > Exp2 ){
      printf("O jogador 2 possui vantagem\n");

    }
    if ( Exp2 > Exp1 ){
      printf("O jogador 1 possui vantagem\n");

    }

  }

  // função para desalocar os espaços utilizados na memória heap
  desaloca(nRec, posRec, map);
  return 0;
}
