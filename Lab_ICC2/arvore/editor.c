#include <stdio.h>
#include "arvore.h"

int main(int argc, char const *argv[]) {

  ABB arvore;
  char input;
  int j, fim = 1;

  cria(&arvore);

  while (fim == 1) {

    if (fim == 0) return 0;

    scanf("%c ", &input);

    switch (input) {
      case 'I': // j (inserção da chave)
        scanf("%d", &j);
        if(insercao(&arvore, j) == 1) printf("Chave existente\n");
        // imprime(arvore);
      break;

      case 'D': // j (remoção da chave)
        scanf("%d", &j);
        (remocao(&arvore, j) == 0)? printf("%d\n", j) : printf("Nao encontrado\n");
        // imprime(arvore);
      break;

      case 'B': // j (busca da chave)
        scanf("%d", &j);
        (busca(arvore, j) == 1)? printf("Encontrado\n") : printf("Nao encontrado\n");
      break;

      case 'N': // (imprime in-ordem)
        printf("InOrdem: ");
        emOrdem(arvore);
      break;

      case 'E': // (imprime pre-ordem)
        printf("PreOrdem: ");
        preOrdem(arvore);
      break;

      case 'O': // (imprime pos-ordem)
        printf("PosOrdem: ");
        posOrdem(arvore);
      break;

      case 'L': // (imprime em largura)
        printf("Largura: ");
        printElements(arvore);
      break;

      case 'Y': // (imprime de todas as maneiras)
        printf("InOrdem: ");
        emOrdem(arvore);
        printf("PreOrdem: ");
        preOrdem(arvore);
        printf("PosOrdem: ");
        posOrdem(arvore);
        printf("Largura: ");
        printElements(arvore);
        // printf("Árvore: \n");
        // printf("-------------------\n");
        // imprime(arvore);
        // printf("-------------------\n");
      break;

      case 'X': // (Finaliza a série de operações)
        destroi(&arvore);
        fim = 0;
      return 0;

    }

  }

  return 0;
}
