#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int* int_pointer;

typedef struct conta {
	int num;
	char* nome; // vetor na heap de tamanho variavel
	float saldo;
}
Conta;

int num_contas = 0;

int tela_opcoes() {
	int op;
	printf("====================\n");
	printf("Bem vindo ao e-bank\n");
	printf("====================\n");
	printf("0 - Sair\n");
	printf("1 - Criar nova conta \n");
	printf("2 - Listar contas \n");
	printf("3 - Consultar saldo \n");
	printf("Operacao: ");
	scanf("%d", &op);
	getchar(); // captura o \n que o scanf ignorou
	return op;
}

void lista_contas(Conta* v1, Conta** v2) {

	// v1 sera endereco do proprio vetor na HEAP!
	// v1[p]

	// v2 e' um ponteiro na main, que contem o endereco do vetor na heap
	// (*v2)[p]

	printf("\n------------------------\n");
	printf("Num.\tNome\tSaldo\n");
	printf("------------------------\n");
	for (int j = 0; j < num_contas; j++) {
		printf("%d\t%s\t%.2f\n", v1[j].num, v1[j].nome, v1[j].saldo);
	}
	printf("\n");

}

void cria_nova_conta(Conta** v) {
	num_contas++;
	(*v) = (Conta*) realloc((*v), sizeof(Conta)*num_contas);

	//   v 	   - Conta**
	//  *v     - Conta*
	// **v     - Conta
	// (*v)[0] - Conta

	int pos = num_contas-1; // total = 1, pos = 0

	// define o numero da conta como sendo o total de contas atual
	(*v)[pos].num = num_contas;
	(*v)[pos].saldo = 0.0;

	printf("Digite o nome do titular (ate 128 caracteres): ");
	char temp[128];
	fgets(temp, 128, stdin);

	// procura pelo \n e troca por \0
	int i = 0;
	char c = temp[i];
	while (c != '\n') {
		i++;
		c = temp[i];
	}
	temp[i] = '\0';

	// TODO 1
	// alocar o campo 'nome' da struct na HEAP considerando
	// o tamanho de temp - o tamanho = i+1

	/*
	// le uma string, com tamanho 10 a partir do teclado (stdin)
	fgets((*v)[pos].nome, 10, stdin);
	// procura pelo \n e troca por \0
	int i = 0;
	char c = (*v)[pos].nome[i];
	while (c != '\n') {
		i++;
		c = (*v)[pos].nome[i];
	}
	(*v)[pos].nome[i] = '\0';
	*/
}

void consulta_saldo(Conta* vet) {
	int consulta;
	printf("Numero da conta para consulta: ");
	scanf("%d", &consulta);

	// a conta de numero 'consulta'
	for (int j = 0; j < num_contas; j++) {
		if (vet[j].num == consulta) {
			printf("Saldo = %.2f\n", vet[j].saldo);
			break;
		}
	}

}

int main (int argc, char* argv[]) {
	// criar um vetor de contas

	Conta* vet = NULL;
	int opc = 0;

	do {
		opc = tela_opcoes();
		switch(opc) {
			case 0: // TODO desaloca_contas
				break;
			case 1: cria_nova_conta(&vet);
				break;
			case 2: lista_contas(vet, &vet);
				break;
			case 3: consulta_saldo(vet);
				break;
		}

	} while (opc != 0);


	return 0;
}
