#include <stdio.h>

int main(){

  float K = 0; // valor recebido em Kelvin
  float C = 0, F = 0; // valores em Celsius e Fahrenheit, respectivamente

  scanf("%f", &K);

  C = K - 273.00;
  F = (9*(K-273.00)/5)+32;

  printf("%.2f\n%.2f\n", C, F);


  return 0;
}
