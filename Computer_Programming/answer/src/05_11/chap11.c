#include <stdio.h>
#include <stdlib.h> // srand() rand()
#include <time.h> // time()

void Q1() {
	int x = 0x12345678;
	unsigned char* xp = (char*)&x;
	// Little-endian: Intel(R) Core(TM) i7-9750H CPU
	printf("����Ʈ ����: %x %x %x %x\n", xp[0], xp[1], xp[2], xp[3]);
}
void get_sum_diff(int x, int y, int* p_sum, int* p_diff) {
	*p_sum = x + y, * p_diff = x - y;
}
void Q2() {
	int x, y, sum, diff;
	printf("���� 2�� �Է� >>"); scanf_s(" %d %d", &x, &y);
	get_sum_diff(x, y, &sum, &diff);
	printf("���ҵ��� ��=%d\n���ҵ��� ��=%d\n", sum, diff);
}
void array_fill(int* A, int size) {
	for (int i = 0; i < size; i++) A[i] = rand();
}
void Q3() {
	int arr[10], size = sizeof(arr) / sizeof(int);
	array_fill(arr, size);
	for (int i = 0; i < size; i++) printf("%d ", arr[i]);
	puts("");
}
void array_print(char* name, int* A, int size) {
	printf("%s[] = { ", name);
	for (int i = 0; i < size; i++)
		printf(i == 0 ? "%d" : ", %d", A[i]);
	printf(" }\n");
}
void Q4() {
	int A[10] = { 1,2,3,4,0 };
	array_print("A", A, sizeof(A) / sizeof(int));
}
void convert(double* grades, double* scores, int size) {
	for (int i = 0; i < size; i++)
		scores[i] = grades[i] * 100 / 4.3;
}
void Q5() {
	double grades[10], scores[10];
	int size = sizeof(grades) / sizeof(double);

	for (int i = 0; i < size; i++) grades[i] = 0.5 * i;
	grades[size - 1] = 4.3;

	convert(grades, scores, size);

	for (int i = 0; i < size; i++) printf("%6.2lf ", grades[i]); puts("");
	for (int i = 0; i < size; i++) printf("%6.2lf ", scores[i]);
}
void array_copy(int* A, int* B, int size) {
	for (int i = 0; i < size; i++) B[i] = A[i];
}
void Q6() {
	int A[10] = { 1,2,3,4,0 }, B[10];
	int size = sizeof(A) / sizeof(int);
	array_copy(A, B, size);
	array_print("A", A, size), array_print("B", B, size);
}
void array_add(int* A, int* B, int* C, int size) {
	for (int i = 0; i < size; i++) C[i] = A[i] + B[i];
}
void Q7() {
	int A[10] = { 1,2,3,4,0 }, B[10] = { 0 }, C[10];
	int size = sizeof(A) / sizeof(int);
	array_add(A, B, C, size);
	array_print("A", A, size), array_print("B", B, size), array_print("C", A, size);
}
int array_sum(int* A, int size) {
	int res = 0;
	for (int i = 0; i < size; i++) res += A[i];
	return res;
}
void Q8() {
	int A[10] = { 1,2,3,4,0 };
	int size = sizeof(A) / sizeof(int);
	printf("������ �� = %d\n", array_sum(A, size));
}
int search(int* A, int size, int search_value) {
	for (int i = 0; i < size; i++) if (A[i] == search_value) return i;
	return -1; // NO SUCH VALUE
}
void Q9() {
	int A[10] = { 240, 200, 0 };
	int search_value = 200;
	printf("������ %d������ ����� �ε��� = %d\n",
		search_value, search(A, sizeof(A) / sizeof(int), search_value));
}
void get_lcm_gcd(int x, int y, int* p_lcm, int* p_gcd) {

	// p_gcd ���ϱ� (ex. 348, 36)
	// 36 / 348 = 0*348 + 36
	// 348 / 36 = 9*36 + 24
	// 36 / 24 = 1*24 + 12
	// 24 / 12 = 2*12
	// >> 348 / 36 = 9*( 1*( 2*12 ) + 12 ) + 24
	// �ᱹ, 12�� �� ���̹Ƿ� �ִ����� 12

	int a = x, b = y, c;
	while (1) {
		c = a % b; // ���� ���� ���
		if (c == 0) { *p_gcd = b; break; } // 0�̸� ���� ���� �ִ� �����
		else a = b, b = c; // 0�� �ƴϸ�(���� ��, ������)�� �ٽ� �ݺ�
	}
	*p_lcm = (x * y) / *p_gcd;
}
void Q10() {
	int x, y, p_lcm, p_gcd;
	printf("�� ���� ������ �Է��Ͻÿ�: "); scanf_s(" %d %d", &x, &y);
	get_lcm_gcd(x, y, &p_lcm, &p_gcd);
	printf("�ּҰ������ %d�Դϴ�.\n�ִ������� %d�Դϴ�.\n", p_lcm, p_gcd);
}
void merge(int* A, int* B, int* C, int size) {
	int ai = 0, bi = 0, ci = 0;
	while (ai < size && bi < size) {
		if (A[ai] <= B[bi]) C[ci++] = A[ai++];
		else C[ci++] = B[bi++];
	}
	while (ai < size) C[ci++] = A[ai++];
	while (bi < size) C[ci++] = B[bi++];
}
void Q11() {
	int A[4] = { 2,5,7,8 }, B[4] = { 1,3,4,6 }, C[8];
	int size = sizeof(A) / sizeof(int);
	merge(A, B, C, size);
	array_print("A", A, size);
	array_print("B", B, size);
	array_print("C", C, size * 2);
}
void get_int(int* px, int* py) {
	printf("2���� ������ �Է��Ͻÿ�: "); scanf_s(" %d %d", px, py);
}
void Q12() {
	int x, y;
	get_int(&x, &y);
	printf("������ ���� %d\n", x + y);
}

int main() {
	srand((unsigned)time(NULL));
	//Q1();
	//Q2();
	//Q3();
	//Q4();
	//Q5(); 
	//Q6();
	//Q7();
	//Q8();
	//Q9();
	//Q10();
	//Q11();
	//Q12();

	return 0;
}