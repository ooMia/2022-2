#include <stdio.h>

int main()
{
	int num, result;
	printf("n�� ���� �Է��Ͻÿ�: "); scanf_s(" %d", &num);

	// 1: O(n)
	result = 0;
	for (int n = num; n > 0; --n) result += n * n;
	printf("��갪�� %d�Դϴ�.\n", result);

	// 2: O(1)
	result = num * (num + 1) * (2 * num + 1) / 6;
	printf("��갪�� %d�Դϴ�.\n", result);

	return 0;
}