#include "tree.h"

struct _node {
  char cor;
  struct _node *filho[4];

};

struct _node* cria_filho() {

  // aloca memória para o novo filho
  struct _node* new = (struct _node*) calloc(1, sizeof(struct _node));

  return new;
}

void insere_node(char* input, int* i, struct _node* pai) {

  pai->cor = (char)input[*i];

  if (input[*i] == 'p') {
//    printf("->filho criado i: %d | %c\n", *i, input[*i]);
    int k = 0;

    while (k < 4) {

      pai->filho[k] = cria_filho();
      *i = *i+1;
      insere_node(input, i, pai->filho[k]);
      k++;
    }

  }

//  printf("filho criado i: %d | %c\n", *i, input[*i]);

  return;
}

struct _node* junta_arvores(struct _node* tree1, struct _node* tree2) {

  if (!tree1) {
    return tree2;
  }

  if (!tree2) {
    return tree1;
  }

  if (tree1->cor == 'f' || tree2->cor == 'f') tree1->cor = 'f';
  else if (tree1->cor == 'p' || tree2->cor == 'p') tree1->cor = 'p';

  int k = 0;
  while (k < 4) {

    tree1->filho[k] = junta_arvores(tree1->filho[k], tree2->filho[k]);
    k++;
  }

  return tree1;
}

int percorre_arvore(struct _node* tree, int total, int soma) {

  if (tree->cor == 'f') {
    total = total+soma;

    return total;
  }

  if (tree->cor == 'p') {
    soma = soma/4;
    for (int i = 0; i < 4; i++) {
      total = percorre_arvore(tree->filho[i], total, soma);
    }
  }

  return total;
}
