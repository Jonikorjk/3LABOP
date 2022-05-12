// Занести дані про студентів групи в контейнер multiset. Ключем є прізвище, в групі можуть бути однофамільці.
// Видати повідомлення, якщо в групі є однофамільці. Видати дані про студентів групи за алфавітом прізвищ.

#include <algorithm>
#include <set>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	multiset<string> ms{ "Ivanov", "Serdiukov", "Ponomarev", "Ivanov", "Ponomarev", "Crysler", "Abobys"};
	for_each(ms.begin(), ms.end(), [&ms](string a)
	{
		if (ms.count(a) > 1)
		{
			cout << "Есть однофамильцы с фамилией: " << a << endl << endl;
		}
	});
	for (auto& i : ms)
	{
		cout << i << endl;
	}
}