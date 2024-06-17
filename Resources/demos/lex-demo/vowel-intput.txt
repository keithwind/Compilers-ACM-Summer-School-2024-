%{	
#include <stdio.h>
%}
%option noyywrap
%%
dz      { printf ("found token dz with lexeme %s\n",yytext); }
cdz     { printf ("found token cdz with lexeme %s\n",yytext); }
bcdz    { printf ("found token bcdz with lexeme %s\n",yytext); }
abcdz   { printf ("found token abcdz with lexeme %s\n",yytext); }
.       { printf ("found unmatched character %s\n",yytext);}
%%
#if 0

This lex script illustrates that each one of the rules may have to be
exercised before discovering that nothing other than the default (dot)
rule matches.

For input abcde, only the first token can be considered (because it begins
with an a) but it does not match because the last character does not match.

Hence the scanner discards the first letter ("a") and considers "bcde" for
a potential match. Now only the second token can be matched because it begins
with a b. However, again the last letter does not match. 

So b is discarded and the remaining input ("cde") for scanning. Now the third 
token is considered but that too does not match.

Hence c is discarded and consider "de" for scanning. The fourth token is 
considered but does not match. 

Thus "e" is considered for matching but that too does not match.

Note that the order of token specification does not matter because the
tokens do not have a common prefixes (they have common suffixes).

#endif
