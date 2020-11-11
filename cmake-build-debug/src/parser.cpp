// A Bison parser, made by GNU Bison 3.6.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 19 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"


// this will be added to your parser.cpp file

#include "lexer.hpp"

static yy::parser::symbol_type yylex(yyscan_t);

template <typename T, typename... Args> static std::unique_ptr<T> make_node(yy::parser::location_type const&, Args&&...);

#define SHOWPARSE true
#define TRACEPARSE(x) if (SHOWPARSE) printf("%s\n", x)


#line 61 "parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 153 "parser.cpp"

  /// Build a parser object.
  parser::parser (yyscan_t lexer_yyarg, std::unique_ptr<Node>& root_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      lexer (lexer_yyarg),
      root (root_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case 3: // HI
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 47: // root
        value.YY_MOVE_OR_COPY< std::unique_ptr<Node> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case 3: // HI
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 47: // root
        value.move< std::unique_ptr<Node> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case 3: // HI
        value.copy< std::string > (that.value);
        break;

      case 47: // root
        value.copy< std::unique_ptr<Node> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case 3: // HI
        value.move< std::string > (that.value);
        break;

      case 47: // root
        value.move< std::unique_ptr<Node> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YYUSE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (lexer));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 3: // HI
        yylhs.value.emplace< std::string > ();
        break;

      case 47: // root
        yylhs.value.emplace< std::unique_ptr<Node> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 99 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                      { yylhs.value.as < std::unique_ptr<Node> > () = nullptr; TRACEPARSE("root->function_list");}
#line 588 "parser.cpp"
    break;

  case 3:
#line 101 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                {TRACEPARSE("function_list->function_plus");}
#line 594 "parser.cpp"
    break;

  case 4:
#line 103 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                        {TRACEPARSE("function_plus->function");}
#line 600 "parser.cpp"
    break;

  case 5:
#line 104 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                        {TRACEPARSE("function_plus->function function_plus");}
#line 606 "parser.cpp"
    break;

  case 6:
#line 106 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                        {TRACEPARSE("function->function_decl TOK_semicolon");}
#line 612 "parser.cpp"
    break;

  case 7:
#line 107 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                {TRACEPARSE("function->function_decl");}
#line 618 "parser.cpp"
    break;

  case 8:
#line 109 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                               {TRACEPARSE("function_decl->type name TOK_lparen parameter_list TOK_rparen");}
#line 624 "parser.cpp"
    break;

  case 9:
#line 111 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                                {TRACEPARSE("function_defn->function_decl block	");}
#line 630 "parser.cpp"
    break;

  case 10:
#line 113 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                        {TRACEPARSE("type->TOK_identifier");}
#line 636 "parser.cpp"
    break;

  case 11:
#line 115 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                        {TRACEPARSE("name->TOK_identifier");}
#line 642 "parser.cpp"
    break;

  case 12:
#line 117 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                {TRACEPARSE("parameter_list->declaration comma_dec_kleene");}
#line 648 "parser.cpp"
    break;

  case 13:
#line 118 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                        {TRACEPARSE("parameter_list->/*empty*/");}
#line 654 "parser.cpp"
    break;

  case 14:
#line 120 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                         {TRACEPARSE("comma_dec_kleene->TOK_comma declaration comma_dec_kleene ");}
#line 660 "parser.cpp"
    break;

  case 15:
#line 121 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                                         {TRACEPARSE("comma_dec_kleene->/*empty*/");}
#line 666 "parser.cpp"
    break;

  case 16:
#line 123 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                {TRACEPARSE("block->TOK_lbrace suite TOK_rbrace");}
#line 672 "parser.cpp"
    break;

  case 17:
#line 125 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                        {TRACEPARSE("suite->statement_kleene");}
#line 678 "parser.cpp"
    break;

  case 18:
#line 127 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                        {TRACEPARSE("statement_kleene->statement statement_kleene");}
#line 684 "parser.cpp"
    break;

  case 19:
#line 128 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                        {TRACEPARSE("statement_kleene->/*empty*/");}
#line 690 "parser.cpp"
    break;

  case 20:
#line 130 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                        {TRACEPARSE("declaration->type name");}
#line 696 "parser.cpp"
    break;

  case 21:
#line 133 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                        {TRACEPARSE("statement->single_statement TOK_semicolon");}
#line 702 "parser.cpp"
    break;

  case 22:
#line 134 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                {TRACEPARSE("statement->compound_statement");}
#line 708 "parser.cpp"
    break;

  case 23:
#line 137 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                {TRACEPARSE("single_statement->declaration TOK_assign expression");}
#line 714 "parser.cpp"
    break;

  case 24:
#line 138 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                        {TRACEPARSE("single_statement->name TOK_assign expression");}
#line 720 "parser.cpp"
    break;

  case 25:
#line 139 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                        {TRACEPARSE("single_statement->name binary_op expression");}
#line 726 "parser.cpp"
    break;

  case 26:
#line 140 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                                        {TRACEPARSE("single_statement->TOK_break");}
#line 732 "parser.cpp"
    break;

  case 27:
#line 141 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                                {TRACEPARSE("single_statement->TOK_continue");}
#line 738 "parser.cpp"
    break;

  case 28:
#line 142 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                {TRACEPARSE("single_statement->TOK_return expression_question");}
#line 744 "parser.cpp"
    break;

  case 29:
#line 143 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                                        {TRACEPARSE("single_statement->expression");}
#line 750 "parser.cpp"
    break;

  case 30:
#line 146 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                {TRACEPARSE("expression_question->expression");}
#line 756 "parser.cpp"
    break;

  case 31:
#line 147 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                                        {TRACEPARSE("expression_question->/*empty*/");}
#line 762 "parser.cpp"
    break;

  case 32:
#line 153 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                                        {TRACEPARSE("expression->TOK_true");}
#line 768 "parser.cpp"
    break;

  case 33:
#line 154 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                                        {TRACEPARSE("expression->TOK_false");}
#line 774 "parser.cpp"
    break;

  case 34:
#line 155 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                                        {TRACEPARSE("expression->TOK_integer");}
#line 780 "parser.cpp"
    break;

  case 35:
#line 156 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                                        {TRACEPARSE("expression->TOK_float");}
#line 786 "parser.cpp"
    break;

  case 36:
#line 157 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                                {TRACEPARSE("expression->binary_expression");}
#line 792 "parser.cpp"
    break;

  case 37:
#line 158 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                                {TRACEPARSE("expression->unary_expression");}
#line 798 "parser.cpp"
    break;

  case 38:
#line 159 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                        {TRACEPARSE("expression->relational_expression");}
#line 804 "parser.cpp"
    break;

  case 39:
#line 160 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                                {TRACEPARSE("expression->ternary_expression");}
#line 810 "parser.cpp"
    break;

  case 40:
#line 161 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                                {TRACEPARSE("expression->cast_expression");}
#line 816 "parser.cpp"
    break;

  case 41:
#line 162 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                                {TRACEPARSE("expression->function_call");}
#line 822 "parser.cpp"
    break;

  case 42:
#line 163 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                {TRACEPARSE("expression->TOK_lparen	expression TOK_rparen");}
#line 828 "parser.cpp"
    break;

  case 43:
#line 166 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                {TRACEPARSE("compound_statement->TOK_if	TOK_lparen	expression TOK_rparen	block");}
#line 834 "parser.cpp"
    break;

  case 44:
#line 168 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
        {TRACEPARSE("compound_statement->TOK_for	TOK_lparen single_statement_question TOK_semicolon expression_question TOK_semicolon single_statement_question TOK_rparen block");}
#line 840 "parser.cpp"
    break;

  case 45:
#line 169 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                {TRACEPARSE("compound_statement->TOK_while	TOK_lparen	expression TOK_rparen block");}
#line 846 "parser.cpp"
    break;

  case 46:
#line 172 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                        {TRACEPARSE("single_statement_question->single_statement");}
#line 852 "parser.cpp"
    break;

  case 47:
#line 173 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                        {TRACEPARSE("single_statement->/*empty*/");}
#line 858 "parser.cpp"
    break;

  case 48:
#line 176 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                        {TRACEPARSE("binary_expression->expression binary_op expression");}
#line 864 "parser.cpp"
    break;

  case 49:
#line 179 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                        {TRACEPARSE("unary_expression->unary_op expression %prec TOK_unop");}
#line 870 "parser.cpp"
    break;

  case 50:
#line 182 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                                {TRACEPARSE("relational_expression->expression relational_op expression");}
#line 876 "parser.cpp"
    break;

  case 51:
#line 185 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                {TRACEPARSE("binary_op->TOK_plus");}
#line 882 "parser.cpp"
    break;

  case 52:
#line 186 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                {TRACEPARSE("binary_op->TOK_minus");}
#line 888 "parser.cpp"
    break;

  case 53:
#line 187 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                {TRACEPARSE("binary_op->TOK_star");}
#line 894 "parser.cpp"
    break;

  case 54:
#line 188 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                {TRACEPARSE("binary_op->TOK_slash");}
#line 900 "parser.cpp"
    break;

  case 55:
#line 189 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                {TRACEPARSE("binary_op->TOK_log_and");}
#line 906 "parser.cpp"
    break;

  case 56:
#line 190 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                {TRACEPARSE("binary_op->TOK_log_or");}
#line 912 "parser.cpp"
    break;

  case 57:
#line 193 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                {TRACEPARSE("unary_op->TOK_minus");}
#line 918 "parser.cpp"
    break;

  case 58:
#line 196 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                        {TRACEPARSE("relational_op->TOK_eq");}
#line 924 "parser.cpp"
    break;

  case 59:
#line 197 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                        {TRACEPARSE("relational_op->TOK_ne");}
#line 930 "parser.cpp"
    break;

  case 60:
#line 198 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                        {TRACEPARSE("relational_op->TOK_lt");}
#line 936 "parser.cpp"
    break;

  case 61:
#line 199 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                        {TRACEPARSE("relational_op->TOK_gt");}
#line 942 "parser.cpp"
    break;

  case 62:
#line 200 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                        {TRACEPARSE("relational_op->TOK_le");}
#line 948 "parser.cpp"
    break;

  case 63:
#line 201 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                        {TRACEPARSE("relational_op->TOK_ge");}
#line 954 "parser.cpp"
    break;

  case 64:
#line 204 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
{TRACEPARSE("ternary_expression->expression TOK_question_mark expression TOK_colon expression");}
#line 960 "parser.cpp"
    break;

  case 65:
#line 206 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                                        {TRACEPARSE("cast_expression->TOK_lparen	type TOK_rparen	expression");}
#line 966 "parser.cpp"
    break;

  case 66:
#line 208 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                                {TRACEPARSE("function_call->name TOK_lparen _ece TOK_rparen");}
#line 972 "parser.cpp"
    break;

  case 67:
#line 211 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                {TRACEPARSE("_ece->expression _ecee");}
#line 978 "parser.cpp"
    break;

  case 68:
#line 212 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                {TRACEPARSE("_ece->/*empty*/");}
#line 984 "parser.cpp"
    break;

  case 69:
#line 214 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                        {TRACEPARSE("_ecee->TOK_comma expression _ecee");}
#line 990 "parser.cpp"
    break;

  case 70:
#line 215 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"
                                {TRACEPARSE("_ecee->/*empty*/");}
#line 996 "parser.cpp"
    break;


#line 1000 "parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0





  const signed char parser::yypact_ninf_ = -91;

  const signed char parser::yytable_ninf_ = -11;

  const short
  parser::yypact_[] =
  {
       0,   -91,    13,   -91,   -91,     0,    -6,   -91,     5,   -91,
     -91,    64,   -91,   -91,   -91,     4,    18,   -91,   -91,   -91,
     -91,   230,   -91,    12,    20,    24,   -91,   -91,   240,     5,
      76,    22,   -91,     1,    64,     3,   209,   -91,   -91,   -91,
     -91,   240,   -91,   -91,   -91,     0,    31,    34,    99,   240,
     240,    10,   -91,   209,   -91,   240,   -91,   -91,   -91,   -91,
     -91,   -91,   240,   240,   -91,   240,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   240,   240,   240,   -91,    36,    17,
     240,   -91,   121,   143,   -91,    21,   165,    39,   209,   209,
     209,   187,   -91,   -91,   -91,     0,   -91,   -91,    41,    41,
     240,   240,   -91,   -91,   240,    17,   -91,   -91,    23,   165,
     209,   -91,    10,   -91,    40,    41,   -91
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    10,     0,     2,     3,     4,     0,     7,     0,     1,
       5,    19,     6,     9,    11,     0,    11,    34,    35,    32,
      33,     0,    57,     0,     0,     0,    26,    27,    31,     0,
       0,     0,    17,     0,    19,     0,    29,    22,    36,    37,
      38,     0,    39,    40,    41,    13,     0,     0,     0,     0,
       0,    47,    28,    30,    20,    68,    51,    52,    53,    54,
      55,    56,     0,     0,    16,     0,    18,    21,    58,    59,
      60,    61,    62,    63,     0,     0,     0,    49,     0,    15,
       0,    42,     0,     0,    46,     0,    70,     0,    24,    25,
      23,     0,    48,    50,     8,     0,    12,    65,     0,     0,
      31,     0,    67,    66,     0,    15,    43,    45,     0,    70,
      64,    14,    47,    69,     0,     0,    44
  };

  const signed char
  parser::yypgoto_[] =
  {
     -91,   -91,   -91,    50,   -91,   -91,   -91,     7,    -8,   -91,
     -45,   -90,   -91,    27,   -43,   -91,   -50,   -36,   -17,   -91,
     -47,   -91,   -91,   -91,    37,   -91,   -91,   -91,   -91,   -91,
     -91,   -41
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,     5,     6,     7,    29,    47,    78,
      96,    13,    31,    32,    33,    34,    35,    52,    36,    37,
      85,    38,    39,    40,    75,    41,    76,    42,    43,    44,
      87,   102
  };

  const signed char
  parser::yytable_[] =
  {
      15,    84,    79,    30,    48,     1,    11,     8,   106,   107,
      14,    53,     8,     9,    45,    16,    17,    18,    19,    20,
      21,    54,    49,   -10,    77,   116,    30,    12,    46,   -10,
      50,    22,    82,    83,    51,    64,    67,    65,    86,    26,
      27,    28,    80,    30,    55,    88,    89,    94,    90,    95,
     103,   115,   105,    11,   100,    10,   112,    91,    92,    93,
     111,    66,    84,    97,   108,   114,     0,    63,   113,    16,
      17,    18,    19,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,    53,   109,    22,    55,   110,     0,     0,
      23,    24,    25,    26,    27,    28,    56,    57,    58,    59,
      60,    61,     0,     0,    30,     0,     0,     0,     0,     0,
      81,     0,    62,    68,    69,    70,    71,    72,    73,    56,
      57,    58,    59,    60,    61,     0,     0,     0,     0,     0,
       0,     0,    98,     0,    74,    68,    69,    70,    71,    72,
      73,    56,    57,    58,    59,    60,    61,     0,     0,     0,
       0,     0,     0,     0,    99,     0,    74,    68,    69,    70,
      71,    72,    73,    56,    57,    58,    59,    60,    61,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,    68,
      69,    70,    71,    72,    73,    56,    57,    58,    59,    60,
      61,     0,     0,     0,     0,     0,     0,   101,     0,     0,
      74,    68,    69,    70,    71,    72,    73,    56,    57,    58,
      59,    60,    61,     0,     0,     0,     0,     0,     0,     0,
       0,   104,    74,    68,    69,    70,    71,    72,    73,    56,
      57,    58,    59,    60,    61,    16,    17,    18,    19,    20,
      21,     0,     0,     0,    74,    14,    17,    18,    19,    20,
      21,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22
  };

  const signed char
  parser::yycheck_[] =
  {
       8,    51,    45,    11,    21,     5,    12,     0,    98,    99,
       5,    28,     5,     0,    10,     5,     6,     7,     8,     9,
      10,    29,    10,     5,    41,   115,    34,    33,    21,    11,
      10,    21,    49,    50,    10,    13,    33,    36,    55,    29,
      30,    31,    11,    51,    10,    62,    63,    11,    65,    32,
      11,    11,    95,    12,    33,     5,    33,    74,    75,    76,
     105,    34,   112,    80,   100,   112,    -1,    30,   109,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   100,   101,    21,    10,   104,    -1,    -1,
      26,    27,    28,    29,    30,    31,    20,    21,    22,    23,
      24,    25,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,
      11,    -1,    36,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    -1,    35,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    11,    -1,    35,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      35,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,     5,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    35,     5,     6,     7,     8,     9,
      10,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21
  };

  const signed char
  parser::yystos_[] =
  {
       0,     5,    47,    48,    49,    50,    51,    52,    53,     0,
      49,    12,    33,    57,     5,    54,     5,     6,     7,     8,
       9,    10,    21,    26,    27,    28,    29,    30,    31,    53,
      54,    58,    59,    60,    61,    62,    64,    65,    67,    68,
      69,    71,    73,    74,    75,    10,    53,    54,    64,    10,
      10,    10,    63,    64,    54,    10,    20,    21,    22,    23,
      24,    25,    36,    70,    13,    36,    59,    33,    14,    15,
      16,    17,    18,    19,    35,    70,    72,    64,    55,    60,
      11,    11,    64,    64,    62,    66,    64,    76,    64,    64,
      64,    64,    64,    64,    11,    32,    56,    64,    11,    11,
      33,    32,    77,    11,    34,    60,    57,    57,    63,    64,
      64,    56,    33,    77,    66,    11,    57
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    46,    47,    48,    49,    49,    50,    50,    51,    52,
      53,    54,    55,    55,    56,    56,    57,    58,    59,    59,
      60,    61,    61,    62,    62,    62,    62,    62,    62,    62,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    65,    66,    66,    67,    68,
      69,    70,    70,    70,    70,    70,    70,    71,    72,    72,
      72,    72,    72,    72,    73,    74,    75,    76,    76,    77,
      77
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     2,     2,     1,     5,     2,
       1,     1,     2,     0,     3,     0,     3,     1,     2,     0,
       2,     2,     1,     3,     3,     3,     1,     1,     2,     1,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     5,     9,     5,     1,     0,     3,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     4,     2,     0,     3,
       0
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "HI", "BYE",
  "TOK_identifier", "TOK_integer", "TOK_float", "TOK_true", "TOK_false",
  "TOK_lparen", "TOK_rparen", "TOK_lbrace", "TOK_rbrace", "TOK_eq",
  "TOK_ne", "TOK_lt", "TOK_gt", "TOK_le", "TOK_ge", "TOK_plus",
  "TOK_minus", "TOK_star", "TOK_slash", "TOK_log_and", "TOK_log_or",
  "TOK_if", "TOK_while", "TOK_for", "TOK_break", "TOK_continue",
  "TOK_return", "TOK_comma", "TOK_semicolon", "TOK_colon",
  "TOK_question_mark", "TOK_assign", "TOK_plus_assign", "TOK_minus_assign",
  "TOK_star_assign", "TOK_slash_assign", "TOK_type", "TOK_relop",
  "TOK_binop", "TOK_unop", "TOK_uminus", "$accept", "root",
  "function_list", "function_plus", "function", "function_decl",
  "function_defn", "type", "name", "parameter_list", "comma_dec_kleene",
  "block", "suite", "statement_kleene", "declaration", "statement",
  "single_statement", "expression_question", "expression",
  "compound_statement", "single_statement_question", "binary_expression",
  "unary_expression", "relational_expression", "binary_op", "unary_op",
  "relational_op", "ternary_expression", "cast_expression",
  "function_call", "_ece", "_ecee", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    99,    99,   101,   103,   104,   106,   107,   109,   111,
     113,   115,   117,   118,   120,   121,   123,   125,   127,   128,
     130,   133,   134,   137,   138,   139,   140,   141,   142,   143,
     146,   147,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   166,   167,   169,   172,   173,   176,   179,
     182,   185,   186,   187,   188,   189,   190,   193,   196,   197,
     198,   199,   200,   201,   203,   206,   208,   211,   212,   214,
     215
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1424 "parser.cpp"

#line 217 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"


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
