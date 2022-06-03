#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;


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
	vector<int> getGrades() const { return grades; }

	double getRaiting() const
	{
		double finalGrade = 0;
		for (auto& i : grades)
		{
			finalGrade += i;
		}
		if (grades.size() == 0) throw "Нет оценок для получения рейтинга";
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
	friend ostream& operator<<(ostream& out, const Student& st)
	{
		out << "Фамилия: " << st.getSecondName() << "\tСтуденченский: " << st.getId()
			<< "\tРейтинговый бал: " << st.getRaiting() << endl;
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
	vector<Student> getFilteredByBstudents() 
	{
		return FilterByB();
	}
	void sortList()
	{
		sort(students.begin(), students.end(), [](const Student& a, const Student& b) -> bool
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
	Student operator[](int i)  { return students.at(i); }
	int size() { return students.size(); }

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

class Less
{
public:
	bool operator()(const Student& a, const Student& b) const
	{
		return a.getRaiting() < b.getRaiting();
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	Group KH221A
	{
		{ Student("Kovalenko", 32345,  vector<int>{70, 21, 5, 24, 7})},
		{ Student("Krid4enko",	52345, vector<int>{83, 83, 83, 83, 83})},
		{ Student("Antonov",	72445, vector<int>{89, 89, 89, 89, 89})},
		{ Student("Golovko",		17745, vector<int>{82, 82, 82, 82, 82})},
		{ Student("Yaroshenko",	18375,  vector<int>{85, 85, 85, 85})},
		{ Student("Semeshin",		92375, vector<int>{82, 82, 82, 82, 85})},
		{ Student("Gryshevsiy",		46215, vector<int>{30, 82, 82, 82, 82})},
		{ Student("Kovalenkof",		46215, vector<int>{99, 99, 99, 99, 99})}
	};

	cout << KH221A << endl;
	priority_queue <Student, vector<Student>, Less> q;
	try
	{
		//KH221A.sortList();
		for (size_t i = 0; i < KH221A.size(); i++)
		{
			q.push(KH221A[i]); 
		}
		while (q.size())
		{
			cout << q.top();
			q.pop();
		}
		//Group KH220(KH221A.SortAscAndFilteredByB());
		//cout << KH220 << endl;
		//KH221A.sortList();
		//cout << KH221A << endl;
		//cout << KH221A.SortAscAndFilteredByB() << endl;
	}
	catch (const char* a)
	{
		cout << a << endl;
	}
	catch (exception& a)
	{
		cout << a.what();
	}

}