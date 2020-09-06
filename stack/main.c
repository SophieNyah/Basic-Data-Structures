#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

//função main com alguns testes da pilha
int main(){
	Stack s = NULL;
	int *x[60], *y;
	stackCreate(&s);
	for(int i=0;i<60;i++){
		x[i] = malloc(sizeof(int));
		*x[i] = i;
		stackPush(s, (void*)x[i]);
	}

	*x[7] = 100;
	
/*	stackDump(s);
	y = stackPop(s);
	if(!y){
		printf("nao Y\n");
	}

	stackFree(&s);
	if(!s){
		printf("nao S\n");
	}
*/
	for(int i=0;i<60;i++){
		y = stackPop(s);
		printf("%d\n", *y);
	}
	stackFree(&s);

	return 0;
}