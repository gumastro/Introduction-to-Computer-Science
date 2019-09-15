#include <stdlib.h>
#include <stdio.h>

struct _node* cria_filho();
void insere_node(char* input, int* i, struct _node* pai);
struct _node* junta_arvores(struct _node* tree1, struct _node* tree2);
int percorre_arvore(struct _node* tree, int total, int soma);
