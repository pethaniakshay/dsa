/*
 * main.cpp
 *
 *  Created on: 21-Feb-2020
 *      Author: sunbeam
 */
#include<cstdio>
#include<cstdlib>
#include"list.h"

enum menu_options{ EXIT, ADDLAST, ADDFIRST, ADDATPOS, DELFIRST,
	DELLAST, DELATPOS, DISPLAY };

int menu(void);
void accept_data(int *ptr_data);


int main(void)
{
	list_t l1;
	int pos;
	int data;

	init_list(&l1);

	while(1)
	{
		int choice = menu();
		switch(choice)
		{
		case EXIT:
			free_list(&l1);
			exit(0);
		case ADDLAST:
			accept_data(&data);
			add_node_at_last_position(&l1, data);
			break;
		case ADDFIRST:
			accept_data(&data);
			add_node_at_first_position(&l1, data);
			break;
		case ADDATPOS:
			while(1)
			{
				printf("enter the position: ");
				scanf("%d", &pos);

				if( pos > 0 && pos <= l1.cnt + 1 )
					break;

				printf("invalid position !!!\n");
			}

			accept_data(&data);
			add_node_at_specific_position(&l1, pos, data);
			break;

		case DELFIRST:
			delete_node_at_first_position(&l1);
			break;

		case DELLAST:
			delete_node_at_last_position(&l1);
			break;

		case DELATPOS:
			while(1)
			{
				printf("enter the position: ");
				scanf("%d", &pos);

				if( pos > 0 && pos <= l1.cnt )
					break;

				printf("invalid position !!!\n");
			}

			delete_node_at_specific_position(&l1, pos);
			break;

		case DISPLAY:
			display_list(&l1);
			break;
		}//end of switch control block
	}//end of while loop

	return 0;
}


int menu(void)
{
	int choice;

	printf("singly linear linked list operations:\n");
	printf("0. exit\n");
	printf("1. add node into the list at last position\n");
	printf("2. add node into the list at first position\n");
	printf("3. add node into the list at specific position\n");
	printf("4. delete node from the list which is at first position\n");
	printf("5. delete node from the list which is at last position\n");
	printf("6. delete node from the list which is at specific position\n");
	printf("7. display the list\n");
	printf("enter the choice: ");
	scanf("%d", &choice);

	return choice;
}

void accept_data(int *ptr_data)
{
	printf("enter the data: ");
	scanf("%d", ptr_data);
}
