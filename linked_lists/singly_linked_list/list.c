#include<stdlib.h>
#include"list.h"

struct Node{
	struct Node *next;
	LinkedListElement element;
};

struct Head{
	struct Node *first;
	int length;
};

int ListCreate(LinkedList *lst){
	struct Head **l = (struct Head**)lst;
	*l = malloc(sizeof(struct Head));
	if(!(*l)){
		return -1;
	}

	(*l)->first = NULL;
	(*l)->length = 0;
	return 0;
}

int ListGetLength(LinkedList lst){
	struct Head *l = (struct Head*)lst;
	return l->length;
}

int ListInsert(LinkedList lst, LinkedListElement elem){
	struct Head *l = (struct Head*)lst;
	struct Node *aux = malloc(sizeof(struct Node));
	if(!aux){
		return -1;
	}

	//O novo nó é inserido na primeira posição da lista,
	// assim não precisamos percorre-la para realizar a inserção.
	aux->next = l->first;
	l->first = aux;
	aux->element = elem;

	l->length = l->length + 1;
	return 0;
}

LinkedListElement ListGetByIndex(LinkedList lst, int index){
	struct Head *l = (struct Head*)lst;
	struct Node *aux = l->first;
	
	//retorna erro caso o indice passado seja inválido
	if(index >= l->length || index < 0){
		return NULL;
	}

	//Se o nó não for o primeiro
	if(index > 0){
		//Percorre a lista até encontrar o indice desejado
		int i=0;
		while(i < index){
			aux = aux->next;
			i++;
		}
	}

	return aux->element;
}

int ListDeleteByIndex(LinkedList lst, int index){
	struct Head *l = (struct Head*)lst;
	struct Node *aux = l->first;
	struct Node *auxPrev = aux;

	//retorna erro caso o indice passado seja inválido
	if(index >= l->length || index < 0){
		return -1;
	}

	//caso especial quando o indice é 0
	if(index == 0){
		l->first = aux->next;
	}
	//caso não seja o primeiro nó
	else{
		//Percorre a lista até encontrar o indice desejado
		int i=0;
		while(i < index){
			auxPrev = aux;
			aux = aux->next;
			i++;
		}
	}

	auxPrev->next = aux->next;
	free(aux);

	l->length = l->length -1;
	return index;
}

void ListFree(LinkedList *lst){
	struct Head **l = (struct Head**)lst;
	struct Node *aux = (*l)->first;
	struct Node *auxPrev = (*l)->first;

	//Exclui todos os nós e elementos da lista
	while(aux != NULL){
		auxPrev = aux;
		aux = aux->next;
		free(auxPrev);
	}
	//Exclui a cabeça da lista
	free(*l);
	*l = NULL;
}
