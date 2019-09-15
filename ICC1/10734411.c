#include <stdio.h>
#include <stdlib.h>

typedef struct _coefs {
  float a;
  float b;
  float c;

} Coefs;

int question2(float i, float j, Coefs numbers, float x, float* results2, int control){

//printf("x = %.2f\tj = %.2f\tcontrol = %d\n", x, j, control);

  if (x <= j){
    results2 = realloc(results2, control);

    results2[control-1] = (numbers.a * x * x) + (numbers.b * x) + numbers.c;
    control = control+1;
    x = x + 0.5;
    question2(i, j, numbers, x, results2, control);
  }

  else return control;

}

void imprime(float* results2, int control, float i){
  float p = i;
//printf("control = %d\n", control);
  for (int q = 0; q < control-1; q++){
    printf("f(%.2f) = %.2f\n", p, results2[q]);
    p = p + 0.5;

  }
}

void inst_speed(Coefs numbers){
  float tempo;
  scanf("%f", &tempo);
  float i = tempo-0.25;

  do {
    printf("f'(%.2f) = %2.f\n", i, ((2*numbers.a*i) + numbers.b));
    i = i+0.25;

  } while (i < tempo+0.5);
}


int main(){

  int item, control;
  float i, j;
  Coefs numbers;
  float* results2 = (float*) malloc( 1 * sizeof(float));


  while(1) {

    scanf("%d", &item);

    switch (item) {

      case 1:
        scanf("%f %f %f", &numbers.a, &numbers.b, &numbers.c);
        printf("f(x) = %.2f x^2 + %.2f x + %.2f\n", numbers.a, numbers.b, numbers.c);

      break;

      case 2:
        scanf("%f %f", &i, &j);
        control = question2(i, j, numbers, i, results2, 1);
//printf("CONTROL** = %d\n", control);

      break;

      case 3:
        imprime(results2, control, i);

      break;

      case 4:
        inst_speed(numbers);

      break;

      case 0:
        free(results2);
        return 0;

      break;
    }
  }

//printf("SAIU\n");


  return 0;
}
