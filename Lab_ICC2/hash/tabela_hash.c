#include "tabela_hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct hash {
  int qntd, TABLE_SIZE;
  char** itens;
};

Hash* criaHash(int TABLE_SIZE) {
  Hash* ha = (Hash*) malloc(sizeof(Hash));

  if (ha != NULL) {
    ha->TABLE_SIZE = TABLE_SIZE;
    ha->itens = (char**) malloc (TABLE_SIZE * sizeof(char*));
    for (int i = 0; i < 2000; i++) {
      ha->itens[i] = (char*) malloc (35 * sizeof(char));
    }

    ha->qntd = 0;

    return ha;
  }
  return NULL;
}

void liberaHash(Hash* ha) {
  if (ha != NULL) {
    int i;
    for (i = 0; i < ha->TABLE_SIZE; i++) {
      if (ha->itens[i] != NULL) {
        free(ha->itens[i]);
      }
      free(ha->itens);
      free(ha);
    }
  }
}

// posição na tabela hash/ no vetor
unsigned long long valorString(char *str) {
  int i;
  unsigned long long valor = 7;
  int tam = strlen(str);
  for (i = 0; i < tam; i++) {
    valor = 31 * valor * (int) str[i];
  }
  return (valor%2000);

}

int insereHash(Hash* ha, char* word) {
  if (ha == NULL || ha->qntd == ha->TABLE_SIZE) {
    return 0;
  }

  unsigned long long pos = valorString(word);
  // printf("oi\n");
  // printf("ha->itens[pos]: %s    word: %s    pos: %llu\n", ha->itens[pos], word, pos);

  strcpy(ha->itens[pos], word);

  return 1;
}

void buscaHash(Hash* ha, char* word) {
  unsigned long long pos = valorString(word);

  if (strcmp(word, ha->itens[pos])) {
    printf("nao encontrado\n");
  }
  else printf("encontrado\n");

  return;
}

void removeHash(Hash* ha, char* word) {
  unsigned long long pos = valorString(word);
  free(ha->itens[pos]);

  return;
}
