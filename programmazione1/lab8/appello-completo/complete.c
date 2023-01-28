#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool valid_expr(char expr[static 1]);
bool valid_values(char assign[static 1]);
void extract_values(char assign[static 1], int values[static 5]);
char* substitute(char expr[static 1], int values[static 5]);
int eval_expr(char expr[static 1]);

int
main(int argc, char* argv[argc+1])
{
	if(argc <= 1) {
		puts("usage: ./complete expr variable:value");
		return EXIT_FAILURE;
	}

	if(valid_expr(argv[1]) && valid_values(argv[2])) {
		int values[5] = {0};

		extract_values(argv[2], values);
		printf("sum: %d\n", eval_expr(substitute(argv[1], values)));
	}

	return EXIT_SUCCESS;
}

bool
valid_expr(char expr[static 1])
{
	for(size_t i = 0; i < strlen(expr); ++i) {
		if(i % 2 == 0 && ((expr[i] < 'A' || expr[i] > 'E')
				   && (expr[i] < '0' || expr[i] > '9'))) {
			return false;
		 } else  if(i % 2 == 1 && expr[i] != '+' && expr[i] != '-') {
			return false;
		}
	}

	return true;
}

bool
valid_values(char assign[static 1])
{
	for(size_t i = 0; i < strlen(assign)-2; i += 3) {
		if(assign[i] < 'A' || assign[i] > 'E'
		   || assign[i+1] != ':' || assign[i+2] < '0' || assign[i+2] > '9') {
			return false;
		}
	}

	return true;
}

void
extract_values(char assign[static 1], int values[static 5])
{
	for(size_t i = 0; i < strlen(assign)-2; ++i) {
		switch(assign[i]) {
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
			values[assign[i]-'A'] = assign[i+2] - '0';
			break;
		}
	}
}

char*
substitute(char expr[static 1], int values[static 5])
{
	unsigned long len = strlen(expr);
	char* copy = calloc(len+1, sizeof(char));
	if(!copy) {
		puts("error: can't copy expression string");
		exit(EXIT_FAILURE);
	}
	memcpy(copy, expr, len);
	copy[len] = 0;

	for(size_t i = 0; i < strlen(copy); ++i ) {
		switch(copy[i]) {
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
			copy[i] = values[expr[i]-'A'] + '0';
			break;
		}
	}
	return copy;
}

int
eval_expr(char expr[static 1])
{
	int num[2] = { 0 };

	num[0] = expr[0] - '0';

	char op = ' ';
	for(size_t i = 1; i < strlen(expr); ++i) {
		if(expr[i] >= '0' && expr[i] <= '9') {
			num[1] = expr[i] - '0';
		} else if(expr[i] == '+' || expr[i] == '-') {
			if(op == ' ') {
				op = expr[i];
			} else {
				switch(expr[i]) {
				case '+':
					num[0] += num[1];
					op = expr[i];
					break;
				case '-':
					num[0] -= num[1];
					op = expr[i];
					break;
				}
			}
		}
	}

	switch(op) {
	case '+':
		num[0] += num[1];
		break;
	case '-':
		num[0] -= num[1];
		break;
	}

	return num[0];
}
