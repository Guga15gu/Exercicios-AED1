#include <stdio.h>
#include <stdlib.h>

int * cria( int n ){
	
	int *vetor;
	vetor = malloc(sizeof (int) * n);
	
	if(vetor == NULL){
		
		printf("Erro na alocação.\n");
		
	}
	return vetor;
}

void retorna( int *vetor, int n ){
	
	for(int a=0; a<n; ++a){
		
		printf("%d ", vetor[a]);
		
	}
	
}

void libera( int *vetor ){
	
	free(vetor);
	
}

int main(int argc, char **argv)
{
	int n;
	int *vetor;
	
	printf("Digite um valor n: ");
	scanf("%d", &n);
	
	while(n!= 0){
	
	
	vetor = cria( n );
	
	for(int a=0; a<n; ++a){
		
		printf("\nDigite o valor para a posição %d: ", a);
		scanf("%d", &vetor[a]);
	
	}
	
	retorna(vetor, n);
	libera(vetor);
	
	printf("\nDigite outro valor para n ou 0 para sair: ");
	scanf("%d", &n);
	
}
	return 0;
}

