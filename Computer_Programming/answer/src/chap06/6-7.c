#include <stdio.h>

int main()
{
	double weight, height;
	printf("키와 체중을 입력하세요:"); scanf_s(" %lf %lf", &height, &weight);
	double standard = (height - 100) * 0.9;

	if (weight == standard) printf("표준 ");
	else if (weight < standard) printf("저");
	else printf("과"); printf("체중입니다.");

	return 0;
}