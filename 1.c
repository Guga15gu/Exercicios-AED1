#include <stdio.h>
#include <stdlib.h>

void ler( int *vetor, int n ){
	
	for(int a=0; a<n; ++a){
		
		printf("\nDigite o valor para a posição %d: ", a);
		scanf("%d", &vetor[a]);
	
	}

}

int main(int argc, char **argv)
{
	int n;
	int *vetor;
	
	printf("Digite um valor n: ");
	scanf("%d", &n);
	
	vetor = malloc(sizeof (int) * n);
	
	if(vetor == NULL){
		
		printf("Erro na alocação.\n");
		
	}
	
	ler(vetor, n);
	
	for(int a=0; a<n; ++a){
		
		printf("%d ", vetor[a]);
		
	
	}
	
	free (vetor);
	
	return 0;
}

