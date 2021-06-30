/*
 * main.cpp
 *
 *  Created on: 07-Mar-2020
 *      Author: sunbeam
 */
#include<iostream>
using namespace std;
#include<iomanip>
#include"functions.h"
int main(void)
{
	//char infix[64] = "a*b/c*d/e+f-g*e";
	//char infix[64] = "(a+b)/(c*d)*e/f+g-e";

	char infix[64] = "4*5/7*8-6*9+2";
	char postfix[64] = "";
	//char prefix[64] = "";

	cout << "infix expression  : " << infix << endl;
	infix_to_postfix(infix, postfix);
	//infix_to_prefix(infix, prefix);

	cout << "postfix expression : " << postfix << endl;
	//cout << "prefix expression  : " << prefix << endl;

	cout << "result = " << postfix_evaluation(postfix) << endl;


	return 0;
}




