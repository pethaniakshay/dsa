/*
 * functions.cpp
 *
 *  Created on: 07-Mar-2020
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<stack>
#include<cstring>
#include"functions.h"


int postfix_evaluation(char *post)
{
	int result;
	stack<int> s;

	//start scanning postfix string from left to right
	for( int i = 0 ; post[i] != '\0' ; i++ )
	{
		//if the cur ele is an operand
		if( is_operand(post[i]))
		{
			//push it into the stack
			s.push(post[i]-'0');
		}
		else//if the cur ele is an operator
		{
			//pop two ele's from the stack
			//first popped ele will be the second operand
			int op2 = s.top(); s.pop();
			//second popped ele will be the first operand
			int op1 = s.top(); s.pop();
			result = calculate(op1, op2, post[i]);
			//push result into the stack
			s.push(result);
		}
	}//end of for loop

	//pop the final result from the stack and return it to the calling function
	result = s.top(); s.pop();
	return result;
}

int calculate(int op1, int op2, char opr)
{
	switch(opr)
	{
	case '+': return ( op1 + op2 );
	case '-': return ( op1 - op2 );
	case '*': return ( op1 * op2 );
	case '/': return ( op1 / op2 );
	case '%': return ( op1 % op2 );
	}
}

void infix_to_postfix(char *in, char *post)
{
	int j=0;
	stack<int> s;

	//start scanning infix expression (string) from left to right till end of string
	for( int i = 0 ; in[i] != '\0' ; i++ )
	{
		//if the cur ele is an operand
		if( is_operand(in[i]) )
		{
			//append it into the postfix string
			post[j++] = in[i];
		}
		else
		if( in[i] == '(')//if the cur is an opening brace
		{
			//push it into the stack
			s.push(in[i]);
		}
		else
		if( in[i] == ')')//if the cur is a closing brace
		{
			//pop all ele'e from the stack one by one and append them into the
			//postfix string till its corresponding opening brace do not occures
			while( s.top() != '(' )
			{
				post[j++] = s.top();
				s.pop();
			}
			//pop an opening brace from the stack
			s.pop();
		}
		else//if the cur is an operator
		{
			//if stack is not empty && priority(topmost ele) >= priority(cur ele)
			while( !s.empty() && priority(s.top()) >= priority(in[i]))
			{
				//pop ele from the stack and append it into the postfix string
				post[j++] = s.top();
				s.pop();
			}

			//push the cur ele into the stack
			s.push(in[i]);
		}

	}//end of for loop - repeat above steps till end of the infix string

	//pop all ele's one by one from the stack and append them into the postfix string
	//till stack not becomes empty
	while( !s.empty())
	{
		post[j++] = s.top();
		s.pop();
	}

	post[j] = '\0';
}

/*
//function to convert given infix expression into its equivalent postfix
void infix_to_postfix(char *in, char *post)
{
	int j=0;
	stack<int> s;

	//start scanning infix expression (string) from left to right till end of string
	for( int i = 0 ; in[i] != '\0' ; i++ )
	{
		//if the cur ele is an operand
		if( is_operand(in[i]) )
		{
			//append it into the postfix string
			post[j++] = in[i];
		}
		else//if the cur is an operator
		{
			//if stack is not empty && priority(topmost ele) >= priority(cur ele)
			while( !s.empty() && priority(s.top()) >= priority(in[i]))
			{
				//pop ele from the stack and append it into the postfix string
				post[j++] = s.top();
				s.pop();
			}

			//push the cur ele into the stack
			s.push(in[i]);
		}

	}//end of for loop - repeat above steps till end of the infix string

	//pop all ele's one by one from the stack and append them into the postfix string
	//till stack not becomes empty
	while( !s.empty())
	{
		post[j++] = s.top();
		s.pop();
	}

	post[j] = '\0';
}
*/

//function to convert given infix expression into its equivalent prefix
void infix_to_prefix(char *in, char *pre)
{
	int j=0;
	stack<int> s;

	//start scanning infix expression (string) from right to left
	for( int i = strlen(in)-1 ; i >= 0 ; i-- )
	{
		//if the cur ele is an operand
		if( is_operand(in[i]) )
		{
			//append it into the prefix string
			pre[j++] = in[i];
		}
		else//if the cur is an operator
		{
			//if stack is not empty && priority(topmost ele) > priority(cur ele)
			while( !s.empty() && priority(s.top()) > priority(in[i]))
			{
				//pop ele from the stack and append it into the prefix string
				pre[j++] = s.top();
				s.pop();
			}

			//push the cur ele into the stack
			s.push(in[i]);
		}

	}//end of for loop - repeat above steps till end of the infix string

	//pop all ele's one by one from the stack and append them into the prefix string
	//till stack not becomes empty
	while( !s.empty())
	{
		pre[j++] = s.top();
		s.pop();
	}

	pre[j] = '\0';
	//reverse the prefix string
	string_reverse(pre);
}

bool is_operand(char ch)
{
	return ( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <= 57) );
}

//we are defining priority for a an operators - programmatically
int priority(char opr)
{
	switch(opr)
	{
	case '(': return 0;

	case '+':
	case '-': return 1;

	case '*':
	case '/':
	case '%': return 2;
	}
}


void string_reverse(char *str)
{
	char *left = str;
	char *right = str;

	while(*right)
		right++;

	right--;

	while( left <= right )
	{
		char temp = *left;
		*left = *right;
		*right = temp;

		left++;
		right--;
	}
}










