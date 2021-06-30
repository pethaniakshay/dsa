/*
 * main.cpp
 *
 *  Created on: 06-Mar-2020
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>

//<return_type> <function_name>(<datatype> <arg1>, <data type> arg2);

/*
int get_max(int n1, int n2)
{
	int max = ( n1 > n2 ) ? n1 : n2 ;
	return max;
}

float get_max(float n1, float n2)
{
	float max = ( n1 > n2 ) ? n1 : n2 ;
	return max;
}
*/

//function template
template <typename T>
T get_max(T n1, T n2)
{
	T max = ( n1 > n2 ) ? n1 : n2 ;
	return max;
}


int main(void)
{
	int in1=50, in2=20;

	int imax = get_max<int>(in1, in2);

	cout << "imax : " << imax << endl;

	float fn1=11.11f, fn2=22.22f;
	float fmax = get_max<float>(fn1, fn2);
	cout << "fmax : " << fmax << endl;

	return 0;
}




