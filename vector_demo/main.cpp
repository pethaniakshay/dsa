/*
 * main.cpp
 *
 *  Created on: 06-Mar-2020
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>
#include<vector>
#include<iterator>
#include<algorithm>

void display_vector(vector<int> &ref_v);


int main(void)
{
	vector<int> v1;

	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(50);
	v1.push_back(60);

	cout << "v1 ele's are: ";
	display_vector(v1);

	cout << "min ele: " << *min_element(v1.begin(), v1.end()) << endl;
	cout << "max ele: " << *max_element(v1.begin(), v1.end()) << endl;
	sort(v1.begin(), v1.end());
	cout << "v1 ele's are: ";
	display_vector(v1);
	return 0;
}


void display_vector(vector<int> &v)
{
	vector<int>::iterator itr;
	for( itr = v.begin() ; itr != v.end() ; itr++ )
		cout << setw(4) << left << *itr;
	cout << endl;
	/*
	for( unsigned int index = 0 ; index < v.size() ; index++ )
		cout << setw(4) << left << v[index];
	cout << endl;
	*/
}

