#include <stdio.h>
#include <stdlib.h>

typedef struct registro{
    char nome[30];
    int key;
}registro;

typedef struct No *Apontador;

typedef struct No{
     registro dado;
     Apontador pEsq, pDir;
  }No;

int insere(registro x, Apontador *p);
void retira(registro x, Apontador *p);
void inicializa(Apontador *p);
void antecessor(Apontador q, Apontador *r);
void preordem(Apontador *p);
void posordem(Apontador *p);
void central(Apontador *p);
void pesquisa( registro *x, Apontador p);
int Altura(Apontador *p);
int FT(Apontador *p);
int balance(Apontador *p);
Apontador newNode();

void inicializa(Apontador *p){
    *agenda = NULL;
}
Apontador newNode(){
    Apontador p;

    p = (Apontador) malloc (sizeof(No));

    if(p == NULL){
        printf("\nErro de alocação.");
       exit(1);
    }
    else{
        return p;
    }
}
void RSD (Apontador *p){
    Apontador aux;
    aux = (*p)->pEsq;
    (*p)->pEsq = (*p)->pDir;
    (*p)->pDir = p;
    p = aux;
}
void RSE (Apontador *p){
    Apontador aux;
    aux = (*p)->pDir;
    (*p)->pDir = aux->pEsq;
    aux->pEsq = p;
    p = aux;
} 
int FB(Apontador *p){
    if(p == NULL){
        return 0;
    }
    return Altura((*p)->pEsq) - Altura((*p)->pDir);
}
int Altura(Apontador *p){

    int esq, dir;

    if(p == NULL){
        return 0;
    }
    esq = Altura((*p)->pEsq);
    dir = Altura((*p)->pDir);

    if(esq>dir){
        return esq+1;
    }
    else{
        return dir+1;
    }
}
int balance(Apontador *p){
 	int fb = FB(p);

 	if( fb > 1)
 		return BalancaEsquerda(&p);
 	else if(fb < -1)
 		return BalancaDireita(&p);
 	else
 		return 0;
}
int balancaEsquerda(Apontador *p){
    int fbe = FB ((*p)->pEsq);
    if ( fbe > 0 ){
        RSD(p);
        return 1;
    }
    else if (fbe < 0 ){ /* Rotação Dupla Direita */
        RSE( &((*p)->pEsq) );
        RSD( *p ); /* &(*ppRaiz) */
        return 1;
    }
  return 0;
}
int balancaDireita(Apontador *p){
    int fbd = FB ((*p)->pDir);
    if ( fbd < 0 ){
        RSE(p);
        return 1;
    }
    else if (fbe > 0 ){ /* Rotação Dupla Esquerda */
        RSD( &((*p)->pDir) );
        RSE( *p ); /* &(*ppRaiz) */
        return 1;
    }
  return 0;
}
int insere(registro x, Apontador *p){

    if(*p == NULL){
        *p = newNode();
        (*p)-> dado = x;
        (*p)->pEsq = NULL;
        (*p)->pDir = NULL;
        return 1;
    }
    else if(x.key < (*p)->dado.key){
        if(insere(x, &(*p)->pEsq)){
            if(balance(p)){
                return 0;
            }
            else{
                return 1;
            }
        }
    }
    else if(x.key > (*p)->dado.key){
        if(insere(x, &(*p)->pDir)){
            if(balance(p)){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            return 0;
        }
    }

    else{
        printf("Erro: Registro já existente.\n");
        return 0;
    }
}
void retira(registro x, Apontador *p){
    Apontador aux;

    if(*p == NULL){
        printf("Erro: Registro não existente.\n");
        return;
    }
    if(x.key < (*p)->dado.key){
        retira(x, &(*p)->pEsq);
        return;
    }
    else if(x.key > (*p)->dado.key){
        retira(x, &(*p)->pDir);
        return;
    }
    else{
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
    }
    balance(p);

}
void antecessor(Apontador q, Apontador *r){

    Apontador aux;

    if((*r)->pDir != NULL){
        antecessor(q, &(*r)->pDir);
        return;
    }
    q-> dado = (*r)-> dado;
    aux = (*r);
    *r = (*r)->pEsq;
    free(aux);
}
void preordem(Apontador *agenda){

    if(*agenda == NULL){
        return;
    }
    else{
        printf("Nome: %s, key: %d.\n",(*agenda)->dado.nome, (*agenda)->dado.key);
        preordem(&((*agenda)->pEsq));
        preordem(&((*agenda)->pDir));

    }
}
void posordem(Apontador *agenda){

    if(*agenda == NULL){
        return;
    }
    else{
        posordem(&((*agenda)->pEsq));
        posordem(&((*agenda)->pDir));
        printf("Nome: %s, key: %d.\n",(*agenda)->dado.nome, (*agenda)->dado.key);
    }
}
void central(Apontador *agenda){

    if(*agenda == NULL){
        return;
    }
    else{
        central(&((*agenda)->pEsq));
        printf("Nome: %s, key: %d.\n",(*agenda)->dado.nome, (*agenda)->dado.key);
        central(&((*agenda)->pDir));
    }
}
void pesquisa( registro *x, Apontador agenda){

    if(agenda == NULL){
        printf("Erro : Registro nao esta presente na arvore\n");
        return;
    }
    if(x->key < agenda->dado.key){
        pesquisa(x, agenda->pEsq);
        return;
    }
    if(x->key > (agenda)->dado.key){
        pesquisa(x, agenda->pDir);
        return;
    }
    else{
        *x = agenda->dado;
    }
}
int main(){

    int e;
    registro aux;
    Apontador *agenda;

    inicializa(&agenda);
    do{
        printf("\nEscolha:\n1- Inserir\n2- Retirar \n3- Listar em preordem \n4- Listar em posordem \n5- Listar em central \n6- Pesquisa \nOutra opção para sair.\n");
        scanf("%d", &e);

        switch(e){
            case 1:
                printf("\nDigite o nome: ");
                scanf("%s", aux.nome);
                printf("\nDigite a key: ");
                scanf("%d", &aux.key);
                insere(aux, &agenda);
            break;
            case 2:
                printf("\nDigite a key: ");
                scanf("%d", &aux.key);
                retira(aux, &agenda);
            break;
            case 3:
                printf("\nPreordem:\n ");
                preordem(&agenda);
            break;
            case 4:
                printf("\nPosordem:\n ");
                posordem(&agenda);
            break;
            case 5:
                printf("\nCentral:\n ");
                central(&agenda);
            break;
            case 6:
                printf("\nDigite a key: ");
                scanf("%d", &aux.key);
                pesquisa(&aux, agenda);
            break;
        }
    }while(e<=5 && e>0);


    return 0;
}

