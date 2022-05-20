#ifndef __ARRAY_H__
#define __ARRAY_H__

#include "stack.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

/**
 * \brief Funcao concatena o array n vezes
 * @param stack A stack
 * @returns Retorna 1
 */
int arrMUL(STCK* stack);

/**
 * \brief Funcao concatena um array com um valor ou outro array
 * @param stack A stack
 * @returns Retorna 1
 */
int arrADD(STCK* stack);

/**
 * \brief Funcao concatena dois arrays
 * @param array1 Primeiro array
 * @param array2 Segundo array
 */
void concatArray( struct ARR* array1, struct ARR* array2);

/**
 * \brief Funcao caso o topo da stack seja um numero da o range desse numero caso seja uma array diz o seu tamanho
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1
 */
int enumerate(STCK* stack, char* token);

/**
 * \brief Funcao devolve um array com os n ultimos valores do array no topo
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1
 */
int lastArray(STCK* stack, char* token);

/**
 * \brief Funcao devolve um array com os n primeiros valores do array no topo
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1
 */
int firstArray(STCK* stack, char* token);

/**
 * \brief Funcao chamada para inicializar um array
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1
 */
int initArr(STCK* stack, char* token);

/**
 * \brief Funcao chamada para finalizar um array
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1
 */
int closeArr(STCK* stack, char* token);

/**
 * \brief Funcao chamada para ler uma string entre '"' e guarda-la no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1
 */
int initString(STCK* stack, char* token);

/**
 * \brief Funcao Poem no topo da stack o valor de index n do array que esta no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1
 */
int indexArr(STCK* stack, char* token);

/**
 * \brief Funcao poem os elementos do array na stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1
 */
int arrayToStack(STCK* stack, char* token);

/**
 * \brief Funcao remove o ultimo elem do array e poem o no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1
 */
int rmLastArr(STCK* stack, char* token);

/**
 * \brief Funcao remove o primeiro elem do array e poem o no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1
 */
int rmFirstArr(STCK* stack, char* token);

/**
 * \brief Funcao procura uma string noutra string e coloca no topo da stack o index da primeira ocurrencia
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1
 */
int findArr(STCK* stack, char* token);

/**
 * \brief Funcao le uma linha e guarda-a como uma string no topo da stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1
 */
int inputToStr(STCK* stack, char* token);

/**
 * \brief Funcao da split a uma string sempre que encontra a substring
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1
 */
int splitStr(STCK* stack, char* token);

/**
 * \brief Funcao da split a uma string sempre que encontra um whitespace
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1
 */
int splitSpace(STCK* stack, char* token);

/**
 * \brief Funcao coloca dois caracteres numa nova string
 * @param stack A stack
 * @returns Retorna 1
 */
int charToArray(STCK* stack);

/**
 * \brief Funcao compara a igualdade das 2 strings no topo da stack e poem no topo da stack o resultado logico
 * @param stack A stack
 * @returns Retorna 1
 */
int cmpString(STCK* stack);

/**
 * \brief Funcao compara se a string no topo da stack é menor do que a que esta em segundo na stack
 * @param stack A stack
 * @returns Retorna o valor logico da comparacao
 */
int lStr(STCK* stack);

/**
 * \brief Funcao compara se a string no topo da stack é maior do que a que esta em segundo na stack
 * @param stack A stack
 * @returns Retorna o valor logico da comparacao
 */
int grStr(STCK* stack);

/**
 * \brief Funcao compara se a string no topo da stack é maior do que a que esta em segundo na stack e poem no topo da stack o resultado logico
 * @param stack A stack
 * @returns Retorna 1
 */
int greaterString(STCK* stack);

/**
 * \brief Funcao compara se a string no topo da stack é menor do que a que esta em segundo na stack e poem no topo da stack o resultado logico
 * @param stack A stack
 * @returns Retorna 1
 */
int lesserString(STCK* stack);

/**
 * \brief Funcao le do stdin ate encontrar um null byte depois guarda os valores lidos numa string e faz push dessa string para a stack
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1
 */
int everythingToStr(STCK* stack, char* token);

/**
 * \brief Funcao da split a uma string sempre que encontra um newline
 * @param stack A stack
 * @param token Valor a ser interpretado
 * @returns Retorna 1
 */
int splitNL(STCK* stack, char* token);

/**
 * \brief Funcao auxiliar copia uma string, de tamanho n, b para a
 * @param a String destino
 * @param b String source
 * @param n tamanho da string source
 */
void cpyDados(DADOS *a, DADOS *b, int n);

#endif