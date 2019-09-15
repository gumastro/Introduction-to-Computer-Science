#include <stdio.h>
#include "pilha.h"

int main(int argc, char* argv[]){
    elem x;
    Pilha p;
    
    x = 0;
    while(!push(&p,++x));
    
    while(!pop(&p,&x))
        printf("%4.2f\n",x);
    
    return 0;
}
