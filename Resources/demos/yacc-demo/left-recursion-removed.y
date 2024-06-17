%{
#include <stdio.h>
#include <stdlib.h>
%}

%term NUM

%%

E : F T
  ;
T : '*' F T
  | F
  ;

F : NUM
  ;

%%
int yyerror (char *mesg)
{
	fprintf (stderr, "%s\n", mesg);
	exit (1);
}
