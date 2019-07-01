#include <stdio.h>
#include <stdlib.h>

typedef struct registro{
    char nome[30];
    int telefone;
}registro;

typedef struct No *Apontador;

typedef struct No{
     registro dado;
     Apontador pEsq, pDir;
  }No;

int insere(registro x, Apontador *p);
void retira(registro x, Apontador *p);
void inicializa(Apontador *agenda);
void antecessor(Apontador q, Apontador *r);
void preordem(Apontador *agenda);
void posordem(Apontador *agenda);
void central(Apontador *agenda);
void pesquisa( registro *x, Apontador agenda);
int Altura(Apontador *tree);
int FT(Apontador *tree);
int balance(Apontador *ppRaiz);

int insere(registro x, Apontador *tree){
    if(*tree == NULL){
        *tree = (Apontador) malloc (sizeof(No));
        (*tree)-> dado = x;
        (*tree)->pEsq = NULL;
        (*tree)->pDir = NULL;
        return 1;
    }
    else if(x.telefone < (*tree)->dado.telefone){
        if(insere(x, &(*tree)->pEsq)){
            if(balance(tree)){
                return 0;
            }
            else{
                return 1;
            }
        }
    }
    else if(x.telefone > (*tree)->dado.telefone){
        if(insere(x, &(*tree)->pDir)){
            if(balance(tree)){
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
void inicializa(Apontador *agenda){
    *agenda = NULL;
}
void retira(registro x, Apontador *p){
    Apontador aux;

    if(*p == NULL){
        printf("Erro: Registro não existente.\n");
        return;
    }
    if(x.telefone < (*p)->dado.telefone){
        retira(x, &(*p)->pEsq);
        return;
    }
    if(x.telefone > (*p)->dado.telefone){
        retira(x, &(*p)->pDir);
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
        printf("Nome: %s, telefone: %d.\n",(*agenda)->dado.nome, (*agenda)->dado.telefone);
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
        printf("Nome: %s, telefone: %d.\n",(*agenda)->dado.nome, (*agenda)->dado.telefone);
    }
}
void central(Apontador *agenda){

    if(*agenda == NULL){
        return;
    }
    else{
        central(&((*agenda)->pEsq));
        printf("Nome: %s, telefone: %d.\n",(*agenda)->dado.nome, (*agenda)->dado.telefone);
        central(&((*agenda)->pDir));
    }
}
void pesquisa( registro *x, Apontador agenda){

    if(agenda == NULL){
        printf("Erro : Registro nao esta presente na arvore\n");
        return;
    }
    if(x->telefone < agenda->dado.telefone){
        pesquisa(x, agenda->pEsq);
        return;
    }
    if(x->telefone > (agenda)->dado.telefone){
        pesquisa(x, agenda->pDir);
        return;
    }
    else{
        *x = agenda->dado;
    }
}
int FT(Apontador *tree){
    if(tree == NULL){
        return 0;
    }
    return Altura((*tree)->pEsq) - Altura((*tree)->pDir);
}
int Altura(Apontador *tree){

    int esq, dir;

    if(tree == NULL){
        return 0;
    }
    esq = Altura((*tree)->pEsq);
    dir = Altura((*tree)->pDir);

    if(esq>dir){
        return esq+1;
    }
    else{
        return dir+1;
    }
}
void RSD (Apontador *tree){
    Apontador aux;

    aux = (*tree)->pEsq;
    (*tree)->pEsq = (*tree)->pDir;
    (*tree)->pDir = tree;
    tree = aux;
}
void RSE (Apontador *tree){
int balancaesq(Apontador *tree){
    int fbe = FB ( (*tree)->pEsq );
    if ( fbe > 0 ){
        RSD(tree);
        return 1;
    }
  else if (fbe < 0 ){ /* Rotação Dupla Direita */
    RSE( &((*tree)->pEsq) );
    RSD( *tree ); /* &(*ppRaiz) */
    return 1;
  }
  return 0;
}
int BalancaDireita(Apontador *tree){
int balance(Apontador *ppRaiz){
 	int fb = FB(ppRaiz);

 	if( fb > 0)
 		return BalancaEsquerda(&ppRaiz);
 	else if(fb < -1)
 		return BalancaDireita(&ppRaiz);
 	else
 		return 0;
 }
 	int fbd = FB((*tree)->pDir);
 	if( fbd < 0 ){
 		RSE(tree);
 		return 1;
 	}
 	else if(fbd > 0){ /* Rotacao dupla para Esquerada */
 		RSD(&((*tree)->pDir));
 		RSE(tree);
 		return 1;
 	}
 	return 0;
 }
    Apontador aux;

    aux = (*tree)->pDir;
    (*tree)->pDir = (*tree)->pEsq;
    (*tree)->pEsq = tree;
    tree = aux;
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
                printf("\nDigite a telefone: ");
                scanf("%d", &aux.telefone);
                insere(aux, &agenda);
            break;
            case 2:
                printf("\nDigite a telefone: ");
                scanf("%d", &aux.telefone);
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
                printf("\nDigite a telefone: ");
                scanf("%d", &aux.telefone);
                pesquisa(&aux, agenda);
            break;
        }
    }while(e<=5 && e>0);


    return 0;
}
