#include <stdio.h>

int main(){

  int valores1, valores2, valores3, valores4, valores5, valores6; // andr = 0; brun = 1; cris = 2; Andreia, Bruno e Cristina
  int cris, andr, brun;

  scanf("%d %d", &valores1, &valores2);
  scanf("%d %d", &valores3, &valores4);
  scanf("%d %d", &valores5, &valores6);

  andr = valores1 + valores2;
  brun = valores3 + valores4;
  cris = valores5 + valores6;

  if ( valores1 > 6 || valores2 > 6 || valores3 > 6 || valores4 > 6 || valores5 > 6 || valores6 > 6 ) printf("Alguem trapaceou nesse jogo\n");

  else{

    if ( cris > andr && cris > brun ){
      if ( andr > brun ){ // cris > andr > brun
        printf("Cristina\nAndreia\nBruno\n");
      }
      else printf("Cristina\nBruno\nAndreia\n");  // cris > brun > andr
    }

    if ( andr > cris && andr > brun ){
      if ( cris > brun ){ // andr > cris > brun
        printf("Andreia\nCristina\nBruno\n");
      }
      else printf("Andreia\nBruno\nCristina\n");  // andr > brun > cris
    }

    if ( brun > cris && brun > andr ){
      if ( cris > andr ){ // brun > cris > andr
        printf("Bruno\nCristina\nAndreia\n");
      }
      else printf("Bruno\nAndreia\nCristina\n");  // brun > andr > cris
    }

  }


  return 0;
}
