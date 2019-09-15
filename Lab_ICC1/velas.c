#include <stdio.h>
#include <stdlib.h>



int main(){

  int candles;
//  int save = 0;
  scanf("%d", &candles);
  int matriz[candles];

  int* count = (int*)calloc(1000000, sizeof(int));

  for (int i = 0; i < candles; i++){
    scanf("%d", &matriz[i]);
    count[matriz[i]]++;

  }

  // for (int i = 0; i < candles; i++){
  //   for (int j = 0; j < candles; j++){
  //     if(matriz[i][0] == matriz[j][1]){
  //       count[i]++;
  //
  //     }
  //   }
  // }
  int temp = count[0];
//  save = matriz[0][0];

  for (int i = 0; i < 1000000; i++){
    if (count[i] > temp){
      temp = count[i];
//    save = matriz[i][0];
    }
  }

  if (temp != 1) printf("%d desejos realizados.\n", temp);
  if (temp == 1) printf("%d desejo realizado.\n", temp);

  free(count);

  return 0;
}
