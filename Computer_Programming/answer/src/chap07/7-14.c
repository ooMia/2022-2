#include <stdio.h>

int main()
{
	int num;
	printf("������ �Է��Ͻÿ�: "); scanf_s(" %d", &num);

	do {
		printf("%d", num % 10);
	} while ((num /= 10) != 0);

	return 0;
}