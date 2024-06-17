%{
#include <stdio.h>
#include <stdlib.h>
//    Precedence is defined by introducing a sequence of associativity rules.
//    A rule that appears lower has a higher precedence.
//    * and / below have a higher precedence than + and -.
//    All of them are left associative here.
%}
%token NUM
%left '+' '-'
%left '*' '/'	
%%
E : NUM    
	{ printf("found an expression consisting of a number\n");}
  | E '+' E  
	{ printf("found a PLUS expression\n");}
  | E '*' E  
	{ printf("found a MULT expression\n");}
  | E '-' E  
	{ printf("found a SUB expression\n");}
  | E '/' E  
	{ printf("found a DIV expression\n");}
%%
int yyerror (char *mesg)
{
	fprintf (stderr, "%s\n", mesg);
	exit (1);
}
