#ifndef DATASTRUCT_STACK_H
#define DATASTRUCT_STACK_H

typedef void* Stack;
typedef void* StackElement;

/*
 * Nota: essa é uma implementação extremamente
 * trivial de uma pilha em C. 
 * As funções Push e Pop tem tempo O(n), mas
 * podem ser facilmente otimizadas para O(1) implementando
 * uma lista duplamente encadeada, ao invés de
 * unicamente encadeada. 
 */ 

//Istancia a pilha.
//O parametro da funcao é o endereço da pilha
int stackCreate(Stack *);

//Insere um elemento na pilha
int stackPush(Stack, StackElement);

//Retira um elemento da pilha, e o devolve
StackElement stackPop(Stack);

//Retira todos os elementos da pilha, mas ela ainda existe e pode ser utilizada
void stackDump(Stack);

//Exclui todos os elementos da pilha, e libera toda a memória da estrutura
//O parametro da funcao é o endereço da pilha
void stackFree(Stack *);

#endif