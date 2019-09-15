#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {

	int n, i;
	bool quebralinha = false;
	float t = 0, media0 = 0, media1 = 0, mediaFinal = 0, mediaFinal0 = 0, s = 0, divisor0 = 0, divisor = 0, nota1 = 0, nota2 = 0, notaFinal = 0, resul = 0, raiz1 = 0, raiz2 = 0, resul2 = 0, cosX = 0 ;
	scanf("%d%d%f", &n, &i, &t);
	int matriz[n][i];


	for (int j = 0; j < n; j++){
		for (int k = 0; k < i; k++){
			scanf("%d", &matriz[j][k]);
		}
	}


	for (int x = 0; x < n; x++){
		for (int z = 0; z < i; z++){
			if (matriz[x][z] == 0){
				for (int k = 0; k < i; k++){
					media0 += matriz[x][k];
					if(matriz[x][k] != 0)divisor0++;
				}
			mediaFinal0 = media0/divisor0;
			//printf("%d\n\n\n\n\n\n\n\n\n", mediaFinal0);
			for (int l = 0; l != x; l++){
				raiz1 = 0;
				raiz2 = 0;
				resul = 0;
				for (int y = 0; y < i; y++){
					if (matriz[l][z] != 0){
						resul += matriz[x][y]*matriz[l][y];
						raiz1 += pow(matriz[x][y], 2);
						raiz2 += pow(matriz[l][y], 2);
					}
				}
				resul2 = sqrt(raiz1)*sqrt(raiz2);
				cosX = resul/resul2;

//printf("cos.: %f\nmatriz[l][z].: %d\n", cosX, matriz[l][z]);
				if (cosX > t){

					for (int r = 0; r < i; r++){
						if (matriz[l][r] != 0){
							media1 += matriz[l][r];
							divisor++;
						}
					}

					mediaFinal = media1/divisor;
					media1 = 0;
					divisor = 0;

					nota2 += fabs(cosX);
					s += cosX * (matriz[l][z] - mediaFinal);
					notaFinal = mediaFinal0 + (s/nota2);
				}

//printf("MédiaFinal0: %f\nmédiaFinal: %f\n", mediaFinal0, mediaFinal);
				if (l + 1 > n){
					quebralinha = true;
				}
			}

			for (int l = x+1; l < n; l++){
				raiz1 = 0;
				raiz2 = 0;
				resul = 0;
				for (int y = 0; y < i; y++){
					if (matriz[l][z] != 0){
						resul += matriz[x][y]*matriz[l][y];
						raiz1 += pow(matriz[x][y], 2);
						raiz2 += pow(matriz[l][y], 2);
					}
				}

				resul2 = sqrt(raiz1)*sqrt(raiz2);
				cosX = resul/resul2;
//printf("cos..: %f\nmatriz[l][z]..: %d\n", cosX, matriz[l][z]);

				if (cosX > t){

					for (int r = 0; r < i; r++){
						if (matriz[l][r] != 0){
							media1 += matriz[l][r];
							divisor++;
						}
					}

					mediaFinal = media1/divisor;
					media1 = 0;
					divisor = 0;

					nota2 += fabs(cosX);
					s += cosX * (matriz[l][z] - mediaFinal);
					notaFinal = mediaFinal0 + (s/nota2);
				}

				nota2 = 0;

				if (l + 1 > n){
					quebralinha = true;
				}
			}
			if (notaFinal > 0){
				printf("%.2f ", notaFinal);
			}
			else printf("DI ");

		}
		if (quebralinha == true){
			printf("\n");
			quebralinha = false;
		}
	}
	}

return 0;
}
