#ifndef DATASTRUCT_SINGLY_LINKED_LIST
#define DATASTRUCT_SINGLY_LINKED_LIST

/*
 * Implementação trivial de uma lista unicamente encadeada genérica.
 * Nota: essa implementação guarda uma referência para os elementos,
 *  e não uma cópia deles. Isso significa que a liberação de memória
 *  de cada elemento deve ser feita pelo próprio programador.
*/

typedef void* LinkedList;
typedef void* LinkedListElement;

//Instância a cabeça da lista
//Parâmetro: endereço da lista a ser criada
//Retorno: -1 se falha, 0 se sucesso
int ListCreate(LinkedList *);

//Getter para a quantidade de elementos na lista
//Parâmetro: variável lista
int ListGetLength(LinkedList);

//Insere um elemento no início da lista
//Parâmetro: variável lista
//Retorno: -1 se falha, 0 se sucesso
int ListInsert(LinkedList, LinkedListElement);

//Pega o i-ésimo elemento da lista
//Parâmetro: variável lista, indice do elemento
//Retorno: NULL se indice inválido, ponteiro para o elemento caso contrário
LinkedListElement ListGetByIndex(LinkedList, int index);

//Exclui o i-ésimo nó da lista
//Parâmetro: variável lista, indice do nó
//Retorno: NULL se indice inválido, indice do nó excluído caso contrário
int ListDeleteByIndex(LinkedList, int index);

//Libera toda a memória da lista, junto com todos os nós e elementos
//Parâmetro: endereço da lista a ser deletada
//Pós-condição: lista liberada, elementos individuais ainda alocados
//CUIDADO: cada elemento deve ser liberado por conta do programador
void ListFree(LinkedList *);

#endif