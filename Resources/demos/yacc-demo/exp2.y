%{
#include <stdio.h>
#include <stdlib.h>
%}
%token NUM
%%
E : NUM    
	{ printf("found an expression consisting of a number %d\n", yylval);}
  | E '+' E  
	{ printf("found a plus expression\n");}
%%
int yyerror (char *mesg)
{
	fprintf (stderr, "%s\n", mesg);
	exit (1);
}
