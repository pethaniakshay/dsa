/*
 * queue.cpp
 *
 *  Created on: 07-Mar-2020
 *      Author: sunbeam
 */

#include"queue.h"
#include<cstring>

queue::queue()
{
	memset(arr,0,sizeof(arr));
	front=-1;
	rear=-1;
}

bool queue::is_queue_full(void) const
{
	return ( rear == SIZE-1 );
}

bool queue::is_queue_empty(void) const
{
	return ( rear == -1 || front > rear );
}

void queue::enqueue(int ele)
{
	//step2: increment the value of rear by 1
	rear++;
	//step3: insert/push/add into the queue at rear position
	arr[ rear ] = ele;

	//if front == -1 => front = 0
	if( front == -1 )
		front=0;
}

void queue::dequeue(void)
{
	//step2: delete ele from the queue which is front position
	//incrementing value of front by 1
	front++;
}

int queue::peek_element(void)
{
	//return the value of an ele which is at front position
	return ( arr[ front ] );
}




