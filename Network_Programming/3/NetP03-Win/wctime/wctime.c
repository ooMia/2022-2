// wctime.c : ctime() �� ���
#include <stdio.h>
#include <time.h>
#include <string.h>
void main() {
	time_t today;
	time(&today); // today = time(NULL);
	printf("ctime() = %s", ctime(&today));
}