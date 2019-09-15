#include <stdio.h>
#include <stdlib.h>

struct node {
  int data; // chave
  int timer; // tempo
  struct node* prev;
  struct node* next;

} Node;

struct node* head = NULL;
struct node* tail = NULL;

void printList(int rem) {
  struct node* temp = head;
  do {
    if (temp->prev != NULL) printf("[%d,%d,%d] ", temp->data, temp->timer, (temp->prev->timer)-rem );
    if (temp->prev == NULL) printf("[%d,%d] ", temp->data, temp->timer);
    temp = temp->next;
  } while(temp->next != NULL);

  if (temp->next == NULL) {
    if (temp->prev != NULL) printf("[%d,%d,%d] ", temp->data, temp->timer, (temp->prev->timer)-rem );
    if (temp->prev == NULL) printf("[%d,%d] ", temp->data, temp->timer);

  }
  printf("\n");

  return;
}

void RemoveKey(int n) {
  struct node* temp = head;
  struct node* temp2 = head;

  if (n == head->data) {
    head->prev = NULL;
    head = head->next;
    if(head != NULL) head->prev = NULL;

    // set as NULL ---------------------
    free(temp);

    return;
  }

  int i = 0;
  while (temp->data != n) {
    temp = temp->next;
    i++;
  }
  for (int j = 0; j < i-1; j++) {
    temp2 = temp->next;
  }

  if (temp->next != NULL) {
    temp2->next = temp->next;

    // set as NULL ----------------------
    free(temp);

    return;
  }

  if (temp->next == NULL) {
    temp2->next = NULL;

    // set as NULL ---------------------
    free(temp);

    return;
  }

  return;
}

struct node* CreateNewNode(int x, int time_counter) {
  struct node* newNode = (struct node*) malloc(sizeof(Node));
  newNode->data = x;
  newNode->timer = time_counter;
  newNode->prev = NULL;
  newNode->next = NULL;

  return newNode;
}

void InsertTail(int x, int j, int time_counter, int list_counter) {
  struct node* newNode = CreateNewNode(x, time_counter);
  if (head == NULL) {
    head = newNode;
    tail = newNode;

    return;
  }

  tail->next = newNode;

  struct node* temp = head;

  if (j != 0) {
    for (int i = 0; i < (list_counter-j); i++) {
      temp = temp->next;
    }
    newNode->prev = temp;
  }
  else if (j == 0) newNode->prev = NULL;

  tail = newNode;

}

int main(int argc, char const *argv[]) {

  int n, j, time_counter = 0, list_counter = 0, rem = 0;
  // n = chave, j = posiçoes antes
  // time_counter = conta o tempo
  // list_counter = qntd de elementos na lista
  char entrada = 'q';
  struct node* temp = head;

  while (entrada != 'f') {
    scanf(" %c", &entrada);

    switch (entrada) {
      case 'i':
        scanf(" %d %d", &n, &j);
        InsertTail(n, j, time_counter, list_counter);
        time_counter++;
        list_counter++;
      break;

      case 'r':
        scanf(" %d", &n);
        temp = head;
         while (temp->next != NULL) {
          if(temp->prev != NULL && temp->prev->data == n) {
            temp->prev = NULL;
          }
          temp = temp->next;
        }
        if (temp->next == NULL) {
          if(temp->prev != NULL && temp->prev->data == n) {
            temp->prev = NULL;
          }
        }

        RemoveKey(n);
        temp = head;
        time_counter++;
        rem++;
        list_counter--;

      break;
    }
  }

  if (head == NULL) {
    printf("-1\n");
    return 0;
  }
  if (head != NULL) printList(rem);

  return 0;
}
