#include <stdio.h>
#include <stdlib.h> // exit

int calc(char op) {
	int n1, n2;
	printf("두 수를 공백으로 분리하여 입력하시오: ");
	scanf_s(" %d %d", &n1, &n2);
	switch (op)
	{
	case 'A': return n1 + n2;
	case 'S': return n1 - n2;
	case 'M': return n1 * n2;
	case 'D': return n1 / n2;
	default: printf("undefined operator\n"); exit(-1);
	}
}

int main()
{
	puts("*****************");
	puts("A---- Add");
	puts("S---- Subtract");
	puts("M---- Multiply");
	puts("D---- Devide");
	puts("Q---- Quit");
	puts("*****************");

	char op = 0;
	do {
		printf("연산을 선택하시오:");
		scanf_s(" %c", &op, 1);

		switch (op)
		{
		case 'A':case 'S':case 'M':case 'D':
			printf("%d\n", calc(op));
		}

		if (op == 'Q') break;
	} while (1);
	
	return 0;
}