#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(){

  char frase[1024];
  int count = 0;

  scanf("%[^\n]s", frase);


  for(int i = 0; frase[i]; i++){
    if(frase[i] != ' ') {
      frase[count++] = frase[i];
    }
  }

  printf("%s\n", frase);



  return 0;
}
