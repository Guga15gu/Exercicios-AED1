#include <stdio.h>

struct s {
	char nome[20];
	int data[3];
	int cpf;
} s;

void preencher( struct s* lista ){
		
		printf("Digite o nome: \n");
		scanf("%s", lista.nome);
		
		printf("Digite o dia de nascimento: \n");
		scanf("%d", lista.data[0]);
		
		printf("Digite o mês de nascimento: \n");
		scanf("%d", lista.data[1]);
		
		printf("Digite o ano de nascimento: \n");
		scanf("%d", lista.data[2]);
		
		printf("Digite o cpf: \n");
		scanf("%d", lista.cpf);
			
}

void imprimir( struct s* lista ){
	
	
		printf("Nome: %s \n", lista.nome);
		
		printf("Dia de nascimento: &d\n", lista.data[0]);
			
		printf("Digite o mês de nascimento: \n");
		scanf("%d", lista.data[1]);
		
		printf("Digite o ano de nascimento: \n");
		scanf("%d", lista.data[2]);
		
		printf("Digite o cpf: \n");
		scanf("%d", lista.cpf);
		

	

	
}

int main(int argc, char **argv)
{
	struct s *lista;
	
	lista = malloc(sizeof(struct s));

	preencher( &lista );
	imprimir( &lista );
	
	
	
	return 0;
}

