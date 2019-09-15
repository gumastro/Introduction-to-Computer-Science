#define TAM 10 // aumentar e ver tempo, removendo impressao
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abb.h"

int main(void) {
    ABB a;
    elem x;
    int total, sucesso;
    clock_t c_inicial, c_insercao, c_busca, c_remocao;
    
    c_inicial = clock();
    
    cria(&a);
    
    c_insercao = clock();
    for (total = 0; total < TAM;) {
        x = rand() % TAM;
        if (!insercao(&a, x)) {
            total++;
            emOrdem(a);
        }
    }
    printf("Insercao: %0.3lf segundos.\n",(double)(clock()-c_insercao)/CLOCKS_PER_SEC);
    
    c_busca = clock();
    for (total = 0; total < TAM; total++) {
        x = rand() % (2*TAM);
        sucesso = busca(a, x);
        printf("Buscando %d: %s\n", x, (sucesso) ? "encontrado" : "nao encontrado");
    }
    printf("Busca: %0.3lf segundos.\n",(double)(clock()-c_busca)/CLOCKS_PER_SEC);
    
    c_remocao = clock();
    while (!vazia(a)) {
        x = rand() % (2*TAM);
        if (!remocao(&a, x))
            emOrdem(a);
    }
    printf("Remocao: %0.3lf segundos.\n",(double)(clock()-c_remocao)/CLOCKS_PER_SEC);
    
    destroi(&a);
    
    printf("Total: %0.3lf segundos.\n",(double)(clock()-c_inicial)/CLOCKS_PER_SEC);
    
    return 0;
}
