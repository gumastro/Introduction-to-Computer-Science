/*
  Programa para gerenciar abas de um navegador, utilizando uma lista duplamente encadeada.

  Gustavo Tuani Mastrobuono
  NºUSP: 10734411

  São Carlos, novembro de 2018
  Universidade de São Paulo (USP) - São Carlos
*/

#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  List L;
  Tab info;
  create(&L);
  int option = 0, pos = 0;
  char search[30];

  while(1) {
    scanf("%d", &option); // lê a opção até que seja '5'

    switch (option) {

      case 1:
        scanf("\n%[^\n]", info.title);
        scanf("%s %d %d %d %d", info.url, &info.date.day, &info.date.month, &info.time.hour, &info.time.min);
        char temp[9];
        sprintf(temp, "%02d%02d%02d%02d", info.date.month, info.date.day, info.time.hour, info.time.min);
        info.number = atoi(temp);
        insert(&L, info);

      break;

      case 2:
        scanf("\n%[^\n]", search);
        scanf("%d ", &pos);
        move(&L, search, pos);

      break;

      case 3:
        radix_sort(&L);
      break;

      case 4:
        show(&L);
      break;

      case 5:
        leave(&L);
        return 0;
      break;
    }
  }

  return 0;
}
