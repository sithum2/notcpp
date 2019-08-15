#include <iostream>
#include <vector>

using namespace std;

template
<typename T>
T accum(vector<T> &v)
{
	T sum = 0;
	for(T &i : v)
		sum += i;

	return sum;
}

int main(int argc, char **argv)
{
	vector<int> nums{4,3,5,6,7};

	cout << accum(nums) << endl;

	return 0;
}
