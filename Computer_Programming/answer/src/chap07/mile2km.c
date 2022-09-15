#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int meter;
	int i = 0;
	
	while(i < 3)
	{
		meter = i * 1609;
		printf("%d 마일은 %d 미터입니다\n", i, meter);
		i++;
	}
	
	return 0;
}
