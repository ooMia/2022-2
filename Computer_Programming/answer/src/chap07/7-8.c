#include <stdio.h>

int main()
{
	int num;

	while (1) {
		printf("막대의 높이(종료: -1): "); scanf_s(" %d", &num);
		if (num == -1) break;
		else if (1 <= num && num <= 50) {
			for (int i = 0; i < num; ++i) printf("*");
			puts("");
		}
	}

	return 0;
}