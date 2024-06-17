digit [0-9] 
alpha [a-zA-Z_] 
%%
{alpha}({alpha}|{digit})*	{printf("Found identifier with lexeme %s\n", yytext);}
int	{ printf("Found INT\n"); }
integer { printf("Found INTEGER\n"); }
