/*

Author: David Charles (inspired by example in Stroustrup section 9.5)

Find primes on an interval [a,b] using the sqrt method augmented by 
a sieve of Eratosthenes which employs a continue to skip iterations for excluded numbers
already in the Sieve

List will be sorted first using insertion sort

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

struct Range_Error {};

bool is_prime(unsigned p)
{
	if(p == 0 || p == 1) return false;

	for(auto d = 2; d <= sqrt(p); ++d) 
		if(p % d == 0) return false;

	return true;
}

//takes an interval [a,b] and returns a vector of primes on that interval
vector<unsigned> extract_primes(unsigned a, unsigned b)
{
	if(a > b) throw Range_Error{};

	vector<unsigned> primes;
	set<unsigned> exclusions;
	unsigned count = 0;

	for(auto i = a; i != b + 1; ++i) 
	{
		if(!exclusions.empty() && (exclusions.find(i) != exclusions.end())) 
		{
			++count;
			continue;
		}

		if(is_prime(i))
		{
			primes.push_back(i);

			for(auto n = 2; n <= (b+1) / i; ++n)
			{
				exclusions.insert(i*n);
			}
		}
	}

	cout << "saved iterations from Sieve: " << count << endl;
	cout << "primes found: " << primes.size() << endl;
	cout << "total iterations: " << b + 1 - a - count << endl;

	return primes;
}

class Print
{
	unsigned value;
	static unsigned index;

	public:
		Print(unsigned val) : value(val) {}

		void print(ostream &os) const
		{
			if(++index % 4 == 0) 
			{	
				os << value << "\n";
			}else
			{
				os << value << " ";
			}
		}
};

unsigned Print::index = 0;

ostream & operator<<(ostream &os, const Print &p)
{	
	p.print(os);

	return os;
}

int main(int argc, char **argv)
{
	if(argc == 3)
	{
		unsigned a = stoi(argv[1]);

		unsigned b = stoi(argv[2]);

		ostream_iterator<Print> output(cout);

		vector<unsigned> primes = extract_primes(a,b);

		copy(primes.begin(), primes.end(), output);

		cout << endl;
			
	}else
	{
		cout << "please specify an interval [a,b] on which to find primes" << endl;
	}

	return 0;
}
