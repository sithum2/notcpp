#include <iostream>

using namespace std;

double prim(bool test)
{
	if(test)
		return 10.7;
	else
		return 0.0;
}

int main(int argc, char **argv)
{
	double left = 100.55;

	if(double d = prim(false))
	{
		left /= d;
	}else
	{
		cout << "condition was false. division was not performed" << endl;
	}

	cout << left << endl;

	return 0;
}
