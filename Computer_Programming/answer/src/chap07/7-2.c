#include <stdio.h>

int main()
{
	int from = 1, to = 100, div = 3, result;

	// 1: (3+6+..+99) - O(n): brute force
	result = 0;
	for (int i = from; i <= to; ++i) {
		if (i % div == 0) result += i;
		// OR result += (i % div == 0) ? i : 0;
	}
	printf("1: %d\n", result);

	// 2: (3+6+..+99) - O(n/3)
	result = 0;
	for (int i = ((from / div) + (from % div != 0)) * div; i <= to; i += div) {
		result += i;
	}
	printf("2: %d\n", result);

	// 3: (1+2+..+33)*3 - O(n/3)
	result = 0;
	for (int i = (from / div) + (from % div != 0); i <= (to / div); ++i) {
		result += i;
	}
	printf("3: %d\n", result *= div);

	// 4: {(1+2+..+33)-(0+..+0)}*3 - O(1)
	int n = (from / div) + (from % div != 0) - 1;
	int m = (to / div);
	result = (m * (m + 1) / 2) - (n * (n + 1) / 2);
	printf("4: %d\n", result *= div);

	printf("%d부터 %d 사이의 모든 %d의 배수의 합은 %d입니다.\n", from, to, div, result);

	return 0;
}