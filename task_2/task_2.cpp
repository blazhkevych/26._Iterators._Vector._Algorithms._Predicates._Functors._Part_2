/*Стандартная библиотека С++. Итераторы. Вектор. Алгоритмы.
Предикаты. Функторы.
2. Дан вектор, хранящий положительные числа. Необходимо удалить из
вектора все простые числа.*/

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

bool isPrime(int n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;

	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}

void print_container(const vector<int>& c)
{
	for (int i : c)
	{
		cout << i << " ";
	}
	cout << '\n';
}

int main()
{
	srand(time(NULL));

	const int min{ 0 };
	const int max{ 100 };

	// Создание пустого вектора.
	vector<int> v1;

	// Заполнение вектора элементами.
	for (int i = 0; i < 20; i++)
	{
		int r = rand() % (max - min + 1) + min;
		v1.push_back(r);
	}
	// Вывод векторов.
	cout << "Vector v1: " << endl;
	print_container(v1);

	// Удалить из вектора все простые числа.
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); )
	{
		if (isPrime(*it))
		{
			it = v1.erase(it);
		}
		else
		{
			++it;
		}
	}

	// Вывод векторов.
	cout << "Vector v1 after removal: " << endl;
	print_container(v1);
}