#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <sstream>

#include "prime.h"

namespace prime
{
	#define BIT(x) ((x / 2 - 1) % 8)
	#define BYTE(x) ((x / 2 - 1) / 8)
	#define POSITION(x) (1 << x)

	void init(uint max)
	{
		if (max < 3)
		{
			std::cout << "ERROR: " << max << " is smaller than 3" << std::endl;
			return;
		}

		if (s_Primes.size() > 0)
		{
			s_Primes.clear();
			s_PrimeCount = 0;
		}

		s_Max = max;

		generate(s_Max);
	}

	bool isPrime(uint n)
	{
		/*if (s_Max == 0)
		{
			std::cout << "ERROR: not initialized";
		}*/

		if (n == 2)
		{
			return true;
		}

		if (n % 2 == 0 || n < 2)
		{
			return false;
		}

		if (n > s_Max)
		{
			std::cout << "WARNING: number is not in primes list, using normal method\n";
			return checkPrime(n);
		}

		return s_Primes[BYTE(n)] & POSITION(BIT(n));
	}

	uint getPrimeCount() 
	{ 
		return s_PrimeCount; 
	}

	uint getByteCount()
	{
		return s_Primes.size();
	}

	void printPrimeBitStream()
	{
		std::ostringstream oss;
		for (auto it = s_Primes.begin(); it != s_Primes.end(); it++)
		{
			oss << std::bitset<8>(*it) << "\n";
		}

		std::cout << oss.str();
	}

	void generate(uint max)
	{
		s_Primes.reserve(BYTE(max));

		for (int i = 3; i <= max; i += 2)
		{
			if (BYTE(i) >= s_Primes.size())
			{
				s_Primes.push_back(0);
			}

			if (checkPrime(i))
			{
				s_Primes[BYTE(i)] |= POSITION(BIT(i));
				s_PrimeCount++;
			}
		}
	}

	void generateSieve(uint max)
	{
		// fill all bytes with: 1111 1111
		s_Primes.resize(BYTE(max), 0xff);

		for (int i = 3; i <= sqrt(max); i += 2)
		{
			if (s_Primes[BYTE(i)] & POSITION(BIT(i)))
			{
				for (int j = i * i; j < max; j += 2*i)
				{
					s_Primes[BYTE(j)] &= (~POSITION(BIT(j)));
				}
			}
		}
	}

	bool checkPrime(uint n)
	{
		if (n == 2)
		{
			return true;
		}

		if (n < 2 || n % 2 == 0)
		{
			return false;
		}

		for (int i = 3; i <= sqrt(n); i += 2)
		{
			if (n % i == 0)
			{
				return false;
			}
		}

		return true;
	}

	void getDetails()
	{
		printf("%d prime numbers, max is %d\n%d bytes\n", s_PrimeCount, s_Max, getByteCount());
	}

	void getComparison()
	{
		printf(
			"%d+1 primes numbers, max is %d\n %d bytes if storing int32\n %d bytes if storing int64\n %d bytes if storing bools\n %d bytes from my method\n",
			s_PrimeCount,
			s_Max,
			4 * (s_PrimeCount + 1), // the +1 is for 2 since its not stored and ignored
			8 * (s_PrimeCount + 1),
			s_Max,
			getByteCount()
		);
	}
}