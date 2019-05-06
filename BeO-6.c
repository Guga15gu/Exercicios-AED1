#include <stdio.h>
#include <stdlib.h>

void AddOrdenado( int *n, int *vetor, int elemento ){
	++*n;
	int a=0;
	vetor = realloc(vetor, sizeof(int) * *n);
	while ( a<*n ){
		
		if(elemento	<= vetor[a]){

			int buffer = vetor[a];
			for(; a< *n; ++a){
				
				vetor[a] = elemento;
				elemento= vetor[a+1];
				vetor[a+1] = buffer;
			}		
		}	
		++a;	
	}		
}

int main(int argc, char **argv)
{
	int n;
	int elemento;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	
	int *vetor;
	vetor = malloc(sizeof(int) * n);
	
	for(int a=0; a< n; ++a){	
		vetor[a] =  a;
		printf("\n vetor[%d]: %d", a, vetor[a]);
	}
	elemento = 5;
	
	AddOrdenado( &n, vetor, elemento );
	
	for(int a=0; a< n; ++a){
		
		printf("\n vetor[%d]: %d", a, vetor[a]);
	}
	return 0;
}

