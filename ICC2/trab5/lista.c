#include "lista.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct _node {
  Tab tab;
  struct _node *next;
  struct _node *prev;

};

/*  create()
*     Define os valores da lista como nulos/0.
*   @parâmetros:
*     List *L = ponteiro para lista
*   @return:
*     void
*/
void create(List *L) {
  L->beg = NULL;
  L->end = NULL;
  L->num_elems = 0;

  return;
}

/*  insert()
*     Função que insere um novo elemento no fim da lista de abas
*   @parâmtros:
*     List *L = ponteiro para lista
*     Tab info = informação a ser inserida na aba
*   @return:
*     int = 1 em caso de erro | 0 caso funcional
*/
int insert(List *L, Tab info) {
  Node *new;
  new = (Node*) malloc(sizeof(Node));

  if (new == NULL) {

    return 1;
  }

  // Atribui valores ao new
  strcpy(new->tab.title, info.title);
  strcpy(new->tab.url, info.url);
  new->tab.date.day = info.date.day;
  new->tab.date.month = info.date.month;
  new->tab.time.hour = info.time.hour;
  new->tab.time.min = info.time.min;
  new->tab.number = info.number;
  new->next = NULL;
  new->prev = NULL;

  if (L->beg == NULL) {
    L->beg = new;
    L->end = new;

  }

  else {
    new->prev = L->end;
    L->end->next = new;

  }

  L->end = new;
  L->num_elems++;

  return 0;
}

/* show()
*   Função que imprime a lista do começo ao fim
*  @parâmetros:
*   List *L = ponteiro para lista
*  @return:
*   void
*/
void show(List *L) {
  Node *aux;
  aux = L->beg;

  while (aux != NULL) {
    printf("%s %s %02d/%02d %02d:%02d\n", aux->tab.title, aux->tab.url, aux->tab.date.day, aux->tab.date.month, aux->tab.time.hour, aux->tab.time.min);

    aux = aux->next;
  }
  printf("\n");

  return;
}

/*  move()
*     Função que altera a posição de uma aba
*   @parâmetros:
*     Lista *L = ponteiro para lista
*     char *search = palavra a ser encontrada na lista
*     int pos = nova posição em que a aba será posicionada
*   @return:
*     void;
*/
void move(List *L, char *search, int pos){
  Node *change, *aux;
  int found = 0;
  change = L->beg;

  while (change != NULL) {

    if (strcmp(search, change->tab.title) == 0) {
      found = 1;
      break;
    }

    change = change->next;
  }

  if (found == 0) return;

  if (change->prev != NULL) {
    change->prev->next = change->next;
  }
  else L->beg = change->next;

  if (change->next != NULL) {
    change->next->prev = change->prev;
  }
  else L->end = change->prev;

  if (pos >= L->num_elems) {
    L->end->next = change;
    change->prev = L->end;
    change->next = NULL;
    L->end = change;

    return;
  }

  aux = L->beg;
  for (int i = 1; i < pos; i++) {
    aux = aux->next;
  }

  if (aux->prev != NULL) {
    aux->prev->next = change;
  }
  else L->beg = change;

  if (aux->next == NULL) {
    L->end = aux;
  }

  change->prev = aux->prev;
  change->next = aux;
  aux->prev = change;

  return;
}

/*  radix_sort()
*     Função que ordena as abas por meio do radix + bucket sort
*   @parâmetros:
*     List *L = ponteiro para lista
*   @return:
*     void;
*/
void radix_sort(List *L) {
  int num_elems = L->num_elems;
  int i, expo = 1;
  Node **b;
  Node *aux = L->beg;
  int biggest = L->beg->tab.number;

  b = (Node**) calloc(num_elems, sizeof(Node*));

  while (aux != NULL) {
    if (aux->tab.number > biggest) {
      biggest = aux->tab.number;
    }
    aux = aux->next;
  }

  while (biggest/expo > 0) {
    int bucket[10] = { 0 };
    aux = L->beg;

  	for (i = 0; i < num_elems; i++) {
  	  bucket[(aux->tab.number/expo)%10]++;
      aux = aux->next;
    }

  	for (i = 1; i < 10; i++) {
  	  bucket[i] += bucket[i-1];
    }

    aux = L->end;
  	for (i = num_elems - 1; i >= 0; i--) {
  	  b[--bucket[(aux->tab.number/expo)%10]] = aux;
      aux = aux->prev;
    }

  	for (i = 0; i < num_elems; i++) {
  	  aux = b[i];

      if (i == 0) {
        L->beg = aux;
        aux->prev = NULL;
      }
      else {
        aux->prev = b[i-1];
      }

      if (i == num_elems-1) {
        L->end = aux;
        aux->next = NULL;
      }
      else {
        aux->next = b[i+1];
      }

      aux = aux->next;
    }

  	expo *= 10;
  }

  free(b);
}

/*  leave()
*     Função que desaloca toda memória
*   @parâmetros:
*     List *L = ponteiro para lista
*   @return:
*     void;
*/
void leave(List *L) {
  Node *aux, *ant;
  ant = L->beg;
  aux = L->beg->next;

  while (aux != NULL) {
    free(ant);
    ant = aux;
    aux = aux->next;
  }
  free(L->end);

  return;
}
