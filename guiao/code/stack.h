/**
 *@file Biblioteca que contem as funcoes da stack(stack.c)
 */
#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>


/**
 * Usado para saber o tipo em uso na estrutura DADOS
 */
typedef enum{
    CHR = 0, /**< Usado para identificar chars */
    LNG = 1, /**< Usado para identificar longs */
    DOUBLE=3, /**< Usado para identificar doubles */
    ARR=4, /**< Usado para identificar arrays */
    BLK=6 /**< Usado para identificar blocos */
}TYPE;

/**
 * Estrutura de dados usada como base da stack
 */
typedef struct DADOS{
	TYPE type; /**< Usado para identificar qual o tipo de dado que esta a ser usado neste momento */
	char CHR; /**< Variavel para guardar caracters */
	long int LNG; /**< Variavel para guardar integers */
	double DOUBLE; /**< Variavel para guardar floats */
    /** Estrutura usada para criar arrays do tipo DADOS */
	struct ARR{
		struct DADOS *array; /**< Pointer para o array do tipo DADOS */
		int size; /**< Tamanho do array */
		int all_size; /**< Tamanho alocado ao array */
	}*ARR; /**< Espaço para guardar arrays do tipo DADOS */
}DADOS;

/**
 * Estrutura de dados usada como a stack principal do projeto
 */
typedef struct STCK{
	DADOS* val; /**< Pointer para os valores da stack */
	int esp; /**< Apontador do topo da stack */
}STCK;

/**
 * \def PROTO_FSTACK(_name,_type)
 * Declara funcoes fazem push e pop a valores de diferentes tipos ( \a _type )
 */
#define PROTO_FSTACK(_name,_type)												\
	/**      																	\
	 * \brief Funcao que faz push a valores do tipo _name para o topo da stack 	\
	 * @param stack Stack 														\
	 * @param value Valor que vai ser posto no topo da stack 					\
	 */																			\
	void push_##_name(STCK* stack, _type value);								\
	/**																			\
	 * \brief Funcao que faz pop ao valor do tipo _name						 	\
	 * @param stack Stack 														\
	 * @returns					 												\
	 */ 																		\
	_type pop_##_name(STCK* stack);												\


PROTO_FSTACK(LNG,long int)
PROTO_FSTACK(CHR,char)
PROTO_FSTACK(DOUBLE,double)

/**
 * \brief Funcao que faz print para o stdout dos valores de um array do tipo DADOS
 * @param stack A stack
 */
void printArr(struct ARR *stack);

/**			
 * \brief Ve se o tipo do dado é o mesmo do tipo fornecido 	
 * @param dado O Dado a ser comparado
 * @param tipo O Tipo a ser testado
 * @returns true se o dado tiver o mesmo tipo ou caso contrario false						
 */	
bool hastype(DADOS dado, TYPE tipo);

/**		
 * \brief Imprime para o stdout a stack fornecida
 * @param stack A stack
 */
void printstack(STCK* stack);

/**			
 * \brief Testa se uma string tem um '.'
 * @param token String a ser testada
 * @returns true se a string possuir um '.', caso contrario false						
 */	
bool isdecimal(char* token);

/**
 * \brief Esta funcao adiciona valores no topo da stack
 * @returns Retorna 1
 * @param stack A stack
 * @param token Valor a ser interpretado
 */
int valor(STCK* stack, char* token);

/**
 * \brief Esta funcao adiciona valores decimais no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int valor_Double(STCK* stack, char* token);

/**
 * \brief Deepcopy de um Array
 * @param arr Array a ser copiado
 * @returns Pointer para o novo Array
 */
struct ARR* copyArr(struct ARR *arr);

/**
 * \brief Esta funcao transforma uma string no topo da stack para um long
 * @param stack A stack
 */
void strToLng(STCK* stack);

/**
 * \brief Esta funcao muda o tipo da variavel no topo da stack para LONG
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int toLNG(STCK* stack, char* token);

/**
 * \brief Esta funcao transforma uma string no topo da stack para um double
 * @param stack A stack
 */
void strToDouble(STCK* stack);

/**
 * \brief Esta funcao muda o tipo da variavel no topo da stack para DOUBLE
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int toDouble(STCK* stack, char* token);

/**
 * \brief Esta funcao faz push a uma copia do valor na nºesima posicao
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int cpyStack(STCK* stack, char* token);

/**
 * \brief Esta funcao muda o tipo da variavel no topo da stack de LONG para CHAR
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int toCHR(STCK* stack, char* token);

 /**
 * \brief Esta funcao roda os 3 elementos no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int rodar(STCK* stack, char* token);

/**
 * \brief Esta funcao troca os 2 valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int trocar(STCK* stack, char* token);

/**
 * \brief Esta funcao faz push a uma copia do valor no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int duplicar(STCK* stack, char* token);

/**
 * \brief Esta funcao faz ""Pop""
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int removeTop(STCK* stack, char* token);

/**
 * \brief Esta funcao faz print para o stdout do valor no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int printTopo(STCK* stack, char* token);

/**
 * \brief Esta funcao passa o topo da stack para o tipo de string
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int toString(STCK* stack, char* token);

#endif