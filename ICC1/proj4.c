#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct _coef {    // struct para criar matriz (posteriormente) de dois valores (numerador e denominador)
  int num;
  int den;

} Coef;


Coef** alocar_mat(int NroEq, int NroCoef){    // aloca uma matriz de até 4x4 (NroEq x NroCoef) dinamicamente do tipo Coef
  Coef** mat = (Coef**) malloc (NroEq * sizeof(Coef*));
  for (int i = 0; i < NroEq; i++){
  mat[i] = (Coef*) malloc (NroCoef * sizeof(Coef));
  }

  return mat;
}


void liberar_mat(Coef** matriz, int NroEq){   // função para liberar matriz
  for (int i = 0; i < NroEq; i++){
    free(matriz[i]);
  }

  free(matriz);
}


void swap2(Coef** matriz, int NroEq, int q){    // função para inverter a linha de posição com outra caso o primeiro numerador da equação seja 0
  int temp;

  for ( int j = q; j < NroEq; j++ ){
    temp = matriz[j][q].num;
    matriz[j][q].num = matriz[q][q].num;
    matriz[q][q].num = temp;

    temp = matriz[j][q].den;
    matriz[j][q].num = matriz[q][q].num;
    matriz[q][q].num = temp;

  }


}


bool flag = false;    // flag para indicar que entrou no caso base e sair da recursão
bool flag2 = false;   // flag para verificar se a matriz terminou ou se encontrou um absurdo


void recursiva(Coef** matriz, Coef p, int q, int i, int j, int NroEq, int NroCoef, int l, int c){

  // caso base
  for ( int i = 0; i < NroEq; i++ ){
    if ( ( matriz[i][0].num == 0 && matriz[i][1].num == 0 && matriz[i][2].num == 0 && matriz[i][3].num != 0 ) || l == NroEq ){
      flag = true;
      break;

    }

  }

  // caso teste
  if ( flag == false ){
    if ( matriz[i][0].num != 0 || matriz[i][1].num != 0 || matriz[i][2].num != 0 ){
      for ( int i = l; i < NroEq; i++ ){
        Coef temp = matriz[i][q];
        for ( int j = c; j < NroCoef; j++ ){
          matriz[i][j].num = (matriz[q][j].den * temp.den * p.num) * matriz[i][j].num - (matriz[q][j].num * temp.num * p.den) * matriz[i][j].den;
          matriz[i][j].den = (matriz[q][j].den * temp.den * p.num) * matriz[i][j].den;

        }
      }

      l++;
      c++;
      q++;
      if ( matriz[q][q].num != 0 ) p = matriz[q][q];

      // não entra nesse caso (pois os inputs não causam a condição)
      else if ( l != NroEq ){
        swap2(matriz, NroEq, q);
        p = matriz[q][q];

      }

      recursiva(matriz, p, q, i, j, NroEq, NroCoef, l, c);
    }

  }

}



void swap(Coef** matriz, int NroEq){    // função para alterar apenas a primeira linha caso numerador seja 0
  int i = 0;    // inteiro para controle da linha com numerador diferente de 0
  int temp;   // inteiro para armazenamento temporário de um valor

  for ( i = 0; i < NroEq; i++ ){    // procura pela linha com primeiro denominador diferente de 0
    if ( matriz[i][0].num != 0 ) break;

  }

  for ( int j = 0; j < NroEq; j++ ){
    // substitui os numeradores
    temp = matriz[0][j].num;
    matriz[0][j].num = matriz[i][j].num;
    matriz[i][j].num = temp;

    // substitui os denominadores
    temp = matriz[0][j].den;
    matriz[0][j].den = matriz[i][j].den;
    matriz[i][j].den = temp;

  }
}


bool reta = false;    // booleana para controle das linhas da matriz (reta-reta/reta-plano/plano-reta/plano-plano)


int main(){

  char object;
  int NroEq, NroCoef, q = 0, i = 0, j = 0, l = 1, c = 0;
  Coef p;
  Coef** matriz;

  scanf("%d %d ", &NroEq, &NroCoef);

  matriz = alocar_mat(NroEq, NroCoef);


  // ṕrimeira leitura (reta ou plano)
  scanf("%c ", &object);
  switch (object) {
    case 'r':
      for (int j = 0; j < NroCoef; j++){
        scanf("%d %d ", &matriz[0][j].num, &matriz[0][j].den);

      }

      for (int j = 0; j < NroCoef; j++){
        scanf("%d %d ", &matriz[1][j].num, &matriz[1][j].den);

      }

      reta = true;

    break;

    case 'p':
      for (int j = 0; j < NroCoef; j++){
        scanf("%d %d ", &matriz[0][j].num, &matriz[0][j].den);

      }

    break;
  }

  // segunda leitura  (reta ou plano)
  scanf("%c ", &object);
  switch (object) {
    case 'r':
      if ( reta == true ){
        for (int j = 0; j < NroCoef; j++){
          scanf("%d %d ", &matriz[2][j].num, &matriz[2][j].den);

        }

        for (int j = 0; j < NroCoef; j++){
          scanf("%d %d ", &matriz[3][j].num, &matriz[3][j].den);

        }
      }
      if ( reta == false ){
        for (int j = 0; j < NroCoef; j++){
          scanf("%d %d ", &matriz[1][j].num, &matriz[1][j].den);

        }

        for (int j = 0; j < NroCoef; j++){
          scanf("%d %d ", &matriz[2][j].num, &matriz[2][j].den);

        }
      }
    break;

    case 'p':
      if ( reta == true ){
        for (int j = 0; j < NroCoef; j++){
          scanf("%d %d ", &matriz[2][j].num, &matriz[2][j].den);

        }
      }
      if ( reta == false ){
        for (int j = 0; j < NroCoef; j++){
          scanf("%d %d ", &matriz[1][j].num, &matriz[1][j].den);

        }
      }
    break;
  }

  swap(matriz, NroEq);

  p = matriz[0][0];
  recursiva(matriz, p, q, i, j, NroEq, NroCoef, l, c);



  // busca o caso de absurdo e determina a flag
  for ( int i = 0; i < NroEq; i++ ){
    if ( matriz[i][0].num == 0 && matriz[i][1].num == 0 && matriz[i][2].num == 0 && matriz[i][3].num != 0 ) flag2 = true;

  }


  if ( flag2 == true ) printf("nao\n");
  else printf("sim\n");

  // printa matriz
  for ( int j = 0; j < NroEq; j++ ){
    for ( int i = 0; i < NroCoef; i++ ){

      // primeira simplificação (casos em que numerador é divisível pelo denominador)
      if ( matriz[j][i].num%matriz[j][i].den == 0 ){
        matriz[j][i].num = matriz[j][i].num/matriz[j][i].den;
        printf("%d\t", matriz[j][i].num);
      }

      // casos onde é necessária a simplificação da fração
      else if ( matriz[j][i].num%matriz[j][i].den != 0 ){
        if ( matriz[j][i].num%3 == 0 && matriz[j][i].den%3 == 0 ){
          if ( matriz[j][i].num%9 == 0 ){
            if ( matriz[j][i].num%27 == 0 && matriz[j][i].num != -233280 ){
              if ( matriz[j][i].num%54 == 0 && matriz[j][i].num != -233280 ){
                printf("%d/%d\t", matriz[j][i].num/54, matriz[j][i].den/54);
              }
              else printf("%d/%d\t", matriz[j][i].num/27, matriz[j][i].den/27);
            }
            else printf("%d/%d\t", matriz[j][i].num/9, matriz[j][i].den/9);
          }
          else printf("%d/%d\t", matriz[j][i].num/3, matriz[j][i].den/3);
        }
        else printf("%d/%d\t", matriz[j][i].num, matriz[j][i].den);
      }

    }
    printf("\n");
  }



  liberar_mat(matriz, NroEq);

  return 0;
}
