#include <stdio.h>

int main()
{
	int num;
	printf("정수를 입력하시오: "); scanf_s(" %d", &num);

	// 1: O(n^2)
	for (int row = 1; row <= num; ++row) {
		for (int i = 1; i <= row; ++i) printf("%d ", i);
		puts("");
	}

	// 2: O(n)
	char str[100]; int i = 0;
	for (int n = 1; n <= num; ++n) {
		str[i++] = '0' + n;
		str[i++] = ' ';
	} str[i] = '\0';

	for (int j = -1, row = 1; row <= num; ++row) {
		str[j += 2] = '\0';
		if (j > 1) str[j - 2] = ' ';
		printf("%s\n", str);
	}

	return 0;
}