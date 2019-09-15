#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash_v2.h"

int main(int argc, char const *argv[]) {

  ABB* t = create_hash_table();
  char input;
  int chave, fim = 1;
  int check = 0;

  while (fim == 1) {

    if (fim == 0) return 0;

    scanf("%c ", &input);

    switch (input) {
      case 'i': // chave (inserção da chave)
        scanf("%d", &chave);
        insert(t, chave);
      break;

      case 'b': // chave (busca da chave)
        scanf("%d", &chave);
        (acha(t, chave) == 0)? printf("nao encontrado\n") : printf("encontrado\n");
      break;

      case 'r': // chave (remoção da chave)
        scanf("%d", &chave);
        tira(t, chave);

      break;

      case 'p': // (imprime todas as chaves (inclusive AB em em-ordem))
        for(int i = 0; i < 100; i++) {
          if(t[i].raiz != NULL) {
            if(check == 1)  printf(", ");
            check = 1;
            emOrdem(t[i]);

          }
        }
        printf("\n");
      break;

      case 'f': // (finaliza)
        fim = 0;
      return 0;

    }

  }



  return 0;
}
