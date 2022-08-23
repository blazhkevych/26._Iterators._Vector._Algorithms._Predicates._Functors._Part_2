/*Стандартная библиотека С++. Итераторы. Вектор. Алгоритмы.
Предикаты. Функторы.
1. Даны два вектора различной размерности: А[M] и B[N]. Необходимо
создать третий вектор, в котором нужно собрать элементы векторов A и
B, которые не являются общими для них.*/

// ГОТОВО

#include <iostream>     
#include <algorithm>    // std::set_symmetric_difference, std::sort
#include <vector>

using namespace std;

int main()
{
	srand(time(NULL));

	const int min{ -10 };
	const int max{ 10 };

	// Создание пустого вектора.
	vector<int> v1;
	vector<int> v2;

	// Заполнение вектора элементами.
	for (int i = 0; i < 10; i++)
	{
		int r = rand() % (max - min + 1) + min;
		v1.push_back(r);
	}
	// Вывод векторов.
	ostream_iterator<int> out(cout, " ");
	cout << "Vector v1: ";
	copy(v1.begin(), v1.end(), out);
	cout << endl << endl;

	// Заполнение вектора элементами.
	for (int i = 0; i < 5; i++)
	{
		int r = rand() % (max - min + 1) + min;
		v2.push_back(r);
	}
	// Вывод векторов.
	cout << "Vector v2: ";
	copy(v2.begin(), v2.end(), out);
	cout << endl << endl;

	vector<int> v3;
	vector<int>::iterator it_v3;

	// Сортировка векторов.
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	v3.reserve(std::max(v1.size(), v2.size()));
	set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v3));

	// Вывод векторов.
	cout << "Vector v3: ";
	copy(v3.begin(), v3.end(), out);
	cout << endl << endl;
}