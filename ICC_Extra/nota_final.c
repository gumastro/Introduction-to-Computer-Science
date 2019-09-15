#include <stdio.h>

int main(){

   float grade1 = 0, grade2 = 0, grade3 = 0;
  // grade1 = 35% da nota final
  // grade2 = 35% da nota final
  // grade3 = 30% da nota final

  scanf("%f%f%f", &grade1, &grade2, &grade3);

  grade1 = grade1*0.35;
  grade2 = grade2*0.35;
  grade3 = grade3*0.30;

  printf("%f\n", grade1+grade2+grade3);

  return 0;
}
