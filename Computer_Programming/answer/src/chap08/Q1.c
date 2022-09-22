#include <stdio.h>
#include <corecrt_math_defines.h> // M_PI
#include <assert.h>

inline double square(double num) {
	return num * num;
}
void Q1() {
	double input;
	printf("정수를 입력하시오: "), scanf_s(" %lf", &input);
	printf("주어진 정수 %lf의 제곱은 %lf입니다.", input, square(input));
}


inline int check_alpha(char c) {
	return ('a' <= c && c <= 'z')
		|| ('A' <= c && c <= 'Z');
}
void Q2() {
	char input;
	printf("문자를 입력하시오: "), scanf_s(" %c", &input, 1);
	printf("%c는 알파벳 문자%s.", input, check_alpha(input) ? "입니다" : "가 아닙니다");
}


inline double cal_area(double radius) {
	return M_PI * radius * radius;
}
void Q3() {
	double input;
	printf("원의 반지름을 입력하시오: "), scanf_s(" %lf", &input);
	printf("원의 면적은 %lf입니다.", cal_area(input));
}


inline int is_leap(int year) {
	return (year % 400 == 0)
		|| (year % 100 != 0 && year % 4 == 0);
}
void Q4() {
	int input;
	printf("연도를 입력하시오: "), scanf_s(" %d", &input);
	printf("%d년은 %d일입니다.", input, is_leap(input) ? 366 : 365);
}


int round(double f) {
	assert(f > 0);
	return (int)(f + 0.5);
}
void Q5() {
	double input;
	printf("실수를 입력하시오: "), scanf_s(" %lf", &input);
	printf("반올림한 값은 %d입니다.", round(input));
}










int main(int argc, char* argv[])
{
	//Q1();
	//Q2();
	//Q3();
	//Q4();
	Q5();
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