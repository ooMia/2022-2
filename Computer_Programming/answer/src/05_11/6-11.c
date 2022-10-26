#include <stdio.h>

int main() {

	printf("문자를 입력하시오: ");
	char ch = getchar();

	if ('a' <= ch) ch -= ('a' - 'A');

	switch (ch)
	{
	case 'R':
		printf("Rectangle");
		break;
	case 'T':
		printf("Triangle");
		break;
	case 'C':
		printf("Circle");
		break;
	default:
		printf("Unknown");
		break;
	}

	return 0;
}