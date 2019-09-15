/*
  Programa feito em C para recuperar imagens de um cartão de memória, mas que leva em conta que todas as imagens estão salvas em sequência
  e não há nenhum header de imagem solto.

  Gustavo Tuani Mastrobuono
  NºUSP: 10734411

  São Carlos, agosto de 2018.
  USP - São Carlos
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// flag to determine whether the file is read to be closed || created to print in case there is a file and no images
bool flag = false, created = false;

int main(){

  // Creates block of 512 bytes (unsigned char = 1 byte)
  unsigned char BLOCK[512];

  // counter for image file names
  int count = 0;

  // checks if the input is a machine-readable binary file and if there is an image in the file
  if (fread(&BLOCK, 512, 1, stdin) == 0){
    printf("Could not find pictures\n");
    created = true;
    return 1;

  }

  else {

    // opens image file pointer
    FILE *img_out;

    // sets the position of the pointer to the beginning of the file
    fseek(stdin, 0, SEEK_SET);
    while (fread(&BLOCK, 512, 1, stdin) == 1){

      // checks if block is image header
      if (BLOCK[0] == 0xff && BLOCK[1] == 0xd8 && BLOCK[2] == 0xff && (BLOCK[3] == 0xe0 || BLOCK[3] == 0xe1)){
        created = true;
        if (flag == true){
          fclose(img_out);
          flag = false;
        }
        // opens file for saving image count.jpg
        char file_name[50];
        sprintf(file_name, "%.3d.jpg", count);
        if (flag == false){
          img_out = fopen(file_name, "wb");
          flag = true;
          }
        // writes the block content in the image file
        fwrite(&BLOCK, 512, 1, img_out);

        count++;
      }
      else if (flag == true) {
        // writes the block content in the image file until finds another header
        fwrite(&BLOCK, 512, 1, img_out);
      }
    }
  }
  if (created == false) printf("Could not find pictures\n");

  return 0;
}
