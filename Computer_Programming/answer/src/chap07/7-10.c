#include <stdio.h>
#include <math.h>

int main()
{
	double num;	printf("�Ǽ��� ���� �Է��Ͻÿ�: ");	scanf_s(" %lf", &num);
	int iter;	printf("�ŵ�����Ƚ���� �Է��Ͻÿ�: ");	scanf_s(" %d", &iter);
	

	// 1
	double result = 1;
	for (int i = iter; i > 0; --i) result *= num;
	printf("������� %lf\n", result);
	
	// 2
	printf("������� %lf\n", pow(num, (double)iter));

	return 0;
}