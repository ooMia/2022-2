#include <stdio.h>

int main()
{
	int x, y;
	printf("정수를 입력하시오:"); scanf_s(" %d", &x);
	printf("정수를 입력하시오:"); scanf_s(" %d", &y);
	printf("약수%s", (x % y == 0) ? "입니다." : "가 아닙니다.");

	return 0;
}