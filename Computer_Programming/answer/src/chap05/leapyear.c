#define _CRT_SECURE_NO_WARNINGS
// ���� ���α׷�
#include <stdio.h>
int main(void)
{
	int year, result;
	
	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &year);

	result = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	printf("result=%d \n", result);

	return 0;
}