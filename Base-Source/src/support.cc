#include "common-headers.hh"

extern lpmode mode;
int temp_count=0;
map <string, int> memory; // Stores values of variables during interpretation

//////////////////////// PROCESSING REDUCTIONS /////////////////////////////////

Node_Attribute * process_NUM(string * name)
{
	Node_Attribute * na;

	Ast * ast = new Number_Expr_Ast<int>(stoi(*name));

	if (mode == interpreter)
		na = new Node_Attribute(stoi(*name));
	else if (mode == compiler)
		na = new Node_Attribute(ast);
	return na;
}

Node_Attribute * process_ID(string * name)
{
	Node_Attribute * na;

	Ast * ast = new Name_Expr_Ast(*name);

	if (mode == interpreter)
		na = new Node_Attribute(memory[*name]);
	else if (mode == compiler)
		na = new Node_Attribute(ast);
	return na;
}

Node_Attribute * process_Expr(Node_Attribute *left, op_type op, Node_Attribute *right)
{
	Node_Attribute * na;
	int result;

	if (mode == interpreter)
	{
		switch (op)
		{
			case PLUS: 	result = left->get_value() + right->get_value(); break;
			case MINUS:	result = left->get_value() - right->get_value(); break;
			case MULT:	result = left->get_value() * right->get_value(); break;
			case DIV:	result = left->get_value() / right->get_value(); break;
			case UMINUS:
				if (right != NULL)
				{
					cerr << "Right operand must be NULL for Unary Minus" << endl;
					exit(1);
				}
				else	result =  - left->get_value();
				break;
			default:
				cerr << "Wrong operator type" << endl;
				exit(1);
				break;
		}
		na = new Node_Attribute(result);
	}
	else if (mode == compiler)
	{
		Ast * ast;

		switch (op)
		{
			case PLUS: 	ast = new Plus_Expr_Ast(left->get_ast(),
						       		right->get_ast()); break;
			case MINUS:	ast = new Minus_Expr_Ast(left->get_ast(),
								right->get_ast()); break;
			case MULT:	ast = new Mult_Expr_Ast(left->get_ast(),
								right->get_ast()); break;
			case DIV:	ast = new Div_Expr_Ast(left->get_ast(),
								right->get_ast()); break;
			case UMINUS:
				if (right != NULL)
				{
					exit(1);
				}
				else	ast = new UMinus_Expr_Ast(left->get_ast());
				break;
			default:
				cerr << "Wrong operator type" << endl;
				exit(1);
				break;
		}

		// Generating the current node's Node_Attribute using the above elements
		na = new Node_Attribute(ast);
	}
	return na;
}

Node_Attribute * process_Asgn(string *lhs_name, Node_Attribute *rhs)
{
	Ast *ast;
	Node_Attribute *attr;

	if (mode == interpreter)
	{
		if (lhs_name == NULL)
		   	cout << "> " << rhs->get_value() << endl;
		else
		{
			memory[*lhs_name] = rhs->get_value();
			cout << "> " << *lhs_name << " = " << rhs->get_value() << endl;
		}
		attr = new Node_Attribute();
	}
	else if (mode == compiler)
	{
		if (lhs_name == NULL)
		{
			ast = rhs->get_ast();
		}
		else
		{
			Ast * l = new Name_Expr_Ast(*lhs_name);
			Ast * r = rhs->get_ast();
			ast = new Assignment_Stmt_Ast(l, r);
			//ast->print_ast(4,cout, true);
		}
        	//ast->print_spaces_on_new_line (4, cout);

		attr = new Node_Attribute(ast);	
	}

	return attr;
}

////////////////////////// BEGIN AND ENDING ///////////////////////////////////////
void process_finish(Node_Attribute * attr)
{ 	if (mode == compiler) 
	{
		//cout << "The AST for the input is:\n";
		(attr->get_ast())->print_ast(4, cout, true);
		cout << endl;
	}
}

