#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define SIZE 500

bool num1_bigger = false;
bool num2_bigger = false;
bool changed = false;
bool div_possible = true;
bool ONLY_ZEROS = false;

int* bigger_than_ten(int* result, int i){

  int carry = 0;

  carry = result[i];
  result[i] = result[i]%10;
  carry = (carry - result[i])/10;
  result[i+1] += carry;

  if (result[i+1] >= 10) {
    return bigger_than_ten(result, i+1);
  }

  else return result;
}

int* lower_than_zero(int* result, int i){

  result[i] += 10;
  result[i+1] = result[i+1] - 1;

  if (result[i+1] < 0 && (i+1) >= 0 && (i+1) <= 400){
    return lower_than_zero(result, i+1);
  }

  else return result;
}

int* subt(int* num1_int, int* num2_int, int* result, int length1, int length2){

  for (int i = length2; i >= 0; i--){
    result[i] = num1_int[i] - num2_int[i];
  }
  for (int i = length1; i > length2; i--){
    result[i] = num1_int[i] - result[i];
  }

  for (int i = length1; i >= 0; i--){
    if (result[i] < 0 ){
      result = lower_than_zero(result, i);
    }
  }

  return result;
}

void str_rev(char *str){

  char *start = str;
  char *end = start + strlen(str) - 1;
  char temp;

  while (start < end){
    temp = *start;
    *start = *end;
    *end = temp;

    start++;
    end--;
  }
}

int* addition(char* num1, char* num2, int* num1_int, int* num2_int, int* result){

  // reverse strings so its easier to add
  str_rev(num1);
  str_rev(num2);

  // sets the bigger number as num1
  if (strlen(num1) < strlen(num2)){
    char* temp = (char*)calloc(sizeof(char), SIZE);
    strcpy(temp, num2);
    strcpy(num2, num1);
    strcpy(num1, temp);
    free(temp);
  }

  // save string lengths as we wont be able to strlen an int vector later
  int length1 = 0, length2 = 0;
  length1 = strlen(num1);
  length2 = strlen(num2);

  // converts the char vectors to int vectors
  for (int i = 0; i < strlen(num1); i++){
    num1_int[i] = num1[i] - '0';
  }
  for (int i = 0; i < strlen(num2); i++){
    num2_int[i] = num2[i] - '0';
  }

  free(num1);
  free(num2);

  // make the additions number by number
  for (int i = length2; i >= 0; i--){
    result[i] = num1_int[i] + num2_int[i] + result[i];
    if (result[i] >= 10){
      result = bigger_than_ten(result, i);

    }
  }
  // add the remaning numbers (when strlen(num1) > strlen(num2))
  if (length1 > length2){
    for (int i = length1 - 1; i > length2; i--){
      result[i] = num1_int[i] + result[i];
      if (result[i] >= 10){
        result = bigger_than_ten(result, i);

      }
    }
  }

  return result;
}

int* subtraction(char* num1, char* num2, int* num1_int, int* num2_int, int* result){

  // reverse strings so its easier to subctract
  str_rev(num1);
  str_rev(num2);

  // sets the bigger number as num1
  if (strlen(num1) < strlen(num2)){
    char* temp = (char*)calloc(sizeof(char), SIZE);
    strcpy(temp, num2);
    strcpy(num2, num1);
    strcpy(num1, temp);
    free(temp);
    changed = true;
  }

  // save string lengths as we wont be able to strlen an int vector later
  int length1 = 0, length2 = 0;
  length1 = strlen(num1);
  length2 = strlen(num2);

  // converts the char vectors to int vectors
  for (int i = 0; i < strlen(num1); i++){
    num1_int[i] = num1[i] - '0';
  }
  for (int i = 0; i < strlen(num2); i++){
    num2_int[i] = num2[i] - '0';
  }

  free(num1);
  free(num2);

  // goes through both vectors (big numbers), comparing each algarism and looking for the bigger one
  if (length1 == length2){
    for (int i = 0; i <= length1; i++){
      if (num1_int[i] > num2_int[i]){
        num1_bigger = true;
        break;
      }
      else if (num2_int[i] > num1_int[i]){
        num2_bigger = true;
        break;
      }
    }
  }
  // Includes also the case when the vectors have different sizes
  if (num1_bigger == true || num2_bigger == false){
    // make the subtractions number by number
    for (int i = length2; i >= 0; i--){
      result[i] = num1_int[i] - num2_int[i];
    }
    for (int i = length1; i > length2; i--){
      result[i] = num1_int[i] - result[i];
    }

    for (int i = length1; i >= 0; i--){
      if (result[i] < 0){
        result = lower_than_zero(result, i);
      }
    }
  }

  if (num2_bigger == true){
    // make the subtractions number by number
    for (int i = length2; i >= 0; i--){
      result[i] = num2_int[i] - num1_int[i];
    }
    for (int i = length1; i > length2; i--){
      result[i] = num1_int[i] - result[i];
    }

    // searches the vector for any negative number inside
    for (int i = length1; i >= 0; i--){
      if (result[i] < 0){
        result = lower_than_zero(result, i);
      }
    }
  }

  return result;
}

int* multiplication(char* num1, char* num2, int* num1_int, int* num2_int, int* result){

  // sets the bigger number as num1
  if (strlen(num1) < strlen(num2)){
    char* temp = (char*)calloc(sizeof(char), SIZE);
    strcpy(temp, num2);
    strcpy(num2, num1);
    strcpy(num1, temp);
    free(temp);
    // reverses only the bigger number
    str_rev(num1);
  }

  // save string lengths as we wont be able to strlen an int vector later
  int length1 = 0, length2 = 0;
  length1 = strlen(num1);
  length2 = strlen(num2);

  // converts the char vectors to int vectors
  for (int i = 0; i < strlen(num1); i++){
    num1_int[i] = num1[i] - '0';
  }
  for (int i = 0; i < strlen(num2); i++){
    num2_int[i] = num2[i] - '0';
  }

  free(num1);
  free(num2);

  // make the multiplications number by number

  // for (int i = length2-1; i >= 0; i--){
  //   for (int j = length1-1; j >= 0; j--){
  //     result[j] = num1_int[j] * num2_int[i];
  //     printf("num1_int[%d] = %d\tnum2_int[%d] = %d\n", j, num1_int[j], i, num2_int[i]);
  //     if (result[j] >= 10){
  //       result = bigger_than_ten(result, j);
  //
  //     }
  //   }
  //   // * j+1 in result
  //   if (result[i] >= 10){
  //     result = bigger_than_ten(result, i);
  //
  //   }
  // }
  //  str_rev(num2_int);

  int i = length2 - 1;
  int x = length1 - 1;
  int count = 0;
  while (i >= 0){
    int j = length1 - 1;
    while (j >= 0){
      result[x] = num1_int[j] * num2_int[i] + result[x];
      if (result[x] >= 10){
        result = bigger_than_ten(result, x);

      }
      j--;
      x--;
    }
    count++;
    x = length1 - 1 + count;
    if (result[i] >= 10){
      result = bigger_than_ten(result, i);

    }
    i--;
  }

  return result;
}

// incomplete
int division(char* num1, char* num2, int* num1_int, int* num2_int, int* result){

  // reverse strings so its easier to subctract
  str_rev(num1);
  str_rev(num2);

  // sets the bigger number as num1
  if (strlen(num1) < strlen(num2)){
    char* temp = (char*)calloc(sizeof(char), SIZE);
    strcpy(temp, num2);
    strcpy(num2, num1);
    strcpy(num1, temp);
    free(temp);
    changed = true;
  }

  // save string lengths as we wont be able to strlen an int vector later
  int length1 = 0, length2 = 0, length_dif;
  length1 = strlen(num1);
  length2 = strlen(num2);
  length_dif = length1 - length2;

  // converts the char vectors to int vectors
  for (int i = 0; i < strlen(num1); i++){
    num1_int[i] = num1[i] - '0';
  }
  for (int i = 0; i < strlen(num2); i++){
    num2_int[i] = num2[i] - '0';
  }

  free(num1);
  free(num2);

  int div_count = 0;
  printf("result[0] : %d\nresult[1] : %d\n", num1_int[0], num1_int[1]);
  result = subt(num1_int, num2_int, result, length1, length2);
  printf("result[0] : %d\nresult[1] : %d\n", num1_int[0], num1_int[1]);
  div_count++;

  // printf("result: %d\n", result[0]);
  do {

    result = subt(result, num2_int, result, length1, length2);
    div_count++;
    for (int i = length1; i >= length2; i--){
      if (result[i] == 0) ONLY_ZEROS = true;
      if (result[i] != 0) ONLY_ZEROS = false;
    }
    if (ONLY_ZEROS == true){
      for (int j = length2 - 1  ; j >= 0; j--){
        printf("result[%d = j] = %d\n", j, result[j]);
        if (result[j] >= num2_int[j]){
          div_possible = true;
          break;
        }
        else div_possible = false;
      }
    }
   printf("*div_count = %d\n", div_count);
  } while (div_possible == true);


  printf("div_count = %d\n", div_count);




  return div_count;

}

int main(int arg, char const* argv[]){

  char* num1 = calloc(sizeof(char), SIZE);
  char* num2 = calloc(sizeof(char), SIZE);
  int* num1_int = calloc(sizeof(int), SIZE);
  int* num2_int = calloc(sizeof(int), SIZE);
  int* result = calloc(sizeof(int), SIZE);
  char* operation = calloc(sizeof(char), 15);
  int result_div = 0;

  scanf("%s", operation);

  // ADDITION
  if (strcmp(operation, "SOMA") == 0){

    // read the first and second numbers
    scanf("%s", num1);
    scanf("%s", num2);

    result = addition(num1, num2, num1_int, num2_int, result);

    for (int i = 64; i >= 0; i--) {
      printf("%d", result[i]);
    }
    printf("\n");
  }

  // SUBTRACTION
  if (strcmp(operation, "SUBTRACAO") == 0){

    // read the first and second numbers
    scanf("%s", num1);
    scanf("%s", num2);

    result = subtraction(num1, num2, num1_int, num2_int, result);

    // checks if the number will be negative or not (is negative when length2 > length1 and when num2 > num1)
    if (num2_bigger == true || (num2_bigger == false && changed == true)) printf("-");
    for (int i = 64; i >= 0; i--) {
      printf("%d", result[i]);
    }
    printf("\n");

  }

  // MULTIPLICATION
  if (strcmp(operation, "MULTIPLICACAO") == 0){

    // read the first and second numbers
    scanf("%s", num1);
    scanf("%s", num2);

    result = multiplication(num1, num2, num1_int, num2_int, result);

    for (int i = 126; i >= 0; i--) {
      printf("%d", result[i]);
    }
    printf("\n");
  }

  // DIVISION - NOT DONE
  if (strcmp(operation, "DIVISAO") == 0){

    // read the first and second numbers
    scanf("%s", num1);
    scanf("%s", num2);
    result_div = division(num1, num2, num1_int, num2_int, result);
    printf("%d\n", result_div);

  }

  free(num1_int);
  free(num2_int);
  free(result);
  free(operation);

  return 0;
}
