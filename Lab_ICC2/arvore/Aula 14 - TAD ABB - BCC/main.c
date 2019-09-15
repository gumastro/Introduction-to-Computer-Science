// trocar TAD ABB para char
#include <stdio.h>
#include "abb.h"

int main(void) {
    ABB a;

    cria(&a);

    insercao(&a, 'K');
    insercao(&a, 'E');
    insercao(&a, 'C');
    insercao(&a, 'P');
    insercao(&a, 'G');
    insercao(&a, 'F');
    insercao(&a, 'A');
    insercao(&a, 'T');
    insercao(&a, 'M');
    insercao(&a, 'U');
    insercao(&a, 'V');
    insercao(&a, 'X');
    insercao(&a, 'Z');

    imprime(a);

    printf("Altura: %d\n", altura(a));

    printf("Pre-ordem: ");
    preOrdem(a);

    printf("Em-ordem: ");
    emOrdem(a);

    printf("Pos-ordem: ");
    posOrdem(a);

    remocao(&a, 'Z');
    printf("Removendo o Z: ");
    emOrdem(a);

    remocao(&a, 'V');
    printf("Removendo o V: ");
    emOrdem(a);

    remocao(&a, 'K');
    printf("Removendo o K: ");
    emOrdem(a);

    destroi(&a);

    return 0;
}
