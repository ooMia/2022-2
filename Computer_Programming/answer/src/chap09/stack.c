#include "stack.h"

void deleteStack(STACK* s) { free(s->data); free(s); }
STACK* createStack(int len)
{
	assert(len > 0);
	STACK* res = (STACK*)malloc(sizeof(STACK));
	assert(res != NULL);
	res->maxLength = len;
	res->sp = -1;
	res->data = (element*)malloc(sizeof(element) * len);
	assert(res->data != NULL);
	memset(res->data, -1, sizeof(element) * len);
	return res;
}

int isFull(STACK* s) { return s->sp >= (s->maxLength - 1); }
int isEmpty(STACK* s) { return s->sp <= -1; }
void printStack(STACK* s) {
	printf("top << ");
	for (int i = s->sp; i >= 0; --i) {
		printf("%d ", s->data[s->sp]);
	} puts("");
}

void push(STACK* s, const element e) { if (!isFull(s)) s->data[++(s->sp)] = e; }
element pop(STACK* s) {
	if (!isEmpty(s)) return s->data[(s->sp)--];
	else return -1;
}
element top(STACK* s) {
	if (!isEmpty(s)) return s->data[s->sp];
	else return -1;
}