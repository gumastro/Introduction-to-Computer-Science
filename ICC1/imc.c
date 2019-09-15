#include <stdio.h>

int main() {
float altura, peso, imc;

scanf("%f %f", &peso, &altura);
imc = peso/(altura*altura);
	if (imc < 17) {
		printf("Muito abaixo do peso.");
	}
	else if (imc >= 17 && imc < 18.5) {
		printf("Abaixo do peso.");
	}
	else if (imc >= 18.5 && imc < 25) {
		printf("Peso normal.");
	}
	else if (imc >= 25 && imc < 30) {
		printf("Acima do peso.");
	}
	else if (imc >= 30 && imc < 35) {
		printf("Obesidade tipo 1.");
	}
	else if (imc >= 35 && imc < 40) {
		printf("Obesidade tipo 2.");
	}
	else {
		printf("Obesidade tipo 3.");
	}	
return 0;
}
