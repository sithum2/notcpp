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

template
<typename T>
T sum(vector<T> &v)
{
	T sum = 0;
	for(auto i = v.begin(); i != v.end(); ++i)
		sum += *i;

	return sum;
}

int main(int argc, char **argv)
{
	vector<int> nums{4,3,5,6,7};

	cout << accum(nums) << endl;
	cout << sum(nums)   << endl;

	for(auto &i : {4,5,56,7,7})
		cout << i << " ";

	vector<int> more_nums;
	
	for(int i; cin >> i;)
		more_nums.push_back(i);


	cout << endl;

	for(auto &i : more_nums)
		cout << i << ((i != *(--more_nums.end())) ? " + " : " = ");

	cout << sum(more_nums) << endl;
/*
	for(;;)
	{		//this loop runs forever until terminated
	}
*/
	cout << "cool cookies" << endl;


	return 0;
}
