/*
 * emp.cpp
 *
 *  Created on: 06-Mar-2020
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>
#include<string>
#include<list>
#include<iterator>

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
	list<int> l1;

	l1.push_back(11);
	l1.push_back(22);
	l1.push_back(33);
	l1.push_back(44);
	l1.push_back(55);
	l1.push_back(66);

	list<int>::iterator itr;

	cout << "list l1 is: ";
	for( itr = l1.begin() ; itr != l1.end() ; ++itr )
		cout << setw(4) << left << *itr;
	cout << endl;


	list<employee> emp_list;

	emp_list.push_back(employee(111,"sachin", 1111.11));
	emp_list.push_back(employee(222,"sourav", 2222.22));
	emp_list.push_back(employee(333,"rahul", 3333.33));
	emp_list.push_back(employee(444,"rohit", 4444.44));
	emp_list.push_back(employee(555,"virat",5555.55));

	list<employee>::iterator itr1;
	cout << "list of employees is: " << endl;
	for( itr1 = emp_list.begin() ; itr1 != emp_list.end() ; itr1++ )
		cout << setw(4) << left << *itr1;


	return 0;
}


