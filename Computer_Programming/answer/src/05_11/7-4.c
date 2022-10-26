#include <stdio.h>

int main()
{
	int nLines = 7;

	// 1
	for (int row = 1; row <= nLines; ++row) {
		for (int space = nLines - row; space > 0; --space) { printf(" "); }
		for (int star = 1; star <= row; ++star) { printf("*"); }
		puts("");
	}

	// 2
	char str[8] = "       ";
	for (int row = 1; row <= nLines; ++row) {
		str[nLines - row] = '*';
		printf("%s\n", str);
	}

	// 3
	for (int row = 1; row <= nLines; ++row) {
		char blanks[8] = "       ";
		char stars[8] = "*******";
		
		blanks[nLines - row] = '\0';
		stars[row] = '\0';

		printf("%s%s\n", blanks, stars);
	}

	return 0;
}