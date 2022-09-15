#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int compute_sum(int n);

int main(void)
{
	int sum = 0;
	sum = compute_sum(100);
	return 0;
}
int compute_sum(int n)
{
	int i;
	int result = 0;
	for(i = 1; i <= n; i++)
		result += i;
	return result;
}
