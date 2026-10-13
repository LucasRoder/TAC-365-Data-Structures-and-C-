#include <iostream>
#include <stdexcept>
#include "TACvector.hpp"

using namespace std;

int main()
{
	cout << "a. Default constructor" << endl;
	TACvector<int> v;
	cout << "capacity: " << v.capacity() << ", size: " << v.size() << endl;

	cout << "\nb. Parameterized constructor" << endl;
	TACvector<int> v2(25);
	cout << "capacity: " << v2.capacity() << endl;

	cout << "\nc. push_back" << endl;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	cout << v << endl;

	cout << "\nd. pop_back" << endl;
	v.pop_back();
	cout << v << endl;
	TACvector<int> empty;
	try
	{
		empty.pop_back();
	}
	catch (out_of_range& e)
	{
		cout << "exception: " << e.what() << endl;
	}

	cout << "\ne. back" << endl;
	cout << v.back() << endl;
	try
	{
		empty.back();
	}
	catch (out_of_range& e)
	{
		cout << "exception: " << e.what() << endl;
	}

	cout << "\nf. Copy constructor" << endl;
	TACvector<int> copy(v);
	cout << "original: " << v << ", copy: " << copy << endl;

	cout << "\ng. Assignment operator" << endl;
	TACvector<int> assigned;
	assigned = v;
	cout << "original: " << v << ", assigned: " << assigned << endl;

	cout << "\nh. [] operator" << endl;
	cout << "v[2]: " << v[2] << endl;
	v[2] = 45;
	cout << "after v[2] = 45: " << v << endl;
	try
	{
		cout << v[10] << endl;
	}
	catch (out_of_range& e)
	{
		cout << "exception: " << e.what() << endl;
	}

	cout << "\ni. clear and empty" << endl;
	cout << "empty before clear: " << v.empty() << endl;
	v.clear();
	cout << "empty after clear: " << v.empty() << endl;

	cout << "\nj. Capacity expansion" << endl;
	for (int i = 0; i < 11; i++)
	{
		v.push_back(i);
		cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;
	}

	return 0;
}
