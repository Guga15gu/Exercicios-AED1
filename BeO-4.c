#include <stdio.h>
#include <stdlib.h>

void imprimiordenado(int n, int *v){
	
	int a=0;
	
	while( a< n-1 ){
		
		if( v[a] <= v[a+1] ){
			
			++a;	
		}
		else{
			a = n + 1;
		}
	}
	if(a == n-1){
		printf("\nORDENADO");
	}
}

int main(){	
	int n;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	
	int vetor[n];
	
	for(int a=0; a< n; ++a){
		
		vetor[a] =  a;
		printf("\n vetor[%d]: %d", a, vetor[a]);
	}
	
	imprimiordenado(n, vetor);
	
	
	for(int a=0; a< n; ++a){
		
		vetor[a] =  rand () % 100;
		printf("\n vetor[%d]: %d", a, vetor[a]);
	}
	
	imprimiordenado(n, vetor);
	return 0;
}

