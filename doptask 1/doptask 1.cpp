//Розробити програму, в якій зчитуються цілі значення і підраховується число повторень кожного значення, за винятком чисел, зазначених у списку.
//Підрахунок числа повторень числа реалізовувати за допомогою асоціативного масиву, список чисел для виключення реалізовувати за допомогою множини.
//Кожен раз, коли зустрілося число зі списку, виводити повідомлення.
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
	set<int> st{ 1, 2, 3 };
	cout << "Input values" << endl;
	multimap <int, int> mmap;
	int data;
	while (cin.good())
	{
		cin >> data;
		if (cin.good()) mmap.emplace(data, data);
	}

	for_each(mmap.begin(), mmap.end(), [mmap, st](auto a)
	{
		if (st.find(a.second) != st.end()) cout << "The value was finded from set" << endl;
		else cout << "Count of element - " << a.second << " : " << mmap.count(a.second) << endl;
	});
}