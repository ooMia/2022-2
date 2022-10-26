#include <stdio.h>
#include <stdlib.h> // srand rand
#include <time.h>	// time

// SWAP Array by its Index
#define SWAP(arrName, indexA, indexB)			\
do {											\
	int temp = (arrName)[(indexA)];				\
	(arrName)[(indexA)] = (arrName)[(indexB)];	\
	(arrName)[(indexB)] = temp;					\
} while (0);


// �迭 ���
void printArray(int* arr, int len) {
	for (int i = 0; i < len; i++) printf("%d ", arr[i]);
	puts("");
}

// [1, 10] ���� �ڿ����� �ʱ�ȭ
void init1(int* arr, int len)
{
	int from = 1, to = 10;

	for (int i = 0; i < len; i++)
		arr[i] = rand() % (to + 1 - from) + from;
}

// [1, 10] ���� �ڿ����� �ߺ����� �ʱ�ȭ
void init2(int* arr, int len)
{
	int from = 1, to = 10;
	char isAssigned[10+1] = { 0, };
	
	for (int i = 0; i < len; i++) {
		int val = rand() % (to + 1 - from) + from; // [to, from] ���� �ڿ���

		if (isAssigned[val]) { i--; continue; }
		else { isAssigned[val] = 1; arr[i] = val; }
	}
}

void sortAsc1(int* arr, int len)
{
	for (int t = 0; t < len; t++) {
		int targetIndex = t;
		int minValueIndex = t;
		
		for (int i = len - 1; i > targetIndex; i--)
			if (arr[i] < arr[minValueIndex]) minValueIndex = i;

		SWAP(arr, targetIndex, minValueIndex);
	}
}


int main() {
	srand((unsigned)time(NULL));
	int arrA[10] = { 0, }, lenA = sizeof(arrA) / sizeof(int);

	printf("\n����\n"); printArray(arrA, lenA);
	
	init1(arrA, lenA);
	printf("\n[1, 10] ���� �ڿ����� �ʱ�ȭ\n"); printArray(arrA, lenA);

	init2(arrA, lenA);
	printf("\n[1, 10] ���� �ڿ����� �ߺ����� �ʱ�ȭ\n"); printArray(arrA, lenA);

	sortAsc1(arrA, lenA);
	printf("\n�������� ����\n"); printArray(arrA, lenA);

	return 0;
}

