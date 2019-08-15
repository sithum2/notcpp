#include <iostream>

using namespace std;

void print_rev(const string &s, int i)
{
	cout << "{";
	do
	{
		cout << s[--i];
	}while(i);

	cout << "}" << endl;
}

int main(int argc, char **argv)
{
	print_rev("Hello", strlen("Hello"));	
	

	return 0;
}
