#include <stdio.h>
#include <stdlib.h>

typedef struct registro{
    char nome[30];
    int idade;
}registro;

typedef No *Apontador;

typedef struct No{
     registro dado;
     Apontador pEsq, pDir;

  }No;

void insere(registro x, Apontador *p){

    if(*p == NULL){
        *p = (Apontador) malloc (sizeof(No));
        (*p)-> registro = x;
        (*p)->pEsq = NULL;
        (*p)->pDir = NULL;
        return;
    }
    if(x.idade < (*p)->registro.idade){
        insere(x, &(*P)->pEsq);
        return;
    }
    if(x.idade > (*p)->registro.idade){
        insere(x, &(*P)->pDir);
        return;
    }
    else{
        printf("Erro: Registro já existente.\n");
    }
}

void  inicializa(Apontador *agenda){
    *agenda = NULL;
}

void retira(registro x, Apontador *p){
    Apontador aux;

    if(*p == NULL){
        printf("Erro: Registro não existente.\n");
        return;
    }
    if(x.idade < (*p)->registro.idade){
        Retira(x, &(*P)->pEsq);
        return;
    }
    if(x.idade > (*p)->registro.idade){
        Retira(x, &(*P)->pDir);
        return;
    }
    if((*p)->pDir == NULL){
        aux = *p;
        *p = (*p)->pEsq;
        free(aux);
        return;
    }

    if((*p)->pEsq != NULL){
        antecessor(*p, &(*p)->pEsq);
        return;
    }

    aux = *p;
    *p  = (*p)-> pDir;
    free(aux);

free(Aux);
}

void antecessor(Apontador q, Apontador *r){

    Apontador aux;

    if((*r)->pDir != NULL){
        Antecessor(q, &(*r)->pDir);
        return;
    }
    q-> dado = (*r)-> dado;
    aux = (*r);
    *r = (*r)->pEsq;
    free(aux);
}

void preordem(Apontador *agenda){
    
    
}
int main(){



    return 0;
}
