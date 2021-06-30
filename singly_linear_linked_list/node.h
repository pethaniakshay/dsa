/*
 * node.h
 *
 *  Created on: 21-Feb-2020
 *      Author: sunbeam
 */

#ifndef NODE_H_
#define NODE_H_


typedef struct node
{
	int data;//4 bytes
	struct node *next;//4 bytes --> self referential pointer
}node_t;


node_t *create_node(int data);



#endif /* NODE_H_ */
