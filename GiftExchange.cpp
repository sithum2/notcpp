// GiftExchange.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <random>
#include <sstream>
#include <fstream>
#include <numeric>
#include <vector>
#include <iterator>
#include <iomanip>

using std::setw;
using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::istringstream;
using std::ostringstream;
using std::ofstream;
using std::iota;
using std::random_shuffle;
using std::ostream_iterator;
using std::vector;
using std::getline;
using std::string;
using std::istream_iterator;
using std::ifstream;
using std::to_string;

int getRand(int i) { return rand() % i; }

int main(int argc, char **argv)
{
	bool paired_exchange = false; //true is paired exchange mode (i.e. A buys for B, B buys for A, C buys for D, D buys for C etc
								  //false is gift-buying-mode (i.e. A buys for B, B buys for C, etc)

	srand(unsigned(time(NULL)));

	string names_list;

	if (argc == 2)
	{
		cout << "opening: " << argv[1] << "..." << endl;

		ifstream input_file(argv[1]);
		if (!input_file.is_open())
		{
			cout << "file was not opened!" << endl;
		}
		else
		{
			cout << argv[1] << " is open..." << endl;
		}

		getline(input_file, names_list);

		input_file.close();

		if (!input_file.is_open())
		{
			cout << argv[1] << " is now closed..." << endl;
		}
		else
		{
			cout << argv[1] << " is still open..." << endl;
		}
	}
	else
	{
		cout << "Please enter list participants in exchange separated by spaces: ";
		getline(cin, names_list);
	}

	istringstream all_names{ names_list };
	istream_iterator<string> is{ all_names };
	istream_iterator<string> eos;

	vector<string> names( is, eos );

	cout << "names list: " << names_list << endl;
	cout << "(there are " << names.size() << " names in total)." << endl;

	ostream_iterator<string> output(cout, " ");

	random_shuffle(names.begin(), names.end(), getRand);

	copy(names.begin(), names.end(), output);
	const time_t now = time(0);
	//string date_time = ctime(&now);
	char date_time[100];

	std::tm holder;     //for thread-safe behavior
	//localtime_s(&holder, &now);
	localtime_s(&now, &holder);

	strftime(date_time, sizeof(date_time), "%Y_%b_%d_%H_%M_%S", &holder);

	string date_time_s(date_time);

	ofstream output_file("exchange_list" + date_time_s + ".txt");
	ostream_iterator<string> output2(output_file);
	ostream_iterator<string> output3(output_file," ");


	if (!paired_exchange)
	{
		//blind pairs (cycle loop used to select names)
		//check for empty case
		if (names.size() == 0)
		{
			output_file.close();
			cerr << endl;
			cerr << "Error: Name list is empty! Cannot proceed with exchange!" << endl;
			output2 = "Error: Name list is empty! Cannot proceed with exchange!";
			return -1;
		}
		//proceed with non-paired gift assignment
		for (auto i = names.begin(); i != names.end();)
		{
			auto buyer = i;
			auto receiver = ++i;

			if (receiver == names.end())
			{
				ostringstream formatted;

				formatted << setw(15) << *buyer << " ** buys for ** " << *names.begin();

				output2 = formatted.str();

				/*
				output2 = *buyer;
				output2 = " buys for ";
				output2 = *names.begin();
				*/
			}
			else
			{
				ostringstream formatted;

				formatted << setw(15) << *buyer << " ** buys for ** " << *receiver << "\n";
				output2 = formatted.str();

				/*
				output2 = *buyer;
				output2 = " buys for ";
				output2 = *receiver;
				output2 = "\n";
				*/
			}
		}
	}
	else //paired exchange
	{
		//should also do version for an actual exchange
		//will require an even number of participants
		if (names.size() % 2 != 0)
		{
			cerr << endl;
			cerr << "Error: Even number of names required" << endl;
			output3 = "Error: Even number of names required";
			output3 = "\n";
			output3 = "list: ";
			copy(names.begin(), names.end(), output3);
			string msg = "\n has an odd number of names (" + to_string(names.size()) + ")\n";
			output3 = msg;
			output3 = "please add or delete names until there are an even number of names to proceed with gift-exchange";
			output_file.close();
			return -1;
		}
		else if (names.size() == 0)
		{
			cerr << endl;
			cerr << "Error: Name list is empty! Cannot proceed with exchange!" << endl;
			output3 = "Error: Name list is empty! Cannot proceed with exchange!";
			output_file.close();
			return -1;
		}

		//proceed with paired gift exchange

		auto first = names.begin();
		auto second = ++names.begin();
		while (second != names.end())
		{
			ostringstream formatted;

			formatted << setw(15) << *first << " ** exchanges with ** " << *second << "\n";
			output2 = formatted;

			/*
			output2 = *first;
			output2 = " exchanges with ";
			output2 = *second;
			output2 = "\n";
			*/

			++first;
			++second;
		}

	}
	
	output_file.close();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
