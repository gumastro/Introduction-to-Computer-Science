#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool pos = false;
int main(int argc, char const *argv[]) {

  int* pedidos;
  int* comandos;
  comandos = (int*)malloc( 1 * sizeof(int));
  pedidos = (int*)malloc( 1 * sizeof(int));

  int q = 0, z = 0, f = 0, count = 0, menor, maior, t = 2;

  while( scanf("%d", &comandos[q]) != EOF ){
    comandos = (int*)realloc(comandos, t * sizeof(int));
//printf("f: %d\nz: %d\npedidos[f]: %d\npedidos[z-1]: %d\ncomandos[u]: %d\n", f, z, pedidos[f], pedidos[z-1], comandos[u]);

    switch (comandos[q]) {
      case 1:
        pedidos = (int*)realloc(pedidos, (z+1) * sizeof(int));
        scanf("%d", &pedidos[z]);
        z++;
        break;

      case 2:
        if ( pedidos [f] != 0 ){
        printf("Pedido %d entregue.\n", pedidos[f]);
        f++;
        count++;
        }
        break;

      case 3:
        menor = 100000000;
        pos = false;
        for ( int w = count; w < z; w++ ){
          if ( pedidos[w] < menor ){ menor = pedidos[w]; pos = true;}
        }
        for ( int w = z-1; w >= count; w-- ){
          if ( pedidos[w] < menor ){ menor = pedidos[w]; pos = true;}
        }
        if ( pos == true ) printf("Menor senha: %d.\n", menor);
        else printf("Menor senha: 0.\n");
        break;

      case 4:
        maior = 0;
        for ( int w = count; w < z; w++ ){
          if( pedidos[w] > maior ){ maior = pedidos[w]; }
        }
        for ( int w = z-1; w >= count; w-- ){
          if( pedidos[w] > maior ){ maior = pedidos[w]; }
        }
        printf("Maior senha: %d.\n", maior);
        break;

      case 5:
        printf("Tamanho da fila: %d.\n", (z-f));
        break;

    }

    q++;
    t++;
  }

free(pedidos);
free(comandos);

  return 0;
}
