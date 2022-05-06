/**
 *@file Ficheiro que contem as funcoes das variaveis (variables.c)
 *
 */
#ifndef __VARIABLES_H__
#define __VARIABLES_H__

#include "stack.h"
#include <stdio.h>

/**
 * \brief Funcao definida no variables.c(libraria)
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @param DADOS Valor do tipo dados
 */

int variablePush(STCK* stack, char* token, DADOS* v);

/**
 * \brief Funcao definida no variables.c(libraria)
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @param DADOS Valor do tipo dados
 */


int variableGet(STCK* stack, char* token, DADOS* v);

#endif