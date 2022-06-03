#include <iostream>
#include <initializer_list>
#include <vector>
using namespace std;

/*Розв'язати завдання 1.2 першої лабораторної роботи з використанням вектора векторів Стандартної бібліотеки.
Для ініціалізації рядків використати ініціалізатори як фактичні параметри конструкторів векторів.
Для циклів, у яких не потрібне явне значення індексу, використовувати циклічну конструкцію for, побудовану на діапазоні (якщо це можливо).*/



template<class T>
class Array
{
private:
	vector<vector<T>> arr;

public:
	Array(int rows, int colz, double value) : Array(rows, colz)
	{
		for (size_t i = 0; i < arr.size(); i++)
		{
			for (size_t j = 0; j < arr[i].size(); j++)
			{
				arr[i][j] = value;
			}
		}
	}

	Array(int rows, int colz)
	{
		arr.resize(rows);
		for (size_t i = 0; i < rows; i++) 
		{
			arr[i].resize(colz);
		}
	}
	Array(initializer_list<vector<T>> list)
	{
		arr.resize(list.size());
		arr = list;
	}
	Array(initializer_list<initializer_list<T>> list)
	{
		arr.resize(list.size());
		int counter = 0;
		for (auto& i : list)
		{
			arr[counter] = i;
			counter++;
		}
	}

	T& operator()(int row, int col) { return arr.at(row).at(col); }
	T operator()(int row, int col) const { return arr.at(row).at(col); } // Отдельный оператор для перегрузки вывода (перегрузка const)

	vector<vector<T>>& GetVector() { return arr; }

	friend istream& operator>>(istream& in, Array<T> a)
	{
		for (size_t i = 0; i < arr.size(); i++)
		{
			for (size_t j = 0; j < arr[i].size(); j++)
			{
				in >> a(i, j);
			}
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, const Array<T>& a)
	{
		for (size_t i = 0; i < a.arr.size(); i++)
		{
			for (size_t j = 0; j < a.arr[i].size(); j++)
			{
				out << a(i, j) << '\t';
			}
			out << endl;
		}
		return out;
	}
	friend Array<T> operator+(const Array<T>& a, const Array<T>& b)
	{
		if (a.arr.size() != b.arr.size() || a.arr[0].size() != b.arr[0].size())
		{
			throw "Ошибка! Матрицы разных размеров";
		}
		else
		{
			Array<T> temp(a.arr.size(), a.arr[0].size());
			for (int i = 0; i < a.arr.size(); i++)
			{
				for (int j = 0; j < a.arr[0].size(); j++)
				{
					temp(i, j) = a(i, j) + b(i, j);
				}
			}
			return temp;
		}
	}
	friend Array<T> operator-(const Array<T>& a, const Array<T>& b)
	{
		if (a.arr.size() != b.arr.size() || a.arr[0].size() != b.arr[0].size())
		{
			throw "Ошибка! Матрицы разных размеров";
		}
		else
		{
			Array<T> temp(a.arr.size(), a.arr[0].size());
			for (int i = 0; i < a.arr.size(); i++)
			{
				for (int j = 0; j < a.arr[0].size(); j++)
				{
					temp(i, j) = a(i, j) - b(i, j);
				}
			}
			return temp;
		}
	}
	friend Array<T> operator*(const Array<T>& a, const Array<T>& b)
	{
		if (a.arr[0].size() != b.arr.size())
		{
			throw "The value of cols object a != value of rows object b";
		}
		Array<T> temp(a.arr.size(), b.arr[0].size());
		for (int i = 0; i < a.arr.size(); i++)
		{
			for (int j = 0; j < b.arr[0].size(); j++)
			{
				int sum = 0;
				for (int k = 0; k < a.arr[0].size(); k++)
				{
					sum += a(i,k) * b(k,j);
				}
				temp(i,j) = sum;
			}
		}
		return temp;
	}
};

template <typename T>
void Change(Array<T>& a)
{
	for (int i = 0; i < a.GetVector().size(); i++)
	{
		for (int j = 0; j < a.GetVector()[i].size(); j++)
		{
			if (a(i, j) == 0)
			{
				a(i, j) = 1;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	Array<int> a = { { 5, 1 }, { 7, 2 }, { 9, 3 } };
	Array<int> b = { vector<int>{ 1, 2 }, vector<int>{ 3, 4 }, vector<int>{ 1, 2 } };
	Array<double> c(3, 2, 2);
	Array<double> f(2, 3, 2);
	try
	{
		cout << c * f << endl;
		cout << a - b << endl;
		//cout << c(2, 4) << endl;
		cout << c - f << endl;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	catch (std::exception& a)
	{
		cout << a.what() << endl;
	}
}