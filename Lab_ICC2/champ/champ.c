#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct competitors {
  long int id_int;
  char name[100];
  char college[20];

} Competitors;

bool usp = false;

int merge_sort (Competitors* v, int ini, int fim, int preset, int reps, int count) {

	if (fim <= ini || count >= reps)  return count; // caso base (vetor de 1 elemento) ou countador atingiu o limite

  int centro;
  if ((fim+ini)%2 != 0 ) centro = (int) ((fim+ini)/2.0);
  if ((fim+ini)%2 == 0 ) centro = (int) ((fim+ini-1)/2.0);

	// 1 - passo recursivo (divisao)
  count = merge_sort(v, ini, centro, preset, reps, count);   // divisao lista 1 (primeira metade)
  count = merge_sort(v, centro+1, fim, preset, reps, count); // divisao lista 2 (segunda metade)

	// 2 - intercalacao, combinando solucoes parciais (conquista)
	// vetor auxiliar para copiar a intercalacao
	Competitors* aux = (Competitors*) malloc(sizeof(Competitors) * (fim-ini+1));

	int i = ini;	  // indice da lista 1 (ini ate centro)
	int j = centro+1; // indice da lista 2 (centro+1 ate fim)
 	int k = 0;	  // indice do vetor auxiliar (0 ate fim-ini)

	// comparar elementos das duas listas
	while ((i <= centro && j <= fim) && count < reps) {
    if (preset == 1) {
  		if (v[i].id_int <= v[j].id_int) {
  			aux[k].id_int = v[i].id_int;
        strcpy(aux[k].name, v[i].name);
        strcpy(aux[k].college, v[i].college);
  			i++; // proximo elemento da lista 1
  		}
  		else {
  			aux[k].id_int = v[j].id_int;
        strcpy(aux[k].name, v[j].name);
        strcpy(aux[k].college, v[j].college);
  			j++; // proximo elemento da lista 2
  		}
    }

    else if (preset == 0) {
      if (strcmp(v[i].name, v[j].name) <= 0) {
        aux[k].id_int = v[i].id_int;
        strcpy(aux[k].name, v[i].name);
        strcpy(aux[k].college, v[i].college);
        i++;
      }
      else {
        aux[k].id_int = v[j].id_int;
        strcpy(aux[k].name, v[j].name);
        strcpy(aux[k].college, v[j].college);
        j++;
      }
    }
		k++; // proximo elemento do aux
	}
  count++;
	// copia o restante da lista 1
	while (i <= centro) {
		aux[k].id_int = v[i].id_int;
    strcpy(aux[k].name, v[i].name);
    strcpy(aux[k].college, v[i].college);
    i++; k++;
	}
	// copia o restante da lista 2
	while (j <= fim) {
	  aux[k].id_int = v[j].id_int;
    strcpy(aux[k].name, v[j].name);
    strcpy(aux[k].college, v[j].college);
    j++; k++;
	}

  // retorna os valores do vetor auxiliar para o vetor principal
	for (i = ini; i <= fim; i++) {
    v[i].id_int = aux[i-ini].id_int;
    strcpy(v[i].name, aux[i-ini].name);
    strcpy(v[i].college, aux[i-ini].college);
	}

	free(aux);
  return count;
}

int main(int argc, char const *argv[]) {

  Competitors* Federal;
  Competitors* Caaso;
  Competitors* All;
  char *endptr;
  int i = 0, j = 0, reps = 0;
  int preset = 0;
  char support[250];

  Federal = calloc(400, sizeof(Competitors));
  Caaso = calloc(400, sizeof(Competitors));
  All = calloc(800, sizeof(Competitors));

  scanf("%s", support);

  while (scanf("%s", support) != EOF) {
    if (strcmp(support, "CAASO") == 0) {
      usp = true;
    }

    if (strcmp(support, "NAME") == 0 || strcmp(support, "ID") == 0) {
      if (strcmp(support, "ID") == 0) preset = 1;
      if (strcmp(support, "NAME") == 0) preset = 0;
      scanf("%d", &reps);
      break;
    }

    if (usp == false) {
      Federal[i].id_int = strtol(support, &endptr, 10);
      getchar();

      scanf("%[^\n]s", Federal[i].name);
      strcpy(Federal[i].college, "FEDERAL");
      i++;
    }

    if (usp == true && strcmp(support, "CAASO") != 0) {
      Caaso[j].id_int = strtol(support, &endptr, 10);
      getchar();

      scanf("%[^\n]s", Caaso[j].name);
      strcpy(Caaso[j].college, "CAASO");
      j++;
    }
  }

  for (int k = 0; k < i; k++) {
    All[k].id_int = Federal[k].id_int;
    strcpy(All[k].name, Federal[k].name);
    strcpy(All[k].college, "FEDERAL");
  }

  int s = 0;
  for (int z = i; z <= j+i; z++) {
    All[z].id_int = Caaso[s].id_int;
    strcpy(All[z].name, Caaso[s].name);
    strcpy(All[z].college, "CAASO");
    s++;
  }

  merge_sort(All, 0, i+j-1, preset, reps, 0);

  for (int q = 0; q < i+j; q++) {
    printf("%s %li %s\n", All[q].college, All[q].id_int, All[q].name);
  }

  free(Federal);
  free(Caaso);

  return 0;
}
