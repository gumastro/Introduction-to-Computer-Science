#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* bigger_than_ten(char* result, int i){

//  if (i-1 >= 0){
    result[i] -= 10;
    result[i+1] = result[i+1] + 1;
//  }

  if (result[i+1] >= 10 && (i+1) >= 0) {
    return bigger_than_ten(result, i+1);
  }

  else return result;

}





// for (int i = strlen(num1) - 1; i >= 0; i--){
//   num1[i] = num1[i] - '0';
//   num2[i] = num2[i] - '0';
//   printf("num1[i = %d]: %d\n", i, num1[i]);
//   result[i] = num1[i] + num2[i];
//   printf("Result: %d: %d\n", i, result[i]);
//
//   while (result[i] >= 10){
//     result[i] -= 10;
//     printf("*R%d: %d\n", i, result[i]%10);
//     result[i-1] = result[i-1] + 1;
//     if (result[i-1] >= 10)
//
//   }





























int main(int arg, char const* argv[]){

  char* num1 = calloc(sizeof(char), 50);
  char* num2 = calloc(sizeof(char), 50);
  char* result = calloc(sizeof(char), 50);
  char* operation = calloc(sizeof(char), 15);

  scanf("%s", operation);

// SOMA
  if (strcmp(operation, "SOMA") == 0){
    // read the first and second numbers
    scanf("%s", num1);
    scanf("%s", num2);
    printf("num1: %s\nnum2: %s\n", num1, num2);


    // set string num1 as the bigger one
    if (strlen(num1) < strlen(num2)){
      char temp[50];
      strcpy(temp, num2);
      strcpy(num2, num1);
      strcpy(num1, temp);
    }
    printf("num1: %s\nnum2: %s\n", num1, num2);

    for (int i = strlen(num1) - 1; i >= 0; i--){
      num1[i] = num1[i] - '0';
      num2[i] = num2[i] - '0';
      printf("num1[i = %d]: %d\n", i, num1[i]);
      result[i] = num1[i] + num2[i];
      printf("Result %d: %d\n", i, result[i]);

      if (result[i] >= 10){
        result = bigger_than_ten(result, i);
        printf("->R%d: %d\n", i, result[i]);

      }
      printf("---R%d: %d\n", i, result[i]);
      printf("--R%d: %d\n", i+1, result[i+1]);
      printf("-R%d: %d\n", i-1, result[i-1]);
    }

    for (int i = strlen(result)-1; i > 0; i--) printf("%d", result[i]);
    printf("\n");

  }

// SUBTRACAO
  if (strcmp(operation, "SUBTRACAO") == 0){


  }

// MULTIPLICACAO
  if (strcmp(operation, "MULTIPLICACAO") == 0){


  }

// DIVISAO
  if (strcmp(operation, "DIVISAO") == 0){


  }


  free(num1);
  free(num2);
  free(result);
  free(operation);

  return 0;
}
