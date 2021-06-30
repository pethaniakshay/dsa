/*
 * bst.h
 *
 *  Created on: 09-Mar-2020
 *      Author: sunbeam
 */

#ifndef BST_H_
#define BST_H_

#include"node.h"

class bst
{
private:
	node *root;
public:
	bst();
	bool is_bst_empty(void)const;
	void add_node(int data);
	void preorder(void);//wrapper function
	void preorder(node *trav);//recursive function
	void inorder(void);//wrapper function
	void inorder(node *trav);//recursive function
	void postorder(void);//wrapper function
	void postorder(node *trav);//recursive function
	void nonrec_preorder(void);
	void nonrec_inorder(void);
	void nonrec_postorder(void);
	void dfs_traversal(void);
	void bfs_traversal(void);
	bool delete_node(int key);
	node *search_node(int key, node **parent);
	int height(void);
	int height(node *trav);
	void balance(void);
	void balance(node *trav, node *parent);
	node *left_rotation(node *axis, node *parent);
	node *right_rotation(node *axis, node *parent);
	~bst(void);

private:
	void free_bst(node *trav);
};



#endif /* BST_H_ */
