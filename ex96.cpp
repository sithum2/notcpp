#include <iostream>

using namespace std;

void process(int n, int m, int a)
{
	int mn[m][n];  //create an m X n empty array

	for(auto i = 0; i != m; ++i)
	{
		for(auto j = 0; j != n; ++j)
		{
			mn[i][j] = m * n;
			if(i > 0 && j > 0 && i == j) 
			{
				cout << "(i > 0 && j > 0 && i == j) condition held" << endl;
//				mn[i][j] = a;
			}
		}
	}

	for(auto i = 0; i != m; ++i)
	{
		for(auto j = 0; j != n; ++j)
		{
			if(mn[i][j] == a)
			{
				goto label;
			} 
		}
	}
	
	goto other_label;

	label:
		cout << "label processed" << endl;
		//do some stuff here..
	other_label:
		cout << "other_label processed" << endl;
}

int main(int argc, char **argv)
{

	process(5,4,10);

	return 0;
}
