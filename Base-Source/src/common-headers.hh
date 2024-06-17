# include <stdio.h>
# include <argp.h>
# include <iostream>
# include <string>
# include <sstream>
# include <map>
# include "ast.hh"
# include <unordered_map>
# include <vector>
# include <assert.h>

using namespace std;


// This class stores the attributes of the nodes creted during parsing.
class Node_Attribute 	
{	
	int value;	// Relevant only for interpretation
	Ast * ast;      // Relevant only for compilation

   public:
	Node_Attribute() { }
	Node_Attribute(int v)  { value=v;  ast = NULL;}
	Node_Attribute(Ast *a) { value=0; ast=a;}
	~Node_Attribute();

	int get_value() 	{ return value; }
	Ast * get_ast()		{ assert (ast!=NULL) ; return ast; }
};


typedef enum {
		compiler,
		interpreter
	} lpmode;

typedef enum {
	PLUS,
	MINUS,
	MULT,
	DIV,
	UMINUS,
	COPY,
	} op_type;


Node_Attribute * process_ID(string * name);
Node_Attribute * process_NUM(string * name);
Node_Attribute * process_Expr(Node_Attribute *left, op_type op, Node_Attribute *right);
Node_Attribute * process_Asgn(string *lhs_name, Node_Attribute *rhs);
void process_finish(Node_Attribute *attr);

