#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "minilibmx.h"

typedef struct s_operation
{
  char op;
  int (*f)(int a, int b);
} t_operation;

enum e_operation
{
	UNKNOWN,
	ADD,
	SUB,
	MUL,
	DIV
};

enum e_objects
{
	OPERAND,
	OPERATION,
	RESULT
};

enum e_error
{
	INVALID_OPERAND,
	INVALID_OPERATION,
	INVALID_RESULT,
	INVALID_COUNT
};
#endif

