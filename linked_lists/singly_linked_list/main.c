#include<stdio.h>
#include<stdlib.h>
#include"list.h"

int main(){
	LinkedList l;
	ListCreate(&l);
	int *x[10], *y;

	for(int i=0;i<10;i++){
		x[i] = malloc(sizeof(int));
		*x[i] = i;
		ListInsert(l, (LinkedListElement)x[i]);
		printf("tamanho: %d\n", ListGetLength(l));
	}

	*x[7]=200;

	for(int i=0;i<10;i++){
		y = ListGetByIndex(l, i);
		if(y){
			printf("%d\n", *y);
		}else{
			printf("deu erro no indice %d\n", i);
		}
	}

	for(int i=0;i<10;i++){
		free(x[i]);
	}
	ListFree(&l);

	return 0;
}