#include "calculator.h"
void mx_out_err(int code) {
	if (code == INCORRECT_OPERAND) 
		mx_printerr("error: invalid number\n");
	else if (code == INCORRECT_OPERATION)
		mx_printerr("error: invalid operation\n");
	else if (code == DIV_BY_ZERO)
		mx_printerr("error: division by zero\n");
}

void mx_print_res(struct s_operation * ops, char op, int a, int b) {
	for (int i = SUB; i <= MOD; i++)
		if (ops[i].op == op){
			if ((op == '/' || op == '%') 
					&& !b)
					{
						 mx_out_err(DIV_BY_ZERO);
						 return;
					}
			else mx_printint(ops[i].f(a, b));
			mx_printchar('\n');
			return;
		}
	mx_out_err(INCORRECT_OPERATION);
}

int main(int argc, char * argv[])
{
	if (argc != 4){
		mx_printerr("usage: ");
		mx_printerr("./calc");
		mx_printerr(" [operand1] [operation] [operand2]\n");
		return 0;
	}
	int err1 = 0;
	int err2 = 0;
	int num1 = mx_atoi(argv[1], &err1);
	int num2 = mx_atoi(argv[3], &err2);
	struct s_operation optns[] = {{'-', mx_sub}, {'+', mx_add}, 
					{'*', mx_mul}, {'/', mx_div}, {'%', mx_mod}};
	if (err1 
		|| err2){
		mx_out_err(INCORRECT_OPERAND);
		return 0;
	}
	mx_print_res(optns, argv[2][0], num1, num2);
	return 0;
}


