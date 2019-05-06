#include <stdio.h>
#include <stdlib.h>

void AddOrdenado( int *n, int *vetor, int elemento ){
	++*n;
	int a=0;
	vetor = realloc(vetor, sizeof(int) * *n);
	while ( a<*n ){

		if(elemento	<= vetor[a]){

			for(int b = *n; b>a; --b){

                vetor[b] = vetor[b-1];

			}
        vetor[a] = elemento;
        a = *n;
		}
		a++;
	}
}

int main(int argc, char **argv)
{
	int n;

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);

	int *vetor;
	vetor = malloc(sizeof(int) * n);

	for(int a=0; a< n; ++a){
		vetor[a] =  a;
		printf("\n vetor[%d]: %d", a, vetor[a]);
	}

    for(int b=0; b<10; ++b){

        AddOrdenado( &n, vetor, b );
        for(int a=0; a< n; ++a){

            printf("\n vetor[%d]: %d", a, vetor[a]);
        }
    }



	return 0;
}
