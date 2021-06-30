/*
 * main.cpp
 *
 *  Created on: 22-Feb-2020
 *      Author: sunbeam
 */

#include<cstdio>
#include<cstdlib>


typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}node_t;


typedef struct
{
	node_t *head;
	int cnt;
}list_t;

bool is_list_empty(list_t *list);
node_t *create_node(int data);
void init_list(list_t *list);
void add_node_at_last_position(list_t *list, int data);
void display_list(list_t *list);


int main(void)
{
	list_t l1;

	init_list(&l1);

	add_node_at_last_position(&l1, 10);
	add_node_at_last_position(&l1, 20);
	add_node_at_last_position(&l1, 30);
	add_node_at_last_position(&l1, 40);
	add_node_at_last_position(&l1, 50);


	display_list(&l1);


	return 0;
}


void init_list(list_t *list)
{
	list->head = NULL;
	list->cnt=0;
}

bool is_list_empty(list_t *list)
{
	return ( list->head == NULL );
}

node_t *create_node(int data)
{
	node_t *temp = (node_t *)malloc(sizeof(node_t));
	if( temp == NULL )
	{
		perror("malloc() failed !!!\n");
		exit(1);
	}

	temp->data = data;
	temp->prev = NULL;
	temp->next = NULL;

	return temp;
}

void add_node_at_last_position(list_t *list, int data)
{
	//create a newnode
	node_t *newnode = create_node(data);

	//if list is empty - attach newly created node to the head
	if( is_list_empty(list) )
	{
		list->head = newnode;
		newnode->next = list->head;
		newnode->prev = newnode;
		list->cnt++;
	}
	else
	{
		//store the addr of first node into the next part of newly created node
		newnode->next = list->head;
		//store the addr of cur last node into the prev part of newly created node
		newnode->prev = list->head->prev;
		//store the addr of newly created node into the next part cur last node
		list->head->prev->next = newnode;
		//update prev part of first node
		list->head->prev = newnode;
		list->cnt++;
	}
}

void display_list(list_t *list)
{
	//if list is not empty
	if( !is_list_empty(list))
	{
		//start traversal from first node
		printf("list in a forward dir: ");
		node_t *trav = list->head;
		//traverse the list till last node
		do
		{
			printf("%4d", trav->data);
			trav = trav->next;//move trav to its next node
		}while( trav != list->head );
		printf("\n");

		//start traversal from last node
		printf("list in a backward dir: ");
		trav = list->head->prev;
		//traverse the list till last node
		do
		{
			printf("%4d", trav->data);
			trav = trav->prev;//move trav to its prev node
		}while( trav != list->head->prev );
		printf("\n");
	}
	else
		printf("list is empty !!!\n");
}














