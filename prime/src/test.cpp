#include "test.h"

#include <iostream>
#include "prime.h"

int testPrime(uint max)
{
	int errCnt = 0;
	for (int i = 2; i <= max; i++)
	{
		bool actual = prime::isPrime(i);
		bool expected = prime::checkPrime(i);
		if (actual != expected)
		{
			printf("%d => expected=%d | actualResult=%d ERROR\n", i, expected, actual);
			errCnt++;
		}
	}
	printf("%d errors found\n", errCnt);
	return errCnt;
}

void testLong()
{
	printf("Proceeding with long test, this might take a while\n\n");

	int arrSize = sizeof(sizes) / sizeof(sizes[0]);
	for (int i = 0; i < arrSize; i++)
	{
		printf("Test for max = %d\n", sizes[i]);

		prime::init(sizes[i]);
		testPrime(sizes[i]);
		prime::getComparison();

		printf("\n");
	}

	printf("Test is finished\n");
}