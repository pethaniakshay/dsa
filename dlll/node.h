/*
 * node.h
 *
 *  Created on: 22-Feb-2020
 *      Author: sunbeam
 */

#ifndef NODE_H_
#define NODE_H_

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}node_t;

node_t *create_node(int data);


#endif /* NODE_H_ */
