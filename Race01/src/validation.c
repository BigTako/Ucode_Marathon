#include "encryptor.h"

void mx_out_err(int code, char * op, int object) {
	if (code == INVALID_OPERAND && object == OPERAND){
		mx_printerr("Invalid operand: ");
		mx_printerr(op);
	}
	else if (code == INVALID_OPERATION && object == OPERATION){
		mx_printerr("Invalid operation: ");
		mx_printerr(op);
	}
	else if (code == INVALID_RESULT && object == RESULT){
		mx_printerr("Invalid result: ");
		mx_printerr(op);
	}
	else if (code == INVALID_COUNT)
		mx_printerr("usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]");
	mx_printerr("\n");
	exit(0);
}	

char * mx_valid_obj(char * op, int object)
{
	int err = 0;
	char * trimmed = 0;
	if (object == OPERAND || object == RESULT) 
		trimmed = mx_strtrim(op, OPERAND, &err);
	else if (object == OPERATION) 
		trimmed = mx_strtrim(op, OPERATION, &err);
	if (err){	
		if (object == OPERAND) 
			mx_out_err(INVALID_OPERAND, op, object);
		else if (object == OPERATION) 
			mx_out_err(INVALID_OPERATION, op, object);
		else if (object == RESULT) 
			mx_out_err(INVALID_RESULT, op, object);
	}
	return trimmed;
}


