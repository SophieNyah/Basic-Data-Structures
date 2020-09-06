#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

struct stackNode{
	void* element;
	struct stackNode* next;
};

struct stack{
	struct stackNode* first;
	//struct stackNode* top;
	int size;
};

int stackCreate(Stack *stck){
	struct stack **s = (struct stack**)stck;
	*s = malloc(sizeof(struct stack));
	if(!s){
		return -1;
	}

	(*s)->size = 0;
	(*s)->first = NULL;
	//(*s)->top = NULL;
	return 0;
}

int stackPush(Stack stck, StackElement elem){
	struct stack *s = (struct stack*)stck;

	struct stackNode *aux = malloc(sizeof(struct stackNode));
	if(!aux){
		return -1;
	}
	aux->element = elem;
	aux->next = NULL;

	if(s->first==NULL){
		s->first = aux;
	}else{
		struct stackNode* iterate = s->first;
		while(iterate->next!=NULL){
			iterate = iterate->next;
		}
		iterate->next = aux;
	}

	//s->top = aux;
	s->size = s->size+1;
	return 0;
}

StackElement stackPop(Stack stck){
	struct stack *s = (struct stack*)stck;
	if(s->first==NULL){
		return NULL;
	}

	s->size = s->size-1;
	StackElement *se;
	if(s->first->next==NULL){
		se = s->first->element;
		free(s->first);
		s->first = NULL;
		return se;
	}

	struct stackNode *aux = s->first;
	while(aux->next->next!=NULL){
		aux = aux->next;
	}
	se = aux->next->element;
	free(aux->next);
	aux->next = NULL;
	return se;
}

int stackSize(Stack stck){
	struct stack *s = (struct stack*)stck;
	return s->size;
}

void stackDump(Stack stck){
	struct stack *s = (struct stack*)stck;
	for(int i=s->size;i>0;i++){
		stackPop(stck);
	}
}

void stackFree(Stack *stck){
	struct stack **s = (struct stack**)stck;
	stackDump(*stck);
	free(*s);
	*s = NULL;
}
