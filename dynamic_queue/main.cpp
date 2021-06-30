/*
 * main.cpp
 *
 *  Created on: 09-Mar-2020
 *      Author: sunbeam
 */


/*
 * main.cpp
 *
 *  Created on: 09-Mar-2020
 *      Author: sunbeam
 */
#include<iostream>
using namespace std;
#include<queue>

enum menu_options{ EXIT, ENQUEUE, DEQUEUE };

int menu(void)
{
	int choice;

	cout << "dynamic queue" << endl;
	cout << "0. exit" << endl;
	cout << "1. enqueue" << endl;
	cout << "2. dequeue" << endl;

	cout << "enter the choice: ";
	cin >> choice;

	return choice;
}

int main(void)
{
	queue<int> q;
	int ele;

	while(1)
	{
		int choice = menu();
		switch(choice)
		{
		case EXIT: exit(0);
		case ENQUEUE:
			cout << "enter an ele: ";
			cin >> ele;
			q.push(ele);
			cout << ele << " pushed into the queue..." << endl;
			break;

		case DEQUEUE:
			//step1: check queue is not empty
			if( !q.empty())
			{
				ele = q.front();//get the value of an ele which is at front end
				q.pop();
				cout << ele << " popped from the queue..." << endl;
			}
			else
				cout << "queue is empty !!!" << endl;
			break;
		}
	}
	return 0;
}






