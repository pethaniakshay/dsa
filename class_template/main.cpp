/*
 * main.cpp
 *
 *  Created on: 06-Mar-2020
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<cstdlib>
#include<iomanip>
#include<string>

//forward declaration
template <class node> class list;

//template class
template <class T>
class node
{
private:
	T data;
	node<T> *next;
public:
	node(T data)
	{
		this->data = data;
		this->next = NULL;
	}

	template <class node> friend class list;
};

//template class
template <class T>
class list
{
private:
	node<T> *head;
	int cnt;
public:
	list()
	{
		head=NULL;
		cnt=0;
	}

	bool is_list_empty(void) const
	{
		return ( head == NULL );
	}

	void add_node_at_last_position(T data)
	{
		//create a newnode
		node<T> *newnode = new node<T>(data);

		//if list is empty -- attach newly created node to the head
		if( is_list_empty())
		{
			head = newnode;
			cnt++;
		}
		else//if list is not empty
		{
			//start traversal from the first node
			node<T> *trav = head;

			//traverse the list till last node
			while( trav->next != NULL )
				trav = trav->next;

			//attach newly created  node to the last node
			trav->next = newnode;
			cnt++;
		}
	}

	void display_list(void) const
	{
		//if list is not empty
		if( !is_list_empty())
		{
			//start traversal from the first node
			node<T> *trav = head;
			//traverse the list till last node including last node
			while( trav != NULL )
			{
				cout << setw(4) << left << trav->data;
				trav = trav->next;
			}
			cout << endl;
		}
	}
};

class employee
{
private:
	int empid;
	string name;
	float salary;
public:
	//ctor
	employee(int empid=0, string name="", float salary=0.0)
	{
		this->empid = empid;
		this->name = name;
		this->salary = salary;
	}

	//inspectors - getter functions

	//mutators - setter functions

	//facilitators
	friend ostream&  operator<<(ostream &out, employee &other)
	{
		out << setw(6) << left << other.empid;
		out << setw(20) << left << other.name;
		out << setw(10) << left << other.salary;
		cout << endl;
		return out;
	}

	//dtor


};


int main(void)
{
	list<int> l1; //-- l1 is a linked list of ele's of type integer


	l1.add_node_at_last_position(11);
	l1.add_node_at_last_position(22);
	l1.add_node_at_last_position(33);
	l1.add_node_at_last_position(44);
	l1.add_node_at_last_position(55);

	cout << "list l1 is: "; l1.display_list();

	list<employee> emp_list;//-- emp_list is a linked list of ele's of type employee

	emp_list.add_node_at_last_position( employee(111, "sachin", 1111.11) );
	emp_list.add_node_at_last_position( employee(222, "nilesh", 2222.22) );
	emp_list.add_node_at_last_position( employee(333, "rakesh", 3333.33) );
	emp_list.add_node_at_last_position( employee(444, "sandeep", 4444.44) );
	emp_list.add_node_at_last_position( employee(555, "amit", 5555.55) );

	cout << "list of employees is: " << endl;
	emp_list.display_list();

	return 0;
}





