#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool is_prime(const string &s)
{
	int p = stoi(s);

	if(p == 2) return true; //base case

	for(auto i = 2; i <= sqrt(p); ++i)
	{
		if(p % i == 0)  // i.e. i divides p so we must return false
			return false;
	}

	return true;
}


string find_prime_1(const initializer_list<string> &lst)
{
	vector<string> v(lst);
//	cout << v[0] << endl;

	for(auto i = 0; i != v.size(); ++i)
	{
		if(!is_prime(v[i]))
			continue;
		
		return v[i];
	}

	return "None Primes Found";
}

string find_prime_2(const initializer_list<string> &lst)
{
	vector<string> v(lst);

	for(auto i = 0; i != v.size(); ++i)
	{	
		if(is_prime(v[i]))
			return v[i];
	}

	return "No Primes Found";
}

int main(int argc, char **argv)
{
	cout << find_prime_1({"4","6","8","9","14","16"}) << endl;
	cout << find_prime_1({"4","6","8","9","17","14","16"}) << endl;

	//is_prime("x");

//	cout << is_prime("4") << endl;	

//	is_prime("10");

//	find_prime_1({"4"});

	return 0;
}
