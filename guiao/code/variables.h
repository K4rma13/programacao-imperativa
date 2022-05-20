/**
 * @file Ficheiro que contem as declaracoes das funcoes das variaveis
 *
 */
#ifndef __VARIABLES_H__
#define __VARIABLES_H__

#include "stack.h"
#include "array.h"
#include <stdio.h>

/**
 * \brief Funcao faz push da variavel correspondente para a stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @param DADOS Variaveis A-Z
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */

int variablePush(STCK* stack, char* token, DADOS* v);

/**
 * \brief Funcao copia o topo da stack e guarda o na variavel correspondente
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @param DADOS Variaveis A-Z
 * @returns Retorna 1 se o token for o correto se nao retorna 0
 */
int variableGet(STCK* stack, char* token, DADOS* v);

#endif