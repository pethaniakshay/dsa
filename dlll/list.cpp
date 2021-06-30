/*
 * list.cpp
 *
 *  Created on: 22-Feb-2020
 *      Author: sunbeam
 */

#include<cstdlib>
#include<cstdio>

#include"list.h"

void init_list(list_t *list)
{
	list->head = NULL;
	list->cnt=0;
}

bool is_list_empty(list_t *list)
{
	return ( list->head == NULL );
}

void add_node_at_last_position(list_t *list, int data)
{
	//create a newnode
	node_t *newnode = create_node(data);

	//if list is empty -- attach newly created node to the head
	if( is_list_empty(list))
	{
		list->head = newnode;
		list->cnt++;
	}
	else//if list is not empty
	{
		//start traversal from the first node
		node_t *trav = list->head;

		//traverse the list till last node
		while( trav->next != NULL )
			trav = trav->next;//move trav to its next node

		//store the addr of cur last node into the prev part of newly created node
		newnode->prev = trav;
		//attach newly created node to the last node i.e. store the addr
		//of newly created node into the next part of cur last node
		trav->next = newnode;
		list->cnt++;
	}
}

void add_node_at_first_position(list_t *list, int data)
{
	//create a newnode
	node_t *newnode = create_node(data);

	//if list is empty -- attach newly created node to the head
	if( is_list_empty(list))
	{
		list->head = newnode;
		list->cnt++;
	}
	else//if list is not empty
	{
		//store the addr of cur first node into the next part of newly created node
		newnode->next = list->head;
		//store the addr of newly created node into the prev part of cur first node
		list->head->prev = newnode;
		//attach newly created node to the head
		list->head = newnode;
		list->cnt++;
	}
}

void add_node_at_specific_position(list_t *list, int pos, int data)
{
	if( pos == 1 )//if pos is the first position
		add_node_at_first_position(list, data);
	else
	if( pos == list->cnt+1 )//if pos is the last position
		add_node_at_last_position(list, data);
	else//if pos is in between position
	{
		node_t *newnode = create_node(data);

		//start traversal from first node
		node_t *trav = list->head;
		int i=1;
		//traverse the till (pos-1)th node
		while( i < pos-1 )
		{
			i++;
			trav = trav->next;
		}

		//store the addr of cur (pos)th node into the next part of newly created node
		newnode->next = trav->next;
		//store the addr of (pos-1)th node into the prev part of newly created node
		newnode->prev = trav;
		//store the addr of newly created node into prev part of cur (pos)th node
		trav->next->prev = newnode;
		//store the add of newly created node into the next part of (pos-1)th node
		trav->next = newnode;
		list->cnt++;
	}
}

void display_list(list_t *list)
{
	//if list is not empty
	if( !is_list_empty(list))
	{
		node_t *temp = NULL;//to avoid wild pointer
		//start traversal from first node
		node_t *trav = list->head;

		printf("list in a forward dir is : ");
		//traverse the list till last node including it
		while( trav != NULL )
		{
			temp = trav;
			printf("%4d", trav->data);
			trav = trav->next;//move trav to its next node
		}
		printf("\n");

		trav = temp;
		printf("list in a backward dir is: ");
		//traverse the list till last node including it
		while( trav != NULL )
		{
			printf("%4d", trav->data);
			trav = trav->prev;//move trav to its prev node
		}
		printf("\n");
	}
	else
		printf("list is empty !!!\n");
}









