#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool flag = false;

int main() {

  char* anos;
  int* result;
  int i = -1;

  anos = (char*)calloc(10, sizeof(char));
  result = (int*)calloc(10, sizeof(int));

  do {
  i++;

  } while( scanf("%c", &anos[i]) != EOF );


  // convert

  for (int j = 0; j < i; j++){
    result[j] = (int)anos[j] - '0';

  }

  if (result[i-1] == 9) flag = true;

  for (int k = 1; k < i; k++){
    result[k] = (9 - result[k]);

  }

  result[i-1] = result[i-1]+1;



  // for (int k = 1; k < i; k++){
  //   if (result[k] == 10){
  //     result[k+1] = result[k]+1;
  //     result[k] = 0;
  //   }
  // }


//printf("i = %d\n", i);

if ( i > 1 && flag == false) printf("Faltam ");
if ( i > 1 && flag == true) printf("Falta ");


  for (int k = 1; k < i; k++){
    if (result[k] != 0) printf("%d", result[k]);

  }

  if ( i <= 1 ) printf("Falta 1 ano.\n");
  if ( i > 1 && flag == false) printf(" anos.\n");
  if ( i > 1 && flag == true) printf(" ano.\n");
  //printf("anos[0] = %d\nanos[1] = %d\nanos[2] = %d\nanos[3] = %d\n", result[0], result[1], result[2], result[3]);


  free(anos);
  free(result);

  return 0;
}


//printf("anos[0] = %c\nanos[1] = %c\nanos[2] = %c\nanos[3] = %c\n", result[0], result[1], result[2], result[3]);
