#include "prime.h"
#include "test.h"

#define MAX 10000000

int main()
{
	prime::init(MAX);
	//prime::printPrimeBitStream();
	//testPrime(MAX);
	testLong();
	return 0;
}