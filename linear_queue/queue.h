/*
 * queue.h
 *
 *  Created on: 07-Mar-2020
 *      Author: sunbeam
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#define SIZE 5


class queue
{
private:
	int arr[SIZE];
	int rear;
	int front;
public:
	queue();
	bool is_queue_full(void) const;
	bool is_queue_empty(void) const;
	void enqueue(int ele);
	void dequeue(void);
	int peek_element(void);
};

#endif /* QUEUE_H_ */
