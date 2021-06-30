/*
 * main.cpp
 *
 *  Created on: 22-Feb-2020
 *      Author: sunbeam
 */
#include<cstdio>
#include"list.h"

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

	/*
	add_node_at_first_position(&l1, 5);
	*/
	int pos;

	while(1)
	{
		//accept pos from the user
		printf("enter the pos: ");
		scanf("%d", &pos);

		if( pos > 0 && pos <= l1.cnt + 1 )
			break;

		printf("invalid position !!!\n");
	}

	add_node_at_specific_position(&l1, pos, 99);

	display_list(&l1);



	return 0;
}


