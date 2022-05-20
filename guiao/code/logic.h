/**
 *@file Biblioteca que contem as funcoes logicas(logic.c)
 */
#ifndef __LOGIC_H__

#define __LOGIC_H__

#include "array.h"
#include <stdio.h>
#include "stack.h"

/**
 * \def OPERATION_PROTOO(_name,_sinal)
 * Declara as funcoes que aplicam comparaçoes entre a e b do tipo DADOS
 */
#define OPERATION_PROTOO(_name)			\
	bool OP_##_name(DADOS b,DADOS a);	\


OPERATION_PROTOO(SMALL)

OPERATION_PROTOO(BIG)

OPERATION_PROTOO(EQUAL)

/**
 * \brief Esta funcao faz a comparacao entre o valor do topo da stack com 0 
 * @param DADOS Recebe um valor do tipo dados
 * @returns Retorna False se o valor for igual a zero e True caso contrario
 */
bool OP_FALSE(DADOS a);

/**
 * \brief Esta funcao faz um AND logico entre os 2 valores a e b
 * @param DADOS Recebe um valor do tipo dados
 * @param DADOS Recebe um valor do tipo dados
 * @returns Retorna True se ambos os valores forem diferentes a zero caso contrario False
 */
bool OP_TRUE(DADOS b, DADOS a);

/**
 * \brief Esta funcao faz um OR logico entre os valores a e b
 * @param DADOS Recebe um valor do tipo dados
 * @param DADOS Recebe um valor do tipo dados
 * @returns Retorna True se um dos dois valores for igual a 0
 */
bool OP_veryFalse(DADOS b, DADOS a);

/**
 * \brief Esta funcao nega o valor logico do elemento do topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se for token for o correto se nao retorna 0
 */
int isFalse(STCK* stack, char* token);

/**
 * \brief Esta funcao verifica se os dois valores do topo da stack sao iguais se sim coloca 1 no topo da stack senao coloca 0
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se for token for o correto se nao retorna 0
 */
int isEqual(STCK* stack, char* token);

/**
 * \brief Esta funcao verifica se o segundo valor do topo da stack e menor que o primeiro se sim coloca 1 no topo da stack senao coloca 0
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se for token for o correto se nao retorna 0
 */
int isSmall(STCK* stack, char* token);

/**
 * \brief Esta funcao verifica se o segundo valor do topo da stack e maior que o primeiro se sim coloca 1 no topo da stack senao coloca 0
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se for token for o correto se nao retorna 0
 */
int isBig(STCK* stack,char* token);

/**
 * \brief Esta funcao verifica se o terceiro valor do topo da stack é zero se nao for coloca no topo da stack o segundo valor, caso contrario coloca no topo da stack o primeiro valor
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se for token for o correto se nao retorna 0
 */
int ifThenElse(STCK* stack,char* token);

/**
 * \brief Esta funcao faz um AND(shortcut) com os 2 valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se for token for o correto se nao retorna 0
 */
int logicalAnd(STCK* stack, char* token);

/**
 * \brief Esta funcao faz um OR(shortcut) com os 2 valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se for token for o correto se nao retorna 0
 */
int logicalOr(STCK* stack, char* token);

/**
 * \brief Esta funcao analisa os dois valores do topo da stack e coloca o maior deles no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se for token for o correto se nao retorna 0
 */
int logicalGreater(STCK* stack, char* token);

/**
 * \brief Esta funcao analisa os dois valores do topo da stack e coloca o menor deles no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se for token for o correto se nao retorna 0
 */
int logicalLess(STCK* stack, char* token);

#endif