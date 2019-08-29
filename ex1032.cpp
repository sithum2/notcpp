#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> v{4,3,4,6,7,3};

	int i = 0;

	v[i] = i++;

	ostream_iterator<int> output(cout, " ");

	copy(v.begin(), v.end(), output);

	cout << endl;

	return 0;
}
