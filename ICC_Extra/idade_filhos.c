#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]){

  int a, b; // a = soma das idades; b = produtos das idades
  int age1, age2;

  scanf("%d%d", &a, &b);

  age1 = (a + sqrt(a*a-(4*b)))/2;
  age2 = (a - sqrt(a*a-(4*b)))/2;

  printf("As idades sao %d e %d anos.", age2, age1);

  return 0;
}
