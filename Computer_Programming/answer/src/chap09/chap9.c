#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <time.h>	// time

#include "calculator.h"
void Q1() {
	char exp[512] = { 0, };
	printf("������ �Է��Ͻÿ�: "); scanf_s(" %s", exp, 512);
	printf("���� ���: %d\n", calculator(exp));
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
	static unsigned totalTrials; // ���� ���� ������ �õ� Ƚ���� �����Ѵ�.
	int input, savedPW = 1234; // ��й�ȣ�� ���� 1234�� ����
	printf("��й�ȣ: "); scanf_s(" %d", &input); // ȣ�⸶�� ��й�ȣ�� �����ϰ�
	int res = (savedPW == input); // ��ġ ���θ� 1(True)�� 0(False)�� ��ȯ
	if (++totalTrials >= 3 && res == 0) puts("�α��� �õ�Ƚ�� �ʰ�"), exit(-1);
	return res;
}
void Q3() {
	// �� ������ ���� �α��� ��ɰ��� �Ÿ��� ������ �ִ��� ���ǿ� �����ϵ��� ������
	while (!check());
}


int get_random() {
	static unsigned inited;
	if (inited == 0) {
		puts("�ʱ�ȭ ����");
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
	printf("������ �Է��Ͻÿ�: "); scanf_s(" %d", &num);
	printf("1���� %d������ ��=%d\n", num, sum(num));
}

int power(int base, int power_raised) {
	if (base == 0) return 0;
	else if (power_raised == 0) return 1;
	else return base * power(base, power_raised - 1);
}
void Q6() {
	int base, exp;
	printf("�ؼ�: "); scanf_s(" %d", &base);
	printf("����: "); scanf_s(" %d", &exp);
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
	printf("������ �Է��Ͻÿ�: "); scanf_s(" %d", &num);
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
	printf("������ �Է��Ͻÿ�: "); scanf_s(" %d", &num);
	printf("�ڸ����� ����: %d\n", n_digit(num));
}



int get_digit_sum(int n) {
	if (n <= 0) return 0;
	else return n % 10 + get_digit_sum(n / 10);
}
void Q9() {
	int num;
	printf("������ �Է��Ͻÿ�: "); scanf_s(" %d", &num);
	printf("�ڸ����� ��: %d\n", get_digit_sum(num));
}

// ��ȭ�޼�: Integral(1/x) = ln|x| (x > 1, diverge)
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

	//Q1(); // 1�� ���: ���� ���� ������ Ȱ���� ����
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