#include <stdio.h>

struct s {
	char nome[20];
	int data[3];
	int cpf;
	struct s *next;
} s;

void preencher( struct s* lista ){
	
	int n;
	printf("Digite o número de pessoas a serem adicionadas: ");
	scanf("%d", &n);
	
	for( int a=0; a<n; ++a ){
		
		printf("Digite o %dº nome: \n", a);
		scanf("%s", lista->nome);
		
		
	}
	
}

int main(int argc, char **argv)
{
	struct s* lista;
	
	
	
	preencher( lista );
	
	
	
	return 0;
}

