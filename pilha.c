#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa{
    char nome[30];
    int idade;
}Pessoa;

struct Pilha{
    struct Pessoa *pessoa;
    int topo;
    int base;
}Pilha;

void reset(struct Pilha *pilha){

	pilha->topo = 0;
	pilha->base = 0;
	pilha->pessoa = NULL;

}
int push(struct Pilha *pilha, struct Pessoa *item){

	++pilha->topo;

	(*pilha).pessoa = realloc((*pilha).pessoa, sizeof(struct Pessoa) * pilha->topo);

	if(pilha->pessoa == NULL){

		printf("Erro na alocação.");
		return 0;
	}
	else{

	strcpy(pilha->pessoa[pilha->topo-1].nome, item->nome);
	pilha->pessoa[pilha->topo-1].idade = item->idade;

	return 1;
	}

}
int empty(struct Pilha *pilha){

    if(pilha->topo == 0){
        return 1;
    }
	return 0;
}
struct Pessoa pop(struct Pilha *pilha){

    struct Pessoa pessoa;

	if( empty(pilha) == 0 ){

	}
	else{
        --pilha-> topo;

        strcpy(pessoa.nome, pilha->pessoa->nome );
        pessoa.idade = pilha->pessoa->idade;


			return pessoa;
	}
}
void clear(){

}

void deletapessoa(struct Pilha *pilha, char *nome){
    
    struct Pilha buffer;
    
    reset
    

}
int main()
{
	struct Pilha pilha;

	int menu;
	struct Pessoa item;

	reset(&pilha);

	printf(" 0. Insere pessoa. \n 1. Deleta pessoa do topo. \n 2. Delete pessoa por nome. \n 3. Limpa a pilha. \n 4. Lista na tela as pessoas. \n 5. Sair do programa.\n");
	scanf("%d", &menu);

	while(menu !=5){

		if(menu == 0){

			printf("\nDigite o nome: ");
			scanf("%s", item.nome);
			printf("\nDigita a idade: ");
			scanf("%d", &item.idade);

			push(&pilha, &item);
		}
		if(menu == 1){

			pop(&pilha);
		}
		
		if(menu == 2){
            
            printf("\nDigite o nome: ");
			scanf("%s", item.nome);
			
            deletapessoa(&pilha, &item.nome);
		
		
		}

		printf("0. Insere pessoa. \n 1. Deleta pessoa do topo. \n 2. Delete pessoa por nome. \n 3. Limpa a pilha. \n 4. Lista na tela as pessoas. \n 5. Sair do programa.\n");
		scanf("%d", &menu);
	}


	return 0;
}


