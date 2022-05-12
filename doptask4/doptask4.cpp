#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int>	vect;
	cout << "Input the values into vector" << endl;
	int data;
	while (cin.good())
	{
		cin >> data;
		if(cin.good()) vect.push_back(data);
	}
	vector<int> sv;
	for_each(vect.cbegin(), vect.cend(), [&sv](int a) 
	{
			sv.push_back(pow(a, 2));
	});
	cout << "1st" << endl;
	for (auto& i : vect)
	{
		cout << i << " ";
	}
	cout << endl << endl;
	cout << "2nd" << endl;
	for (auto& i : sv)
	{
		cout << i << " ";
	}
}