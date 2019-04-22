#include <stdio.h>
#include <stdlib.h>
int* valores_entre(int *v, int n, int min, int max, int *qtd){

    int b=0;
    int *vetor;
    *qtd = 0;
    for(int a=0; a<n; ++a){

        if(v[a] > min && v[a]< max){

        ++*qtd;
        }
    }
    if(qtd>0){
        vetor= malloc(sizeof(int)* *qtd);
        if(vetor ==NULL){
            printf("Erro na alocação.\n");
            exit(1);
        }
        for(int a=0; a<n; ++a){

            if(v[a] > min && v[a]< max){

                vetor[b] = v[a];
            ++b;
            }
        }
    }
    else{
        printf("\nNenhum valor encontrado.");
        vetor = NULL;
    }
    return vetor;
}
int main(){

    int n, min, max, qtd;
    int *v;

    printf("Digite o número de elementos desejado: ");
    scanf("%d", &n);
    int vetor[n];

    for(int a=0; a<n; ++a){

        vetor[a] = rand() %100;
        printf("\nPosição %d: %d ", a, vetor[a]);
    }

    printf("\nDigite o máximo: ");
    scanf("%d", &max);

    printf("\nDigite o minimo: ");
    scanf("%d", &min);

    v = valores_entre(vetor, n, min, max, &qtd);

    for(int a=0; a<qtd; ++a){

        printf("\nPosição %d: %d ", a, v[a]);
    }
    free(v);
    return 0;
}
