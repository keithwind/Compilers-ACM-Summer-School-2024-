
digit [0-9]                     
letter [a-zA-Z_]
%%
int     			{ printf ("Found  Keyword INT with lexeme %s\n", yytext); }
float     			{ printf ("Found  Keyword FLOAT with lexeme %s\n", yytext); }
{letter}({letter}|{digit})*    	{ printf ("Found  ID with lexeme %s\n", yytext); }
.				{ 
					/* This eats away a character that does 
					   not match any of the above patterns
					   except the newline character.
                                        */
				}
\n				{				
					/* This eats away a newline.
                                        */
				}

