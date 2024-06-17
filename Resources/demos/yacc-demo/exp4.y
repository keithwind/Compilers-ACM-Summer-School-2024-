%{
#include <stdio.h>
#include <stdlib.h>
%}
%token NUM
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
