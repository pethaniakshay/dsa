/*
 * node.cpp
 *
 *  Created on: 21-Feb-2020
 *      Author: sunbeam
 */
#include<cstdlib>
#include<cstdio>
#include"node.h"

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

