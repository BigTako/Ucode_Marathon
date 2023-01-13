#include "encryptor.h"


void mx_get_combinations(char * n1, char * n2, char * res, t_operation * op) { // get combiations of digits in numbers including which equation will be true
	int n1_overflow = 0;
	int n2_overflow = 0;
	int res_overflow = 0;
	char * num1 = mx_get_init_num(n1);
	char * num2 = mx_get_init_num(n2);
	char * res_str = mx_get_init_num(res);
	int num1_int;
	int num2_int;
	int res_int;
	while (!n1_overflow){
		num1_int = mx_atoi(num1);
		while (!n2_overflow) {
			num2_int = mx_atoi(num2);
			while (!res_overflow){	
				res_int = mx_atoi(res_str);
				if (op->op == '/' && num2_int == 0) num2_int = 0;	
				else
					if (op->f(num1_int, num2_int) == res_int) 
						mx_print_comb(num1, num2, res_str, op->op);
				mx_add_one(res_str, res, mx_strlen(res) - 1, &res_overflow);
			}
			res_str = mx_reinit_str(res_str, res, &res_overflow);	
			mx_add_one(num2, n2, mx_strlen(n2) - 1, &n2_overflow);
		}
		num2 = mx_reinit_str(num2, n2, &n2_overflow);					
		mx_add_one(num1, n1, mx_strlen(n1) - 1, &n1_overflow);	
	}
	mx_strdel(&num1);
	mx_strdel(&num2);
	mx_strdel(&res_str); 
}


int main(int argc, char * argv[])
{
	if (argc != 5) mx_out_err(INVALID_COUNT, 0, 0);
	char operation = mx_valid_obj(argv[2], OPERATION)[0];
	char * num1 = mx_valid_obj(argv[1], OPERAND);
	char * num2 = mx_valid_obj(argv[3], OPERAND);
	char * res = mx_valid_obj(argv[4], RESULT);
	t_operation optns[] = {{'?', 0},{'+', mx_add} , {'-', mx_sub}, {'*', mx_mul}, {'/', mx_div}};
	
	if (operation == optns[UNKNOWN].op)
		for (int op = ADD; op <= DIV; op++)
			mx_get_combinations(num1, num2, res, &optns[op]);
	else
		for (int op = ADD; op <= DIV; op++)
			if (operation == optns[op].op){
				mx_get_combinations(num1, num2, res, &optns[op]);
				break;
			}
	return 0;
}
