#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// опис завдання

/*Створити клас для представлення даних про студента. Клас повинен містити такі елементи даних:

номер студентського посвідчення (unsigned int);
прізвище (рядок типу std::string);
оцінки за останню сесію у вигляді послідовності цілих від 0 до 100 (оцінка за предметом, std::vector).
Всередині класу реалізувати функції доступу, а також об'явити конструктор, який ініціалізує елементи даних, та функції, які здійснюють:

обчислення показника, за величиною якого здійснюється сортування відповідно до індивідуального завдання;
перевірку умови, яка використовується для пошуку даних відповідно до індивідуального завдання.
Здійснити опис класу для представлення групи студентів. В об'єкті такого класу повинні зберігатись дані про студентів у вигляді вектора об'єктів класу, який представляє студента. Клас повинен містити перевантажені операції введення-виведення, а також функції-елементи, які здійснюють

сортування масиву за ознакою, яка наведена в індивідуальному завданні (з використанням алгоритму sort());
пошук даних про студентів, які відповідають умові, наведеній в індивідуальному завданні (з використанням алгоритму for_each()).
Розмістити об'єкти класу "Студент" в черзі з пріоритетом, з якої вилучати об'єкти в порядку зменшення середнього балу.*/


class Student
{
private:
	string secondName;
	size_t id;
	vector<int> grades;

public:
	Student(string t_name, size_t t_id, vector<int> t_grades) :
		secondName(t_name), id(t_id), grades(move(t_grades)) {}

	string getSecondName() const { return secondName; }
	size_t getId() const { return id; }

	double getRaiting() const
	{
		double finalGrade = 0;
		for (auto& i : grades)
		{
			finalGrade += i;
		}
		if(grades.size() == 0) throw "Нет оценок для получения рейтинга";
		return (finalGrade / grades.size());
	}

	bool RaitingIsB() // ф-ція для відбору студентів з конкретним рейтингом
	{
		double raiting = getRaiting();
		return raiting <= 89 && raiting >= 82;
	}

	friend ostream& operator<<(ostream& out, const vector<Student>& st)
	{
		for (auto& i : st)
		{
			out << "Фамилия: " << i.getSecondName() << "\tСтуденченский: " << i.getId()
				<< "\tРейтинговый бал: " << i.getRaiting() << endl;
		}
		return out;
	}
};

class Group
{
private:
	vector<Student> students;

public:
	Group(initializer_list<Student> list)
	{
		students = list;
	}
	Group(vector<Student> temp) : students(temp) {}

	vector<Student> SortAscAndFilteredByB()
	{
		sortList();
		return FilterByB();
	}

	void sortList()
	{
		sort(students.begin(), students.end(), [](const Student& a, const Student& b)
		{
			return a.getSecondName().length() < b.getSecondName().length();
		});
	}

	friend ostream& operator<<(ostream& out, const Group& grp)
	{
		for (auto& i : grp.students)
		{
			out << "Фамилия: " << i.getSecondName() << "\tСтуденченский: " << i.getId()
				<< "\tРейтинговый бал: " << i.getRaiting() << endl;
		}
		return out;
	}
private:
	vector<Student> FilterByB()
	{
		vector<Student> temp;
		for_each(students.begin(), students.end(), [&temp](Student a)
		{
			if (a.RaitingIsB()) temp.push_back(a);
		});
		return temp;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	Group KH221A
	{
		{ Student("rg", 12345, vector<int>{87, 87, 87, 87, 87})},
		{ Student("Дружочек",	12345, vector<int>{83, 83, 83, 83, 83})},
		{ Student("j",	12345, vector<int>{89, 89, 89, 89, 89})},
		{ Student("ebhfqwekgkq",		12345, vector<int>{82, 82, 82, 82, 82})},
		{ Student("ewf",	12345, vector<int>{85, 85, 85, 85, 85})},
		{ Student("Scefgtwetwpin",		12345, vector<int>{82, 82, 82, 82, 82})},
		{ Student("123f",		12345, vector<int>{30, 82, 82, 82, 82})}
	};
	Group KH220(KH221A.SortAscAndFilteredByB());
	try
	{
		cout << KH221A << endl;
		KH221A.sortList();
		cout << KH221A << endl;
		cout << KH221A.SortAscAndFilteredByB() << endl;
	}
	catch (string a)
	{
		cout << a << endl;
	}
	catch (exception& a)
	{
		cout << a.what();
	}

}