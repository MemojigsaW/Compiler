%code requires {

// this will be added to your parser.hpp file

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif

#include "nodes.hpp"
#include <memory>

class Node;



}

%code {

// this will be added to your parser.cpp file

#include "lexer.hpp"

static yy::parser::symbol_type yylex(yyscan_t);

template <typename T, typename... Args> static std::unique_ptr<T> make_node(yy::parser::location_type const&, Args&&...);

#define SHOWPARSE false
#define TRACEPARSE(x) if (SHOWPARSE) printf("%s\n", x)

}

/* see https://www.gnu.org/software/bison/manual/html_node/Declarations.html */

%require "3.6"
%language "c++"
%locations
%param { yyscan_t lexer }
%parse-param { std::unique_ptr<Node>& root }
%verbose
%define api.value.type variant
%define api.token.constructor
//todo enable in lab 3
%define api.value.automove
%define parse.trace
%define parse.assert

%token <std::string> HI
%token BYE

%token <std::string>TOK_identifier
%token <int>TOK_integer
%token <float>TOK_float
%token <bool>TOK_true TOK_false
%token TOK_lparen
%token TOK_rparen
%token TOK_lbrace
%token TOK_rbrace
%token TOK_eq TOK_ne TOK_lt TOK_gt TOK_le TOK_ge
%token TOK_plus TOK_minus TOK_star TOK_slash
%token TOK_log_and TOK_log_or
%token TOK_if TOK_while TOK_for TOK_break TOK_continue TOK_return 
%token TOK_comma TOK_semicolon TOK_colon TOK_question_mark
%token TOK_assign 

//Lab 3 updates
%token TOK_plus_assign TOK_minus_assign TOK_star_assign TOK_slash_assign
%token <std::string>TOK_type


/*Precedence - first declare is lowest*/
%right TOK_assign
%right TOK_colon TOK_question_mark
%left TOK_log_or
%left TOK_log_and
%left TOK_eq TOK_ne
%left TOK_lt TOK_gt TOK_le TOK_ge
%left TOK_plus TOK_minus
%left TOK_star TOK_slash
/*Setting precedence for the binary and relation expression rule so reduce is prioritized 
 * over shift
/*%prec TOK_uminus must be on the line where the op and context are together
 * unary_expression reduce precedence over shift*/
%nonassoc TOK_unop
%right TOK_uminus
%left TOK_lparen TOK_rparen TOK_lbrace TOK_rbrace 

//declare node type for AST

%type <std::unique_ptr<Node>> root
%type <std::unique_ptr<OperatorNode>>unary_op
%type <std::unique_ptr<TypeNode>> type
%type <std::unique_ptr<NameNode>> name

%type <std::unique_ptr<Node>> expression expression_question
%type <std::unique_ptr<Node>> single_statement single_statement_question
%type <std::unique_ptr<Node>> statement compound_statement
%type <std::unique_ptr<Node>> function function_list

%type <std::unique_ptr<ChainNode>> _ece _ecee statement_kleene suite comma_dec_kleene
%type <std::unique_ptr<ChainNode>> function_plus

%type <std::unique_ptr<FunctionCallNode>> function_call
%type <std::unique_ptr<BinaryExprNode>> binary_expression relational_expression
%type <std::unique_ptr<UnaryExprNode>> unary_expression
%type <std::unique_ptr<CastNode>> cast_expression
%type <std::unique_ptr<TernaryExprNode>> ternary_expression

%type <std::unique_ptr<DeclNode>> declaration
%type <std::unique_ptr<BlockNode>> block
%type <std::unique_ptr<ParamNode>> parameter_list
%type <std::unique_ptr<FuncDeclNode>> function_decl
%type <std::unique_ptr<FuncDefNode>> function_defn

%start root

%%
root
	:	function_list 
	{ root = std::move($1); TRACEPARSE("root->function_list");}
	;

function_list
	:	function_plus					
	{TRACEPARSE("function_list->function_plus");$$ = std::move($1);}
	;

function_plus:	function						
	{TRACEPARSE("function_plus->function");
	$$ = make_node<ChainNode>(@$, std::move($1), std::move(make_node<ChainNode>(@$, nullptr, nullptr)));}
	|	function function_plus					
	{TRACEPARSE("function_plus->function function_plus");
	$$ = make_node<ChainNode>(@$, std::move($1), std::move($2));}
	;

function
	:	function_decl TOK_semicolon 		
	{TRACEPARSE("function->function_decl TOK_semicolon");$$ = std::move($1);}
	|	function_defn							
	{TRACEPARSE("function->function_decl"); $$ = std::move($1);}
	;

function_decl
	:	type name TOK_lparen parameter_list TOK_rparen 
	{TRACEPARSE("function_decl->type name TOK_lparen parameter_list TOK_rparen");
	$$ = make_node<FuncDeclNode>(@$, std::move($1), std::move($2), std::move($4));}
	;
function_defn
	:	function_decl block								
	{TRACEPARSE("function_defn->function_decl block	");
	$$ = make_node<FuncDefNode>(@$, std::move($1), std::move($2));}
	;

parameter_list
	: declaration comma_dec_kleene	
	{TRACEPARSE("parameter_list->declaration comma_dec_kleene");
	$$ = make_node<ParamNode>(@$, std::move($1), std::move($2));}
	|	/*empty*/								
	{TRACEPARSE("parameter_list->/*empty*/");
	$$ = make_node<ParamNode>(@$, nullptr, nullptr);}
	;
comma_dec_kleene
	: TOK_comma declaration comma_dec_kleene 
	{TRACEPARSE("comma_dec_kleene->TOK_comma declaration comma_dec_kleene ");
	$$ = make_node<ChainNode>(@$, std::move($2), std::move($3));}
	|	/*empty*/										 
	{TRACEPARSE("comma_dec_kleene->/*empty*/");
	$$ = make_node<ChainNode>(@$, nullptr, nullptr);}
	;

block
	:	TOK_lbrace suite TOK_rbrace				
	{TRACEPARSE("block->TOK_lbrace suite TOK_rbrace");
	$$ = make_node<BlockNode>(@$, std::move($2));}
	;

suite
	:	statement_kleene						
	{TRACEPARSE("suite->statement_kleene");
	$$ = std::move($1);}
	;

statement_kleene
	:	statement statement_kleene 	
	{TRACEPARSE("statement_kleene->statement statement_kleene");
	$$ = make_node<ChainNode>(@$, std::move($1), std::move($2));}
	|	/*empty*/								
	{TRACEPARSE("statement_kleene->/*empty*/");
	$$ = make_node<ChainNode>(@$, nullptr, nullptr);}
	;
	
statement
	:	single_statement TOK_semicolon		
	{TRACEPARSE("statement->single_statement TOK_semicolon");
	$$ = std::move($1);}
	|	compound_statement						
	{TRACEPARSE("statement->compound_statement");
	$$ = std::move($1);}
	;
		
compound_statement
	:	TOK_if	TOK_lparen	expression TOK_rparen	block	
	{TRACEPARSE("compound_statement->TOK_if	TOK_lparen	expression TOK_rparen	block");
	$$ = make_node<IfNode>(@$, std::move($3), std::move($5));}
	|	TOK_for	TOK_lparen single_statement_question TOK_semicolon expression_question TOK_semicolon single_statement_question TOK_rparen block
	{TRACEPARSE("compound_statement->TOK_for	TOK_lparen single_statement_question TOK_semicolon expression_question TOK_semicolon single_statement_question TOK_rparen block");
	$$ = make_node<ForNode>(@$, std::move($3), std::move($5), std::move($7), std::move($9));}
	|	TOK_while	TOK_lparen	expression TOK_rparen block	
	{TRACEPARSE("compound_statement->TOK_while	TOK_lparen	expression TOK_rparen block");
	$$ = make_node<WhileNode>(@$, std::move($3), std::move($5));}
	;

single_statement_question
	:	single_statement	
	{TRACEPARSE("single_statement_question->single_statement");$$ = std::move($1);}
	| /*empty*/									
	{TRACEPARSE("single_statement->/*empty*/");$$ = nullptr;}
	;

single_statement
	:	declaration TOK_assign expression	
	{TRACEPARSE("single_statement->declaration TOK_assign expression");
	$$ = make_node<VarDeclNode>(@$, std::move($1), std::move($3));}
	|	name TOK_assign expression						
	{TRACEPARSE("single_statement->name TOK_assign expression");
	$$ = make_node<AssignmentNode>(@$, std::move($1), "=", std::move($3));}
	|	name TOK_plus_assign expression				
	{TRACEPARSE("single_statement->name augmented_assign_op expression");
	$$ = make_node<AssignmentNode>(@$, std::move($1), "+=", std::move($3));}
	|	name TOK_minus_assign expression
	{TRACEPARSE("single_statement->name augmented_assign_op expression");
	$$ = make_node<AssignmentNode>(@$, std::move($1), "-=", std::move($3));}		
	|	name TOK_star_assign expression
	{TRACEPARSE("single_statement->name augmented_assign_op expression");
	$$ = make_node<AssignmentNode>(@$, std::move($1), "*=", std::move($3));}
	|	name TOK_slash_assign expression
	{TRACEPARSE("single_statement->name augmented_assign_op expression");
	$$ = make_node<AssignmentNode>(@$, std::move($1), "/=", std::move($3));}

	|	TOK_break										
	{TRACEPARSE("single_statement->TOK_break");$$ = make_node<ControlNode>(@$, "break");}
	|	TOK_continue									
	{TRACEPARSE("single_statement->TOK_continue");$$ = make_node<ControlNode>(@$, "continue");}
	|	TOK_return expression_question					
	{TRACEPARSE("single_statement->TOK_return expression_question");
	$$ = make_node<ReturnNode>(@$, "return", std::move($2));}
	|	expression										
	{TRACEPARSE("single_statement->expression"); $$ = std::move($1);}
	;

declaration
	:	type name						
	{TRACEPARSE("declaration->type name");
	$$ = make_node<DeclNode>(@$, std::move($1), std::move($2));}
	;

expression_question
	:	expression 						
	{TRACEPARSE("expression_question->expression");$$ = std::move($1);}
	|	/*empty*/										
	{TRACEPARSE("expression_question->/*empty*/");$$ = nullptr;}
	;


ternary_expression
	:	expression TOK_question_mark expression TOK_colon expression
	{TRACEPARSE("ternary_expression->expression TOK_question_mark expression TOK_colon expression");
	$$ = make_node<TernaryExprNode>(@$, std::move($1), std::move($3), std::move($5));}
	;

cast_expression
	:	TOK_lparen	type TOK_rparen	expression	
	{TRACEPARSE("cast_expression->TOK_lparen	type TOK_rparen	expression");
	$$ = make_node<CastNode>(@$, std::move($2), std::move($4));}
	;

binary_expression
	:	expression  TOK_plus expression 
	{TRACEPARSE("binary_expression->expression binary_op expression"); $$ = make_node<BinaryExprNode>(@$, std::move($1), "+", std::move($3));}
	
	| expression  TOK_minus expression
	{TRACEPARSE("binary_expression->expression binary_op expression"); $$ = make_node<BinaryExprNode>(@$, std::move($1), "-", std::move($3));}

	| expression  TOK_star expression
	{TRACEPARSE("binary_expression->expression binary_op expression"); $$ = make_node<BinaryExprNode>(@$, std::move($1), "*", std::move($3));}

	| expression  TOK_slash expression
	{TRACEPARSE("binary_expression->expression binary_op expression"); $$ = make_node<BinaryExprNode>(@$, std::move($1), "/", std::move($3));}

	| expression  TOK_log_and expression
	{TRACEPARSE("binary_expression->expression binary_op expression"); $$ = make_node<BinaryExprNode>(@$, std::move($1), "&&", std::move($3));}

	| expression  TOK_log_or expression
	{TRACEPARSE("binary_expression->expression binary_op expression"); $$ = make_node<BinaryExprNode>(@$, std::move($1), "||", std::move($3));}
	;

relational_expression
	:	expression TOK_eq expression 
	{TRACEPARSE("relational_expression->expression relational_op expression");$$ = make_node<BinaryExprNode>(@$, std::move($1), "==", std::move($3));}
	|	expression TOK_ne expression 
		{TRACEPARSE("relational_expression->expression relational_op expression");$$ = make_node<BinaryExprNode>(@$, std::move($1), "!=", std::move($3));}

	|	expression TOK_le expression 
		{TRACEPARSE("relational_expression->expression relational_op expression");$$ = make_node<BinaryExprNode>(@$, std::move($1), "<=", std::move($3));}

	|	expression TOK_ge expression 
		{TRACEPARSE("relational_expression->expression relational_op expression");$$ = make_node<BinaryExprNode>(@$, std::move($1), ">=", std::move($3));}

	|	expression TOK_lt expression 
		{TRACEPARSE("relational_expression->expression relational_op expression");$$ = make_node<BinaryExprNode>(@$, std::move($1), "<", std::move($3));}

	|	expression TOK_gt expression 
		{TRACEPARSE("relational_expression->expression relational_op expression");$$ = make_node<BinaryExprNode>(@$, std::move($1), ">", std::move($3));}



	;

unary_expression
	:	unary_op expression %prec TOK_unop		
	{TRACEPARSE("unary_expression->unary_op expression %prec TOK_unop");$$ = make_node<UnaryExprNode>(@$, std::move($1), std::move($2));}
	;

function_call
	:	name TOK_lparen _ece TOK_rparen	
	{TRACEPARSE("function_call->name TOK_lparen _ece TOK_rparen");$$=make_node<FunctionCallNode>(@$, std::move($1), std::move($3));}
	;
/* ece is (expression (comma expression)*)?  */
_ece
	:	expression _ecee	
	{TRACEPARSE("_ece->expression _ecee");$$=make_node<ChainNode>(@$, std::move($1), std::move($2));}
	|	/*empty*/	
	{TRACEPARSE("_ece->/*empty*/");$$ = make_node<ChainNode>(@$, nullptr, nullptr);}
	;

_ecee
	:	TOK_comma expression _ecee	
	{TRACEPARSE("_ecee->TOK_comma expression _ecee");$$ = make_node<ChainNode>(@$, std::move($2), std::move($3));}
	|	/*empty*/	
	{TRACEPARSE("_ecee->/*empty*/");$$ = make_node<ChainNode>(@$, nullptr, nullptr);}
	;

expression
	:	name											
	{TRACEPARSE("expression->name");$$ = std::move($1);}
	|	TOK_true 										
	{TRACEPARSE("expression->TOK_true");$$ = make_node<BoolNode>(@$, true);}
	|	TOK_false										
	{TRACEPARSE("expression->TOK_false");$$ = make_node<BoolNode>(@$, false);}
	|	TOK_integer										
	{TRACEPARSE("expression->TOK_integer");$$ = make_node<IntNode>(@$, $1);}
	|	TOK_float										
	{TRACEPARSE("expression->TOK_float");$$ = make_node<FloatNode>(@$, $1);}
	|	binary_expression								
	{TRACEPARSE("expression->binary_expression"); $$ = std::move($1);}
	|	unary_expression								
	{TRACEPARSE("expression->unary_expression"); $$ = std::move($1);}
	|	relational_expression							
	{TRACEPARSE("expression->relational_expression"); $$ = std::move($1);}
	|	ternary_expression								
	{TRACEPARSE("expression->ternary_expression");$$ = std::move($1);}
	|	cast_expression									
	{TRACEPARSE("expression->cast_expression");$$ = std::move($1);}
	|	function_call									
	{TRACEPARSE("expression->function_call");$$ = std::move($1);}
	|	TOK_lparen	expression TOK_rparen				
	{TRACEPARSE("expression->TOK_lparen	expression TOK_rparen");$$ = std::move($2);}
	;

type:	TOK_type							
	{TRACEPARSE("type->TOK_type");$$ = make_node<TypeNode>(@$, $1);}
	;

name:	TOK_identifier 							
	{TRACEPARSE("name->TOK_identifier");$$ = make_node<NameNode>(@$, $1);}
	;

unary_op
	:	TOK_minus %prec TOK_uminus	
	{TRACEPARSE("unary_op->TOK_minus");$$=make_node<OperatorNode>(@$, "-");}
	;
	
%%

yy::parser::symbol_type yylex(yyscan_t lexer) {
	yy::parser::symbol_type s;
	int x = yylex(&s, nullptr, lexer);
	assert(x == 1);
	return s;
}

void yy::parser::error(location_type const& loc, std::string const& msg) {
	std::cout << "[error] parser error at " << loc << ": " << msg << ".\n";
}

template <typename T, typename... Args> static std::unique_ptr<T> make_node(yy::parser::location_type const& loc, Args&&... args) {
	std::unique_ptr<T> n = std::make_unique<T>(std::forward<Args>(args)...);
	n->location = loc;
	return n;
}
