/*
 * main.cpp
 *
 *  Created on: 22-Feb-2020
 *      Author: sunbeam
 */
#include<cstdlib>
#include<cstdio>

typedef struct node
{
	int data;
	struct node *next;
}node_t;

typedef struct
{
	node_t *head;
	int cnt;
}list_t;

void init_list(list_t *list);
bool is_list_empty(list_t *list);
void add_node_at_last_position(list_t *list, int data);
void add_node_at_first_position(list_t *list, int data);
node_t *create_node(int data);
void display_list(list_t *list);
void delete_node_at_last_position(list_t *list);
void free_list(list_t *list);


int main(void)
{
	list_t l1;

	init_list(&l1);

	add_node_at_last_position(&l1, 11);
	add_node_at_last_position(&l1, 22);
	add_node_at_last_position(&l1, 33);
	add_node_at_last_position(&l1, 44);
	add_node_at_last_position(&l1, 55);
	add_node_at_last_position(&l1, 66);

	display_list(&l1);

	//add_node_at_first_position(&l1, 5);
	delete_node_at_last_position(&l1);

	display_list(&l1);

	free_list(&l1);


	return 0;
}


void init_list(list_t *list)
{
	list->head = NULL;
	list->cnt = 0;
}

bool is_list_empty(list_t *list)
{
	return ( list->head == NULL );
}

node_t *create_node(int data)
{
	//allocate memory dynamically for a node
	node_t *temp = (node_t *)malloc(sizeof(node_t));
	if( temp == NULL )
	{
		perror("malloc() failed !!!\n");
		exit(1);
	}

	//initialize members of the node
	temp->data = data;
	temp->next = NULL;
	//return the addr of newly created node to the calling function
	return temp;
}

void display_list(list_t *list)
{
	if( !is_list_empty(list))
	{
		//start traversal from the first node
		node_t *trav = list->head;
		printf("list is: head -> ");
		//traverse the list till last node including it
		do
		{
			printf("%d -> ", trav->data);
			trav = trav->next;
		}while( trav != list->head );
		printf("head\n");
	}
	else
		printf("list is empty !!!\n");
}

void add_node_at_last_position(list_t *list, int data)
{
	//create a newnode
	node_t *newnode = create_node(data);

	//if list is empty
	if( is_list_empty(list) )
	{
		 //attach newly created node to the head and store the addr of that node
		//into the next part the same node
		list->head = newnode;
		newnode->next = list->head;
		list->cnt++;
	}
	else//if list is not empty
	{
		//start traversal from the first node
		node_t *trav = list->head;

		//traverse the list till last node
		while( trav->next != list->head )
			trav = trav->next;//move trav to its next node

		//store the addr of first node into the next part of newly created node
		newnode->next = list->head;
		//attach newly created node to the last node
		trav->next = newnode;

		list->cnt++;
	}
}

void add_node_at_first_position(list_t *list, int data)
{
	//create a newnode
	node_t *newnode = create_node(data);

	//if list is empty
	if( is_list_empty(list) )
	{
		 //attach newly created node to the head and store the addr of that node
		//into the next part the same node
		list->head = newnode;
		newnode->next = list->head;
		list->cnt++;
	}
	else//if list is not empty
	{
		//start traversal from the first node
		node_t *trav = list->head;

		//traverse the list till last node
		while( trav->next != list->head )
			trav = trav->next;//move trav to its next node

		//store the addr of cur first node into next part of newly created node
		newnode->next = list->head;
		//attach newly created node to the head
		list->head = newnode;
		//update next part of last node
		trav->next = list->head;

		list->cnt++;
	}
}


void delete_node_at_last_position(list_t *list)
{
	//if list is not empty
	if( !is_list_empty(list))
	{
		//if list contains only one node
		if( list->head == list->head->next )
		{
			//delete the node and make head as NULL & cnt as 0
			free(list->head);
			list->head = NULL;
			list->cnt=0;
		}
		else//if list contains more than one nodes
		{
			//start traversal from the first
			node_t *trav = list->head;

			//traverse the list till second last node
			while( trav->next->next != list->head )
				trav = trav->next;//move trav to its next node

			//delete the last node
			free(trav->next);
			//store the addr of first node into the next part second last node
			trav->next = list->head;
			list->cnt--;
		}
	}
	else
		printf("list is empty !!!\n");
}

void free_list(list_t *list)
{
	if( !is_list_empty(list))
	{
		while( !is_list_empty(list))
			delete_node_at_last_position(list);

		printf("list freed successfully !!!\n");
	}
	else
		printf("list is empty !!!\n");
}












