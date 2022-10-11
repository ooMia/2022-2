#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <stdio.h>	// printf
#include <ctype.h>	// atoi
#include <assert.h> // assert
#include <stdlib.h> // exit
#include "stack.h"

void printCount(const char* name, const int count);
int add_(const element a, const element b);
int sub_(const element a, const element b);
int mul_(const element a, const element b);
int div_(const element a, const element b);
int callOperator(const char op);

int calculator(char* str);

#endif // !CALCULATOR_H
