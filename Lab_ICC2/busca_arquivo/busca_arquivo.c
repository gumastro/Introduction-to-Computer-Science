#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool found = false;

int binary_search(char** text, char* key, int i_begin, int i_end) {

  int middle = (int)(i_begin + i_end)/2;

  if(strcmp(key, text[middle]) == 0 || i_begin >= i_end) {
    return middle;
  }

  if (i_begin >= i_end) {
    return (strcmp(key, text[i_begin]) > 0)?  (i_begin + 1): i_begin;
  }

  if(strcmp(key, text[middle]) > 0) {
    return binary_search(text, key, middle+1, i_end);
  }

  if(strcmp(key, text[middle]) < 0) {
    return binary_search(text, key, i_begin, middle-1);
  }

  return middle;
}

void insertion_sort(char** text, int words) {

  int i, j, pos;
  char key[30];

  for (i = 1; i < words; i++){
    strcpy(key, text[i]);
    j = i-1;

    pos = binary_search(text, key, 0, j);

    while (j >= pos && strcmp(text[j], key) > 0) {
      strcpy(text[j+1], text[j]);
      j--;
    }
    strcpy(text[j+1], key);
  }
}

char** lower_case(char** text, int i) {

  for (int k = 0; k < i; k++){
    for (int j = 0; j < 30; j++){
      text[k][j] = tolower(text[k][j]);
    }
  }

  return text;
}

// char** exclude_punc(char** text, int i, int j) {
//
//   for (int x = j; x < strlen(text[i]); x++) {
//     text[i][x] = text[i][x+1];
//   }
//
//   return text;
// }

int main(int argc, char const *argv[]) {

  // Create and open file
  FILE* fptr;
  char file_name[50];

  scanf("%s", file_name);
  fptr = fopen(file_name, "r");

  if (fptr == NULL) {
    printf("Error! File name is invalid!\n");
    return 0;
  }

  // Scans the words to be searched
  int num_words = 0;
  scanf("%d", &num_words);
  char words_search[num_words][30];
  for (int i = 0; i < num_words; i++) {
    scanf("%s", words_search[i]);
  }

  // Reads the whole file, word by word
  char** text = (char**) calloc(1, sizeof(char*));
  int total_words = 0;

  while (!feof(fptr)) {
    text = (char**) realloc (text, (total_words+1) * sizeof (char*));
    text[total_words] = (char*) calloc (30, sizeof (char));

    fscanf(fptr, "%s", text[total_words]);
    total_words++;
  }
  // number of words : total_words

  text = lower_case(text, total_words);

  // for (int i = 0; i < total_words; i++){
  //   for (int j = 0; j < 20; j++){
  //     if(ispunct(text[i][j]) || text[i][j] == 39 || text[i][j] == '-') text = exclude_punc(text, i, j);
  //   }
  // }

  insertion_sort(text, total_words);

  int position = 0;
  for (int g = 0; g < num_words; g++) {
    int count = 0;
printf("fuck\n");
    position = binary_search(text, words_search[g], 0, total_words);
    printf("oi\n");
    int position_pos = position;
    int position_neg = position-1;
    while (position_pos < total_words && strcmp(text[position_pos], words_search[g]) == 0) {
      count++;
      position_pos++;
      found = true;
    }

    if (found == true) {
      while (position_neg >= 0 && strcmp(text[position_neg], words_search[g]) == 0) {
        count++;
        position_neg--;
      }
    }
    if (position_pos+2 < total_words) printf("%s %d %s %s %s\n", words_search[g], count, text[position_pos], text[position_pos+1], text[position_pos+2]);
    if (position_pos+1 < total_words) printf("%s %d %s %s\n", words_search[g], count, text[position_pos], text[position_pos+1]);
    if (position_pos < total_words) printf("%s %d %s\n", words_search[g], count, text[position_pos]);
    if (position_pos >= total_words) printf("%s %d\n", words_search[g], count);
  }

  // frees the memory and closes the file
  for (int j = 0; j < total_words; j++){
    free(text[j]);
  }
  free(text);
  fclose(fptr);

  return 0;
}
