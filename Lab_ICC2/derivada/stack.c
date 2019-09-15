#include "stack.h"

// Cria Pilha
void create_stack(Stack* s) {
  s->top = -1;
  return;

}

// Adiciona elemento na Pilha
long long push(Stack* s, long long x) {
  if (s->top == Stack_SIZE-1) {
    return 1;
  }
  s->top++;
  s->array[s->top] = x;
  return 0;

}

// Verifica se a Pilha está vazia
long long is_empty(Stack* s) {
  return s->top == -1;

}

// Retira elemento da Pilha
long long pop(Stack* s, long long* x) {
  if(is_empty(s))
    return 1;
  *x = s->array[s->top];
  s->top--;
  return 0;

}

// Verifica o elemento no topo da Pilha
long long see_top(Stack* s, long long* error) {
  if(is_empty(s)) {
    *error = 1;
    return 1;
  }
  *error = 0;
  return s->array[s->top];
}

// Esvazia a Pilha
void empty(Stack* s) {
  create_stack(s);
  return;

}
