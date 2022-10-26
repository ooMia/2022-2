#include <stdio.h>
#include <stdlib.h> // malloc exit

#define MAX_NUM (12)
typedef unsigned long long ull;

ull* mem[MAX_NUM][MAX_NUM] = { NULL, };

ull Permutation_2(ull n, ull r)
{
	if (r == 0) return 1;
	else if (r == 1) return n;
	else if (mem[n][r] != NULL) return *mem[n][r];

	mem[n][r] = (ull*)malloc(sizeof(ull));
	if (mem[n][r] == NULL) exit(-1);
	else if (n - r <= 1) { *mem[n][r] = n * Permutation_2(n - 1, r - 1); }
	else *mem[n][r] // n_P_r = n-1_P_r + n-1_P_r-1 * r
		= Permutation_2(n - 1, r) + Permutation_2(n - 1, r - 1) * r;
	return *mem[n][r];
}

int main()
{
	ull n, r, nPr = 1;
	printf("n의 값:\t"); scanf_s(" %lld", &n);
	printf("r의 값:\t"); scanf_s(" %lld", &r);

	// 1
	for (ull i = n; i >= (n - r + 1); --i) { nPr *= i; }
	printf("순열의 값은 %lld입니다.\n", nPr);

	// 2 - dynamic programming
	printf("순열의 값은 %lld입니다.", Permutation_2(n,r));

	return 0;
}