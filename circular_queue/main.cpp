/*
 * main.cpp
 *
 *  Created on: 09-Mar-2020
 *      Author: sunbeam
 */
#include<iostream>
using namespace std;
#include"queue.h"

enum menu_options{ EXIT, ENQUEUE, DEQUEUE };

int menu(void)
{
	int choice;

	cout << "circular queue" << endl;
	cout << "0. exit" << endl;
	cout << "1. enqueue" << endl;
	cout << "2. dequeue" << endl;

	cout << "enter the choice: ";
	cin >> choice;

	return choice;
}

int main(void)
{
	queue q;
	int ele;

	while(1)
	{
		int choice = menu();
		switch(choice)
		{
		case EXIT: exit(0);
		case ENQUEUE:
			//step1: check queue is not full
			if( !q.is_queue_full())
			{
				cout << "enter an ele: ";
				cin >> ele;
				q.enqueue(ele);
				cout << ele << " pushed into the queue..." << endl;
			}
			else
				cout << "queue is full !!!" << endl;
			break;

		case DEQUEUE:
			//step1: check queue is not empty
			if( !q.is_queue_empty())
			{
				ele = q.peek_element();
				q.dequeue();
				cout << ele << " popped from the queue..." << endl;
			}
			else
				cout << "queue is empty !!!" << endl;
			break;
		}
	}
	return 0;
}




