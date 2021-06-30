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

//forward declaration
class graph;

class edge
{
private:
	int v;//to vertex
	int w;//weight
public:
	edge(int v=0, int w=0)
	{
		this->v = v;
		this->w = w;
	}

	friend class graph;
};

class graph
{
private:
	vector<list<edge>> gr;
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
		list<edge> empty_list;

		for( int i = 0 ; i < this->vertices ; i++ )
			gr.push_back(empty_list);

		for( int i = 0 ; i < this->edges ; i++ )
		{
			int from, to, weight;
			cout << "enter an edge: from to to & weight : ";
			cin >> from >> to >> weight;

			edge ed1(to, weight);
			gr[from].push_back(ed1);

			edge ed2(from, weight);
			gr[to].push_back(ed2);
		}
	}

	void display_graph(void)
	{
		cout << "graph input is: " << endl;
		cout << "no. of vertices: " << this->vertices << endl;
		cout << "no. of edges: " << this->edges << endl;
		cout << "----------------------------------------------------" << endl;
		list<edge>::iterator itr;

		//outer for loop is for vector traversal
		for( unsigned int i = 0 ; i < gr.size() ; i++ )
		{
			cout << "[ " << i << " ]" << " => ";
			//inner for loop is for list traversal
			for( itr = gr[i].begin() ; itr != gr[i].end() ; itr++ )
				cout << "|" << itr->v << " : " << itr->w  << "|" << "->";
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




