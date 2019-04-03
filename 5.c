#include <stdio.h>
#include <stdlib.h>

struct pessoa{
	
	char nome[20];
	char data[20];
	int cpf;
		
};

void preencher(struct pessoa *a){
	
	printf("Digite o nome: ");
	scanf("%s", a->nome);
	
	printf("\nDigite a data de nascimento: ");
	scanf("%s", a->data);
	
	printf("\nDigite o cpf da pessoa: ");
	scanf("%d", &a->cpf);
	
}

void imprimir(struct pessoa *a){
	

	
	printf("\nNome: %s ", a->nome);
	
	printf("\nData de nascimento: %s", a->data);

	printf("\nCpf da pessoa: %d", a->cpf);
	
}

int main(int argc, char **argv)
{	
	struct pessoa *a;
	
	a = malloc( sizeof(struct pessoa) );
	
	if( a == NULL ){
		
		printf("Erro. ");
		exit(1);
	}
	preencher( a );
	imprimir( a );
	
	return 0;
}

