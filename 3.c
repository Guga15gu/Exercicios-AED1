#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int **matriz;
	int m, n;
	
	printf("Digite um valor para m: ");
	scanf("%d", &m);
	
	printf("Digite um valor para n: ");
	scanf("%d", &n);
	
	matriz = malloc(sizeof(int*)*n);
	
	for(int a=0; a<n; ++a){
		
		matriz[a] = malloc(sizeof(int)*m);
	
	}
	
	for( int c=0; c<m; ++c ){
		
		for( int d=0; d<n; ++d ){
			
			printf("\nDigite o valor para a posição %d %d: ", c, d);
			scanf("%d", &matriz[c][d]);		
		}
	}
	
	for( int c=0; c<m; ++c ){
		
		for( int d=0; d<n; ++d ){
			
			printf("\nValor para a posição %d %d: %d", c, d, matriz[c][d]);
	
		}
	}
	
	for(int a=0; a<n; ++a){
		
		free(matriz[a]);
	
	}
	
	free(matriz);
	
	for( int c=0; c<m; ++c ){
		
		for( int d=0; d<n; ++d ){
			
			printf("\nValor para a posição %d %d: %d", c, d, matriz[c][d]);
	
		}
	}
	
	return 0;
}

