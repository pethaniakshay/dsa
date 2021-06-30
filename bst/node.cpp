/*
 * node.cpp
 *
 *  Created on: 09-Mar-2020
 *      Author: sunbeam
 */

#include<cstdio>
#include"node.h"

node::node(int data)
{
	this->data = data;
	this->left = NULL;
	this->right = NULL;
	this->visited = false;
}
