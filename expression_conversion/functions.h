/*
 * functions.h
 *
 *  Created on: 07-Mar-2020
 *      Author: sunbeam
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_


void infix_to_postfix(char *in, char *post);
void infix_to_prefix(char *in, char *pre);
bool is_operand(char ch);
int priority(char opr);
void string_reverse(char *str);
int postfix_evaluation(char *post);
int calculate(int op1, int op2, char opr);


#endif /* FUNCTIONS_H_ */
