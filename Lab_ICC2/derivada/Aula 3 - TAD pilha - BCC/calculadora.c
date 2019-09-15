#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(int argc, char* argv[]){
    char exp[TamPilha];
    elem x, y;
    Pilha p;
    int i;
    
    printf("digite uma expressao:");
    scanf("%s", exp);
    
    cria_pilha(&p);
    
    i=0;
    while (exp[i] != '\0') {
        if (exp[i] != '/' && exp[i] != '*' &&
            exp[i] != '+' && exp[i] != '-')
            push(&p, (float) exp[i]-'0');
        else {
            pop(&p, &y);
            pop(&p, &x);
            switch (exp[i]) {
                case '+':
                    push(&p,x+y);
                    break;
                case '-':
                    push(&p,x-y);
                    break;
                case '*':
                    push(&p,x*y);
                    break;
                case '/':
                    push(&p,x/y);
                    break;
            }
        }
        i++;
    }
    
    pop(&p, &x);
    printf("O resultado e: %4.2f", x);
    
    return 0;
}
