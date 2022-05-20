#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "stack.h"
#include "array.h"
#include "handler.h"
#include <stdio.h>

/**
 * \brief Funcao cria um bloco
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1
 */
int createBlock(STCK* stack, char* token);

/**
 * \brief Funcao executa o bloco no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @param v Variaveis A-Z
 * @param functions Array com os pointers para as funcoes a ser chamadas
 * @returns Retorna 1
 */
int executeBlock(STCK* stack, char* token,DADOS* v,int (*functions[])(STCK*,char*));

/**
 * \brief Funcao compara se a string a é menor do que a string b
 * @param stack A stack
 * @returns Retorna o valor logico da comparacao
 */
bool smallArray(DADOS a, DADOS b);

/**
 * \brief Funcao aplica o bloco no topo da stack ao array/string em segundo na stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @param v Variaveis A-Z
 * @param functions Array com os pointers para as funcoes a ser chamadas
 * @returns Retorna 1
 */
int mapBlock(STCK* stack, char* token,DADOS* v,int (*functions[])(STCK*,char*));

/**
 * \brief Funcao faz fold sobre array em segundo na stack usando o bloco no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @param v Variaveis A-Z
 * @param functions Array com os pointers para as funcoes a ser chamadas
 * @returns Retorna 1
 */
int foldBlock(STCK* stack, char* token,DADOS* v,int (*functions[])(STCK*,char*));

/**
 * \brief Funcao ordena usando o bloco
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @param v Variaveis A-Z
 * @param functions Array com os pointers para as funcoes a ser chamadas
 * @returns Retorna 1
 */
int ordBlock(STCK* stack, char* token,DADOS* v,int (*functions[])(STCK*,char*));

/**
 * \brief Funcao filtra um array/string utilizando um bloco
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @param v Variaveis A-Z
 * @param functions Array com os pointers para as funcoes a ser chamadas
 * @returns Retorna 1
 */
int filterBlock(STCK* stack, char* token,DADOS* v,int (*functions[])(STCK*,char*));

/**
 * \brief Funcao executa o bloco enquanto ele deixar um truthy no topo da stack; Remove o truthy
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @param v Variaveis A-Z
 * @param functions Array com os pointers para as funcoes a ser chamadas
 * @returns Retorna 1
 */
int whileBlock(STCK* stack, char* token,DADOS* v,int (*functions[])(STCK*,char*)); 

#endif