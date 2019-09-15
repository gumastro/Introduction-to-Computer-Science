#include <stdio.h>
#include "lista.h"

int main(int argc, char *argv[]) {
    Lista l;
    
    cria(&l);
    
    insere(&l, 'a');
    insere(&l, 'b');
    insere(&l, 'c');
    insere(&l, 'd');
    
    imprime(l);
    
    //printf("O tamanho da lista eh: %d\n", tamanho(&l));
    printf("O tamanho da lista eh: %d\n", tamanho_rec(l.ini));
    
    //if (esta_na_lista(l, 'b'))
    if (esta_na_lista_rec(l.ini, 'b'))
        printf("O elemento b estah na lista\n");
    else
        printf("O elemento b NAO estah na lista\n");
    
    //if (esta_na_lista(l, 'e'))
    if (esta_na_lista_rec(l.ini, 'e'))
        printf("O elemento e estah na lista\n");
    else
        printf("O elemento e NAO estah na lista\n");
    
    elimina2(&l,'b');
    imprime(l);
    printf("\n\n");
    
    elimina2(&l,'a');
    imprime(l);
    printf("\n\n");
    
    elimina2(&l,'d');
    imprime(l);
    printf("\n\n");
    
    elimina2(&l,'c');
    imprime(l);
    printf("\n\n");
    
    if (elimina2(&l,'c'))
        printf("erro!\n");
    
    finaliza(&l);
    
    return 0;
}
