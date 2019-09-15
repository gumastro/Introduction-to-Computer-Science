#include <stdio.h>
#include <stdlib.h>

int main(){

  int* alocado;
  int resul;

  alocado = malloc(1 * sizeof(int));

  scanf("%d", alocado);

  resul = 2 * (*alocado);

/*
  printf("ALOCADO: %p\n", alocado);
  printf("*ALOCADO: %d\n", *alocado);
  printf("&(*ALOCADO): %p\n", &(*alocado));
  printf("&ALOCADO: %p\n", &alocado);
*/

  printf("Matilda conseguiu produzir %d copos de suco.\n", resul);

  free(alocado);

  return 0;
}
