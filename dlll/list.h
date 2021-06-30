/*
 * list.h
 *
 *  Created on: 22-Feb-2020
 *      Author: sunbeam
 */

#ifndef LIST_H_
#define LIST_H_

#include"node.h"

typedef struct
{
	node_t *head;
	int cnt;
}list_t;

void init_list(list_t *list);
bool is_list_empty(list_t *list);
void add_node_at_last_position(list_t *list, int data);
void add_node_at_first_position(list_t *list, int data);
void add_node_at_specific_position(list_t *list, int pos, int data);
void display_list(list_t *list);


#endif /* LIST_H_ */
