#include "common-headers.hh"

struct Options chosen_options;

struct argp_option options[] = {
		{ "interpret", 'i', 0, 0, "Interpret the input and print result"},
		{ "compile", 'c', 0, 0, "Compile the input into abstract syntax trees"},
  		{ "sa-scan", 'n' , 0, 0, "Stop after lexical analysis"},
  		{ "sa-parse", 'e' , 0, 0, "Stop after parsing"},
  		{ "show-tokens", 't' , 0, 0, "Show the abstract syntax trees on stdout"},
  		{ "show-ast", 'a' , 0, 0, "Show the abstract syntax trees on stdout"},
  		{ "show-parse", 'p' , 0, 0, "Show the abstract syntax trees on stdout"},
		{ 0 }
		};


int parse_opt (int key, char *arg, struct argp_state *state)
{
	switch (key)
	{
		case 'i': 
			if (chosen_options.compile)
			{
				cerr << "coi: Compilation and interpretation are mutually exclusive" << endl;
				exit(1);
			}
			chosen_options.interpret = true;
			mode = interpreter;
			break;
		case 'c': 
			if (chosen_options.interpret)
			{
				cerr << "coi: Compilation and interpretation are mutually exclusive" << endl;
				exit(1);
			}
			chosen_options.compile = true;
			mode = compiler;
			break;
		case 'a':
			chosen_options.show_ast = true;
			break;
		case 't':
			chosen_options.show_tokens = true;
			break;
		case 'p':
			chosen_options.show_parse = true;
			break;
		case 'e':
			chosen_options.sa_parse = true;
			break;
		case 'n':
			chosen_options.sa_scan = true;
			break;
			/*
		default:
			// No need of this default, the error is caught by the argp
			// library. Using this default requires setting up some more
			// things such as the state struct.
			argp_usage(state);
			break;
			*/
	}
	return 0;
}

bool show_tokens()
{
	return chosen_options.show_tokens;
}

bool show_parse()
{
	return chosen_options.show_parse;
}

bool show_ast()
{
	if (chosen_options.show_ast)
	{
		if (chosen_options.interpret)
		{
			cerr << "coi: The show AST option is incompatible with the interpret option" << endl;
			exit(1);
		}
	}
	return chosen_options.show_ast;
}

bool stop_after_scanning()
{
	return chosen_options.sa_scan;
}

bool stop_after_parsing()
{
	return chosen_options.sa_parse;
}

lpmode lp_mode()
{
	if (chosen_options.interpret)
	{
		return interpreter;
	}
	if (chosen_options.compile)
		return compiler;
	assert ("Unknown option which is neither interpretation nor compilation");
}

bool semantic_analysis()
{
	return ((chosen_options.sa_scan == false) && 
                (chosen_options.sa_parse == false)); 
}
#include <string>

string last_token_seen;
char * last_lexeme_seen;

void store_token_name(std::string token_name, char *lexeme, int lineno)
{
	if (show_tokens())
  	{
    		cout << "\tToken Name: " << token_name;
    		cout << "\tLexeme: " << lexeme;
    		cout << "\tLineno: "<< lineno <<"\n";
  	}
  
  	last_token_seen = token_name;
        last_lexeme_seen = lexeme;
}

