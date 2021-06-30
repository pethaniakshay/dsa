/*
 * node.cpp
 *
 *  Created on: 22-Feb-2020
 *      Author: sunbeam
 */

#include<cstdlib>
#include<cstdio>

#include"node.h"

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


