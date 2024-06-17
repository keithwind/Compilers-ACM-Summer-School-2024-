%{
#include "common-headers.hh"
extern "C" void yyerror(char *s);
#include "parse.tab.h"

%}
%option noyywrap

digit  [0-9]
ws	[ \t\n]*
operator [-+*/=;]
letter [a-zA-Z_]
punct [{}()[\],]



%%
{digit}+ 		{ 	yylval.name= new string(yytext); return NUM; }

{operator}|{punct}	{	return yytext[0]; }

{letter}({letter}|{digit})* { yylval.name= new string(yytext); return ID; }
		
{ws}		;
.		{
			cerr << "Illegal Character \"" << yytext[0] << "\". Ignoring the rest of the input. " << endl;
			exit(1);
		}
