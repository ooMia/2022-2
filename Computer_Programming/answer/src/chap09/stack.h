#ifndef STACK_H
#define STACK_H
#include <stdio.h>	// printf
#include <malloc.h> // malloc, free
#include <string.h> // memset
#include <assert.h> // assert

typedef int element;
typedef struct simpleStack {
	int maxLength;
	int sp;
	element* data;
} STACK;

STACK* createStack(int);
void deleteStack(STACK*);

int isFull(STACK*);
int isEmpty(STACK*);
void printStack(STACK*);

void push(STACK*, const element);
element pop(STACK*);
element top(STACK*);

#endif // !STACK_H
