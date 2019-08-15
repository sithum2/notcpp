//reviewed from github.com

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	//int i = 10;
	int i = 5;

	switch(i)
	{
		case (5):
			cout << "i is less than 5" << endl;
			int h;
			cout << "h is " << h << endl;
			break;
		case (10):
			cout << "i is greater than 5" << endl;
			//h = 99;
			++h;
			cout << "h is: " << h << endl;
			break;

	};



	return 0;
}
