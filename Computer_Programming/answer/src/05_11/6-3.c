#include <stdio.h>

int main()
{
	int x, y, z, min;
	printf("3개의 정수를 입력하시오:"); scanf_s(" %d %d %d", &x, &y, &z);

	if (x < y) {
		if (x < z) min = x;
		else min = z;
	}
	else if (y < z) min = y;
	else min = z;

	printf("제일 작은 정수는 %d입니다.", min);

	return 0;
}