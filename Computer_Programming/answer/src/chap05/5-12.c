#include <stdio.h>
int main()
{
	unsigned int result = 0;
	char a;
	printf("첫번째 문자를 입력하시오: "); scanf_s(" %c", &a, 1); result = result | (a << 0);
	printf("두번째 문자를 입력하시오: "); scanf_s(" %c", &a, 1); result = result | (a << 8);
	printf("세번째 문자를 입력하시오: "); scanf_s(" %c", &a, 1); result = result | (a << 16);
	printf("네번째 문자를 입력하시오: "); scanf_s(" %c", &a, 1); result = result | (a << 24);

	return 0;
}