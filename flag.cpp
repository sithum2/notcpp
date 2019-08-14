#include <iostream>

using namespace std;

enum class Flag : char { x = 1, y = 2, z = 4, e = 8 };

int main(int argc, char **argv)
{
	Flag f0{};
	
//	Flag f1 = 5;

	Flag f2 = Flag{static_cast<Flag>(4)};

	switch(f2)
	{
		case Flag::x :
			cout << "x" << endl;
			break;
		case Flag::y :
			cout << "y" << endl;
			break;
		case Flag::z :
			cout << "z" << endl;	
			break;
		case Flag::e :
			cout << "e" << endl;
			break;
		default:
			cout << " could not decode value " << endl;
	};
	
	return 0;
}
