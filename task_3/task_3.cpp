/*Стандартная библиотека С++. Итераторы. Вектор. Алгоритмы.
Предикаты. Функторы.
3. Дан вектор, хранящий целые числа. Необходимо распределить
положительные, отрицательные и нулевые элементы в другие вектора. */

#include <iostream>
#include <vector>

using namespace std;

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

	const int min{ -10 };
	const int max{ 10 };

	// Создание пустого вектора.
	vector<int> source;
	vector<int> positive;
	vector<int> negative;
	vector<int> zero;

	// Заполнение вектора элементами.
	for (int i = 0; i < 20; i++)
	{
		int r = rand() % (max - min + 1) + min;
		source.push_back(r);
	}

	cout << "Source:" << endl;
	print_container(source);

	// Распределение.
	for (auto it = source.begin(); it != source.end(); it++)
	{
		if (*it < 0)
			negative.push_back(*it);
		if (*it == 0)
			zero.push_back(*it);
		if (*it > 0)
			positive.push_back(*it);
	}

	cout << "Negative:" << endl;
	print_container(negative);

	cout << "Zero:" << endl;
	print_container(zero);

	cout << "Positive:" << endl;
	print_container(positive);
}