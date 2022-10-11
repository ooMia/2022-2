#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <time.h>	// time

#include "calculator.h"
void Q1() {
	char exp[512] = { 0, };
	printf("연산을 입력하시오: "); scanf_s(" %s", exp, 512);
	printf("연산 결과: %d\n", calculator(exp));
}

int get_dice_face(unsigned callLimit) {
	static unsigned called[7], totalCall;

	int res = rand() % 6 + 1;
	called[res] += 1, totalCall++;

	if (totalCall >= callLimit)
		for (int i = 1; i <= 6; ++i)
			printf("%d->%d\n", i, called[i]);

	return res;
}
void Q2() {
	unsigned limit = 100;
	for (; limit > 0; limit--) get_dice_face(limit);
}


int check() {
	static unsigned totalTrials; // 정적 지역 변수에 시도 횟수를 저장한다.
	int input, savedPW = 1234; // 비밀번호는 숫자 1234로 고정
	printf("비밀번호: "); scanf_s(" %d", &input); // 호출마다 비밀번호를 질문하고
	int res = (savedPW == input); // 일치 여부를 1(True)과 0(False)로 반환
	if (++totalTrials >= 3 && res == 0) puts("로그인 시도횟수 초과"), exit(-1);
	return res;
}
void Q3() {
	// 본 문제는 실제 로그인 기능과는 거리가 있으나 최대한 조건에 부합하도록 구현함
	while (!check());
}


int get_random() {
	static unsigned inited;
	if (inited == 0) {
		puts("초기화 실행");
		srand((unsigned)time(NULL));
		inited = 1;
	}
	return rand();
}
void Q4() {
	for (int i = 0; i < 3; ++i) printf("%d\n", get_random());
}

int sum(int n) {
	if (n <= 1) return n;
	else return n + sum(n - 1);
}
void Q5() {
	int num;
	printf("정수를 입력하시오: "); scanf_s(" %d", &num);
	printf("1부터 %d까지의 합=%d\n", num, sum(num));
}

int power(int base, int power_raised) {
	if (base == 0) return 0;
	else if (power_raised == 0) return 1;
	else return base * power(base, power_raised - 1);
}
void Q6() {
	int base, exp;
	printf("밑수: "); scanf_s(" %d", &base);
	printf("지수: "); scanf_s(" %d", &exp);
	printf("%d^%d = %d\n", base, exp, power(base, exp));
}



void show_digit(int x) {
	if (x > 0) {
		show_digit(x / 10);
		printf("%d ", x % 10);
	}
}
void Q7() {
	int num;
	printf("정수를 입력하시오: "); scanf_s(" %d", &num);
	show_digit(num);
}



// (input, result) = { (0,1), (1,1), (10,2), (11,2), ... }
int n_digit(int x) {
	static unsigned called;
	if (called == 0 && x == 0) return 1;
	else if (x != 0) n_digit(x / 10);
	return ++called;
}
void Q8() {
	int num;
	printf("정수를 입력하시오: "); scanf_s(" %d", &num);
	printf("자리수의 개수: %d\n", n_digit(num));
}



int get_digit_sum(int n) {
	if (n <= 0) return 0;
	else return n % 10 + get_digit_sum(n / 10);
}
void Q9() {
	int num;
	printf("정수를 입력하시오: "); scanf_s(" %d", &num);
	printf("자리수의 합: %d\n", get_digit_sum(num));
}

// 조화급수: Integral(1/x) = ln|x| (x > 1, diverge)
double harmonic_series(int n) {
	assert(n > 0);
	if (n == 1) return 1.;
	else return 1. / n + harmonic_series(n - 1);
}
void Q10() {
	printf("recursive(10): %lf\n", harmonic_series(10));
}



int binomial_coef(int n, int k) {
	if (k == 0 || k == n) return 1;
	else if (0 < k && k < n)
		return binomial_coef(n - 1, k - 1) + binomial_coef(n - 1, k);
	else exit(-135);
}
void Q11() {
	int n, k;
	printf("n="); scanf_s(" %d", &n);
	printf("k="); scanf_s(" %d", &k);
	printf("%d\n", binomial_coef(n, k));
}

int fibo_sequence(int n) {
	assert(n >= 0);
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibo_sequence(n - 2) + fibo_sequence(n - 1);
}
void Q12() {
	for (int i = 0; i <= 9; ++i)
		printf("fib(%d) = %d\n", i, fibo_sequence(i));
}





int main(int argc, char* argv[])
{
	srand((unsigned)time(NULL));

	//Q1(); // 1번 방법: 정적 지역 변수를 활용한 구현
	//Q2();
	//Q3();
	//Q4();
	//Q5();
	//Q6();
	//Q8();
	//Q9();
	//Q10();
	//Q11();
	Q12();

	return 0;
}