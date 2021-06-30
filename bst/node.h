/*
 * node.h
 *
 *  Created on: 09-Mar-2020
 *      Author: sunbeam
 */

//forward declaration
class bst;

class node
{
private:
	int data;
	node *left;
	node *right;
	bool visited;
public:
	node(int data);
	friend class bst;
};
