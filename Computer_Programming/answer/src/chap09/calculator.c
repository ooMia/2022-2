#include "calculator.h"

STACK* NUM = NULL;
STACK* OP = NULL;

// 각 연산을 지원하는 함수들은 자신이 호출된 횟수를 화면에 출력한다.
void printCount(const char* name, const int count) {
	assert(name != NULL);
	if (count > 0) printf("%s은 총 %d번 실행되었습니다.\n", name, count);
}
int add_(const element a, const element b) { static int count; printCount("덧셈", ++count); return a + b; }
int sub_(const element a, const element b) { static int count; printCount("뺄셈", ++count); return a - b; }
int mul_(const element a, const element b) { static int count; printCount("곱셈", ++count); return a * b; }
int div_(const element a, const element b) { static int count; printCount("나눗셈", ++count); return a / b; }

int callOperator(const char op) {
	switch (op)
	{
	case '+': return add_(pop(NUM), pop(NUM)); break;
	case '-': return sub_(pop(NUM), pop(NUM)); break;
	case '*': return mul_(pop(NUM), pop(NUM)); break;
	case '/': return div_(pop(NUM), pop(NUM)); break;
	default: exit(-23);
	}
}

int calculator(char* str) {
	int maxLength = 512;
	NUM = createStack(maxLength);
	OP = createStack(maxLength);
	assert(NUM != NULL && OP != NULL);
	
	push(NUM, atoi(str)); // 최초 숫자 push
	int i, p, len = (int)strlen(str);
	for (i = p = 0; i < len; i++)
	{
		char c = str[i];
		switch (c)
		{
		// operator
		case '+': case '-': case '*': case '/':
			if (isEmpty(OP)) push(OP, c);
			else {
				char topOP = top(OP);
				// 스택의 OP가 현재 OP보다 우선순위가 낮은 경우
				if ((topOP == '+' || topOP == '-')
					&& (c == '*' || c == '/')) push(OP, c);
				else {
					push(NUM, callOperator(pop(OP)));
					push(OP, c);
				}
			}
			// 연산자 뒤의 숫자 push
			p = i + 1; push(NUM, atoi(str + p));
			break;
		// non-operator
		default: break;
		}
	}
	while (!isEmpty(OP)) push(NUM, callOperator(pop(OP)));
	return pop(NUM);
}