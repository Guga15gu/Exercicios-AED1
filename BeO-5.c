#include <stdio.h>
#include <stdlib.h>
void OrdenaDecrescente( int n, int *vetor ){
	int a;
	int b;
	int c=n;
	do{
		a = 0;
		for(int i = 1; i< c; ++i){
			
			if(vetor[i-1]> vetor[i]){
				b = vetor[i-1];
				vetor[i-1] = vetor[i];
				vetor[i] = b;	
				a = 1;	
			}	
		}
		--c;
	}while(a==1);
	
}
int main(int argc, char **argv){
	
	int n;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	
	int vetor[n];
		
	for(int a=0; a< n; ++a){
		
		vetor[a] =  rand () % 100;
		printf("\n vetor[%d]: %d", a, vetor[a]);
	}
	
	OrdenaDecrescente(n, vetor);
	printf("\n\n");
	
	for(int a=0; a< n; ++a){
		
		printf("\n vetor[%d]: %d", a, vetor[a]);
	}
	
	return 0;
}

