#include "common-headers.hh"

static int parse_opt (int key, char *arg, struct argp_state *state);
int yyparse();

lpmode mode;

int main (int argc, char **argv)
{
	struct argp_option options[] = {
		{ 0, 'i', 0, 0, "Interpret the input and print result"},
		{ 0, 'c', 0, 0, "Compile the input into abstract syntax trees and print them"},
		{ 0 }
		};

	struct argp argp = {options, parse_opt };

	argp_parse (&argp, argc, argv, 0, 0, 0);
	return yyparse();
}

static int parse_opt (int key, char *arg, struct argp_state *state)
{
	switch (key)
	{
		case 'i': 
			mode = interpreter;
			break;
		case 'c': 
			mode = compiler;
			break;
	}
	return 0;
}
