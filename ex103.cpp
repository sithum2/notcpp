#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	string s1{"hello"};	
	string &s = s1;

	s.move(string{10,'c'});

	return 0;
}
