#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int s[3][5];		// 2���� �迭 ����
	int i, j;		// 2���� �ε��� ����
	int value = 0;		// �迭 ���ҿ� ����Ǵ� ��
	
	for(i=0;i<3;i++)	
		for(j=0;j<5;j++)	
			s[i][j] = value++;

	for(i=0;i<3;i++)	
		for(j=0;j<5;j++)	
			printf("%d\n", s[i][j]);
	return 0;
}