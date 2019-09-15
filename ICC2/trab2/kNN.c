#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct _results {
  char species[100];
  char expected[100];
  float dist;

} Results;

typedef struct _flower {
  char species[100]; // espécie da flor
  float petal_length; // altura da pétala
  float petal_width;  // largura da pétala
  float sepal_length; // altura da sépala
  float sepal_width;  // largura da sépala

} Flower;


/*  binary_search()
      Function that does a binary search. The vector has to be ordered to work.
    @Parameters
      Result* label: struct vector to be searched
      float key: number to be found
      i_begin: beginning of the vector
      i_end: end of the vector
    @Return
      int: position where the number is located in the vector
*/
int binary_search(Results* label, float key, int i_begin, int i_end) {

  int middle = (int)(i_begin + i_end)/2;

  if(key == label[middle].dist || i_begin >= i_end) {
    return middle;
  }

  if (i_begin >= i_end) {
    return (key > label[i_begin].dist)?  (i_begin + 1): i_begin;
  }

  if(key > label[middle].dist) {
    return binary_search(label, key, middle+1, i_end);
  }

  if(key < label[middle].dist) {
    return binary_search(label, key, i_begin, middle-1);
  }

  return middle;
}

/*  insertion_sort()
      Function to order the vector using binary search based on a float key
    @Parameters
      Results* label: struct vector to be ordered
      int total: total size of the vector
    @Return
      void
*/
void insertion_sort(Results* label, int total) {

  int i, j, pos;
  float key;
  char key_name[100];
  char key_name2[100];

  for (i = 1; i < total; i++){
    strcpy(key_name, label[i].species);
    strcpy(key_name2, label[i].expected);
    key = label[i].dist;
    j = i-1;

    pos = binary_search(label, key, 0, j);

    while (j >= pos && label[j].dist > key) {
      strcpy(label[j+1].species, label[j].species);
      strcpy(label[j+1].expected, label[j].expected);
      label[j+1].dist = label[j].dist;
      j--;
    }
    strcpy(label[j+1].species, key_name);
    strcpy(label[j+1].expected, key_name2);
    label[j+1].dist = key;
  }
}

int main(int argc, char const *argv[]) {

  int k = 0, total_flowers_train = 0, total_flowers_test = 0;
  char train[30], test[30], junk[300];

  // Pointer to train and test files
  FILE* fptr_train;
  FILE* fptr_test;

  // saves the input (train_file test_file k)
  scanf("%s %s %d", train, test, &k);
  fptr_train = fopen(train, "r");

  // checks the file pointer
  if (fptr_train == NULL) {
    printf("Error! \"%s\" does not exist!\n", train);
    return 404;
  }

  Flower* f_train = calloc(1, sizeof(Flower));

  // reads the first line (junk)
  fscanf(fptr_train, "%s", junk);

  // saves the info about each train flower in a struct (Flower) vector
  while (!feof(fptr_train)) {
    f_train = realloc(f_train, (total_flowers_train+1) * sizeof(Flower));

    fscanf(fptr_train, "%f%*c%f%*c%f%*c%f%*c%*c%s", &f_train[total_flowers_train].sepal_length, &f_train[total_flowers_train].sepal_width, &f_train[total_flowers_train].petal_length, &f_train[total_flowers_train].petal_width, f_train[total_flowers_train].species);

    // excludes the last quotation mark
    int size_name = strlen(f_train[total_flowers_train].species);
    f_train[total_flowers_train].species[size_name-1] = '\0';

    total_flowers_train++;
  }
  // As opposed to the f_test, f_train showed no need to adjust its last and second last values

  // it counts one more flower than it should
  total_flowers_train--;


  // checks if k is a valid number
  if (k < 1 || k > total_flowers_train) {
    printf("k is invalid\n");
    exit(0);
  }


  fptr_test = fopen(test, "r");

  // checks the file pointer
  if (fptr_test == NULL) {
    printf("Error! \"%s\" does not exist!\n", test);
    return 404;
  }

  Flower* f_test = calloc(1, sizeof(Flower));

  // reads the first line (junk)
  fscanf(fptr_test, "%s", junk);

  // saves the info about each test flower in a struct (Flower) vector
  while (!feof(fptr_test)) {
    f_test = realloc(f_test, (total_flowers_test+1) * sizeof(Flower));
    float temp;

    fscanf(fptr_test, "%f%*c%f%*c%f%*c%f%*c%*c%s", &f_test[total_flowers_test].sepal_length, &temp, &f_test[total_flowers_test].petal_length, &f_test[total_flowers_test].petal_width, f_test[total_flowers_test].species);

    // for some reason, when I directly read the f_test[total_flowers_test].sepal_width, the last and the second to last values were set to 0.0000
    // because of that, I created a temporary float variable, which seemed to work
    f_test[total_flowers_test].sepal_width = temp;

    // excludes the last quotation mark
    int size_name = strlen(f_test[total_flowers_test].species);
    f_test[total_flowers_test].species[size_name-1] = '\0';

    total_flowers_test++;
  }

  // The next line is essential for the program to work properly. It defines the variable that used to store 0.0000 to its correct value.
  // after some tests, I could conclude that the program, for some misterious reason, skips the f_test[total_flowers_test-2] position.
  f_test[total_flowers_test-2].sepal_width = f_test[total_flowers_test-1].sepal_width;

  // it counts one more flower than it should
  total_flowers_test--;

  Results result[total_flowers_test][total_flowers_train];

  for (int i = 0; i < total_flowers_test; i++) { // flowers for train - varies less
    for (int j = 0; j < total_flowers_train; j++) {  // flowers for testing - varies more
      strcpy(result[i][j].species, f_train[j].species);
      strcpy(result[i][j].expected, f_test[i].species);
      result[i][j].dist = sqrt(pow((f_train[j].sepal_length - f_test[i].sepal_length), 2) + pow((f_train[j].sepal_width - f_test[i].sepal_width), 2) + pow((f_train[j].petal_length - f_test[i].petal_length), 2) + pow((f_train[j].petal_width - f_test[i].petal_width), 2));
    }
    insertion_sort(result[i], total_flowers_train);
  }

  int setosa = 0, versicolor = 0, virginica = 0;
  int count = 0;

  // checks which flower appears the most and therefore is the one the program thinks is the correct
  for (int i = 0; i < total_flowers_test; i++) {
    for (int j = 0; j < k; j++) {
      if (strcmp(result[i][j].species, "setosa") == 0)  setosa++;
      else if (strcmp(result[i][j].species, "versicolor") == 0) versicolor++;
      else if (strcmp(result[i][j].species, "virginica") == 0) virginica++;
    }
    // case setosa > all
    if (setosa > versicolor && setosa > virginica) strcpy(result[i]->species, "setosa");
    // case versicolor > all
    else if (versicolor > setosa && versicolor > virginica) strcpy(result[i]->species, "versicolor");
    // case virginica > all
    else if (virginica > versicolor && virginica > setosa) strcpy(result[i]->species, "virginica");
    // case (setosa == versicolor) > virginica
    else if (setosa == versicolor && setosa > virginica) {
      for (int j = 0; j < k; j++) {
        if (strcmp(result[i][j].species, "setosa") == 0) {
          strcpy(result[i]->species, "setosa");
          break;
        }
        else strcpy(result[i]->species, "versicolor");
      }
    }
    // case (setosa == virginica) > versicolor
    else if (setosa == virginica && setosa > versicolor) {
      for (int j = 0; j < k; j++) {
        if (strcmp(result[i][j].species, "setosa") == 0) {
          strcpy(result[i]->species, "setosa");
          break;
        }
        else strcpy(result[i]->species, "virginica");
      }
    }
    // case (virginica == versicolor) > setosa
    else if (virginica == versicolor && virginica > setosa) {
      for (int j = 0; j < k; j++) {
        if (strcmp(result[i][j].species, "virginica") == 0) {
          strcpy(result[i]->species, "virginica");
          break;
        }
        else strcpy(result[i]->species, "versicolor");
      }
    }

    if (strcmp(result[i]->species, result[i]->expected) == 0) count++;
    setosa = 0; virginica = 0; versicolor = 0;
  }

  for (int i = 0; i < total_flowers_test; i++) {
    printf("%s %s\n", result[i]->species, result[i]->expected);

  }
  printf("%.4f\n", (float)count/(float)total_flowers_test);

  free(f_train);
  free(f_test);
  fclose(fptr_train);
  fclose(fptr_test);

  return 0;
}
