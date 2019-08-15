#include <iostream>
#include <vector>

using namespace std;

template
<typename Iter, typename Value>
size_t find_it(Iter beg, Iter end, const Value &v)
{
	auto old_beg = beg;
	while(beg != end && *beg != v)
		++beg;

	return beg - old_beg;
}

int main(int argc, char **argv)
{
	vector<int> nums{4,5,6,7,8,4,3,4,56,7};

	int n = 3;

	if(size_t i = find_it(nums.begin(), nums.end(), n))
	{
		cout <<  n << " found " << " at index " << i << endl;
	}else
	{
		cout << "number not found" << endl;
	}

	return 0;
}
