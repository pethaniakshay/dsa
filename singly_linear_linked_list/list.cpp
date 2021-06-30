/*
 * list.cpp
 *
 *  Created on: 21-Feb-2020
 *      Author: sunbeam
 */

#include<cstdlib>
#include<cstdio>
#include"list.h"

void init_list(list_t *list)
{
	list->head = NULL;
	list->cnt = 0;
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
	if( is_list_empty(list) )
	{
		//store the addr of newly created node into the head
		list->head = newnode;
		list->cnt++;
	}
	else//if list is not empty
	{
		//start traversal from first node
		node_t *trav = list->head;

		//traverse the list till last node
		while( trav->next != NULL )
			trav = trav->next;//move trav to its next node

		//attach newly created node to the last node i.e. store the addr of
		//newly created node into the next part of last node
		trav->next = newnode;
		list->cnt++;
	}
}

void add_node_at_first_position(list_t *list, int data)
{
	//create a newnode
	node_t *newnode = create_node(data);

	//if list is empty -- attach newly created node to the head
	if( is_list_empty(list) )
	{
		//store the addr of newly created node into the head
		list->head = newnode;
		list->cnt++;
	}
	else//if list is not empty
	{
		//store the addr of cur first node into next part of newly created node
		newnode->next = list->head;
		//attach newly created node to the head
		list->head = newnode;
		list->cnt++;
	}
}

void display_list(list_t *list)
{
	if( !is_list_empty(list))
	{
		//start traversal from first node
		node_t *trav = list->head;

		printf("list is: head -> ");
		//traverse the list till last node including it
		while( trav != NULL )
		{
			printf("%d -> ", trav->data);//display data part of current node
			trav = trav->next;//move trav to its next node
		}
		printf("NULL\n");
		printf("no. of nodes in a list are: %d\n", list->cnt);
	}
	else
		printf("list is empty !!!\n");
}

void add_node_at_specific_position(list_t *list, int pos, int data)
{
	if( pos == 1 )//if the pos is the first position
		add_node_at_first_position(list, data);
	else
	if( pos == list->cnt + 1 )//if the pos is the last position
		add_node_at_last_position(list, data);
	else//if the pos is in between position
	{
		//create a newnode
		node_t *newnode = create_node(data);

		//start traversal from first node
		node_t *trav = list->head;
		int i = 1;

		//traverse the list till (pos-1)th node
		while( i < pos-1 )
		{
			trav = trav->next;
			i++;
		}

		//store the addr of cur (pos)th node into the next part of newly created node
		newnode->next = trav->next;
		//store the addr of newly created node into the next part of (pos-1)th node
		trav->next = newnode;
		list->cnt++;
	}
}

void delete_node_at_first_position(list_t *list)
{
	//if list is not empty
	if( !is_list_empty(list) )
	{
		//if list contains only one node
		if( list->head->next == NULL )
		{
			//delete the node & make head as NULL and cnt as 0
			free(list->head);
			list->head = NULL;
			list->cnt=0;
		}
		else//list contains more than one nodes
		{
			//store the addr of cur first node into the temp pointer variable
			//which is to be deleted
			node_t *temp = list->head;
			//attach cur second node to the head
			list->head = list->head->next;
			//delete the node
			free(temp);
			temp = NULL;//to avoid dangling pointer
			list->cnt--;
		}
	}
	else
		printf("list is empty !!!\n");
}

void delete_node_at_last_position(list_t *list)
{
	//if list is not empty
	if( !is_list_empty(list) )
	{
		//if list contains only one node
		if( list->head->next == NULL )
		{
			//delete the node & make head as NULL and cnt as 0
			free(list->head);
			list->head = NULL;
			list->cnt=0;
		}
		else//list contains more than one nodes
		{
			//start traversal from first node
			node_t *trav = list->head;

			//traverse the list till second last node
			while( trav->next->next != NULL )
				trav = trav->next;

			//delete last node
			free(trav->next);
			//make next part of second last as NULL
			trav->next = NULL;

			list->cnt--;
		}
	}
	else
		printf("list is empty !!!\n");
}

void delete_node_at_specific_position(list_t *list, int pos)
{
	if( pos == 1 )//if position is the first position
		delete_node_at_first_position(list);
	else
	if( pos == list->cnt )//if position is the last position
		delete_node_at_last_position(list);
	else//position is the in between position
	{
		//start traversal from first node
		node_t *trav = list->head;
		int i = 1;

		//traverse the list till (pos-1)th node
		while( i < pos-1 )
		{
			trav = trav->next;
			i++;
		}

		//store the addr of node which is to be deleted in temp
		node_t *temp = trav->next;
		//store the addr of (pos+1)th node into the next part of (pos-1)th node
		trav->next = trav->next->next;
		//delete the node
		free(temp);
		temp = NULL;
		list->cnt--;
	}
}

void free_list(list_t *list)
{
	//if list is not empty
	if( !is_list_empty(list))
	{
		while( !is_list_empty(list))
			delete_node_at_last_position(list);

			//delete_node_at_first_position(list);

		printf("list freed successfully...\n");
	}
	else
		printf("list is empty !!!\n");
}
















