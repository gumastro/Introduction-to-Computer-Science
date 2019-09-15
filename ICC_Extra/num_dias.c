#include <stdio.h>

int main(){

  int month, year;

  scanf("%d%d", &month, &year);

  if ( month > 12 || month < 0 || year < 0 ) printf("Erro na entrada\n");

  else{

    if ( month == 1 ){
      printf("Janeiro de %d teve 31 dias\n", year);
    }

    if ( month == 2 ){
      if ( year%4 == 0 && ( year%400 == 0 || year%100 != 0 ) ) printf("Fevereiro de %d teve 29 dias\n", year);
      else printf("Fevereiro de %d teve 28 dias\n", year);
    }

    if ( month == 3 ){
      printf("Março de %d teve 31 dias\n", year);
    }

    if ( month == 4 ){
      printf("Abril de %d teve 30 dias\n", year);
    }

    if ( month == 5 ){
      printf("Maio de %d teve 31 dias\n", year);
    }

    if ( month == 6 ){
      printf("Junho de %d teve 30 dias\n", year);
    }

    if ( month == 7 ){
      printf("Julho de %d teve 31 dias\n", year);
    }

    if ( month == 8 ){
      printf("Agosto de %d teve 31 dias\n", year);
    }

    if ( month == 9 ){
      printf("Setembro de %d teve 30 dias\n", year);
    }

    if ( month == 10 ){
      printf("Outubro de %d teve 31 dias\n", year);
    }

    if ( month == 11 ){
      printf("Novembro de %d teve 30 dias\n", year);
    }

    if ( month == 12 ){
      printf("Dezembro de %d teve 31 dias\n", year);
    }

  }

  return 0;
}
