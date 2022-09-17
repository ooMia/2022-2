#include <stdio.h>

int main()
{
	int num, result;
	printf("n의 값을 입력하시오: "); scanf_s(" %d", &num);

	// 1: O(n)
	result = 0;
	for (int n = num; n > 0; --n) result += n * n;
	printf("계산값은 %d입니다.\n", result);

	// 2: O(1)
	result = num * (num + 1) * (2 * num + 1) / 6;
	printf("계산값은 %d입니다.\n", result);

	return 0;
}