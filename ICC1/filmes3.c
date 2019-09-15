#include <stdio.h>
#include <math.h>

int main(){

       int n, i, b;
       float t = 0, numerador = 0, raiz1 = 0, raiz2 = 0, sim = 0, DenominadorNota = 0, Nota = 0, MediaNotaFixaDenominador = 0, DivisorNotaFixa = 0, MediaNotasDenominador = 0, DivisorNotas = 0, MediaNotas = 0, MediaNotaFixa = 0, NumeradorFinal = 0;
       scanf("%d%d%f", &n, &i, &t);
       int matriz[n][i];

       for (int z = 0; z < n; z++){

              for (int x = 0; x < i; x++){

                     scanf("%d", &matriz[z][x]);
              }
       }

       for (int q = 0; q < n; q++){

              for (int w = 0; w < i; w++){

                     if (matriz[q][w] == 0){

                            for (int r = 0; r != q; r++){

                                   raiz1 = 0;
                                   raiz2 = 0;
                                   numerador = 0;

                                   for (int e = 0; e < i; e++){

                                          if (matriz[r][w] != 0 ){

                                                 numerador += matriz[q][e] * matriz[r][e];
                                                 raiz1 += pow(matriz[q][e], 2);
                                                 raiz2 += pow(matriz[r][e], 2);
                                          }
                                   }

                                   sim = (numerador) / (sqrt(raiz1) * sqrt(raiz2));

                                   if (sim > t){

                                          MediaNotasDenominador = 0;
                                          DivisorNotaFixa = 0;
                                          MediaNotaFixaDenominador = 0;
                                          DivisorNotas = 0;

                                          for (int u = 0; u < i; u++){

                                                 MediaNotaFixaDenominador += matriz[q][u];
                                                 if (matriz[q][u] != 0) DivisorNotaFixa++;
                                                 MediaNotasDenominador += matriz[r][u];
                                                 if (matriz[r][u] != 0) DivisorNotas++;
                                          }

                                          MediaNotas = MediaNotasDenominador/DivisorNotas;
                                          MediaNotaFixa = MediaNotaFixaDenominador/DivisorNotaFixa;
                                          NumeradorFinal += sim * (matriz[r][w] - MediaNotas);
                                          DenominadorNota += fabs(sim);
                                          Nota = MediaNotaFixa + (NumeradorFinal/DenominadorNota);
                                   }

                                   //printf("MediaNotaFixa: %.2f ", MediaNotaFixa);

                            }

                            for (int r = q + 1; r < n; r++){

                                   raiz1 = 0;
                                   raiz2 = 0;
                                   numerador = 0;

                                   for (int e = 0; e < i; e++){

                                          if (matriz[r][w] != 0 ){

                                                 numerador += matriz[q][e] * matriz[r][e];
                                                 raiz1 += pow(matriz[q][e], 2);
                                                 raiz2 += pow(matriz[r][e], 2);
                                          }
                                   }

                                   sim = (numerador) / (sqrt(raiz1) * sqrt(raiz2));

                                   if (sim > t){

                                          MediaNotasDenominador = 0;
                                          DivisorNotaFixa = 0;
                                          MediaNotaFixaDenominador = 0;
                                          DivisorNotas = 0;

                                          for (int u = 0; u < i; u++){

                                                 MediaNotaFixaDenominador += matriz[q][u];
                                                 if (matriz[q][u] != 0) DivisorNotaFixa++;
                                                 MediaNotasDenominador += matriz[r][u];
                                                 if (matriz[r][u] != 0) DivisorNotas++;
                                          }

                                          MediaNotas = MediaNotasDenominador/DivisorNotas;
                                          MediaNotaFixa = MediaNotaFixaDenominador/DivisorNotaFixa;
                                          NumeradorFinal += sim * (matriz[r][w] - MediaNotas);
                                          DenominadorNota += fabs(sim);
                                          Nota = MediaNotaFixa + (NumeradorFinal/DenominadorNota);
                                   }

                                   //printf("MediaNotaFixa: %.2f ", MediaNotaFixa);

                            }
                            b = 1;
                            if (Nota > 0) printf("%.2f ", Nota);
                            else printf("DI ");

                            numerador = 0; raiz1 = 0; raiz2 = 0; sim = 0; DenominadorNota = 0; Nota = 0; MediaNotaFixaDenominador = 0; DivisorNotaFixa = 0; MediaNotasDenominador = 0; DivisorNotas = 0; MediaNotas = 0; MediaNotaFixa = 0; NumeradorFinal = 0;

                     }
              }

              if(b == 1) printf("\n");
              b = 0;
       }


       return 0;
}
