/*
 * main.cpp
 *
 *  Created on: 10-Mar-2020
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<cstring>
#include<iomanip>

#define MAX 10

class graph
{
private:
	int mat[MAX][MAX];
	int vertices;
	int edges;
public:
	graph()
	{
		memset(mat,0,sizeof(mat));
		this->vertices = 0;
		this->edges = 0;
	}


	void accept_graph(void)
	{
		cout << "enter no. of vertices : ";
		cin >> this->vertices;

		cout << "enter no. of edges : ";
		cin >> this->edges;

		for( int i = 0 ; i < this->edges ; i++ )
		{
			int from, to;
			cout << "enter an edge from to to: ";
			cin >> from >> to;

			mat[from][to] = 1;
			mat[to][from] = 1;//this line will be in comment for di-graph
		}
	}

	void display_graph(void)
	{
		cout << "graph g1 is: " << endl;
		cout << "no. of vertices: " << this->vertices << endl;
		cout << "no. of edges : " << this->edges << endl;
		cout << "---------------------------------" << endl;
		for( int i = 0 ; i < this->vertices ; i++ )
		{
			for( int j = 0 ; j < this->vertices ; j++ )
			{
				cout << setw(4) << left << mat[i][j];
			}
			cout << endl;
		}
		cout << endl;
		cout << "---------------------------------" << endl;
	}
};


int main(void)
{
	graph g1;

	g1.accept_graph();
	g1.display_graph();

	return 0;
}


