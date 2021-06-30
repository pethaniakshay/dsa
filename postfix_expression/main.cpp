/*
 * main.cpp
 *
 *  Created on: 07-Mar-2020
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<vector>
#include<iterator>
#include<stack>
#include<string>
#include<cstdio>
#include<sstream>

void display_expression(vector<string> &exp);
void infix_to_postfix(vector<string> &in, vector<string> &post);
bool is_operator(char opr);
int priority(char opr);
int postfix_evaluation(vector<string> &post);
int calculate(int op1, int op2, char opr);


int main(void)
{
	vector<string> infix = {"25", "+", "50", "*", "12", "-", "100", "/", "45" };
	vector<string> postfix;

	cout << "infix expression is  : "; display_expression(infix);
	infix_to_postfix(infix, postfix);
	cout << "postfix expression is: "; display_expression(postfix);
	cout << "result = " << postfix_evaluation(postfix) << endl;

	return 0;
}

int postfix_evaluation(vector<string> &post)
{
	int result;
	vector<string>::iterator itr;
	stack<int> s;

	//start scanning postfix expression from left to right
	for( itr = post.begin() ; itr != post.end() ; itr++ )
	{
		string cur_term = *itr;
		std::string::iterator str_itr;
		str_itr = cur_term.begin();
		char cur_ele = *str_itr;
		//if the cur ele is an operand
		if( !is_operator(cur_ele))
		{
			//push it into the stack
			stringstream number(cur_term);
			int n = 0;
			number >> n;
			s.push(n);
		}
		else//if the cur ele is an operator
		{
			//pop two ele's from the stack
			//first popped ele will be second operand
			int op2 = s.top(); s.pop();
			//second popped ele will be first operand
			int op1 = s.top(); s.pop();
			result = calculate(op1, op2, cur_ele);
			//push result into the stack
			s.push(result);
		}
	}
	//pop the final result from the stack and return it to the calling function
	result = s.top(); s.pop();
	return result;
}

void infix_to_postfix(vector<string> &in, vector<string> &post)
{
	stack<string> s;
	vector<string>::iterator itr;
	std::string::iterator str_itr;

	//start scanning infix expression from left to right
	for( itr = in.begin() ; itr != in.end() ; itr++ )
	{
		string cur_term = *itr;
		str_itr = cur_term.begin();
		char cur_ele = *str_itr;
		//if the cur ele is an operand i.e. if not operator
		if( !is_operator(cur_ele) )
		{
			//push it into the stack
			post.push_back(cur_term);
		}
		else//if the cur ele is an operator
		{
			char top_ele;
			if(!s.empty())
			{
				string top_term = s.top();
				str_itr = top_term.begin();
				top_ele = *str_itr;
			}

			while( !s.empty() && priority(top_ele) >= priority(cur_ele) )
			{
				string ele = s.top(); s.pop();
				post.push_back(ele);
			}

			//push the cur term into the stack
			s.push(cur_term);
		}
	}

	//pop all ele's from the stack and append them into the postfix string
	while( !s.empty())
	{
		string ele = s.top(); s.pop();
		post.push_back(ele);
	}
}

int priority(char opr)
{
	switch(opr)
	{
	case '+':
	case '-': return 1;

	case '*':
	case '/':
	case '%': return 2;
	}
}

bool is_operator(char opr)
{
	return ( (opr == '+') || (opr == '-') || (opr == '*') || (opr == '/') || (opr == '%') );
}


void display_expression(vector<string> &exp)
{
 	vector<string>::iterator itr;

	for( itr = exp.begin() ; itr != exp.end() ; itr++ )
		cout << " " << *itr;
	cout << endl;

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
