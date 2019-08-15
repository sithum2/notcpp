#include <iostream>
#include <vector>

using namespace std;

template
<typename Iter, typename Value>
Iter find_it(Iter beg, Iter end, const Value &v)
{
	while(beg != end && *beg != v)
		++beg;

	return beg;
}

int main(int argc, char **argv)
{

	vector<int> nums{4,5,6,7,8,4,3,4,56,7};

	int n = 3;

	if(auto i = find_it(nums.begin(), nums.end(), n) != nums.end())
	{
		cout <<  n << " found " << " at index " << i << endl;
		cout << nums[i] << endl;
	}else
	{
		cout << "number not found" << endl;
	}

	return 0;
}
