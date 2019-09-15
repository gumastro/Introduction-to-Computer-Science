#include <stdio.h>

int main(){

  int N = 3;
  float* endf;
  double* endd;

  double vet[4] = {4.4, 3.3, 2.2, 1.1};
  float mat[2][2] = {{4.0, 3.0}, {2.0, 1.0}};

  endd = vet+1;
  endf = (float*) mat; //converte endereço float** em float*

printf("%p\n", endf );
printf("%c\n%p\n", ((char*)endf)+2, ((char*)endf)+2);

  return 0;
}
