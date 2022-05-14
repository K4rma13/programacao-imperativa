/**
 *@file Biblioteca que contem as funcoes matematicas (mat.c)
 */
#ifndef MATH_H
#define MATH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack.h"
#include "array.h"

#define PROTO_OPERATION_SGN(_name,_sinal)       \
    double double_##_name(DADOS b,DADOS a);     \
    long int long_##_name(DADOS b,DADOS a);     

PROTO_OPERATION_SGN(ADD,+)
PROTO_OPERATION_SGN(SUB,-)
PROTO_OPERATION_SGN(MUL,*)
PROTO_OPERATION_SGN(DIV,/)

/**
 * \brief Funcao definida no mat.c(libraria)
 * @param DADOS valor do tipo dados
 * @param DADOS valor do tipo dados
 
 */
double addition(DADOS a,DADOS b);
/**
 * \brief Funcao definida no mat.c(libraria)
 * @param stack A stack
 * @param token Valor a ser interpretado
 
 */

int potencia(STCK* stack, char* token);

/**
 * \brief Funcao definida no mat.c(libraria)
 * @param stack A stack
 * @param token Valor a ser interpretado
 
 */
int add(STCK* stack, char* token);

/**
 * \brief Funcao definida no mat.c(libraria)
 * @param stack A stack
 * @param token Valor a ser interpretado
 
 */
int sub(STCK* stack, char* token);

/**
 * \brief Funcao definida no mat.c(libraria)
 * @param stack A stack
 * @param token Valor a ser interpretado
 
 */
int divisao(STCK* stack, char* token);

/**
 * \brief Funcao definida no mat.c(libraria)
 * @param stack A stack
 * @param token Valor a ser interpretado
 
 */
int mul(STCK* stack, char* token);

/**
 * \brief Funcao definida no mat.c(libraria)
 * @param stack A stack
 * @param token Valor a ser interpretado
 
 */
int incr(STCK* stack, char* token);

/**
 * \brief Funcao definida no mat.c(libraria)
 * @param stack A stack
 * @param token Valor a ser interpretado
 
 */
int decr(STCK* stack, char* token);

/**
 * \brief Funcao definida no mat.c(libraria)
 * @param stack A stack
 * @param token Valor a ser interpretado
 
 */
int module(STCK* stack, char* token);

/**
 * \brief Funcao definida no mat.c(libraria)
 * @param stack A stack
 * @param token Valor a ser interpretado
 
 */
int and(STCK* stack, char* token);

/**
 * \brief Funcao definida no mat.c(libraria)
 * @param stack A stack
 * @param token Valor a ser interpretado
 
 */
int or(STCK* stack, char* token);

/**
 * \brief Funcao definida no mat.c(libraria)
 * @param stack A stack
 * @param token Valor a ser interpretado
 
 */
int xor(STCK* stack, char* token);

/**
 * \brief Funcao definida no mat.c(libraria)
 * @param stack A stack
 * @param token Valor a ser interpretado
 
 */
int not(STCK* stack, char* token);



#endif