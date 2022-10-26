#include <stdio.h>
#define _USE_MATH_DEFINES // M_PI
#include <math.h> // sin
#include <assert.h>
#include <stdlib.h> // rand srand 
#include <time.h> // time

double square(double num) { return num * num; }
void Q1() {
	double input;
	printf("정수를 입력하시오: "), scanf_s(" %lf", &input);
	printf("주어진 정수 %lf의 제곱은 %lf입니다.", input, square(input));
}


int check_alpha(char c) {
	return ('a' <= c && c <= 'z')
		|| ('A' <= c && c <= 'Z');
}
void Q2() {
	char input;
	printf("문자를 입력하시오: "), scanf_s(" %c", &input, 1);
	printf("%c는 알파벳 문자%s.", input, check_alpha(input) ? "입니다" : "가 아닙니다");
}


double cal_area(double radius) {
	assert(radius > 0);
	return M_PI * radius * radius;
}
void Q3() {
	double input;
	printf("원의 반지름을 입력하시오: "), scanf_s(" %lf", &input);
	printf("원의 면적은 %lf입니다.", cal_area(input));
}


int is_leap(int year) {
	return (year % 400 == 0)
		|| (year % 100 != 0 && year % 4 == 0);
}
void Q4() {
	int input;
	printf("연도를 입력하시오: "), scanf_s(" %d", &input);
	printf("%d년은 %d일입니다.", input, is_leap(input) ? 366 : 365);
}

// include <math.h>한 상태에서 함수명을 round로 사용하면
// 의도치 않은 함수 재정의로 오류 발생 
int _round(double f) {
	assert(f > 0);
	return (int)(f + 0.5);
}
void Q5() {
	double input;
	printf("실수를 입력하시오: "), scanf_s(" %lf", &input);
	printf("반올림한 값은 %d입니다.", _round(input));
}

int even(int n) { return (n % 2 == 0); }
int absolute(int n) {
	return n * (n < 0 ? -1 : +1); // OR return n * sign(n);
}
int sign(int n) {
	return n < 0 ? -1
		: n > 0 ? +1
		: 0;
}
void Q6() {
	int input;
	printf("정수를 입력하시오:"), scanf_s(" %d", &input);
	printf("even()의 결과: %s\n", even(input) ? "짝수" : "홀수");
	printf("absolute()의 결과: %d\n", absolute(input));
	printf("sign()의 결과: %s\n", input == 0 ? "0" : sign(input) > 0 ? "양수" : "음수");
}


int get_tax(int income) {
	double res = 0.08;
	if (income < 1000) res *= income;
	else {
		res *= 1000., income -= 1000;
		res += income * 0.1;
	}
	return (int)res;
}
void Q7() {
	int input;
	printf("소득을 입력하시오(만원):"), scanf_s(" %d", &input);
	printf("소득세는 %d입니다.", get_tax(input));
}



double sin_degree(double degree) {
	double radian = M_PI * degree / 180.;
	return sin(radian);
}
void Q8() {
	double input;
	printf("각도를 입력하세요: "), scanf_s(" %lf", &input);
	printf("sin(%lf)의 값은 %lf", input, sin_degree(input));
}


// srand는 main 함수에서 한 번만 호출
int b_rand() { return rand() % 2; }
void Q9() {
	for (int i = 5; i > 0; --i)
		printf("%d ", b_rand());
}


void Q10() {

	double user;
	char iter;
	do {

		do {
			printf("앞면(1) 또는 뒷면(0): "); scanf_s(" %lf", &user);
		} while (user != 1 && user != 0);
		printf("%s\n", b_rand() == (int)user ? "맞았습니다" : "틀렸습니다");

		while (1) {
			printf("계속하시겠습니까?(y 또는 n) "), scanf_s(" %c", &iter, 1);
			if (iter == 'y' || iter == 'n') break;
		}

	} while (iter == 'y');
}



// srand는 main 함수에서 한 번만 호출
double f_rand() { return rand() / (double)RAND_MAX; }
void Q11() {
	for (int i = 5; i > 0; --i)
		printf("%lf ", f_rand());
}

// Q7-8
void print_value(int n) {
	for (int i = 0; i < n; ++i) { printf("*"); }
	puts("");
}
void Q12() {
	while (1) {
		int i;
		printf("값을 입력하시오(종료는 음수): "); scanf_s(" %d", &i);
		if (i < 0) break;
		else print_value(i);
	}
}


int is_multiple(int n, int m) {
	return !(n % m);
}
void Q13() {
	int n, m;
	printf("첫번째 정수를 입력하시오:"); scanf_s(" %d", &n);
	printf("두번째 정수를 입력하시오:"); scanf_s(" %d", &m);
	printf("%d는 %d의 배수%s\n", n, m, is_multiple(n, m) ? "입니다." : "가 아닙니다.");
}



double get_distance(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
void Q14() {
	double x1, y1, x2, y2;
	printf("첫번째 점의 좌표를 입력하시오(x1 ,y1): "); scanf_s(" %lf %lf", &x1, &y1);
	printf("첫번째 점의 좌표를 입력하시오(x2 ,y2): "); scanf_s(" %lf %lf", &x2, &y2);
	printf("두 점 사이의 거리는 %lf입니다.", get_distance(x1, y1, x2, y2));
}

// Q7-7
int is_prime(int num) {
	for (int i = 2; i * i <= num; ++i) {
		if (num % i == 0) return 0;
	}
	return 1;
}
void Q15() {
	for (int i = 2; i <= 100; ++i)
		if (is_prime(i)) printf("%d ", i);
}

// 교재 332p
// result 변수 자료형: long > unsigned long long으로 변환
typedef unsigned long long ull;
ull factorial(int num) {
	ull result = 1;
	for (int i = 1; i <= num; i++)
		result *= i; // result = result * i
	return result;
}
void Q16() {
	int num;
	printf("어디까지 계산할까요: "), scanf_s(" %d", &num);

	double result = 0;
	for (int i = 0; i <= num; ++i) { result += 1. / (double)factorial(i); }
	printf("오일러 수는 %lf입니다.", result);
}


double f_abs(double x) { return x * (x < 0 ? -1 : +1); }
double f_min(double x, double y) { return x < y ? x : y; }
int f_equal(double a, double b) {
	double e = 0.000001;
	return f_abs(a - b) < e * f_min(f_abs(a), f_abs(b));
}
void Q17() {
	double a, b;
	printf("실수를 입력하시오: "), scanf_s(" %lf", &a);
	printf("실수를 입력하시오: "), scanf_s(" %lf", &b);
	printf("두 개의 실수는 서로 %s", f_equal(a, b) ? "같음" : "다름");
}




// div 함수 재정의 방지
inline int _add(int a, int b) { return a + b; }
inline int _sub(int a, int b) { return a - b; }
inline int _mul(int a, int b) { return a * b; }
inline int _div(int a, int b) { return a / b; }
inline int _mod(int a, int b) { return a % b; }

void menu_intro() {
	puts("===================\nMENU\n===================");
}
int menu_contents() {
	char menu[][64] = { "", "덧셈", "뺄셈", "곱셈", "나눗셈", "나머지" };
	int nMenu = (sizeof(menu) / 64) - 1;
	for (int i = 1; i <= nMenu; ++i) printf("%i. %s\n", i, menu[i]);
	return nMenu;
}
int menu() {
	menu_intro();
	int nContents = menu_contents();
	
	int n;
	do {
		printf("원하는 메뉴를 선택하시오(1-%d):",nContents);
		scanf_s(" %d", &n);
	} while (n < 1 || nContents < n);
	return n;
}

int calc(int nMenu) { 
	int a, b;
	printf("정수 2개를 입력하시오: "); scanf_s(" %d %d", &a, &b);

	switch (nMenu)
	{
	case 1: return _add(a, b);
	case 2: return _sub(a, b);
	case 3: return _mul(a, b);
	case 4: return _div(a, b);
	case 5: return _mod(a, b);
	default: exit(INT_MIN);
	}
}

void Q18() {
	printf("연산결과: %d", calc(menu()));
}


int main(int argc, char* argv[])
{
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
	//Q16();
	//Q17();
	//Q18();

	return 0;
}