#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool change = false;

typedef struct _data{
  int hi, hf, dh;
  int mi, mf, dm;
  int si, sf, ds;
  char nome[30];
  char nome2[30];
  bool vazio;

} Data;

Data calc_tempo (Data* matriz, int i){

  if ( matriz[i].sf >= matriz[i].si ){
    matriz[i].ds = matriz[i].sf - matriz[i].si;

    if ( matriz[i].mf >= matriz[i].mi ){
      matriz[i].dm = matriz[i].mf - matriz[i].mi;

      if ( matriz[i].hf >= matriz[i].hi ){
        matriz[i].dh = matriz[i].hf - matriz[i].hi;

      }

      else {
        matriz[i].hf = matriz[i].hf + 24;
        matriz[i].dh = matriz[i].hf - matriz[i].hi;

      }

    }

    else {
      matriz[i].hf = matriz[i].hf - 1;
      matriz[i].mf = matriz[i].mf + 60;
      matriz[i].dm = matriz[i].mf - matriz[i].mi;

      if ( matriz[i].hf >= matriz[i].hi ){
        matriz[i].dh = matriz[i].hf - matriz[i].hi;

      }

      else {
        matriz[i].hf = matriz[i].hf + 24;
        matriz[i].dh = matriz[i].hf - matriz[i].hi;
      }
    }
  }

  else  {
    matriz[i].mf = matriz[i].mf - 1;
    matriz[i].sf = matriz[i].sf + 60;
    matriz[i].ds = matriz[i].sf - matriz[i].si;

    if ( matriz[i].mf >= matriz[i].mi ){
      matriz[i].dm = matriz[i].mf - matriz[i].mi;

      if ( matriz[i].hf >= matriz[i].hi ){
        matriz[i].dh = matriz[i].hf - matriz[i].hi;

      }

      else {
        matriz[i].hf = matriz[i].hf + 24;
        matriz[i].dh = matriz[i].hf - matriz[i].hi;

      }

    }

    else {
      matriz[i].hf = matriz[i].hf - 1;
      matriz[i].mf = matriz[i].mf + 60;
      matriz[i].dm = matriz[i].mf - matriz[i].mi;

      if ( matriz[i].hf >= matriz[i].hi ){
        matriz[i].dh = matriz[i].hf - matriz[i].hi;

      }

      else {
        matriz[i].hf = matriz[i].hf + 24;
        matriz[i].dh = matriz[i].hf - matriz[i].hi;
      }

    }

  }

  return matriz[i];
}






int main(){

  char random[30];
  char extra;
  int N; //número de participantes
  scanf("%d", &N);

  Data matriz[N];

  for ( int i = 0; i < N*2; i++ ){
    scanf("%s", random);

    for ( int j = 0; j < N; j++ ){
      if ( strcmp(random, matriz[j].nome) == 0 ){
        strcpy(matriz[j].nome2, random);
        scanf("%d%c%d%c%d", &matriz[j].hf, &extra, &matriz[j].mf, &extra, &matriz[j].sf);
        change = true;
        break;

      }

    }

    if ( change == false ) {
      for ( int k = 0; k < N; k++ ){
        if ( matriz[k].vazio == false ){
          strcpy(matriz[k].nome, random);
          scanf("%d%c%d%c%d", &matriz[k].hi, &extra, &matriz[k].mi, &extra, &matriz[k].si);
          matriz[k].vazio = true;
          break;
        }
      }

    }

    change = false;
  }


/*  for (int i = 0; i < N; i++ ){

    scanf("%s%d%c%d%c%d", matriz[i].nome, &matriz[i].hi, &extra, &matriz[i].mi, &extra, &matriz[i].si);

  }

  for ( int i = 0; i < N; i++ ){

    scanf("%s", matriz[i].nome2);

    for ( int j = 0; j < N; j++ ){

      if( strcmp(matriz[i].nome2, matriz[j].nome) == 0 ){

        scanf("%d%c%d%c%d", &matriz[j].hf, &extra, &matriz[j].mf, &extra, &matriz[j].sf);

      }
    }
  }

*/



for ( int i = 0; i < N; i++){
  //printf("*I %s levou %d:%d:%d\n", matriz[i].nome, matriz[i].hi, matriz[i].mi, matriz[i].si);
  //printf("*F %s levou %d:%d:%d\n", matriz[i].nome, matriz[i].hf, matriz[i].mf, matriz[i].sf);
  matriz[i] = calc_tempo(matriz, i);
  printf("%s levou %02d:%02d:%02d.\n", matriz[i].nome, matriz[i].dh, matriz[i].dm, matriz[i].ds);

}





  return 0;
}
