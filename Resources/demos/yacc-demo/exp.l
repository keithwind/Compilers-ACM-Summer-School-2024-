%{
# include "y.tab.h"
%}

digit [0-9]	
operator [-+*/]
%%
{digit}+    { yylval = atoi(yytext); return NUM; }
{operator}  { return yytext[0]; }
.	    { printf ("Illegal character \"%c\"\n", yytext[0]); }
%%
/* Some C Code */
