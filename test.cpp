// this will count the number of item's in the vector the_list
// this is cool

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{	
	vector<int> the_list = {32,12,10,13,41,10,11,10,10,11,13,14,10};

	int item = 10;

	int num = count(the_list.cbegin(), the_list.cend(), item);

	cout << "there are "     << num
	     << " instances of " << item
	     << endl;

	return 0;
}
