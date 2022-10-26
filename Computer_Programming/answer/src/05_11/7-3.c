#include <stdio.h>

int main()
{
	int num;
	printf("정수를 입력하시오: "); scanf_s(" %d", &num);
	
	// 1: [1..60] - O(n): brute force
	printf("\n약수: ");
	for (int i = 1; i <= num; ++i) {
		if (num % i == 0) { printf("%d ", i); }
	}

	// 2: [1..7] - O(sqrt n)
	printf("\n약수: ");
	for (int i = 1; i*i <= num; ++i) {
		if (num % i == 0) {
			if (i * i == num) { printf("%d ", i); }
			else { printf("%d %d ", i, num / i); }
		}
	}

	// 3: [1..7] - O(sqrt n), Sorted
	printf("\n약수: ");
	int j = -1, stack[100];
	for (int i = 1; i * i <= num; ++i) {
		if (num % i == 0) {
			printf("%d ", i);
			if (i * i != num) { stack[++j] = (num / i); }
		}
	}
	while (j >= 0) { printf("%d ", stack[j--]); }

	return 0;
}