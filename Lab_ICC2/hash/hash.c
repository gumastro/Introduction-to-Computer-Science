#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"



int main(int argc, char const *argv[]) {

  Hash* ha = criaHash(2000);

  int loop = 1;
  char word[35];
  char buffer;

  while (loop) {

    scanf("%c ", &buffer);

    //printf("hey\n");
    if (buffer == 'f')  {
      loop = 0;
      break;
    }

    else if (buffer == 'i') {
  //    printf("aqui\n");
      scanf("%s\n", word);
      insereHash(ha, word);
    //  printf("saiu\n");
    }

    else if (buffer == 'b') {
      scanf("%s\n", word);
      buscaHash(ha, word);
    }

    else if (buffer == 'r') {
      scanf("%s\n", word);
      removeHash(ha, word);
    }
  }

  liberaHash(ha);

  return 0;
}
