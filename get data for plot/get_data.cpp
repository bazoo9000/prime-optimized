#include <iostream>
#include <fstream>
#include <cmath>

bool isPrime(int n)
{
	if (n <= 1)
	{
		return false;
	}

	int sq = std::sqrt(n);
	for (int d = 2; d <= sq; d++)
	{
		if (n % d == 0)
		{
			return false;
		}
	}

	return true;
}

int primeCountBetween(int a, int b)
{
	if (b < a)
	{
		std::swap(a, b);
	}

	int count = 0;
	for (int n = a; n <= b; n++)
	{
		if (isPrime(n))
		{
			count++;
		}
	}

	return count;
}

int main()
{
	int start, end, step;
	std::cout << "Select starting point (greater than 0), end point and step (start += step while < end)\n";
	std::cout << "start = ";
	std::cin >> start;
	std::cout << "end = ";
	std::cin >> end;
	std::cout << "step = ";
	std::cin >> step;

	if (start < 1)
	{
		printf("start=%d is less than 1\n", start);
		std::cin.get();
		return 1;
	}

	std::ofstream out("data.txt");

	int crtCount = 0;
	for (int i = start; i <= end; i += step)
	{
		// This is so i dont have to count again from 0, more fast
		crtCount += primeCountBetween(i - start + 1, i);
		out << i << " " << crtCount << "\n";
	}

	out.close();
	std::cin.get();
	return 0;
}