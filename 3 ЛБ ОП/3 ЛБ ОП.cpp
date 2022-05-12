#include <iostream>
#include <vector>

template <class T>
class Array
{
private:
	std::vector<std::vector<T>> arr;

public:
	Array(std::initializer_list<std::initializer_list<T>> list)
	{
		std::vector<std::vector<T>> newVect(list);

		arr = std::move(newVect);
	}
	T& operator()(int row, int col) 
	{
		//return array.at(row).at(col);
	}

};



int main()
{
	Array<int> arr{ {1,4,5},{3,2,1}, {4,6,8} };
	std::cout << arr(5, 5);
	//*Array<int> a;*/
	std::vector<std::vector<int>> a{ {3,1,5,7,8}, 
									{21,2,7,8,3} };
	a[1][3];
	//std::cout << a[1][0] << '\n';

	//std::cout << a.capacity();
}