#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <Windows.h>

#define MAX_LENGTH (50)
char* mem[MAX_LENGTH + 1] = { "", "*", "**", NULL,};

char* getStars(int num) {
	if (num < 0 && num > MAX_LENGTH) exit(-1);
	if (0 <= num && num <= 2) return mem[num];
	
	else if (mem[num] == NULL) {
		
		char* ptr = (char*)calloc(num + 5, sizeof(char));
		if (ptr == NULL) exit(-1);
		
		char* halfStars = getStars(num / 2);
		strcpy_s(ptr, sizeof(ptr), halfStars), Sleep(300);
		strcat_s(ptr, sizeof(ptr), halfStars), Sleep(300);
		if (num % 2) { strcat_s(ptr, sizeof(ptr), "*"); Sleep(300); }
		return (mem[num] = ptr);
	}

	else if (mem[num] != NULL) return mem[num];

	else return "ERROR";
}

int main()
{
	int num;

	while (1) {
		printf("막대의 높이(종료: -1): "); scanf_s(" %d", &num);
		if (num == -1) break;
		else if (1 <= num && num <= MAX_LENGTH) {
			// 1
			for (int i = 0; i < num; ++i) { printf("*"); Sleep(300); }
			puts("");

			// 2
			printf("%s\n", getStars(num));
		}
	}

	return 0;
}