#include <stdio.h>
#include <math.h>

int main()
{
	double num;	printf("실수의 값을 입력하시오: ");	scanf_s(" %lf", &num);
	int iter;	printf("거듭제곱횟수를 입력하시오: ");	scanf_s(" %d", &iter);
	

	// 1
	double result = 1;
	for (int i = iter; i > 0; --i) result *= num;
	printf("결과값은 %lf\n", result);
	
	// 2
	printf("결과값은 %lf\n", pow(num, (double)iter));

	return 0;
}