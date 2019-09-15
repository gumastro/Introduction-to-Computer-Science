#include <stdio.h>
#include <math.h>
#include "stack.h"

int main(int argc, char const *argv[]) {

  long long base, expo;
  Stack s1, s2;
  long long spot_X = 0, count = 0;
  scanf("%lli", &spot_X);

  create_stack(&s1);

  while(scanf("%lli %lli", &base, &expo) != EOF) {
    push(&s1, base);
    push(&s1, expo);
    count++;

  }

  create_stack(&s2);
  long long x = 0, y = 0, z = 0, add = 0;
  long long aux_Y[count*2];

  for (int i = count-1; i >= 0; i--) {
    pop(&s1, &y);
    pop(&s1, &x);
    aux_Y[add] = x;
    aux_Y[add+1] = y;
    add+=2;
    z = x*y;
    y--;
    push(&s2, y);
    push(&s2, z);
  }
  long long array[count*2];
  long long pos = 0;
  while (is_empty(&s2) != 1) {
    pop(&s2, &array[pos]);
    pos++;
  }

  // calculates the spot Y
  long long spot_Y = 0;
  for (int i = 0; i < count*2; i+=2) {
    spot_Y += ((pow(spot_X, aux_Y[i+1])) * aux_Y[i]);
  }

  printf("f'(x) = ");

  for (int i = 0; i < count*2; i+=2) {
    // caso Ax^B ou Ax, A positivo primeiro
    if(array[i] > 0 && array[i+1] > 1 && i == 0) printf("%llix^%lli ", array[i], array[i+1]);
    else if(array[i] > 0 && array[i+1] == 1 && i == 0) printf("%llix ", array[i]);
    // caso Ax^B ou Ax, A negativo primeiro
    else if(array[i] < 0 && array[i+1] > 1 && i == 0) printf("- %.0fx^%lli ", fabs(array[i]), array[i+1]);
    else if(array[i] < 0 && array[i+1] == 1 && i == 0) printf("- %.0fx ", fabs(array[i]));
    // caso Ax^B ou Ax, A positivo
    else if(array[i] > 0 && array[i+1] > 1 && i != 0) printf("+ %llix^%lli ", array[i], array[i+1]);
    else if(array[i] > 0 && array[i+1] == 1 && i != 0) printf("+ %llix ", array[i]);
    // caso Ax^B ou Ax, A negativo
    else if(array[i] < 0 && array[i+1] > 1 && i != 0) printf("- %.0fx^%lli ", fabs(array[i]), array[i+1]);
    else if(array[i] < 0 && array[i+1] == 1 && i != 0) printf("- %.0fx ", fabs(array[i]));
    // caso A
    else if(array[i] > 0 && array[i+1] <= 0) {
      printf("+ %lli", array[i]);
      break;
    }
    // caso -A
    else if(array[i] < 0 && array[i+1] <= 0) {
      printf("- %.0f", fabs(array[i]));
      break;
    }
  }

  long long declive = 0;
  for (int i = 0; i < count*2; i+=2) {
    if(array[i+1] >= 0) declive += ((pow(spot_X, array[i+1])) * array[i]);
  }

  long long rest = 0;
  rest = ((-1)*(declive)*spot_X) + spot_Y;

  printf("\ng(x) = ");
  if (declive > 0 && rest > 0) printf("%llix + %lli\n", declive, rest);
  else if (declive < 0 && rest > 0) printf("-%.0fx + %lli\n", fabs(declive), rest);
  else if (declive > 0 && rest < 0) printf("%llix - %.0f\n", declive, fabs(rest));
  else if (declive < 0 && rest < 0) printf("-%.0fx - %.0f\n", fabs(declive), fabs(rest));
  else if (declive > 0 && rest == 0) printf("%llix\n", declive);
  else if (declive < 0 && rest == 0) printf("-%.0fx\n", fabs(declive));

  return 0;
}
