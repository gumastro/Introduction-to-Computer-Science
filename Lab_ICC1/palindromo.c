#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int recursiva(char* str, int i){

  char k = scanf("%c ", &str[i]);

  if ( str[i] == '\n' || str[i] == '\r'){    // \n deve ser final do input
    str[i] = '\0';
  }

  if ( k == EOF ){
    return i;
  }

  if (str[i] == ' '){   // espaços serão ignorados
    i = recursiva(str, i);
  }

  else {
    i++;
    i = recursiva(str, i);
  }

  return i;

}


int main(){

  char str[1024];
  int i = 0;
  FILE *arq;

  arq = fopen("teste.txt", "w");

  i = recursiva(str, i);
  char inverse[i];

  for ( int h = 0; h < i; h++ ){
    str[h] = tolower(str[h]);
  }

  int y = i;    // ignora o primeiro caracter (\0)
  for (int x = 0; x < i; x++){    // for para inverter a string
    inverse[x] = str[y-1];
    y = y-1;

  }
  inverse[i] = '\0';
  str[i] = '\0';

  // compara as duas strings
  if(strcmp(str, inverse) == 0) printf("PALINDROMO!\n");
  else printf("Nao e palindromo. Ufa!\n");
  fprintf(arq, "%s\n%s", str, inverse);

  fclose(arq);

  return 0;
}
