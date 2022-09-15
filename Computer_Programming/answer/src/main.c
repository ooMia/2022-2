#include <stdio.h>
#include <stdlib.h>

void readFile(chapter, question)
{
	printf("readFile(%d, %d)\n", chapter, question);
}

int main(int argc, char* argv[])
{
	int chapter, question;
	if (argc == 1) {
		scanf_s(" %d %d", &chapter, &question);
	}
	else {
		printf("%d\n", argc);
		chapter = atoi(argv[1]);
		question = atoi(argv[2]);
	}

	readFile(chapter, question);

	return 0;
}