#include <stdio.h>
#include <stdlib.h>
#include "d_list.h"

struct node {
  int data;
  struct node* prev;
  struct node* next;

};

Node* head;
Node* tail;

Node* CreateNewNode(int x) {
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->data = x;
  newNode->prev = NULL;
  newNode->next = NULL;

  return newNode;
}

void InsertHead(int x) {
  Node* newNode = CreateNewNode(x);
  if (head == NULL) {
    head = newNode;
    tail = newNode;

    return;
  }

  head->prev = newNode;
  newNode->next = head;
  head = newNode;
}

void InsertTail(int x) {
  Node* newNode = CreateNewNode(x);
  if (head == NULL) {
    head = newNode;
    tail = newNode;

    return;
  }

  tail->next = newNode;
  newNode->prev = tail;
  tail = newNode;

}

void RemovePos(int n) {
  Node* temp = head;
  Node* store_next;
  Node* store_prev;

  if (n == 1) {
    head = head->next;
    head->prev = NULL;
    free(temp);

    return;
  }


  while (temp->data != n) {
    temp = temp->next;
  }
  if (temp->next != NULL) {
    store_next = temp->prev;
    store_prev = temp->next;
    store_next->prev = store_prev;
    store_prev->next = store_next;
    free(temp);

    return;
  }

  if (temp->next == NULL) {
    store_prev = temp->prev;
    store_prev->next = NULL;
    free(temp);

    return;
  }

  return;
}

void RemoveAll() {
  Node* temp = head;
  while(temp->next != NULL) {
    temp = head;
    RemovePos(1);
  }

  return;
}

int ListSize() {
  int size = 0;
  Node* temp = head;
  while (temp->next != NULL) {
    size++;
    temp = temp->next;
  }

  return size;
}
