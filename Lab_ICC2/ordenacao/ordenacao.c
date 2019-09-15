#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//INSERTIONSORT,  BUBBLESORT, MERGESORT, HEAPSORT, QUICKSORT

typedef struct data {
  int c[5];   // comparações
  int m[5];   // movimentação
  int b[5];
  char algs[5][30];

} Data;


// Busca binária -> Funcionando
int binary_search(int* vet, int key, int i_begin, int i_end, Data dados) {

  int middle = (int)(i_begin + i_end)/2;

  // caso base
  if(key == vet[middle] || i_begin >= i_end) {
    return middle;
  }

  if (i_begin >= i_end) {
    return (key > vet[i_begin])?  (i_begin + 1): i_begin;
  }

  if(key > vet[middle]) {
    return binary_search(vet, key, middle+1, i_end, dados);
  }

  if(key < vet[middle]) {
    return binary_search(vet, key, i_begin, middle-1, dados);
  }

  return middle;
}

// Insertion sort -> Funcionando -------------------------------- 0
Data insertion_sort(int* vet_nums, int numbers, Data dados) {

  int i, j, pos, key;

  for (i = 1; i < numbers; i++){
    key = vet_nums[i];
    j = i-1;

    dados.c[0]++;
    pos = binary_search(vet_nums, key, 0, j, dados);

    while (j >= pos && vet_nums[j] > key) {
      dados.m[0]++;
      vet_nums[j+1] = vet_nums[j];
      j--;
    }
    dados.m[0]++;
    vet_nums[j+1] = key;
  }

  return dados;
}

// Merge sort -> Funcionando ------------------------------------ 2
Data merge(int* vet, int ini, int meio, int fim, Data dados) {

  int i, j, k;
  int n1 = meio - ini + 1;
  int n2 =  fim - meio;

  int left[n1], right[n2];

  for (i = 0; i < n1; i++) {
  //    m[2]++;
    left[i] = vet[ini + i];
  }
  for (j = 0; j < n2; j++) {
  //    m[2]++;
    right[j] = vet[meio + 1 + j];
  }
  // ----------------------------

  i = 0;
  j = 0;
  k = ini;
  while (i < n1 && j < n2) {
    dados.c[2]++;
    dados.m[2]++;
    if (left[i] <= right[j]) {
      vet[k] = left[i];
      i++;
    }
    else {
      vet[k] = right[j];
      j++;
    }
    k++;
  }
  while (i < n1) {
    vet[k] = left[i];
    i++;
    k++;
  }
  while (j < n2) {
    vet[k] = right[j];
    j++;
    k++;
  }

  return dados;
}

Data merge_sort(int* vet, int ini, int fim, Data dados) {

  if (ini < fim) {
    int meio = (int) ini+(fim - ini)/2;

    dados = merge_sort(vet, ini, meio, dados);
    dados = merge_sort(vet, meio+1, fim, dados);

    dados = merge(vet, ini, meio, fim, dados);
  }

  return dados;
}

// Bubble sort -> Funcionando ----------------------------------- 1
Data bubble_sort(int* vet, int size, Data dados) {

	int i, j, temp;

	for (i = 0; i < size-1; i++) {
    for (j = (i+1); j < size; j++) {
      dados.c[1]++;
      if (vet[j] < vet[i]){
        dados.m[1]++;
        temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;
      }
    }
  }

  return dados;
}

// Heap sort -> Funcionando ------------------------------------- 3
Data heapify(int* vet, int size, int i, Data dados) {

  int largest = i; // Initialize largest as root
  int left = 2*i + 1; // left = 2*i + 1
  int right = 2*i + 2; // right = 2*i + 2
  int temp;

  // If left child is larger than root
  dados.c[3]++;
  if (left < size && vet[left] > vet[largest]) {
    dados.m[3]++;
    largest = left;
  }

  // If right child is larger than largest so far
  dados.c[3]++;
  if (right < size && vet[right] > vet[largest]) {
    dados.m[3]++;
    largest = right;
  }

  // If largest is not root
  if (largest != i) {
    dados.m[3]++;
    temp = vet[i];
    vet[i] = vet[largest];
    vet[largest] = temp;
    // Recursively heapify the affected sub-tree
    dados = heapify(vet, size, largest, dados);
  }

  return dados;
}

Data heap_sort(int* vet, int size, Data dados) {
  int temp;
  // Build heap (rearrange array)
  for (int i = (size/2)-1; i >= 0; i--) {
    dados = heapify(vet, size, i, dados);
  }
  // One by one extract an element from heap
  for (int i = size-1; i >= 0; i--) {
    // Move current root to end
    dados.m[3]++;
    temp = vet[0];
    vet[0] = vet[i];
    vet[i] = temp;

    // call max heapify on the reduced heap
    dados = heapify(vet, i, 0, dados);
  }

  return dados;
}

// Quick sort -> Funcionando ------------------------------------ 4
Data quick_sort(int* vet, int left, int right, Data dados) {

  dados.c[4]++;
  if (left >= right) return dados;

  int pivot = vet[left + (right - left)/2];
  int leftI = left-1;
  int rightI = right+1;
  int temp;

  while (leftI <= rightI) {

    dados.c[4]++;
    while (vet[++leftI] < pivot);
    dados.c[4]++;
    while (vet[--rightI] > pivot);

    dados.c[4]++;
    if (leftI >= rightI) break;

    dados.m[4]++;
    temp = vet[leftI];
    vet[leftI] = vet[rightI];
    vet[rightI] = temp;
  }

  quick_sort(vet, left, rightI, dados);
  quick_sort(vet, rightI+1, right, dados);

  return dados;
}

// ---------------------------------------------------------------------------------

void merge_sort2 (Data* v, int ini, int fim, int preset) {

	if (fim <= ini)  return; // caso base (vetor de 1 elemento)

  int centro;
  if ((fim+ini)%2 != 0 ) centro = (int) ((fim+ini)/2.0);
  if ((fim+ini)%2 == 0 ) centro = (int) ((fim+ini-1)/2.0);

	// 1 - passo recursivo (divisao)
  merge_sort2(v, ini, centro, preset);   // divisao lista 1 (primeira metade)
  merge_sort2(v, centro+1, fim, preset); // divisao lista 2 (segunda metade)

	// 2 - intercalacao, combinando solucoes parciais (conquista)
	// vetor auxiliar para copiar a intercalacao
	Data* aux = (Data*) malloc(sizeof(Data) * (fim-ini+1));

	int i = ini;	  // indice da lista 1 (ini ate centro)
	int j = centro+1; // indice da lista 2 (centro+1 ate fim)
 	int k = 0;	  // indice do vetor auxiliar (0 ate fim-ini)

	// comparar elementos das duas listas
	while (i <= centro && j <= fim) {
    if (preset == 1) {                              // baseado no .C
  		if (v->c[i] <= v->c[j]) {
  			aux->c[k] = v->c[i];
        aux->b[k] = v->b[i];
        strcpy(aux->algs[k], v->algs[i]);
  			i++; // proximo elemento da lista 1
  		}
  		else {
  			aux->c[k] = v->c[j];
        aux->b[k] = v->b[j];
        strcpy(aux->algs[k], v->algs[j]);
  			j++; // proximo elemento da lista 2
  		}
    }

    else if (preset == 0) {                         // baseado no .M
      if (v->m[i] <= v->m[j]) {
        aux->m[k] = v->m[i];
        aux->b[k] = v->b[i];
        strcpy(aux->algs[k], v->algs[i]);
        i++;
      }
      else {
        aux->m[k] = v->m[j];
        aux->b[k] = v->b[j];
        strcpy(aux->algs[k], v->algs[j]);
        j++;
      }
    }
		k++; // proximo elemento do aux
	}

	// copia o restante da lista 1
	while (i <= centro) {
		aux->c[k] = v->c[i];
    aux->b[k] = v->b[i];
    aux->m[k] = v->m[i];
    strcpy(aux->algs[k], v->algs[i]);
    i++; k++;
	}
	// copia o restante da lista 2
	while (j <= fim) {
	  aux->c[k] = v->c[j];
    aux->b[k] = v->b[j];
    aux->m[k] = v->m[j];
    strcpy(aux->algs[k], v->algs[j]);
    j++; k++;
	}

  // retorna os valores do vetor auxiliar para o vetor principal
	for (i = ini; i <= fim; i++) {
    v->c[i] = aux->c[i-ini];
    v->b[i] = aux->b[i-ini];
//    v->m[i] = aux->m[i-ini];
    strcpy(v->algs[i], aux->algs[i-ini]);
	}

	free(aux);
  return;
}


// ---------------------------------------------------------------------------------

int main(int argc, char const *argv[]) {

  int o, n; // o = qntd de alg de ordenção que deverão ser utilizados || n = tamanho do conjunto de dados
  char algorithm[30];

  scanf("%d %d", &o, &n);

  int order_this[5][n];
  int x = 0;
  Data dados;

  for(int i = 0; i < 5; i++) {
    dados.m[i] = 0;
    dados.c[i] = 0;
    dados.b[i] = 0;
    strcpy(dados.algs[i], "aaa");
  }

  for (int i = 0; i < o; i++) {
    scanf("%s", algorithm);

    if (strcmp(algorithm, "INSERTIONSORT") == 0) {  // 0 -------------- OK
      strcpy(dados.algs[0], "INSERTIONSORT");
      dados.b[0] = 1;
      x++;
    }

    if (strcmp(algorithm, "BUBBLESORT") == 0) { // 1 ---------------- OK
      strcpy(dados.algs[1], "BUBBLESORT");
      dados.b[1] = 1;
      x++;
    }

    if (strcmp(algorithm, "MERGESORT") == 0) {  // 2 --------------- OK
      strcpy(dados.algs[2], "MERGESORT");
      dados.b[2] = 1;
      x++;
    }

    if (strcmp(algorithm, "HEAPSORT") == 0) {  // 3 ---------------- OK
      strcpy(dados.algs[3], "HEAPSORT");
      dados.b[3] = 1;
      x++;
    }

    if (strcmp(algorithm, "QUICKSORT") == 0) {  // 4 --------------- OK
      strcpy(dados.algs[4], "QUICKSORT");
      dados.b[4] = 1;
      x++;
    }

  }

  for (int i = 0; i < n; i++) {
    scanf("%d", &order_this[0][i]);
    order_this[1][i] = order_this[0][i];
    order_this[2][i] = order_this[1][i];
    order_this[3][i] = order_this[2][i];
    order_this[4][i] = order_this[3][i];

  }

  if (dados.b[0] == 1) dados = insertion_sort(order_this[0], n, dados);
  if (dados.b[1] == 1) dados = bubble_sort(order_this[1], n, dados);
  if (dados.b[2] == 1) dados = merge_sort(order_this[2], 0, n-1, dados);
  if (dados.b[3] == 1) dados = heap_sort(order_this[3], n, dados);
  if (dados.b[4] == 1) dados = quick_sort(order_this[4], 0, n-1, dados);

  Data dados2;
  int j = 0;
  for (int i = 0; i < 5; i++) {
    if(dados.b[i] == 1) {
      dados2.m[j] = dados.m[i];
      dados2.c[j] = dados.c[i];
      dados2.b[j] = dados.b[i];
      strcpy(dados2.algs[j], dados.algs[i]);
      j++;

    }
  }

  printf("Insertion c[0] = %d || Insertion m[0] = %d\n", dados.c[0], dados.m[0]);
  printf("Bubble c[1] = %d || Bubble m[1] = %d\n", dados.c[1], dados.m[1]);
  printf("Merge c[2] = %d || Merge m[2] = %d\n", dados.c[2], dados.m[2]);
  printf("Heap c[3] = %d || Heap m[3] = %d\n", dados.c[3], dados.m[3]);
  printf("Quick c[4] = %d || Quick m[4] = %d\n", dados.c[4], dados.m[4]);

  merge_sort2(&dados2, 0, x, 1);

  for (int i = 0; i < x; i++) {
    //if(dados.b[i] == 1) {
      printf("Menor C: %s %d\n", dados2.algs[i], i);
      printf("Maior C: %s %d\n", dados2.algs[x], x);
    //  break;
    //}

  }

//  merge_sort2(&dados, 0, 5, 0);

  // for (int i = 0; i < 4; i++) {
  //   if(dados.b[i] == 1) {
  //     printf("Menor M: %s %d\n", dados.algs[i], i);
  //     printf("Maior M: %s %d\n", dados.algs[4], 4);
  //     break;
  //   }
  //
  // }


  printf("--------------------------------\n");
  printf("%s c[0] = %d || %s m[0] = %d\n", dados.algs[0], dados.c[0], dados.algs[0], dados.m[0]);
  printf("%s c[1] = %d || %s m[1] = %d\n", dados.algs[1], dados.c[1], dados.algs[1], dados.m[1]);
  printf("%s c[2] = %d || %s m[2] = %d\n", dados.algs[2], dados.c[2], dados.algs[2], dados.m[2]);
  printf("%s c[3] = %d || %s m[3] = %d\n", dados.algs[3], dados.c[3], dados.algs[3], dados.m[3]);
  printf("%s c[4] = %d || %s m[4] = %d\n", dados.algs[4], dados.c[4], dados.algs[4], dados.m[4]);


  return 0;
}
