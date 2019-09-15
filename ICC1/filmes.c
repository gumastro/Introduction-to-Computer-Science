#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {

	int n, i, x, y, l = 0;
	// n = número de usuários
	// i = número de filmes (itens na base de dados)
	bool quebra = false;
	
	float t = 0;
	// t = limiar p/ selecionar usuários similares
	
	float media0 = 0, media1 = 0, mediaFinal0 = 0, mediaFinal = 0;
	// float com as médias
	
	float s = 0, divisor0 = 0, divisor = 0, nota1 = 0, resul = 0, raiz1 = 0, raiz2 = 0, resul2 = 0, cosX = 0, nota2 = 0, nota11 = 0;
	// float com outras variáveis p/ o cálculo
	
	scanf("%d%d%f", &n, &i, &t);
	// recebe os valores do número de usuários, filmes e limiar

	int matriz[n][i];
	// matriz de notas usuários x item

	// comando para escanear as notas de cada usuário para cada filme
	for (int j = 0; j<n; j++){
	// j aumenta até o número de usuários (linhas da matriz)
		for (int k = 0; k<i; k++){
		// k aumenta até o número de filmes (colunas da matriz)
			scanf("%d", &matriz[j][k]);
		}
	}
	
	// 2 comandos "for" que percorrem a matriz procurando um valor 0
	for (int x = 0; x<n; x++){
		
		for(int z = 0; z<i; z++){
			
			if(matriz[x][z] == 0){
			// caso encontre um valor igual a 0, deve calcular a possível nota do usuário
						
				for(int k=0;k<i;k++){
				// for para calcular a média do usuário com nota 0
					if (matriz[x][k] != 0){
					media0 += matriz[x][k];	
					divisor0++;
					}
				}
				mediaFinal0 = media0/divisor0;
				// mediaFinal0 = média do usuário com alguma nota 0
				
				
				// for para calcular até a linha em que l é igual a x-1
				for(l = 0; l != x; l++){
					raiz1 = 0;
					raiz2 = 0;
					resul = 0;
					for (int y = 0; y < i; y++){
					// for que percorre as colunas tanto da matriz com 0 quanto das que compara
						if(matriz[l][z] != 0){
						resul += matriz[x][y]*matriz[l][y];
						// parte de cima da equação, que multiplica os vetores 'u' e 'v'
						raiz1 += pow(matriz[x][y], 2);
						raiz2 += pow(matriz[l][y], 2);
						// parte de baixo da equação (apenas soma dos números ao quadrado)
					}
						
					}
					
					resul2 = sqrt(raiz1)*sqrt(raiz2);
					//parte de baixo da equação
					cosX = resul/resul2;
					//similaridade (ou cosseno)
					
printf("cos.: %f\nmatriz[l][z].: %d\n", cosX, matriz[l][z]);
					
					for (int r = 0; r < i; r++){
						if ( matriz[l][r] != 0 ){
						media1 += matriz[l][r];
						divisor++;
						}						
					}
					
					mediaFinal = media1/divisor;
					// mediaFinal = média de notas dadas pelos outros usuários
					media1 = 0;
					divisor = 0;
					// zerar os valores para serem usados na próxima operação
					
					if(cosX > t){
						
						nota2 += fabs(cosX);
						s += cosX * (fabs(matriz[l][z] - mediaFinal));
						nota11 = mediaFinal0 + (s/nota2);
					}
					// nota11 = resultado final da nota
					
printf("MédiaFinal0: %f\nmédiaFinal: %f\n", mediaFinal0, mediaFinal);
					if(l + 1 > n){
							//s = 0;
							quebra = true;

					}
			

				}
			
				for(l = x+1; l < n; l++){
				// for para calcular após a linha em que l = x
					raiz1 = 0;
					raiz2 = 0;
					resul = 0;
					for (int y = 0; y < i; y++){
					// for que percorre as colunas tanto da matriz com 0 quanto das que compara
						if(matriz[l][z] != 0){
						resul += matriz[x][y]*matriz[l][y];
						// parte de cima da equação, que multiplica os vetores 'u' e 'v'
						raiz1 += pow(matriz[x][y], 2);
						raiz2 += pow(matriz[l][y], 2);
						// parte de baixo da equação (apenas soma dos números ao quadrado)
						}
					}
						
					
					
					resul2 = sqrt(raiz1)*sqrt(raiz2);
					// pt. 2 parte de baixo da equação
					cosX = resul/resul2;
					// pt. 2 similaridade (ou cosseno)
printf("cos..: %f\nmatriz[l][z]..: %d\n", cosX, matriz[l][z]); 
					// pt. 2 somatória do módulo da similaridade (cos)
					
					// pt. 2 zerar os valores pois, por algum  motivo, influenciam no resultado final em (0.02)
					
					for (int r = 0; r < i; r++){
						
						if (matriz[l][r] != 0){
							
							media1 += matriz[l][r];
							// calcula a média de notas dadas pelo usuário a ser comparado
							divisor++;
						}
					}
					
					mediaFinal = media1/divisor;	
					media1 = 0;
					divisor = 0;
					
					if(cosX > t){
						
						nota2 += fabs(cosX);
						s += cosX * (fabs(matriz[l][z] - mediaFinal));
						nota11 = mediaFinal0 + (s/nota2);
					}
					// pt. 2 resultado final da nota
					
					//s = 0;
					media1 = 0;
					divisor = 0;
					nota2 = 0;
					
					if(l + 1 > n) {
						quebra = true;
					}
			}
				
			nota2 = 0;
			s = 0;
			media1 = 0;
			divisor = 0;
			nota2 = 0;
			media0 = 0;
			divisor0 = 0;
		
			
		
			if(nota11 > 0) printf("%.2f ", nota11);
			else printf("DI ");
		
		}
			
			if(quebra == true) {
				printf("\n");
				quebra = false;
			}
		
			nota2 = 0;
			s = 0;
			media1 = 0;
			divisor = 0;
			nota2 = 0;
			media0 = 0;
			divisor0 = 0;
		}
	
				nota2 = 0;
			s = 0;
			media1 = 0;
			divisor = 0;
			nota2 = 0;
			media0 = 0;
			divisor0 = 0;
			
	}
return 0;
}
