// lab 6.3 - recursion
// варіант 24*

#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
T first_pair0(T* a, T size, T m, T i)
{
	if (i < size)
	{
		if (a[i] % 2 == 0)
		{
			m = a[i];
			return m; // повертаємо перший знайдений парний елемент
		}
		first_pair0(a, size, m, i + 1);
	}
	else
		return m; // якщо не знайдено парних елементів - повертаємо 0
}

template <class T>
T max0(T* a, const T size, T i, T m)
{
	if (i < size)
	{
		if (a[i] % 2 == 0)
		{
			if (a[i] > m)
				m = a[i];
		}
		max0(a, size, i + 1, m);
	}
	else
		return m; 
}

template <class T>
T Print0(T* a, const T size, T i)
{
	if (i < size)
	{
		cout << setw(4) << a[i];
		Print0(a, size, i + 1);
	}
	return 0;
}

template <class T>
T Create0(T* a, const T size, const T Low, const T High, T i)
{
	if (i < size)
	{
		a[i] = Low + rand() % (High - Low + 1);
		Create0(a, size, Low, High, i + 1);
	}
	return 0;
} 

int first_pair(int* a, const int size, int m, int i)
{
	if (i < size)
	{
		if (a[i] % 2 == 0)
		{
			m = a[i];
			return m; // повертаємо перший знайдений парний елемент
		}
		first_pair(a, size, m, i + 1);
	}
	else
		return m;
}

int max(int* a, const int size, int i, int m)
{
	if (i < size)
	{
		if (a[i] % 2 == 0)
		{
			if (a[i] > m)
				m = a[i];
		}
		max(a, size, i + 1, m);
	}
	else
		return m;
}
void Print(int* a, const int size, int i)
{
	if (i < size)
	{ 
		cout << setw(4) << a[i];
		Print(a, size, i + 1);
	}
}

void Create(int* a, const int size, const int Low, const int High, int i)
{
	if (i < size)
	{
		a[i] = Low + rand() % (High - Low + 1);
		Create(a, size, Low, High, i + 1);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	const int n = 20;

	int a[n];
	int m = 0;
	int i = 0;
	
	Create(a, n, -20, -1, 0);
	
	cout << "array = ";
	Print(a, n, 0);
	cout << '\n' << '\n' << "max" << setw(5) << max(a, n, 0, first_pair(a, n, 0, 0)) << '\n';
	m = 0;

	cout << "----------------------------------------" << '\n';
	Create0(a, n, -20, -1, 0);

	cout << "array = ";
	Print0(a, n, 0);
	cout << '\n' << '\n' << "max (template)" << setw(5) << max0(a, n, 0, first_pair0(a, n, 0, 0)) << '\n';


	getchar();
}