#pragma once

#include <vector>

typedef unsigned char byte;
typedef unsigned int uint;

namespace prime 
{
	static std::vector<byte> s_Primes;
	static uint s_PrimeCount = 0;
	static uint s_Max = 0;

	// used to initialize the list of primes, ALWAYS use it first before using isPrime()
	// it can also be reinitialized at any time
	void init(uint max);
	// this is the function that will be used by the user, to check if its in the primes vector
	bool isPrime(uint n);
	void printPrimeBitStream();
	uint getPrimeCount();
	uint getByteCount();

	// generate all prime numbers up until s_Max, and store it in s_Primes vector, using sieve of Eratosthenes alg
	static void generate(uint max);
	// function used for checking if number is prime
	bool checkPrime(uint n);

	// get some details about stored amount
	void getDetails();
	// get comparison data between other methods of storage
	void getComparison();
}