/*
 * main.cpp
 *
 *  Created on: 06-Mar-2020
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<cstring>
#include<cstdlib>

#define SIZE 5

class stack
{
private:
	int arr[SIZE];
	int top;
public:
	stack()
	{
		//initialize all array ele's by 0
		/*
		for(int index=0; index < SIZE; index++)
			arr[index]=0;
		*/
		memset(arr, 0, sizeof(arr));
		top = -1;
	}

	bool is_stack_empty(void)const
	{
		return ( top == -1 );
	}

	bool is_stack_full(void) const
	{
		return ( top == SIZE-1 );
	}

	void push_element(int ele)
	{
		//step2: increment the value of top by 1
		top++;
		//step3: push/add/insert an ele into the stack at top position
		arr[ top ] = ele;
	}

	void pop_element(void)
	{
		/* step2: delete/remove/pop ele from the stack which is at top
		position => decrementing value of top by 1 */
		top--;
	}

	int peek_element(void)
	{
		/*step2: return the value of ele which is at top pos
		(without incrementing/decrementing top) */
		return ( arr[ top ] );
	}
};

enum menu_options{ EXIT, PUSH, POP, PEEK };

int menu(void);

int main(void)
{
	stack s;
	int ele;

	while(1)
	{
		int choice = menu();
		switch(choice)
		{
		case EXIT:
			exit(0);
		case PUSH:
			//step1: to check stack is not full
			if( !s.is_stack_full())
			{
				cout << "enter an ele: ";
				cin >> ele;
				s.push_element(ele);
				cout << ele << " pushed into the stack ..." << endl;
			}
			else
				cout << "stack overflow !!!" << endl;
			break;

		case POP:
			//step1: to check stack is not empty
			if( !s.is_stack_empty())
			{
				ele = s.peek_element();
				s.pop_element();
				cout << "popped ele is: " << ele << endl;
			}
			else
				cout << "stack underflow !!!" << endl;
			break;

		case PEEK:
			//step1: to check stack is not empty
			if( !s.is_stack_empty())
			{
				ele = s.peek_element();
				cout << "topmost ele is: " << ele << endl;
			}
			else
				cout << "stack underflow !!!" << endl;
			break;
		}
	}
	return 0;
}

int menu(void)
{
	int choice;

	cout << "static stack" << endl;
	cout << "0. exit" << endl;
	cout << "1. push element" << endl;
	cout << "2. pop element" << endl;
	cout << "3. peek element" << endl;
	cout << "enter the choice: ";
	cin >> choice;

	return choice;
}
