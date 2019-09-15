#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

  int D = 0; // número de dias p/ processar todos os arquivos
  int R = 0; // qntd de recursos que podem ser utilizados durante o dias
  int T = 0; // qntd de arquivos que receberá no dia
  int* line;
  int* pointer;
  int dif = 0;
  bool my_bool = false;

  scanf("%d%d", &D, &R);

  scanf("%d", &T);
  line = (int*) malloc ( T * sizeof(int) );
  for ( int i = 0; i < T; i++ ){
    scanf("%d", &line[i]);

  }

  int sum = 0;
  for ( int i = T-1; i >= 0; i-- ){

    sum += line[i];
printf("Line[%d]: %d\nSUM = %d\nDIF = %d\n", i, line[i], sum, dif);
    if ( sum >= R ){
      if ( sum > R ){
        i++;
        dif = i;
printf("SUM = %d\nDIF = %d\n", sum, dif);
        if ( dif == 1 ) printf("Resta 1 arquivo.\n");
        if ( dif != 1 ) printf ("1 - Restam %d arquivos.\n", dif);
        break;
      }

      if ( sum == R && i != 0 ){
        dif = i;
        if ( dif != 1 ) printf("2 - Restam %d arquivos.\n", dif);
        break;
      }

      if ( sum == R && dif == 0 ){
        dif = i;
        printf("Todos os arquivos foram concluidos.\n");
        break;
      }
printf("SUM = %d\nDIF = %d\n", sum, dif);

    }

  }
printf("SUM = %d\n", sum);

  if ( sum < R ) printf("Todos os arquivos foram concluidos.\n");

  sum = 0;



  for ( int i = 1; i < D; i++){
    scanf("%d", &T);
printf("D = %d\nT = %d\ndif = %d\nLINE[DIF]= %d\n&LINE[DIF] = %d\n& = %p\n\n", D, T, dif, line[dif], &line[dif], &line[dif]);
    line = (int*) realloc ( line, T * sizeof(int) );

    for ( int j = dif; j < T; j++ ){
      scanf("%d", &line[j]);
    }







printf("line = %d\n", *line);
    for ( int z = T-1; z >= 0; z-- ){
      my_bool = false;

      sum += line[z];
printf("*line[%d]: %d\nSUM = %d\nDIF = %d\n", z, line[z], sum, dif);
      if ( sum >= R ){
        if ( sum > R ){
          z++;
          dif = z;
printf("SUM = %d\nDIF = %d\n", sum, dif);
          if ( dif == 1 ) printf("*Resta 1 arquivo.\n");
          if ( dif != 1 ) printf ("*1 - Restam %d arquivos.\n", dif);
          my_bool = true;
          break;
        }

        if ( sum == R && z != 0 ){
          dif = z;
          if ( dif != 1 ) printf("*2 - Restam %d arquivos.\n", dif);
          my_bool = true;
          break;
        }

        if ( sum == R && dif == 0 ){
          dif = z;
          printf("*Todos os arquivos foram concluidos.\n");
          my_bool = true;
          sum = 0;
          break;
        }
      }


      // sum += line[z];
      // if ( sum > R ){
      //   dif = z;
      //   printf("Restam %d arquivos.\n", dif);
      //   break;
      //
      // }

    }
    printf("%d\n", sum);
    if ( !my_bool && sum < R ) printf("**Todos os arquivos foram concluidos.\n");

  }


free(line);
  return 0;
}
