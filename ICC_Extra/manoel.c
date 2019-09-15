#include <stdio.h>

int main(){

  double spent = 0;
  double bolos[5];
  double total = 0;
  double profit = 0;

  scanf("%lf", &spent);
  for ( int i = 0; i < 5; i++ ){
    scanf("%lf", &bolos[i]);
    total += bolos[i];

  }
  profit = total - spent;
  printf("%.2lf", profit);

  return 0;
}
