#include <stdio.h>
#define FROM (2)
#define TO (100)

int main()
{
	int isPrime = 1;

	// 1: O(n^2) - brute force
	for (int num = FROM; num <= TO; ++num) {

		for (int n = 2; n < num; ++n) {
			if (num % n == 0) { isPrime = 0; break; }
		}

		if (isPrime) printf("%d ", num);
		else isPrime = 1;
	}
	
	puts("");

	// 2:  O(n * log log n) - Sieve of Eratosthenes
	char isNotPrime[TO + 1] = { 1,1,0, };
	for (int num = 2; num * num <= TO; ++num) {
		for (int i = num * 2; i <= TO; i += num)
			isNotPrime[i] = 1;
	}
	for (int num = FROM; num <= TO; ++num) {
		if (!isNotPrime[num]) printf("%d ", num);
	}

	return 0;
}