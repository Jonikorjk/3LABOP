#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
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
	vector<int> someVect;
	transform(vect.begin(), vect.end(), vect.begin(), back_inserter(someVect), multiplies<int>());
	for (auto& i : someVect)
	{
		cout << i << '\t';
	}
}