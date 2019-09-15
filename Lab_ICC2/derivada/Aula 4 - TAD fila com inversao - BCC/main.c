#include <stdio.h>
#include "fila.h"

int main(int argc, char* argv[]){
    elem x;
    Fila f;
    
    cria(&f);
    
    x = 0;
    while(!entra(&f,++x));
    
    inverte(&f);
    
    while(!sai(&f,&x))
        printf("%d\n",x);
    
    return 0;
}
