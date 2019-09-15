#include <stdio.h>

int main() {
  int n = 0, m = 0;
  int prox = 0;

    // n = linhas ; m = colunas
  scanf("%d %d ", &n, &m);

  char vetor[n][m];

  for (int i = 0; i < n; i++){
    for (int k = 0; k < m; k++){
      scanf("%c ", &vetor[i][k]);
    }
  }

  for (int j = 0; j < n; j++){
    for (int l = 0; l < m; l++){
      if (vetor[j][l] == '.'){
        prox = 0;
        if ((j-1) >= 0 && (l-1) >= 0 && vetor[j-1][l-1] == '*'){
        prox++;
        }
        if ((j-1) >= 0 && vetor[j-1][l] == '*'){
        prox++;
        }
        if ((j-1) >= 0 && (l+1) < m && vetor[j-1][l+1] == '*'){
        prox++;
        }
        if ((l-1) >= 0 && vetor[j][l-1] == '*'){
        prox++;
        }
        if ((l+1) < m &&vetor[j][l+1] == '*'){
        prox++;
        }
        if ((j+1) < n && (l-1) >= 0 && vetor[j+1][l-1] == '*'){
        prox++;
        }
        if ((j+1) < n && vetor[j+1][l] == '*'){
        prox++;
        }
        if ((j+1) < n && (l+1) < m && vetor[j+1][l+1] == '*'){
        prox++;
        }
        // vetor[j][l] = prox;
        printf("%d ", prox);
      }
      else printf("* ");
    }
  printf("\n");
  }

/*  for (int x = 0; x < n; x++){
    for (int z = 0; z < m; z++){
      if (vetor[x][z] == 42) printf("* ");
      else printf("%d ", vetor[x][z]);
    }
    printf("\n");
  }
*/
  return 0;
}
