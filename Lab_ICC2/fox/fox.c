#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct _position {
  float x;
  float y;
  float z;

} Position;

bool flag = false;

int main(){

  int holes_num;
  Position rabbit, fox;

  scanf("%d %f %f %f %f", &holes_num, &rabbit.x, &rabbit.y, &fox.x, &fox.y);

  Position holes[holes_num], rabbit_dist[holes_num], fox_dist[holes_num];

  for (int i = 0; i < holes_num; i++){
    scanf("%f %f", &holes[i].x, &holes[i].y);
  }

  for (int i = 0; i < holes_num; i++){
    rabbit_dist[i].x = fabs(rabbit.x - holes[i].x);
    rabbit_dist[i].y = fabs(rabbit.y - holes[i].y);
    fox_dist[i].x = fabs(fox.x - holes[i].x);
    fox_dist[i].y = fabs(fox.y - holes[i].y);
  }

  for (int i = 0; i < holes_num; i++){
    rabbit_dist[i].x = pow(rabbit_dist[i].x, 2);
    rabbit_dist[i].y = pow(rabbit_dist[i].y, 2);
    fox_dist[i].x = pow(fox_dist[i].x, 2);
    fox_dist[i].y = pow(fox_dist[i].y, 2);

    rabbit_dist[i].z = sqrt(rabbit_dist[i].x + rabbit_dist[i].y);
    fox_dist[i].z = sqrt(fox_dist[i].x + fox_dist[i].y);

  }

  for (int i = 0; i < holes_num; i++){
    if ((2*rabbit_dist[i].z)/fox_dist[i].z <= 1){
      printf("O coelho pode escapar pelo buraco (%.3f,%.3f).\n", holes[i].x, holes[i].y);
      flag = true;
      break;
    }
  }
  if (flag == false) printf("O coelho nao pode escapar.\n");


  return 0;
}
