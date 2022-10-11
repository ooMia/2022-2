#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <Windows.h>
#include <conio.h>


Q1(){
	int days[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	for (int month = 1; month <= 12; month++)
		printf("%d월은 %d일까지 있습니다.\n", month, days[month - 1]);
}
int getMax(int* arr, int len) {
	int res = arr[0];
	for (int i = 1; i < len; i++) { if (res < arr[i]) res = arr[i]; }
	return res;
}
int getMin(int* arr, int len) {
	int res = arr[0];
	for (int i = 1; i < len; i++) { if (arr[i] < res) res = arr[i]; }
	return res;
}
Q2(){
	int arr[10];
	int len = sizeof(arr) / sizeof(int);
	for (int i = 0; i < len; i++) { arr[i] = rand(); }
	printf("최대값은 %d\n최소값은 %d\n", getMax(arr, len), getMin(arr, len));
}
int array_equal(int a[], int b[], int len) {
	for (int i = 0; i < len; i++) { if (a[i] != b[i]) return 0; }
	return 1;
}
Q3(){
	int a[] = { 1,2,3,0,0,0,0,0,0,0 };
	int b[] = { 0,0,0,0,0,0,0,0,0,0 };
	printf("2개의 배열은 %s\n", array_equal(a, b, 10) ? "같음" : "다름");
}
void array_copy(int a[], int b[], int len) {
	for (int i = 0; i < len; i++) b[i] = a[i];
}
void printArray(int a[], int len) {
	for (int i = 0; i < len; i++) { printf("%d ", a[i]); } puts("");
}
Q4(){
	int a[] = { 1,2,3,0,0,0,0,0,0,0 };
	int b[] = { 0,0,0,0,0,0,0,0,0,0 };
	array_copy(a, b, 10);
	printArray(a, 10), printArray(b, 10);
}
int getMaxIndex(int* arr, int len) {
	int j = 0, res = arr[0];
	for (int i = 1; i < len; i++) { if (res < arr[i]) res = arr[i], j = i; }
	return j;
}
Q5(){
	int count[10] = { 0, };
	for (int i = 0; i < 100; i++) count[rand() % 10]++;
	printf("가장 많이 나온 수 = %d\n", getMaxIndex(count, 10));
}
Q6(){
	int arr[3][5] = {
		12,56,32,16,98,
		99,56,34,41, 3,
		65, 3,87,78,21 };
	for (int row = 0; row < 3; row++) {
		int sum = 0;
		for (int col = 0; col < 5; col++) { sum += arr[row][col]; }
		printf("%d행의 합계: %d\n", row, sum);
	}
	for (int col = 0; col < 5; col++) {
		int sum = 0;
		for (int row = 0; row < 3; row++) { sum += arr[row][col]; }
		printf("%d열의 합계: %d\n", col, sum);
	}
}
Q7(){
	int arr[10][3]; // [x][0] = 정수, [x][1] = 제곱, [x][0] = 세제곱
	for (int i = 1; i <= 10; i++) {
		arr[i - 1][0] = i;
		arr[i - 1][1] = i * i;
		arr[i - 1][2] = i * i * i;
	}
	int input; printf("정수를 입력하시오:"); scanf_s(" %d", &input);
	int j = 0;
	for (int i = 1; i < 10; i++) {
		if (arr[i][2] <= input) j = i + 1;
	}
	printf("%d의 세제곱근은 %d\n", input, j);
}
double getMean(double data[], int len) {
	double sum = 0;
	for (int i = 0; i < len; i++) sum += data[i];
	return sum / len;
}
double getStdDev(double data[], int len) {
	double sum = 0, mean = getMean(data, len);
	for (int i = 0; i < len; i++) {
		sum += (data[i] - mean) * (data[i] - mean);
	}
	return sqrt(sum / len);
}
Q8(){
	double data[10]/* = {10,20,30,40,50,60,70,80,90,100}*/;
	for (int i = 0; i < 10; i++)data[i] = (double)rand();
	int len = sizeof(data) / sizeof(double);
	printf("평균값은 %lf\n표준편차값은 %lf\n", getMean(data, len), getStdDev(data, len));
}
Q9(){
	int data[5][4] =
	{
		1,30,10,11,
		2,40,90,32,
		3,70,65,56,
		4,70,43,32,
		5,80,10,89
	};
	for (int i = 0; i < 5; i++) {
		for (int j = 1; j <= 3; j++) {
			data[i][j] = rand() % 101;
		}
	}

	int minMax[3][2] =
	{
		30,30,
		10,10,
		11,11
	};
	for (int i = 0; i < 3; i++) {
		minMax[i][0] = minMax[i][1] = data[0][i + 1];
	}

	for (int i = 1; i < 5; i++) {
		for (int j = 1; j <= 3; j++) {
			if (data[i][j] < minMax[j - 1][0]) minMax[j - 1][0] = data[i][j];
			else if (minMax[j - 1][1] < data[i][j]) minMax[j - 1][1] = data[i][j];
		}
	}
	for (int j = 0; j < 3; j++) {
		printf("시험 #%d의 최대점수=%d\n", j + 1, minMax[j][1]);
		printf("시험 #%d의 최저점수=%d\n", j + 1, minMax[j][0]);
	}
	
}
void vector_add(double x[], double y[], double z[]) {
	for (int i = 0; i < 3; i++) { z[i] = x[i] + y[i]; }
}
double vector_dot_prod(double x[], double y[]) {
	double res = 0;
	for (int i = 0; i < 3; i++) { res += x[i] * y[i]; }
	return res;
}
Q10(){
	double v1[3] = { 1,2,3 };
	double v2[3] = { 1,2,3 };
	double v3[3];
	vector_add(v1, v2, v3);
	printf("벡터의 합 = [ %lf %lf %lf ]\n", v3[0], v3[1], v3[2]);
	printf("벡터의 내적 = %lf\n", vector_dot_prod(v1, v2));
}
Q11(){
	int location[11] = { 0,1,2,3,4,5,1,2,3,4,5 };
	int input; printf("상품 번호를 입력하시오:"); scanf_s(" %d", &input);
	printf("상품 번호 %d의 위치는 %d입니다.\n", input, location[input]);
}
void printMatrix(int a[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) printf("%2d ", a[i][j]);
		puts("");
	}
}
void scalar_mult(int a[][3], int scalar) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			a[i][j] *= scalar;
}
void transpose(int a[][3], int b[][3]) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			b[i][j] = a[j][i];
}
Q12(){
	int data[3][3] =
	{
		1,2,3,
		4,5,6,
		7,8,9
	}; printMatrix(data);

	scalar_mult(data, 2); printMatrix(data);
	int trans[3][3]; transpose(data, trans); printMatrix(trans);
	
}
Q13(){
	int binary[32] = {0,}, n = 32, i;
	for (i = 0; i < 32 && n>0; i++) {
		binary[i] = n % 2;
		n /= 2;
	}
	printf("%d->", n); for (int j = i - 1; j >= 0; --j) printf("%d", binary[j]); puts("");
}
void printMap(int map[][16], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			printf("%s ", (map[i][j] >= 1) ? "* " : ". ");
		puts("");
	}
}
void applyMove(int* curRow, int* curCol, int next) {
	// 0 <= next < 8
	switch (next)
	{
	case 1:	case 2: case 3: (*curCol)++; break;
	case 5:	case 6: case 7: (*curCol)--; break;
	default: break;
	}
	switch (next)
	{
	case 7:	case 0: case 1: (*curRow)++; break;
	case 3:	case 4: case 5: (*curRow)--; break;
	default: break;
	}
}
Q14(){
	int tile[16][16] = { 0, };
	int row = 16, col = 16;
	int curRow = row / 2, curCol = col / 2;
	//printMap(tile, row, col);
	while (1) {
		system("cls"); Sleep(1);
		printMap(tile, row, col);
		if (curRow < 0 || row <= curRow) break;
		if (curCol < 0 || col <= curCol) break;
		tile[curRow][curCol] = 1;
		applyMove(&curRow, &curCol, rand() % 8);
	}
}
void printMap2(int map[][10], int row, int col, int std) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			printf("%s ", (map[i][j] <= std) ? "# " : ". ");
		puts("");
	}
}
Q15(){
	int tile[10][10] = { 0, };
	int row = 10, col = 10;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			tile[i][j] = rand() % 100;
	}

	printMap2(tile, row, col, 30);
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
	//Q13();
	//Q14();
	//Q15();
}