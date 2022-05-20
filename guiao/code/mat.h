/**
 *@file Ficheiro que contem as funçoes matematicas
 *
 */

#ifndef MATH_H
#define MATH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"
#include "array.h"

/**
 * \def PROTO_OPERATION_SGN(_name,_sinal)
 * Declara funcoes que efetuam operacoes matematicas ( \a _sinal ) entre a e b do tipo DADOS
 */
#define PROTO_OPERATION_SGN(_name,_sinal)       	\
	/**                                         	\   
	 * \brief Funcao que faz _name do DADOS a b 	\
	 * @returns Retorna resultado como um double 	\
	 */                                         	\
	double double_##_name(DADOS b,DADOS a);     	\
	/**                                         	\   
	 * \brief Funcao que faz _name do DADOS a b 	\
	 * @returns Retorna resultado como um integer   \
	 */												\
	long int long_##_name(DADOS b,DADOS a);

PROTO_OPERATION_SGN(ADD,+)
PROTO_OPERATION_SGN(SUB,-)
PROTO_OPERATION_SGN(MUL,*)
PROTO_OPERATION_SGN(DIV,/)

/**
 * \brief Esta funcao exponencia o segundo valor no topo da stack pelo primeiro
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */

int potencia(STCK* stack, char* token);

/**
 * \brief Esta funcao adiciona os dois valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int add(STCK* stack, char* token);

/**
 * \brief Esta funcao subtrai o segundo valor no topo da stack pelo primeiro
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int sub(STCK* stack, char* token);

/**
 * \brief Esta funcao divide o segundo valor no topo da stack pelo primeiro
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int divisao(STCK* stack, char* token);

/**
 * \brief Esta funcao multiplica os dois valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int mul(STCK* stack, char* token);

/**
 * \brief Esta funcao incrementa o valor no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int incr(STCK* stack, char* token);

/**
 * \brief Esta funcao decrementa o valor no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int decr(STCK* stack, char* token);

/**
 * \brief Esta funcao calcula o resto de uma divisao inteira do segundo valor no topo da stack pelo primeiro
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int module(STCK* stack, char* token);

/**
 * \brief Esta funcao calcula o "and(bitwise)" entre os dois valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int and(STCK* stack, char* token);

/**
 * \brief Esta funcao calcula o "or(bitwise)" entre os dois valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int or(STCK* stack, char* token);

/**
 * \brief Esta funcao calcula o "xor(bitwise)" entre os dois valores no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int xor(STCK* stack, char* token);

/**
 * \brief Esta funcao calcula o "not(bitwise)" do valor no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int not(STCK* stack, char* token);



#endif