/*
 * main.cpp
 *
 *  Created on: 09-Mar-2020
 *      Author: sunbeam
 */
#include<iostream>
using namespace std;

#include"bst.h"

int main(void)
{
	bst t1;
	/*
	t1.add_node(50);
	t1.add_node(20);
	t1.add_node(90);
	t1.add_node(85);
	t1.add_node(10);
	t1.add_node(45);
	t1.add_node(30);
	t1.add_node(100);
	t1.add_node(15);
	t1.add_node(75);
	t1.add_node(95);
	t1.add_node(120);
	t1.add_node(5);
	t1.add_node(50);
	*/
	t1.add_node(10); t1.add_node(20); t1.add_node(30); t1.add_node(40);
	t1.add_node(50); t1.add_node(60);t1.add_node(70);
	t1.preorder();//call to wrapper function
	//t1.nonrec_preorder();

	t1.inorder();//call to wrapper function
	//t1.nonrec_inorder();

	t1.postorder();//call to wrapper function
	//t1.nonrec_postorder();

	t1.dfs_traversal();
	t1.bfs_traversal();
	cout << "height of t1 is: " << t1.height() << endl;
	/*
	int key;
	cout << "enter the key to be deleted : ";
	cin >> key;

	if( t1.delete_node(key) )
		cout << "node deleted successfully...." << endl;
	else
		cout << "node does not exists !!!" << endl;

	*/

	t1.balance();
	cout << "------------- after balancing bst ----------------- " << endl;
	cout << "height of t1 is: " << t1.height() << endl;
	t1.preorder();//call to wrapper function
	t1.inorder();//call to wrapper function
	t1.postorder();//call to wrapper function
	t1.dfs_traversal();
	t1.bfs_traversal();

	return 0;
}

