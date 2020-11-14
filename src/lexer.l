%{

// this will be added to the top of your lexer.c file

#include "bridge.hpp"

#define GET_COLUMN() yyget_extra(yyscanner)
#define SET_COLUMN(x) yyset_extra((x), yyscanner)
#define INC_COLUMN(x) yyset_extra(GET_COLUMN() + (x), yyscanner)

#define LOC(x) (yy::parser::location_type { nullptr, yylineno, (x) })

#define TOK(t, x, ...) \
	make_symbol(yylval, yy::parser::make_ ##t (__VA_ARGS__ __VA_OPT__(,) LOC(x)))

#define yyterminate() return TOK(YYEOF, GET_COLUMN())

static int make_symbol(YYSTYPE*, YYSTYPE);

%}

/* see https://westes.github.io/flex/manual/Scanner-Options.html */

%option header-file="lexer.h"

%option yylineno
%option noyywrap

%option bison-bridge
%option bison-locations
%option reentrant
%option nounput
%option extra-type="int"

%option debug
%option nodefault
%option verbose
%option warn


%%
[\r\n]+ {SET_COLUMN(1);}
[ \t]+ {INC_COLUMN(yyleng);}

true {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_true, x, true);}
false {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_false, x, false);}

if {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_if,x);}
while {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_while,x);}
for {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_for,x);}
break {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_break,x);}
continue {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_continue,x);}
return {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_return,x);}

"+=" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_plus_assign,x);} 
"-=" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_minus_assign,x);}
"*=" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_star_assign,x);}
"/=" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_slash_assign,x);}

"int"|"float"|"bool"|"void" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_type,x, std::string{yytext, static_cast<size_t>(yyleng)});}

"(" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_lparen,x);}
")" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_rparen,x);}
"{" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_lbrace,x);}
"}" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_rbrace,x);}

"==" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_eq,x);}
"!=" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_ne,x);}
"<" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_lt,x);}
">" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_gt,x);}
"<=" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_le,x);}
">=" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_ge,x);}

"+" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_plus,x);}
"-" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_minus,x);}
"*" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_star,x);}
"/" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_slash,x);}

"&&" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_log_and,x);}
"||" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_log_or,x);}

"," {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_comma,x);}
";" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_semicolon,x);}
":" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_colon,x);}
"?" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_question_mark,x);}

"=" {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_assign,x);}

[a-zA-Z_][a-zA-Z0-9_]* {int x= GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_identifier, x, std::string{yytext, static_cast<size_t>(yyleng)});}

0|[1-9][0-9]* {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_integer, x, std::stoi(std::string{yytext, static_cast<size_t>(yyleng)}));}

(0|[1-9][0-9]*)\.[0-9]* {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_float, x, std::stof(std::string{yytext, static_cast<size_t>(yyleng)}));}
\.[0-9]+ {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_float, x, std::stof(std::string{yytext, static_cast<size_t>(yyleng)}));}
(0|[1-9][0-9]*)\.[0-9]*[eE][+-]?[1-9][0-9]* {int x = GET_COLUMN(); INC_COLUMN(yyleng); return TOK(TOK_float, x, std::stof(std::string{yytext, static_cast<size_t>(yyleng)}));}


. { printf("[error] invalid token.\n"); return TOK(YYUNDEF, GET_COLUMN()); }
<<EOF>> {yyterminate();}

%%

int make_symbol(YYSTYPE* val, YYSTYPE sym) {
	val->move(sym);
	return 1;
}