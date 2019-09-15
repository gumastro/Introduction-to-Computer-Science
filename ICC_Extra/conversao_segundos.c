#include <stdio.h>

int main(){

  int inic = 0;
  int hours = 0, minutes = 0, sec = 0, resto_minutos = 0;

  scanf("%d", &inic);

  if ( inic/3600 >= 1 ){
    hours = inic/3600;

    resto_minutos = inic - (hours*3600);
    minutes = resto_minutos/60;
    sec = resto_minutos - (60*minutes);

  }

  if ( inic < 3600){
    minutes = inic/60;
    resto_minutos = 60*minutes;
    sec = inic - resto_minutos;

  }

  printf("%dh %dm %ds\n", hours, minutes, sec);

  return 0;
}
