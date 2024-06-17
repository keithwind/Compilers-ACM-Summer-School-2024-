
#include<iostream>
#include<fstream>
#include<typeinfo>

using namespace std;

#include "common-headers.hh"
#include "ast.hh"

Ast::Ast()
{}

Ast::~Ast()
{}



////////////////////////////////////////////////////////////////

Ast * Unary_Expr_Ast::get_opd()
{
	stringstream msg;
	msg << "opd is NULL for reading an object of class " << typeid(*this).name();

	assert (opd !=NULL);
	return opd;
}

void Unary_Expr_Ast::set_opd(Ast *o)
{
	stringstream msg;
	msg << "opd is NULL for setting in an object of class " << typeid(*this).name();

	assert (o !=NULL);
	opd = o;
}


////////////////////////////////////////////////////////////////

Ast * Binary_Expr_Ast::get_left_child()
{
	stringstream msg;
	msg << "lopd is NULL for reading an object of class " << typeid(*this).name();

	assert (left_child !=NULL);
	return left_child;
}

Ast * Binary_Expr_Ast::get_right_child()
{
	stringstream msg;
	msg << "ropd is NULL for reading an object of class " << typeid(*this).name();

	assert (right_child !=NULL);
	return right_child;
}


void Binary_Expr_Ast::set_left_child(Ast *l)
{
	stringstream msg;
	msg << "lopd is NULL for setting in an object of class " << typeid(*this).name();

	assert (l !=NULL);
	left_child = l;
}

void Binary_Expr_Ast::set_right_child(Ast *r)
{
	stringstream msg;
	msg << "ropd is NULL for setting in an object of class " << typeid(*this).name();

	assert (r !=NULL);
	right_child = r;
}

////////////////////////////////////////////////////////////////

Statement_Ast::Statement_Ast()
{}

Statement_Ast::~Statement_Ast()
{}


Assignment_Stmt_Ast::Assignment_Stmt_Ast(Ast * l, Ast * r)
{
	assert (l !=NULL);
	assert (r !=NULL);

	set_lhs(l);
	set_rhs(r);
}

Assignment_Stmt_Ast::~Assignment_Stmt_Ast()
{
}

void Assignment_Stmt_Ast::print_ast(int sc, ostream & file_buffer, bool top_level)
{
	/*
	 *if (top_level)
     *    print_spaces_on_new_line (sc, file_buffer);
	 */

    print_spaces_on_new_line (sc, file_buffer);
	file_buffer << "Asgn:";

        print_spaces_on_new_line (sc+INDENT_INCR, file_buffer);
	file_buffer << "LHS (";
	get_lhs()->print_ast(sc+2*INDENT_INCR, file_buffer, false);
        //print_spaces_on_new_line (sc+INDENT_INCR, file_buffer);
	file_buffer << ")";

        print_spaces_on_new_line (sc+INDENT_INCR, file_buffer);
	file_buffer << "RHS (";
	get_rhs()->print_ast(sc+2*INDENT_INCR, file_buffer, false);
        //print_spaces_on_new_line (sc+INDENT_INCR, file_buffer);
	file_buffer << ")";
}

Ast * Assignment_Stmt_Ast::get_lhs()
{
	assert (lhs !=NULL);
	return lhs;
}

Ast * Assignment_Stmt_Ast::get_rhs()
{
	assert (rhs !=NULL);
	return rhs;
}


void Assignment_Stmt_Ast::set_lhs(Ast *l)
{
	assert (l !=NULL);
	lhs = l;
}

void Assignment_Stmt_Ast::set_rhs(Ast *r)
{
	assert (r !=NULL);
	rhs = r;
}

///////////////////////////////////////////////////////////////////////////////

template <class DATA_TYPE>
Number_Expr_Ast<DATA_TYPE>::Number_Expr_Ast(DATA_TYPE number)
{
	constant = number;
}

template <class DATA_TYPE>
Number_Expr_Ast<DATA_TYPE>::~Number_Expr_Ast()
{}


template <class DATA_TYPE>
void Number_Expr_Ast<DATA_TYPE>::print_ast(int sc, ostream & file_buffer, bool top_level)
{
	// Ignore the space count sc
	if (top_level)
        	print_spaces_on_new_line (sc, file_buffer);
	
	file_buffer << "Num : " << constant;
}


///////////////////////////////////////////////////////////////////////////////


Plus_Expr_Ast::Plus_Expr_Ast(Ast * l, Ast * r)
{
	assert (l !=NULL);
	assert (r !=NULL);

	set_left_child(l);
	set_right_child(r);
}

void Plus_Expr_Ast::print_ast(int sc, ostream & file_buffer, bool top_level)
{
        print_spaces_on_new_line (sc, file_buffer);
	file_buffer << "Arith: Plus";

        print_spaces_on_new_line (sc+INDENT_INCR, file_buffer);
	file_buffer << "L_Opd (";
	get_left_child()->print_ast(sc+2*INDENT_INCR, file_buffer, false);
	file_buffer << ")";

        print_spaces_on_new_line (sc+INDENT_INCR, file_buffer);
	file_buffer << "R_Opd (";
	get_right_child()->print_ast(sc+2*INDENT_INCR, file_buffer, false);
	file_buffer << ")";
}

/////////////////////////////////////////////////////////////////

Minus_Expr_Ast::Minus_Expr_Ast(Ast * l, Ast * r)
{
	assert (l !=NULL);
	assert (r !=NULL);

	set_left_child(l);
	set_right_child(r);
}

void Minus_Expr_Ast::print_ast(int sc, ostream & file_buffer, bool top_level)
{
        print_spaces_on_new_line (sc, file_buffer);
	file_buffer << "Arith: Minus";

        print_spaces_on_new_line (sc+INDENT_INCR, file_buffer);
	file_buffer << "L_Opd (";
	get_left_child()->print_ast(sc+2*INDENT_INCR, file_buffer, false);
	file_buffer << ")";

        print_spaces_on_new_line (sc+INDENT_INCR, file_buffer);
	file_buffer << "R_Opd (";
	get_right_child()->print_ast(sc+2*INDENT_INCR, file_buffer, false);
	file_buffer << ")";
}

//////////////////////////////////////////////////////////////////

Mult_Expr_Ast::Mult_Expr_Ast(Ast * l, Ast * r)
{
	assert (l !=NULL);
	assert (r !=NULL);

	set_left_child(l);
	set_right_child(r);
}

void Mult_Expr_Ast::print_ast(int sc, ostream & file_buffer, bool top_level)
{
        print_spaces_on_new_line (sc, file_buffer);
	file_buffer << "Arith: Mult";

        print_spaces_on_new_line (sc+INDENT_INCR, file_buffer);
	file_buffer << "L_Opd (";
	get_left_child()->print_ast(sc+2*INDENT_INCR, file_buffer, false);
	file_buffer << ")";

        print_spaces_on_new_line (sc+INDENT_INCR, file_buffer);
	file_buffer << "R_Opd (";
	get_right_child()->print_ast(sc+2*INDENT_INCR, file_buffer, false);
	file_buffer << ")";
}

////////////////////////////////////////////////////////////////////

Div_Expr_Ast::Div_Expr_Ast(Ast * l, Ast * r)
{
	assert (l !=NULL);
	assert (r !=NULL);

	set_left_child(l);
	set_right_child(r);
}

void Div_Expr_Ast::print_ast(int sc, ostream & file_buffer, bool top_level)
{
        print_spaces_on_new_line (sc, file_buffer);
	file_buffer << "Arith: Div";

        print_spaces_on_new_line (sc+INDENT_INCR, file_buffer);
	file_buffer << "L_Opd (";
	get_left_child()->print_ast(sc+2*INDENT_INCR, file_buffer, false);
	file_buffer << ")";

        print_spaces_on_new_line (sc+INDENT_INCR, file_buffer);
	file_buffer << "R_Opd (";
	get_right_child()->print_ast(sc+2*INDENT_INCR, file_buffer, false);
	file_buffer << ")";
}


//////////////////////////////////////////////////////////////////////

UMinus_Expr_Ast::UMinus_Expr_Ast(Ast * l)
{

	assert (l !=NULL);

	set_opd(l);
}

void UMinus_Expr_Ast::print_ast(int sc, ostream & file_buffer, bool top_level)
{
        print_spaces_on_new_line (sc, file_buffer);
	file_buffer << "Arith: Uminus";

        print_spaces_on_new_line (sc+INDENT_INCR, file_buffer);
	file_buffer << "L_Opd (";
	get_opd()->print_ast(sc+2*INDENT_INCR, file_buffer, false);
	file_buffer << ")";
}

//////////////////////////////////////////////////////////////////////

template class Number_Expr_Ast<double>;
template class Number_Expr_Ast<int>;
///////////////////////////////////////////////////////////////////////////////



void Ast::print_spaces_on_new_line (int sc, ostream & file_buffer)
{
	file_buffer << "\n";
	for (int i=0; i<sc; i++)
		file_buffer << " ";
}

/////////////////////////////////////////////////////////////////

Name_Expr_Ast::Name_Expr_Ast(string & name)
{
	expr_name = name;
}

Name_Expr_Ast::~Name_Expr_Ast()
{}


void Name_Expr_Ast::print_ast(int sc, ostream & file_buffer, bool top_level)
{
	// Ignore the space count sc
	if (top_level)
        	print_spaces_on_new_line (sc, file_buffer);
	
	file_buffer << "Name : " << expr_name;
}


#if 0
int main()
{
	
// 	Code to test the class.

//	Create objects by calling the constructors and supplying string values or
//	numeric values as needed.
//	The call different methods on the class and print them.

	string * a = new string ("distance");
	string * b = new string ("speed");
	string * c = new string ("time");

	Ast *o1 = new Name_Expr_Ast(*b,1);
	Ast *o2 = new Name_Expr_Ast(*b,1);

	Ast *l = new Name_Expr_Ast(*a,1);
	Ast *r = new Mult_Expr_Ast(o1,o2,1);

	Ast *s = new Assignment_Stmt_Ast(l, r, 1);

	s->print_ast(4, cout, true);

	return 0;
}

#endif
