#ifndef __HANDLER_H__
#define __HANDLER_H__

#include "stack.h"
#include "array.h"
#include "mat.h"
#include "logic.h"
#include "variables.h"
#include "block.h"
#include <stdio.h>


/**
 * \brief Esta funcao auxiliar le uma linha que contem uma string que comeca e acaba com um '"' e separa-a
 * @param buf Linha que contem uma string
 * @param aux String interpretada
 */
int stringParser(char* buf, char* aux);

/**
 * \brief Esta funcao separa a linha do input em cada uma das operaçoes e valores a serem interpretados
 * @param buf Linha com as intrucoes a serem processadas
 * @param stack A stack
 * @param v Variaveis A-Z
 * @param functions Array com os pointers para as funcoes a ser chamadas
 */
void parser(char* buf,STCK* stack,DADOS* v,int (*functions[])(STCK*,char*));

/**
 * \brief Esta funcao chama a funcao apropriada para lidar com blocos
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @param v Variaveis A-Z
 * @param functions Array com os pointers para as funcoes a ser chamadas
 * @returns 1 se o token trabalhar com blocos, se nao 0
 */
int handlerBlock(STCK* stack, char* token, DADOS* v,int (*functions[])(STCK*,char*));

/**
 * \brief Esta funcao chama a funcao apropriada se o token tiver um caracter de A-Z
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @param v Variaveis A-Z
 * @returns 1 se o token tiver um caracter de A-Z, se nao 0
 */
int handlerLetras(STCK* stack, char* token, DADOS* v);

/**
 * \brief Esta funcao chama a funcao apropriada para lidar com o valores numericos
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for um numero, se nao 0
 */
int handlerValores(STCK* stack, char* token);

/**
 * \brief Esta funcao chama a funcao apropriada para lidar com o valor que esta no token
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @param v Variaveis A-Z
 * @param functions Array com os pointers para as funcoes a ser chamadas
 */
void handler(STCK* stack, char* token, DADOS* v,int (*functions[])(STCK*,char*));

/**
 * \brief Esta funcao chama a funcao apropriada quando o token é '~'
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for '~', se nao 0
 */
int til(STCK* stack, char* token);

/**
 * \brief Esta funcao chama a funcao apropriada quando o token é '('
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for '(', se nao 0
 */
int parOpen(STCK* stack, char* token);

/**
 * \brief Esta funcao chama a funcao apropriada quando o token é ')'
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for ')', se nao 0
 */
int parClose(STCK* stack, char* token);

/**
 * \brief Esta funcao chama a funcao apropriada quando o token é '*'
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for '*', se nao 0
 */
int asterisco(STCK* stack, char* token);

/**
 * \brief Esta funcao chama a funcao apropriada quando o token é '/'
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for '/', se nao 0
 */
int slash(STCK* stack, char* token);

/**
 * \brief Esta funcao chama a funcao apropriada quando o token é '+'
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for '+', se nao 0
 */
int plus(STCK* stack, char* token);

/**
 * \brief Esta funcao chama a funcao apropriada quando o token é '#'
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for '#', se nao 0
 */
int hastag(STCK* stack, char* token);

/**
 * \brief Esta funcao chama a funcao apropriada quando o token é '='
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for '=', se nao 0
 */
int equal(STCK* stack, char* token);

/**
 * \brief Esta funcao chama a funcao apropriada quando o token é '<'
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for '<', se nao 0
 */
int lessSign(STCK* stack, char* token);

/**
 * \brief Esta funcao chama a funcao apropriada quando o token é '>'
 * @param token Valor/operacao a ser interpretada
 * @param stack A stack
 * @returns 1 se o token for '>', se nao 0
 */
int greaterSign(STCK* stack, char* token);

#endif