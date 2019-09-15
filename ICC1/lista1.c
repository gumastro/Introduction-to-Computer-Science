#include <stdio.h>

int main(){

  int livros[3] = {0};
  int livro1 = 0, livro2 = 0, livro3 = 0, livro4 = 0;
  int notas;
  int x = 0;

  printf("Vote em seu livro favorito:\n1: 1984\n2: Mestre e Margarida\n3: A Cidade & a Cidade\n4: Cama de Gato\n\n\n\n9: Finalizar Pesquisa\n");

  while ( x != 9){
  scanf("%d", &x);

  switch(x) {
    case 1: livro1++;
    break;

    case 2: livro2++;
    break;

    case 3: livro3++;
    break;

    case 4: livro4++;
    break;
  }
}

    notas = livro1+livro2+livro3+livro4;
    printf("------NOTAS------\n1984: %d votos, %d por cento\nMestre e Margarida: %d votos, %d por cento\nA Cidade & a Cidade: %d votos, %d por cento\nCama de Gato: %d votos, %d por cento\n", livro1, (livro1*100)/notas, livro2, (livro2*100)/notas, livro3, (livro3*100)/notas, livro4, (livro4*100)/notas);






  return 0;
}
