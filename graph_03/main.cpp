/*
 * main.cpp
 *
 *  Created on: 10-Mar-2020
 *      Author: sunbeam
 */


#include<iostream>
using namespace std;
#include<iomanip>
#include<vector>
#include<list>
#include<iterator>


class graph
{
private:
	vector<list<int>> gr;
	int vertices;
	int edges;
public:
	graph()
	{
		this->vertices=0;
		this->edges=0;
	}

	void accept_graph(void)
	{
		cout << "enter no. of vertices : ";
		cin >> this->vertices;

		cout << "enter no. of edges : ";
		cin >> this->edges;

		//create an empty list objects
		list<int> empty_list;

		for( int i = 0 ; i < this->vertices ; i++ )
			gr.push_back(empty_list);

		for( int i = 0 ; i < this->edges ; i++ )
		{
			int from, to;
			cout << "enter an edge: from to to: ";
			cin >> from >> to;

			gr[from].push_back(to);
			gr[to].push_back(from);
		}
	}

	void display_graph(void)
	{
		cout << "graph input is: " << endl;
		cout << "no. of vertices: " << this->vertices << endl;
		cout << "no. of edges: " << this->edges << endl;
		cout << "----------------------------------------------------" << endl;
		list<int>::iterator itr;

		//outer for loop is for vector traversal
		for( unsigned int i = 0 ; i < gr.size() ; i++ )
		{
			cout << "[ " << i << " ]" << " => ";
			//inner for loop is for list traversal
			for( itr = gr[i].begin() ; itr != gr[i].end() ; itr++ )
				cout << *itr << "->";
			cout << "null" << endl;
		}
		cout << "----------------------------------------------------" << endl;

	}
};

int main(void)
{
	graph g1;

	g1.accept_graph();
	g1.display_graph();

	return 0;
}
