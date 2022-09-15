#include <stdio.h>
int main(void)
{
	int x;
	printf("정수를 입력하시오:"); scanf_s("%d", &x);
	printf("2의 보수:%d", ~x + 1);

	return 0;

}