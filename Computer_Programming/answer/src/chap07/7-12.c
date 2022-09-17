#include <stdio.h>
#include <string.h> // memset
#define MAX_NUM (1000)

int fibonacci_2(int n) {
	if (n <= 1) return n;
	else return fibonacci_2(n - 1) + fibonacci_2(n - 2);
}

int mem[MAX_NUM];
int fibonacci_3(int n) {
	if (mem[n] != -1) return mem[n];
	else {
		mem[n] = fibonacci_3(n - 2) + fibonacci_3(n - 1);
		return mem[n];
	}
}

int main()
{
	int num;
	printf("몇번째 항까지 구할까요? "); scanf_s(" %d", &num);

	// 1: O(n)
	int a = 0, b = 1, c = a + b;
	if (num >= 0) printf("%d", a);
	if (num >= 1) printf(", %d", b);
	for (int i = 2; i <= num; ++i) {
		printf(", %d", c);
		a = b, b = c, c = a + b;
	}

	puts("");
	
	// 2: O(2^n) - recursive function call
	if (num >= 0) printf("0");
	for (int i = 1; i <= num; ++i) {
		printf(", %d", fibonacci_2(i));
	}

	puts("");

	// 3: O(N) - dynamic programming
	memset(mem, -1, sizeof(int) * MAX_NUM);
	// OR memset(mem, 0xff, sizeof(int) * MAX_NUM);
	mem[0] = 0, mem[1] = 1;

	if (num >= 0) printf("0");
	for (int i = 1; i <= num; ++i) {
		printf(", %d", fibonacci_3(i));
	}

	return 0;
}