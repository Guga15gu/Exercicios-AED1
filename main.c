#include <stdio.h>
#include <stdlib.h>

void imprimeBuffer(void *pBuffer, unsigned int nTotal){
    void *c ;
    c = pBuffer;
    for(int a=0; a< nTotal; a = a + 3){

        printf("%d\n", *(int*)c);
        c = c +sizeof(int);
        
        printf("%f\n", *(float*)c);
        c = c +sizeof(float);

        printf("%lf\n", *(double*)c);
        c = c +sizeof(double);

    }
}

void preencher(void **pBuffer, unsigned int nTotal){
    
   *pBuffer = malloc( sizeof(double) * (nTotal/3) + sizeof(float) * (nTotal/3) + sizeof(int) * (nTotal/3));
   
   if(pBuffer == NULL){
       printf("Erro ao alocar.\n");
       exit(1);
   }
   void *c ;
   c = pBuffer;
   
    for(int a=0; a< nTotal; a = a + 3){

        printf("Digite um int: \n");
        scanf("%d", (int*)c);
        c = c +sizeof(int);

        printf("Digite um float: \n");
        scanf("%f", (float*)c);
        c = c +sizeof(float);

        printf("Digite um double: \n");
        scanf("%lf", (double*)c);
        c = c +sizeof(double);

    }
}

int main() {

    void * pBuffer;
    int nTotal;

    printf("Digite o total(múltiplos de 3): \n");
    scanf("%d", &nTotal);

    preencher(pBuffer, nTotal);
    imprimeBuffer(pBuffer, nTotal);



    return 0;
}


