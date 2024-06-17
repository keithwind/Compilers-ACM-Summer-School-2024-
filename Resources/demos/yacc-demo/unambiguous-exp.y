%{
#include <stdlib.h>
%}

%term id

%%

E : E '+' T
  | T
  ;

T : T '*' F
  | F
  ;

F : id
%%
int yyerror (char *mesg)
{
	fprintf (stderr, "%s\n", mesg);
	exit (1);
}
