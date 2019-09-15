#include <stdio.h>
#include <math.h>

double func (double v1, double v2, double prodesc){
  double ang = 0, angulo = 0;

  ang = acos((prodesc)/(v1 * v2));
  angulo = (ang * 180)/3.1415926;

  return angulo;
}

int main(){

  int d = 0;
  double vetor1 = 0, vetor2 = 0, vec1 = 0, vec2 = 0, ProdEsc = 0;
  scanf("%d", &d);
  double array1[d];
  double array2[d];


  for (int i = 0; i < d; i++){
    scanf("%lf", &array1[i]);
    vec1 += pow(array1[i], 2);
    // array1[0]^2 + array1[1]^2 + array1[2]^2
  }
  for (int j = 0; j < d; j++){
    scanf("%lf", &array2[j]);
    vec2 += pow(array2[j], 2);
    // array2[0]^2 + array2[1]^2 + array2[2]^2
  }

  vetor1 = sqrt(vec1);
  vetor2 = sqrt(vec2);

  for (int k = 0; k < d; k++){
    // array1[0]*array2[0] + array1[1]*array2[1] + array1[2]*array2[2]
    ProdEsc += array1[k]*array2[k];
  }

  printf ("%.2lf graus.\n", func(vetor1, vetor2, ProdEsc));
  return 0;
}
