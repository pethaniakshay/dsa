/*
 * main.cpp
 *
 *  Created on: 07-Mar-2020
 *      Author: sunbeam
 */
/*
 * main.cpp
 *
 *  Created on: 06-Mar-2020
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<cstdlib>
#include<stack>

enum menu_options{ EXIT, PUSH, POP, PEEK };

int menu(void);

int main(void)
{
	stack<int> s;
	int ele;

	while(1)
	{
		int choice = menu();
		switch(choice)
		{
		case EXIT:
			exit(0);
		case PUSH:
			cout << "enter an ele: ";
			cin >> ele;
			s.push(ele);
			cout << ele << " pushed into the stack ..." << endl;
			break;

		case POP:
			//step1: to check stack is not empty
			if( !s.empty())
			{
				ele = s.top();
				s.pop();
				cout << "popped ele is: " << ele << endl;
			}
			else
				cout << "stack underflow !!!" << endl;
			break;

		case PEEK:
			//step1: to check stack is not empty
			if( !s.empty())
			{
				ele = s.top();
				cout << "topmost ele is: " << ele << endl;
			}
			else
				cout << "stack underflow !!!" << endl;
			break;
		}//end of switch control block
	}//end of while loop
	return 0;
}

int menu(void)
{
	int choice;

	cout << "dynamic stack" << endl;
	cout << "0. exit" << endl;
	cout << "1. push element" << endl;
	cout << "2. pop element" << endl;
	cout << "3. peek element" << endl;
	cout << "enter the choice: ";
	cin >> choice;

	return choice;
}




