%{
#include "common-headers.hh"
#include "ast.hh"
extern "C" void yyerror(char *s);
extern int yylex(void);


%}
%union{
	string * name;
	Node_Attribute * node_attribute;
}
%token <name> NUM 
%token <name> ID

%left '+' '-'
%left '*' '/'
%right Uminus
%type <node_attribute> Expr
%type <node_attribute> Stmt
%start StmtList
%%
StmtList : StmtList Stmt
      | Stmt

Stmt : ID '=' Expr  ';' 		{ $$ = process_Asgn($1, $3); process_finish($$);	}
	;

Expr : Expr '+' Expr			{ $$ = process_Expr($1, PLUS, $3); }
	| Expr '*' Expr 		{ $$ = process_Expr($1, MULT, $3); }
	| Expr '/' Expr 		{ $$ = process_Expr($1, DIV, $3); }
	| Expr '-' Expr 		{ $$ = process_Expr($1, MINUS, $3); }
	| '-' Expr	%prec Uminus	{ $$ = process_Expr($2, UMINUS, NULL); }
	| NUM 				{ $$ = process_NUM($1); }
	| ID 				{ $$ = process_ID($1); }
	| '(' Expr ')'			{ $$ = $2; }
	;
	
%%
