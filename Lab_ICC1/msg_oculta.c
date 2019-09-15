#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main(){

  FILE *fptr, *fnew;
  char nome_de_arquivo[100];
  char ignore[100][100], palavras[50000][100];
  int i = 0, j = 0;
  int lidas = 0, ign = 0;
  bool flag = false;


  scanf("%s", nome_de_arquivo);

  fptr = fopen(nome_de_arquivo, "r");
  fnew = fopen("saida.txt", "w");

  while ( scanf("%s", ignore[i]) != EOF ) i++;

  while ( fscanf(fptr, "%s", palavras[j]) != EOF ){
    for ( int x = 0; x < i; x++ ){
      if ( strcmp(palavras[j], ignore[x]) == 0 ){
        ign++;
        flag = true;
        break;

      }

    }
    if ( flag == false ) fprintf(fnew, "%s ", palavras[j]);
    lidas++;
    j++;
    flag = false;

  }

  printf("Palavras lidas: %d\nPalavras ignoradas: %d\n", lidas, ign);

  fclose(fptr);
  fclose(fnew);

  return 0;
}
