
digit [0-9]                     
letter [a-zA-Z_]
%%
int     			{ printf ("Found  Keyword INT with lexeme %s\n", yytext); }
float     			{ printf ("Found  Keyword FLOAT with lexeme %s\n", yytext); }
{letter}({letter}|{digit})*    	{ printf ("Found  ID with lexeme %s\n", yytext); }
.*				{ 
					/* This eats away anything else because .*
					   means longest match including spaces
					   until a newline is found.
					   so this eats away a complete line
					   of "int int int" without breaking it
					   up into three-ints.
                                        */
				}
\n				{				
					/* This eats away a newline.
                                        */
				}

