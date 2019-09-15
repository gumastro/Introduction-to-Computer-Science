#include <stdio.h>

int main() {
int num1, num2, result;
char fixa, operacao;

scanf("%c", &fixa);
	switch (fixa) {
		case 'E':	
		scanf(" %c", &operacao);											//pré-fixo
			switch(operacao) {
				case '+':
				scanf(" %d %d", &num1, &num2);
				result = num1+num2;
					if(result%2 == 0) {
						printf("O resultado %d eh par.", result);
						}
					else {
						printf("O resultado %d eh impar.", result);
					}
				break;
				
				case '-':
				scanf(" %d %d", &num1, &num2);
				result = num1-num2;
					if(result%2 == 0) {
						printf("O resultado %d eh par.", result);
						}
					else {
						printf("O resultado %d eh impar.", result);
					}
				break;
				
				case 'x':
				scanf(" %d %d", &num1, &num2);
				result = num1*num2;
					if(result%2 == 0) {
						printf("O resultado %d eh par.", result);
						}
					else {
						printf("O resultado %d eh impar.", result);
					}
				break;
				
				case ':':
				scanf(" %d %d", &num1, &num2);
				result = num1/num2;
					if(result%2 == 0) {
						printf("O resultado %d eh par.", result);
						}
					else {
						printf("O resultado %d eh impar.", result);
					}
				break;
			}
		break;
		
		
		
		
		case 'I':												//infixo
		scanf(" %d %c", &num1, &operacao);
			switch(operacao) {
			case '+':
				scanf(" %d", &num2);
				result = num1+num2;
					if(result%2 == 0) {
						printf("O resultado %d eh par.", result);
						}
					else {
						printf("O resultado %d eh impar.", result);
					}
				break;
				
				case '-':
				scanf(" %d", &num2);
				result = num1-num2;
					if(result%2 == 0) {
						printf("O resultado %d eh par.", result);
						}
					else {
						printf("O resultado %d eh impar.", result);
					}
				break;
				
				case 'x':
				scanf(" %d", &num2);
				result = num1*num2;
					if(result%2 == 0) {
						printf("O resultado %d eh par.", result);
						}
					else {
						printf("O resultado %d eh impar.", result);
					}
				break;
				
				case ':':
				scanf(" %d", &num2);
				result = num1/num2;
					if(result%2 == 0) {
						printf("O resultado %d eh par.", result);
						}
					else {
						printf("O resultado %d eh impar.", result);
					}
				break;
			}
		break;
		
		
		
		
		case 'O':												//pós-fixo
		scanf(" %d %d %c", &num1, &num2, &operacao);
			switch(operacao) {
		case '+':
				result = num1+num2;
					if(result%2 == 0) {
						printf("O resultado %d eh par.", result);
						}
					else {
						printf("O resultado %d eh impar.", result);
					}
				break;
				
				case '-':
				result = num1-num2;
					if(result%2 == 0) {
						printf("O resultado %d eh par.", result);
						}
					else {
						printf("O resultado %d eh impar.", result);
					}
				break;
				
				case 'x':
				result = num1*num2;
					if(result%2 == 0) {
						printf("O resultado %d eh par.", result);
						}
					else {
						printf("O resultado %d eh impar.", result);
					}
				break;
				
				case ':':
				result = num1/num2;
					if(result%2 == 0) {
						printf("O resultado %d eh par.", result);
						}
					else {
						printf("O resultado %d eh impar.", result);
					}
				break;
			}
		break;
	}


return 0;
}
