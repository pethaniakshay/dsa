/*
 * bst.cpp
 *
 *  Created on: 09-Mar-2020
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>
#include<cstdio>
#include<stack>
#include<queue>
#include"bst.h"

bst::bst()
{
	root = NULL;
}

bool bst::is_bst_empty(void)const
{
	return ( root == NULL );
}

void bst::add_node(int data)
{
	//create a new node
	node *newnode = new node(data);

	//if bst is empty - attach newly created node to the root pointer
	if( is_bst_empty())
	{
		root = newnode;
	}
	else//if bst is not empty --> find an appropriate position of a node
	{
		//start traversal from root node
		node *trav = root;
		//traverse bst

		while(1)
		{
			if( data < trav->data )//node will be a part of its left subtree
			{
				if( trav->left == NULL )//if the cur node's left subtree is empty
				{
					//attach newly created node as its left child
					trav->left = newnode;
					break;
				}
				else//if the cur node is having left subtree
					trav = trav->left;//go its left subtree
			}
			else//node will be a part of its right subtree
			{
				if( trav->right == NULL )//if the cur node's right subtree is empty
				{
					//attach newly created node as its right child
					trav->right = newnode;
					break;
				}
				else//if the cur node is having right subtree
					trav = trav->right;//go its right subtree
			}
		}//end of while loop
	}//end of else -- bst is not empy
}

void bst::preorder(void)//wrapper function
{
	if( !is_bst_empty())
	{
		cout << "preorder : ";
		preorder(root);//first time function calling to rec function
		cout << endl;
	}
	else
		cout << "bst is empty !!!" << endl;
}

void bst::preorder(node *trav)//recursive function
{
	
	
	if( trav == NULL )
		return;

	//VLR
	cout << setw(4) << left << trav->data;//visit the node
	preorder(trav->left);//visit its left subtree
	preorder(trav->right);//visit its right subtree
}

void bst::inorder(void)//wrapper function
{
	if( !is_bst_empty())
	{
		cout << "inorder  : ";
		inorder(root);//first time function calling to rec function
		cout << endl;
	}
	else
		cout << "bst is empty !!!" << endl;
}

void bst::inorder(node *trav)//recursive function
{
	if( trav == NULL )
		return;

	//LVR
	inorder(trav->left);//visit its left subtree
	cout << setw(4) << left << trav->data;//visit the node
	inorder(trav->right);//visit its right subtree
}

void bst::postorder(void)//wrapper function
{
	if( !is_bst_empty())
	{
		cout << "postorder: ";
		postorder(root);//first time function calling to rec function
		cout << endl;
	}
	else
		cout << "bst is empty !!!" << endl;
}

void bst::postorder(node *trav)//recursive function
{
	if( trav == NULL )
		return;

	//LRV
	postorder(trav->left);//visit its left subtree
	postorder(trav->right);//visit its right subtree
	cout << setw(4) << left << trav->data;//visit the node
}

void bst::nonrec_preorder(void)
{
	//if bst is empty
	if( is_bst_empty() )
	{
		cout << "bst is empty !!!" << endl;
		return;
	}
	else//if bst is not empty
	{
		//start traversal bst from root node
		node *trav = root;
		stack<node *> s;

		cout << "preorder : ";
		while( trav != NULL || !s.empty() )
		{
			while( trav != NULL )
			{
				//visit the node
				cout << setw(4) << left << trav->data;
				//if the cur node is having right child -> push it into the stack
				if( trav->right != NULL )
					s.push(trav->right);

				//go to its left sub tree
				trav = trav->left;
			}//end of inner while loop

			//if stack is not empty
			if(!s.empty())
			{
				//pop ele from the stack and store its addr of into trav
				trav = s.top();
				s.pop();
			}
		}//end of outer while loop
		cout << endl;
	}
}

void bst::nonrec_inorder(void)
{
	//if bst is empty
	if( is_bst_empty() )
	{
		cout << "bst is empty !!!" << endl;
		return;
	}
	else//if bst is not empty
	{
		//start traversal bst from root node
		node *trav = root;
		stack<node *> s;

		cout << "inorder  : ";
		while( trav != NULL || !s.empty() )
		{
			while( trav != NULL )
			{
				//push the cur node into stack
				s.push(trav);

				//go to its left sub tree
				trav = trav->left;
			}//end of inner while loop

			//if stack is not empty
			if(!s.empty())
			{
				//pop ele from the stack and store its addr of into trav
				trav = s.top();
				s.pop();

				//visit the node
				cout << setw(4) << left << trav->data;
				//goto its right subtree
				trav = trav->right;
			}
		}//end of outer while loop
		cout << endl;
	}
}

void bst::nonrec_postorder(void)
{
	//if bst is empty
	if( is_bst_empty() )
	{
		cout << "bst is empty !!!" << endl;
		return;
	}
	else//if bst is not empty
	{
		//start traversal bst from root node
		node *trav = root;
		stack<node *> s;

		cout << "postorder: ";
		while( trav != NULL || !s.empty() )
		{
			while( trav != NULL )
			{
				//push the cur node into stack
				s.push(trav);

				//go to its left sub tree
				trav = trav->left;
			}//end of inner while loop

			//if stack is not empty
			if(!s.empty())
			{
				//pop ele from the stack and store its addr of into trav
				trav = s.top();
				s.pop();

				if( trav->right != NULL && trav->right->visited == false )
				{
					//push the cur node into the stack
					s.push(trav);
					//goto its right subtree
					trav = trav->right;
				}
				else
				{
					//visit the node & mark it as visited
					cout << setw(4) << left << trav->data;
					trav->visited = true;
					trav = NULL;
				}
			}
		}//end of outer while loop
		cout << endl;
	}
}

void bst::dfs_traversal(void)
{
	//if bst is empty
	if( is_bst_empty())
	{
		cout << "bst is empty !!!" << endl;
		return;
	}
	else//bst is not empty
	{
		//start traversal from the root node
		node *trav = root;
		stack<node *> s;

		//step1: push the root node into the stack
		s.push(trav);

		cout << "dfs traversal is: ";
		while(!s.empty())
		{
			//step2: pop the node from the stack and visit it
			trav = s.top(); s.pop();
			cout << setw(4) << left << trav->data;

			//step3: push its right child into the stack if it is having
			if( trav->right != NULL )
				s.push(trav->right);

			//step4: push its left child into the stack if it is having
			if( trav->left != NULL )
				s.push(trav->left);
		}//step5: repeat step2, step3 & step4 till stack not becomes empty
		cout << endl;

	}
}

void bst::bfs_traversal(void)
{
	//if bst is empty
	if( is_bst_empty())
	{
		cout << "bst is empty !!!" << endl;
		return;
	}
	else//bst is not empty
	{
		//start traversal from the root node
		node *trav = root;
		queue<node *> s;

		//step1: push the root node into the queue
		s.push(trav);

		cout << "bfs traversal is: ";
		while(!s.empty())
		{
			//step2: pop the node from the queue and visit it
			trav = s.front(); s.pop();
			cout << setw(4) << left << trav->data;

			//step4: push its left child into the queue if it is having
			if( trav->left != NULL )
				s.push(trav->left);

			//step3: push its right child into the queue if it is having
			if( trav->right != NULL )
				s.push(trav->right);

		}//step5: repeat step2, step3 & step4 till queue not becomes empty
		cout << endl;

	}
}

//on success this function returns addr of the node which to be deleted and addr
//of its parent node as an out parameter & on failure it returns NULL
node *bst::search_node(int key, node **parent)
{
	node *trav = root;

	while( trav != NULL )
	{
		if( key == trav->data )
			return trav;

		*parent = trav;
		if( key < trav->data )
			trav = trav->left;
		else
			trav = trav->right;
	}

	*parent = NULL;
	return NULL;
}

bool bst::delete_node(int key)
{
	//search a node
	node *parent = NULL;
	node *temp = search_node(key, &parent);

	if( temp == NULL )
		return false;
	/*
	if( parent == NULL )
		cout << "temp->data : " << temp->data << endl;
	else
		cout << "parent->data: " << parent->data << "\t" << "temp->data: " << temp->data << endl;
	*/

	//logic to delete a node
	if( temp->left != NULL && temp->right != NULL )
	{
		//traverse the till its inorder successor
		node *succ = temp->right;
		parent = temp;
		while( succ->left != NULL )
		{
			parent = succ;
			succ = succ->left;
		}

		temp->data = succ->data;
		temp = succ;
	}

	if( temp->left == NULL )
	{
		if( temp == root )//node to be deleted is root node
			root = temp->right;
		else
		if( temp == parent->left )//if temp is a left child of its parent
			parent->left = temp->right;
		else//temp is a right child of its parent
			parent->right = temp->right;
	}
	else
	{
		if( temp == root )//node to be deleted is a root node
			root = temp->left;
		else
		if( temp == parent->left )//if temp is a left child of its parent
			parent->left = temp->left;
		else//temp is a right child of its parent
			parent->right = temp->left;
	}

	delete temp;
	return true;
}

bst::~bst(void)
{
	if( !is_bst_empty())
	{
		free_bst(root);
		cout << "bst freed successfully..." << endl;
	}
	else
		cout << "bst is empty !!!" << endl;
}

void bst::free_bst(node *trav)
{
	if( trav == NULL )
		return;

	free_bst(trav->left);
	free_bst(trav->right);
	delete trav;
}

int bst::height(void)//wrapper function
{
	if( !is_bst_empty())
		return height(root);
	else
		return 0;
}

int bst::height(node *trav)
{
	if( trav == NULL )
		return 0;

	return ( max( height(trav->left), height(trav->right) ) + 1 );
}

void bst::balance(void)
{
	if( !is_bst_empty() )
		balance(root, NULL);
}


node *bst::left_rotation(node *axis, node *parent)
{
	//if axis or its right subtree is NULL
	if( axis == NULL || axis->right == NULL )
		return NULL;

	node *newaxis = axis->right;
	axis->right = newaxis->left;
	newaxis->left = axis;

	//if axis is a root
	if( axis == root )
		root = newaxis;
	else
	if( axis == parent->left )//if axis is a left child of its parent
		parent->left = newaxis;
	else//if axis is a right child of its parent
		parent->right = newaxis;

	return newaxis;
}

node *bst::right_rotation(node *axis, node *parent)
{
	//if axis or its right subtree is NULL
	if( axis == NULL || axis->left == NULL )
		return NULL;

	node *newaxis = axis->left;
	axis->left = newaxis->right;
	newaxis->right = axis;

	//if axis is a root
	if( axis == root )
		root = newaxis;
	else
	if( axis == parent->left )//if axis is a left child of its parent
		parent->left = newaxis;
	else//if axis is a right child of its parent
		parent->right = newaxis;

	return newaxis;
}

void bst::balance(node *trav, node *parent)
{
	if( trav == NULL )
		return;

	//calculate the balance factor of the cur node
	int bf = height(trav->left) - height(trav->right);

	//if node is not balanced
	while( bf < -1 || bf > +1 )
	{
		if( bf < -1 )//if node is left imbalanced
		{
			//apply left rotation
			trav = left_rotation(trav, parent);
			bf += 2;
		}
		else//if node is left imbalanced
		{
			//apply right rotation
			trav = right_rotation(trav, parent);
			bf -= 2;
		}
	}

	//balance left subtree of cur node
	balance(trav->left, trav);
	//balance right subtree of cur node
	balance(trav->right, trav);
}



















