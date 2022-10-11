#include "calculator.h"

STACK* NUM = NULL;
STACK* OP = NULL;

// �� ������ �����ϴ� �Լ����� �ڽ��� ȣ��� Ƚ���� ȭ�鿡 ����Ѵ�.
void printCount(const char* name, const int count) {
	assert(name != NULL);
	if (count > 0) printf("%s�� �� %d�� ����Ǿ����ϴ�.\n", name, count);
}
int add_(const element a, const element b) { static int count; printCount("����", ++count); return a + b; }
int sub_(const element a, const element b) { static int count; printCount("����", ++count); return a - b; }
int mul_(const element a, const element b) { static int count; printCount("����", ++count); return a * b; }
int div_(const element a, const element b) { static int count; printCount("������", ++count); return a / b; }

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
	
	push(NUM, atoi(str)); // ���� ���� push
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
				// ������ OP�� ���� OP���� �켱������ ���� ���
				if ((topOP == '+' || topOP == '-')
					&& (c == '*' || c == '/')) push(OP, c);
				else {
					push(NUM, callOperator(pop(OP)));
					push(OP, c);
				}
			}
			// ������ ���� ���� push
			p = i + 1; push(NUM, atoi(str + p));
			break;
		// non-operator
		default: break;
		}
	}
	while (!isEmpty(OP)) push(NUM, callOperator(pop(OP)));
	return pop(NUM);
}