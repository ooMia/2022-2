//// 7-1
//#include <stdio.h>
//#include <Windows.h> //Sleep, Beep
//
//int main()
//{
//	int time;
//	printf("카운터의 초기값을 입력하시오: "); scanf_s(" %d", &time);
//
//	for (; time > 0; --time) {
//		printf("%d ", time), Sleep(1000);
//	}
//	Beep(350, 600);
//
//	return 0;
//}
//
//
//// 7-2
//#include <stdio.h>
//
//int main()
//{
//	int from = 1, to = 100, div = 3, result;
//
//	result = 0;
//	for (int i = from; i <= to; ++i) {
//		if (i % div == 0) result += i;
//		// OR result += (i % div == 0) ? i : 0;
//	}
//	printf("%d부터 %d 사이의 모든 %d의 배수의 합은 %d입니다.\n", from, to, div, result);
//	return 0;
//}
//
//// 7-3
//#include <stdio.h>
//
//int main()
//{
//	int num;
//	printf("정수를 입력하시오: "); scanf_s(" %d", &num);
//
//	printf("약수: ");
//	for (int i = 1; i <= num; ++i) {
//		if (num % i == 0) { printf("%d ", i); }
//	}
//	return 0;
//}
//
//
//// 7-4
//#include <stdio.h>
//
//int main()
//{
//	int nLines = 7;
//
//	for (int row = 1; row <= nLines; ++row) {
//		for (int space = nLines - row; space > 0; --space) { printf(" "); }
//		for (int star = 1; star <= row; ++star) { printf("*"); }
//		puts("");
//	}
//	return 0;
//}
//
//
//// 7-5
//#include <stdio.h>
//
//int main()
//{
//	int num;
//	printf("정수를 입력하시오: "); scanf_s(" %d", &num);
//
//	for (int row = 1; row <= num; ++row) {
//		for (int i = 1; i <= row; ++i) printf("%d ", i);
//		puts("");
//	}
//	return 0;
//}
//
//
//// 7-6
//#include <stdio.h>
//#include <stdlib.h> // exit
//
//int calc(char op) {
//	int n1, n2;
//	printf("두 수를 공백으로 분리하여 입력하시오: ");
//	scanf_s(" %d %d", &n1, &n2);
//	switch (op)
//	{
//	case 'A': return n1 + n2;
//	case 'S': return n1 - n2;
//	case 'M': return n1 * n2;
//	case 'D': return n1 / n2;
//	default: printf("undefined operator\n"); exit(-1);
//	}
//}
//
//int main()
//{
//	puts("*****************");
//	puts("A---- Add");
//	puts("S---- Subtract");
//	puts("M---- Multiply");
//	puts("D---- Devide");
//	puts("Q---- Quit");
//	puts("*****************");
//
//	char op = 0;
//	do {
//		printf("연산을 선택하시오:");
//		scanf_s(" %c", &op, 1);
//
//		switch (op)
//		{
//		case 'A':case 'S':case 'M':case 'D':
//			printf("%d\n", calc(op));
//		}
//
//		if (op == 'Q') break;
//	} while (1);
//
//	return 0;
//}
//
//
//// 7-7
//#include <stdio.h>
//#define FROM (2)
//#define TO (100)
//
//int main()
//{
//	int isPrime = 1;
//
//	for (int num = FROM; num <= TO; ++num) {
//
//		for (int n = 2; n < num; ++n) {
//			if (num % n == 0) { isPrime = 0; break; }
//		}
//
//		if (isPrime) printf("%d ", num);
//		else isPrime = 1;
//	}
//
//	return 0;
//}
//
//
//// 7-8
//#include <stdio.h>
//
//int main()
//{
//	int num;
//
//	while (1) {
//		printf("막대의 높이(종료: -1): "); scanf_s(" %d", &num);
//		if (num == -1) break;
//		else if (1 <= num && num <= 50) {
//			for (int i = 0; i < num; ++i) printf("*");
//			puts("");
//		}
//	}
//
//	return 0;
//}
//
//
//// 7-9
//#include <stdio.h>
//
//int main()
//{
//	int limit = 10000, sum, i;
//	sum = i = 0;
//
//	while (1) {
//		if (sum > limit) break;
//		else {
//			i += 1;
//			sum += i;
//		}
//	} sum -= i; i -= 1;
//
//	printf("1부터 %d까지의 합이 %d입니다.\n", i, sum);
//	return 0;
//}
//
//
//// 7-10
//#include <stdio.h>
//
//int main()
//{
//	double num;	printf("실수의 값을 입력하시오: ");	scanf_s(" %lf", &num);
//	int iter;	printf("거듭제곱횟수를 입력하시오: ");	scanf_s(" %d", &iter);
//
//	double result = 1;
//	for (int i = iter; i > 0; --i) result *= num;
//	printf("결과값은 %lf\n", result);
//
//	return 0;
//}
//
//
//// 7-11
//#include <stdio.h>
//
//int main()
//{
//	int num;
//	printf("n의 값을 입력하시오: "); scanf_s(" %d", &num);
//
//	int result = 0;
//	for (int n = num; n > 0; --n) result += n * n;
//	printf("계산값은 %d입니다.\n", result);
//
//	return 0;
//}
//
//
//// 7-12
//#include <stdio.h>
//
//int main()
//{
//	int num;
//	printf("몇번째 항까지 구할까요? "); scanf_s(" %d", &num);
//
//	int a = 0, b = 1, c = a + b;
//	if (num >= 0) printf("%d", a);
//	if (num >= 1) printf(", %d", b);
//	for (int i = 2; i <= num; ++i) {
//		printf(", %d", c);
//		a = b, b = c, c = a + b;
//	}
//	return 0;
//}
//
//
//// 7-13
//#include <stdio.h>
//
//int main()
//{
//	int n, r, nPr = 1;
//	printf("n의 값:\t"); scanf_s(" %d", &n);
//	printf("r의 값:\t"); scanf_s(" %d", &r);
//
//	for (int i = n; i >= (n - r + 1); --i) { nPr *= i; }
//	printf("순열의 값은 %d입니다.\n", nPr);
//
//	return 0;
//}
//
//
//// 7-14
//#include <stdio.h>
//
//int main()
//{
//	int num;
//	printf("정수를 입력하시오: "); scanf_s(" %d", &num);
//
//	do {
//		printf("%d", num % 10);
//	} while ((num /= 10) != 0);
//
//	return 0;
//}