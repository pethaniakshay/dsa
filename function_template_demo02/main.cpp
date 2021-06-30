/*
 * main.cpp
 *
 *  Created on: 06-Mar-2020
 *      Author: sunbeam
 */

#include<iostream>
using namespace std;
#include<iomanip>

/*
void swap_values(int &in1, int &in2)
{
	int temp = in1;
	in1 = in2;
	in2 = temp;
}

void swap_values(float &fn1, float &fn2)
{
	float temp = fn1;
	fn1 = fn2;
	fn2 = temp;
}
*/

//function template
template <typename T>
void swap_values(T &n1, T &n2)
{
	T temp = n1;
	n1 = n2;
	n2 = temp;
}

class complex
{
private:
	int real;
	int imag;
public:
	//ctor
	complex(int real=0, int imag=0)
	{
		this->real = real;
		this->imag = imag;
	}

	//mutators

	//inspectors

	//facilitators
	void display_number(void) const
	{
		cout << this->real << " + " << this->imag << "i" << endl;
	}

	//dtor
	~complex()
	{ }
};

int main(void)
{
	int in1=10, in2=20;

	cout << "before swapping: in1 = " << in1 << "\tin2 = " << in2 << endl;
	//swap_values<int>(in1, in2);
	swap<int>(in1, in2);
	cout << "after swapping : in1 = " << in1 << "\tin2 = " << in2 << endl;
	cout << "------------------------------------------------------" << endl;
	float fn1=10.10f, fn2=20.20f;

	cout << "before swapping: fn1 = " << fn1 << "\tfn2 = " << fn2 << endl;
	//swap_values<float>(fn1, fn2);
	swap<float>(fn1, fn2);
	cout << "after swapping : fn1 = " << fn1 << "\tin2 = " << fn2 << endl;
	cout << "------------------------------------------------------" << endl;

	complex c1(2,3);
	complex c2(4,5);
	cout << "before swapping: " << endl;
	cout << "c1 : "; c1.display_number();
	cout << "c2 : "; c2.display_number();

	//swap_values<complex>(c1, c2);
	swap<complex>(c1, c2);

	cout << "after swapping: " << endl;
	cout << "c1 : "; c1.display_number();
	cout << "c2 : "; c2.display_number();

	return 0;
}




