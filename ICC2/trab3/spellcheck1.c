/*
  Programa para encontrar erros de digitação em tweets, utilizando como base livros de referência.
  Feito por: Gustavo Tuani Mastrobuono
  No USP: 10734411

  USP - São Carlos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool tweet = false;
bool no_tweets = true;

/*  binary_search()
*     Função que realiza uma busca binária
*   @parâmetros:
*     char** arr = array de strings que será buscado
*     int beg = início do array
*     int end = fim do array
*     char* x = elemento a ser buscado
*   @return:
*     int = posição em que o elemento se encontra
*           ou -1 caso não haja o elemento em arr
*/
int binary_search(char** arr, int beg, int end, char* x) {
  if (end >= beg) {
    int mid = beg + (end - beg)/2;

    // encontrou o elemento
    if (strcasecmp(arr[mid], x) == 0) {
      return mid;
    }

    // o elemento está do inicio para a metade
    if (strcasecmp(arr[mid], x) > 0) {
      return binary_search(arr, beg, mid-1, x);
    }

    // o elemento está da metade para o fim
    return binary_search(arr, mid+1, end, x);
  }

  return -1;
}

/*  merge_sort()
*     Função que organiza um array de strings em ordem alfabética de forma recursiva, pelo método de dividir e conquistar
*   @parâmetros:
*     char** v = array de strings que será ordenado
*     int ini = inicio do array
*     int fim = fim do array
*   @return:
*     void
*/
void merge_sort (char** v, int ini, int fim) {

  // caso base (vetor de 1 elemento)
	if (fim <= ini)  return;

  int centro;
  // metade da direita maior
  if ((fim+ini)%2 != 0 ) centro = (int) ((fim+ini)/2.0);
  if ((fim+ini)%2 == 0 ) centro = (int) ((fim+ini-1)/2.0);

  // Divisão do array em subseguimentos
  merge_sort(v, ini, centro);
  merge_sort(v, centro+1, fim);

  // Conquista - ordenação dos arrays
	char** aux = (char**) malloc(sizeof(char*) * (fim-ini+1));
  for (int z = 0; z < (fim-ini+1); z++) {
    aux[z] = (char*) malloc(sizeof(char) * 35);
  }

	int i = ini;
	int j = centro+1;
 	int k = 0;

  // compara elementos das duas listas
	while (i <= centro && j <= fim) {
    if (strcasecmp(v[i], v[j]) <= 0) {
      strcpy(aux[k], v[i]);
      i++;
    }
    else {
      strcpy(aux[k], v[j]);
      j++;
    }

		k++;
	}

  // copia o resto da lista 1
	while (i <= centro) {
    strcpy(aux[k], v[i]);
    i++;
    k++;
	}

  // copia o resto da lista 2
	while (j <= fim) {
    strcpy(aux[k], v[j]);
    j++;
    k++;
	}

  // volta os valores do array auxiliar para o array principal
	for (i = ini; i <= fim; i++) {
    strcpy(v[i], aux[i-ini]);
	}

  for (int z = 0; z < (fim-ini+1); z++) {
    free(aux[z]);
  }
	free(aux);
}

int main(int argc, char const* argv[]) {

  FILE* fptr_dic;
  FILE* fptr_tweet;

  char* buffer = (char*) malloc (sizeof(char) * 500000);

  // alocando espaço para o dicionário com palavras repetidas (dictionary) e sem repetição (words)
  char** dictionary = (char**) malloc(sizeof(char*) * (1000000));
  for (int z = 0; z < 1000000; z++) {
    dictionary[z] = (char*) malloc(sizeof(char) * 35);
  }
  char** words = (char**) malloc(sizeof(char*) * (1000000));
  for (int z = 0; z < 1000000; z++) {
    words[z] = (char*) malloc(sizeof(char) * 35);
  }

  char file_name_dic[50];   // nome do arquivo dicionário
  char file_name_tweet[50]; // nome do arquivo tweet

  scanf("%s", file_name_dic);
  scanf("%s", file_name_tweet);

  // ------------------------------------------------ DICTIONARY

  fptr_dic = fopen(file_name_dic, "r");
  // verifica se o arquivo existe
  if (fptr_dic == NULL) {
    printf("No tweets to check\n");
    return -1;
  }

  // lê as palavras do livro base utilizadas no dicionário, sem pontuação
  int i = 0;
  while (!feof(fptr_dic)) {
    fscanf(fptr_dic, "%34[a-zA-Z]%*[^a-zA-Z]", dictionary[i]);
    i++;
  }

  // organiza as palavras em ordem alfabética
  merge_sort(dictionary, 0, i-1);

  // retira as palavras repetidas
  int u = 0, s = 0;
  while (u < i-1) {
    if (strcasecmp(dictionary[u], dictionary[u+1]) == 0) {
      u++;
    }
    else {
      strcpy(words[s], dictionary[u]);
      u++;
      s++;
    }
  }

  // ------------------------------------------------ TWEET

  fptr_tweet = fopen(file_name_tweet, "r");
  // verifica se o arquivo existe
  if (fptr_tweet == NULL) {
    printf("No tweets to check\n");
    return -1;
  }

  // lê o tweet até encontrar " "text:" "
  while (!feof(fptr_tweet)) {
    fscanf(fptr_tweet, "%s", buffer);
    if (strcmp(buffer, "\"text\":") == 0) {
      no_tweets = false;
      tweet = true;
      // lê o conteúdo dentro de text:, sem pontuação, até encontrar "truncated"
      while (strcmp(buffer, "truncated") != 0) {
        fscanf(fptr_tweet, "%*[^a-zA-Z]%[a-zA-Z]", buffer);
        // busca pelas palavras tweetadas no dicionário
        if (binary_search(words, 0, s, buffer) == -1 && strcmp(buffer, "truncated") != 0) printf("%s ", buffer);
      }
    }

    if (tweet == true) {
      printf("\n");
      tweet = false;
    }
  }

  // caso em que nenhum tweet ("text":) foi encontrado
  if (no_tweets == true) {
    printf("No tweets to check\n");
  }

  // libera a memória alocada e fecha os arquivos abertos
  for (int z = 0; z < 1000000; z++) {
    free(dictionary[z]);
  }
  free(dictionary);
  for (int z = 0; z < 1000000; z++) {
    free(words[z]);
  }
  free(words);
  free(buffer);

  fclose(fptr_dic);
  fclose(fptr_tweet);

  return 0;
}
