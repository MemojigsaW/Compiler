// A Bison parser, made by GNU Bison 3.6.4.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file /home/memojigsaw/ece467/ece467-1002654950/cmake-build-debug/src/parser.hpp
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_HOME_MEMOJIGSAW_ECE467_ECE467_1002654950_CMAKE_BUILD_DEBUG_SRC_PARSER_HPP_INCLUDED
# define YY_YY_HOME_MEMOJIGSAW_ECE467_ECE467_1002654950_CMAKE_BUILD_DEBUG_SRC_PARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 1 "/home/memojigsaw/ece467/ece467-1002654950/src/parser.y"


// this will be added to your parser.hpp file

#ifndef YY_TYPEDEF_YY_SCANNER_T
#define YY_TYPEDEF_YY_SCANNER_T
typedef void* yyscan_t;
#endif

#include "nodes.hpp"
#include <memory>

class Node;




#line 67 "/home/memojigsaw/ece467/ece467-1002654950/cmake-build-debug/src/parser.hpp"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 201 "/home/memojigsaw/ece467/ece467-1002654950/cmake-build-debug/src/parser.hpp"




  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    semantic_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    semantic_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // HI
      char dummy1[sizeof (std::string)];

      // root
      char dummy2[sizeof (std::unique_ptr<Node>)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    HI = 258,                      // HI
    BYE = 259,                     // BYE
    TOK_identifier = 260,          // TOK_identifier
    TOK_integer = 261,             // TOK_integer
    TOK_float = 262,               // TOK_float
    TOK_true = 263,                // TOK_true
    TOK_false = 264,               // TOK_false
    TOK_lparen = 265,              // TOK_lparen
    TOK_rparen = 266,              // TOK_rparen
    TOK_lbrace = 267,              // TOK_lbrace
    TOK_rbrace = 268,              // TOK_rbrace
    TOK_eq = 269,                  // TOK_eq
    TOK_ne = 270,                  // TOK_ne
    TOK_lt = 271,                  // TOK_lt
    TOK_gt = 272,                  // TOK_gt
    TOK_le = 273,                  // TOK_le
    TOK_ge = 274,                  // TOK_ge
    TOK_plus = 275,                // TOK_plus
    TOK_minus = 276,               // TOK_minus
    TOK_star = 277,                // TOK_star
    TOK_slash = 278,               // TOK_slash
    TOK_log_and = 279,             // TOK_log_and
    TOK_log_or = 280,              // TOK_log_or
    TOK_if = 281,                  // TOK_if
    TOK_while = 282,               // TOK_while
    TOK_for = 283,                 // TOK_for
    TOK_break = 284,               // TOK_break
    TOK_continue = 285,            // TOK_continue
    TOK_return = 286,              // TOK_return
    TOK_comma = 287,               // TOK_comma
    TOK_semicolon = 288,           // TOK_semicolon
    TOK_colon = 289,               // TOK_colon
    TOK_question_mark = 290,       // TOK_question_mark
    TOK_assign = 291,              // TOK_assign
    TOK_plus_assign = 292,         // TOK_plus_assign
    TOK_minus_assign = 293,        // TOK_minus_assign
    TOK_star_assign = 294,         // TOK_star_assign
    TOK_slash_assign = 295,        // TOK_slash_assign
    TOK_type = 296,                // TOK_type
    TOK_relop = 297,               // TOK_relop
    TOK_binop = 298,               // TOK_binop
    TOK_unop = 299,                // TOK_unop
    TOK_uminus = 300               // TOK_uminus
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 46, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_HI = 3,                                // HI
        S_BYE = 4,                               // BYE
        S_TOK_identifier = 5,                    // TOK_identifier
        S_TOK_integer = 6,                       // TOK_integer
        S_TOK_float = 7,                         // TOK_float
        S_TOK_true = 8,                          // TOK_true
        S_TOK_false = 9,                         // TOK_false
        S_TOK_lparen = 10,                       // TOK_lparen
        S_TOK_rparen = 11,                       // TOK_rparen
        S_TOK_lbrace = 12,                       // TOK_lbrace
        S_TOK_rbrace = 13,                       // TOK_rbrace
        S_TOK_eq = 14,                           // TOK_eq
        S_TOK_ne = 15,                           // TOK_ne
        S_TOK_lt = 16,                           // TOK_lt
        S_TOK_gt = 17,                           // TOK_gt
        S_TOK_le = 18,                           // TOK_le
        S_TOK_ge = 19,                           // TOK_ge
        S_TOK_plus = 20,                         // TOK_plus
        S_TOK_minus = 21,                        // TOK_minus
        S_TOK_star = 22,                         // TOK_star
        S_TOK_slash = 23,                        // TOK_slash
        S_TOK_log_and = 24,                      // TOK_log_and
        S_TOK_log_or = 25,                       // TOK_log_or
        S_TOK_if = 26,                           // TOK_if
        S_TOK_while = 27,                        // TOK_while
        S_TOK_for = 28,                          // TOK_for
        S_TOK_break = 29,                        // TOK_break
        S_TOK_continue = 30,                     // TOK_continue
        S_TOK_return = 31,                       // TOK_return
        S_TOK_comma = 32,                        // TOK_comma
        S_TOK_semicolon = 33,                    // TOK_semicolon
        S_TOK_colon = 34,                        // TOK_colon
        S_TOK_question_mark = 35,                // TOK_question_mark
        S_TOK_assign = 36,                       // TOK_assign
        S_TOK_plus_assign = 37,                  // TOK_plus_assign
        S_TOK_minus_assign = 38,                 // TOK_minus_assign
        S_TOK_star_assign = 39,                  // TOK_star_assign
        S_TOK_slash_assign = 40,                 // TOK_slash_assign
        S_TOK_type = 41,                         // TOK_type
        S_TOK_relop = 42,                        // TOK_relop
        S_TOK_binop = 43,                        // TOK_binop
        S_TOK_unop = 44,                         // TOK_unop
        S_TOK_uminus = 45,                       // TOK_uminus
        S_YYACCEPT = 46,                         // $accept
        S_root = 47,                             // root
        S_function_list = 48,                    // function_list
        S_function_plus = 49,                    // function_plus
        S_function = 50,                         // function
        S_function_decl = 51,                    // function_decl
        S_function_defn = 52,                    // function_defn
        S_type = 53,                             // type
        S_name = 54,                             // name
        S_parameter_list = 55,                   // parameter_list
        S_comma_dec_kleene = 56,                 // comma_dec_kleene
        S_block = 57,                            // block
        S_suite = 58,                            // suite
        S_statement_kleene = 59,                 // statement_kleene
        S_declaration = 60,                      // declaration
        S_statement = 61,                        // statement
        S_single_statement = 62,                 // single_statement
        S_expression_question = 63,              // expression_question
        S_expression = 64,                       // expression
        S_compound_statement = 65,               // compound_statement
        S_single_statement_question = 66,        // single_statement_question
        S_binary_expression = 67,                // binary_expression
        S_unary_expression = 68,                 // unary_expression
        S_relational_expression = 69,            // relational_expression
        S_binary_op = 70,                        // binary_op
        S_unary_op = 71,                         // unary_op
        S_relational_op = 72,                    // relational_op
        S_ternary_expression = 73,               // ternary_expression
        S_cast_expression = 74,                  // cast_expression
        S_function_call = 75,                    // function_call
        S__ece = 76,                             // _ece
        S__ecee = 77                             // _ecee
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case 3: // HI
        value.move< std::string > (std::move (that.value));
        break;

      case 47: // root
        value.move< std::unique_ptr<Node> > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::unique_ptr<Node>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::unique_ptr<Node>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case 3: // HI
        value.template destroy< std::string > ();
        break;

      case 47: // root
        value.template destroy< std::unique_ptr<Node> > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if YYDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }
#endif // #if YYDEBUG || 0


      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YY_ASSERT (tok == token::YYEOF || tok == token::YYerror || tok == token::YYUNDEF || tok == token::BYE || tok == token::TOK_identifier || tok == token::TOK_integer || tok == token::TOK_float || tok == token::TOK_true || tok == token::TOK_false || tok == token::TOK_lparen || tok == token::TOK_rparen || tok == token::TOK_lbrace || tok == token::TOK_rbrace || tok == token::TOK_eq || tok == token::TOK_ne || tok == token::TOK_lt || tok == token::TOK_gt || tok == token::TOK_le || tok == token::TOK_ge || tok == token::TOK_plus || tok == token::TOK_minus || tok == token::TOK_star || tok == token::TOK_slash || tok == token::TOK_log_and || tok == token::TOK_log_or || tok == token::TOK_if || tok == token::TOK_while || tok == token::TOK_for || tok == token::TOK_break || tok == token::TOK_continue || tok == token::TOK_return || tok == token::TOK_comma || tok == token::TOK_semicolon || tok == token::TOK_colon || tok == token::TOK_question_mark || tok == token::TOK_assign || tok == token::TOK_plus_assign || tok == token::TOK_minus_assign || tok == token::TOK_star_assign || tok == token::TOK_slash_assign || tok == token::TOK_type || tok == token::TOK_relop || tok == token::TOK_binop || tok == token::TOK_unop || tok == token::TOK_uminus);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YY_ASSERT (tok == token::YYEOF || tok == token::YYerror || tok == token::YYUNDEF || tok == token::BYE || tok == token::TOK_identifier || tok == token::TOK_integer || tok == token::TOK_float || tok == token::TOK_true || tok == token::TOK_false || tok == token::TOK_lparen || tok == token::TOK_rparen || tok == token::TOK_lbrace || tok == token::TOK_rbrace || tok == token::TOK_eq || tok == token::TOK_ne || tok == token::TOK_lt || tok == token::TOK_gt || tok == token::TOK_le || tok == token::TOK_ge || tok == token::TOK_plus || tok == token::TOK_minus || tok == token::TOK_star || tok == token::TOK_slash || tok == token::TOK_log_and || tok == token::TOK_log_or || tok == token::TOK_if || tok == token::TOK_while || tok == token::TOK_for || tok == token::TOK_break || tok == token::TOK_continue || tok == token::TOK_return || tok == token::TOK_comma || tok == token::TOK_semicolon || tok == token::TOK_colon || tok == token::TOK_question_mark || tok == token::TOK_assign || tok == token::TOK_plus_assign || tok == token::TOK_minus_assign || tok == token::TOK_star_assign || tok == token::TOK_slash_assign || tok == token::TOK_type || tok == token::TOK_relop || tok == token::TOK_binop || tok == token::TOK_unop || tok == token::TOK_uminus);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YY_ASSERT (tok == token::HI);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YY_ASSERT (tok == token::HI);
      }
#endif
    };

    /// Build a parser object.
    parser (yyscan_t lexer_yyarg, std::unique_ptr<Node>& root_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

#if YYDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if YYDEBUG || 0


    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF (location_type l)
      {
        return symbol_type (token::YYEOF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYEOF (const location_type& l)
      {
        return symbol_type (token::YYEOF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HI (std::string v, location_type l)
      {
        return symbol_type (token::HI, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_HI (const std::string& v, const location_type& l)
      {
        return symbol_type (token::HI, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BYE (location_type l)
      {
        return symbol_type (token::BYE, std::move (l));
      }
#else
      static
      symbol_type
      make_BYE (const location_type& l)
      {
        return symbol_type (token::BYE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_identifier (location_type l)
      {
        return symbol_type (token::TOK_identifier, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_identifier (const location_type& l)
      {
        return symbol_type (token::TOK_identifier, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_integer (location_type l)
      {
        return symbol_type (token::TOK_integer, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_integer (const location_type& l)
      {
        return symbol_type (token::TOK_integer, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_float (location_type l)
      {
        return symbol_type (token::TOK_float, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_float (const location_type& l)
      {
        return symbol_type (token::TOK_float, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_true (location_type l)
      {
        return symbol_type (token::TOK_true, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_true (const location_type& l)
      {
        return symbol_type (token::TOK_true, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_false (location_type l)
      {
        return symbol_type (token::TOK_false, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_false (const location_type& l)
      {
        return symbol_type (token::TOK_false, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_lparen (location_type l)
      {
        return symbol_type (token::TOK_lparen, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_lparen (const location_type& l)
      {
        return symbol_type (token::TOK_lparen, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_rparen (location_type l)
      {
        return symbol_type (token::TOK_rparen, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_rparen (const location_type& l)
      {
        return symbol_type (token::TOK_rparen, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_lbrace (location_type l)
      {
        return symbol_type (token::TOK_lbrace, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_lbrace (const location_type& l)
      {
        return symbol_type (token::TOK_lbrace, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_rbrace (location_type l)
      {
        return symbol_type (token::TOK_rbrace, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_rbrace (const location_type& l)
      {
        return symbol_type (token::TOK_rbrace, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_eq (location_type l)
      {
        return symbol_type (token::TOK_eq, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_eq (const location_type& l)
      {
        return symbol_type (token::TOK_eq, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_ne (location_type l)
      {
        return symbol_type (token::TOK_ne, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_ne (const location_type& l)
      {
        return symbol_type (token::TOK_ne, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_lt (location_type l)
      {
        return symbol_type (token::TOK_lt, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_lt (const location_type& l)
      {
        return symbol_type (token::TOK_lt, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_gt (location_type l)
      {
        return symbol_type (token::TOK_gt, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_gt (const location_type& l)
      {
        return symbol_type (token::TOK_gt, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_le (location_type l)
      {
        return symbol_type (token::TOK_le, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_le (const location_type& l)
      {
        return symbol_type (token::TOK_le, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_ge (location_type l)
      {
        return symbol_type (token::TOK_ge, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_ge (const location_type& l)
      {
        return symbol_type (token::TOK_ge, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_plus (location_type l)
      {
        return symbol_type (token::TOK_plus, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_plus (const location_type& l)
      {
        return symbol_type (token::TOK_plus, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_minus (location_type l)
      {
        return symbol_type (token::TOK_minus, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_minus (const location_type& l)
      {
        return symbol_type (token::TOK_minus, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_star (location_type l)
      {
        return symbol_type (token::TOK_star, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_star (const location_type& l)
      {
        return symbol_type (token::TOK_star, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_slash (location_type l)
      {
        return symbol_type (token::TOK_slash, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_slash (const location_type& l)
      {
        return symbol_type (token::TOK_slash, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_log_and (location_type l)
      {
        return symbol_type (token::TOK_log_and, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_log_and (const location_type& l)
      {
        return symbol_type (token::TOK_log_and, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_log_or (location_type l)
      {
        return symbol_type (token::TOK_log_or, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_log_or (const location_type& l)
      {
        return symbol_type (token::TOK_log_or, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_if (location_type l)
      {
        return symbol_type (token::TOK_if, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_if (const location_type& l)
      {
        return symbol_type (token::TOK_if, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_while (location_type l)
      {
        return symbol_type (token::TOK_while, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_while (const location_type& l)
      {
        return symbol_type (token::TOK_while, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_for (location_type l)
      {
        return symbol_type (token::TOK_for, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_for (const location_type& l)
      {
        return symbol_type (token::TOK_for, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_break (location_type l)
      {
        return symbol_type (token::TOK_break, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_break (const location_type& l)
      {
        return symbol_type (token::TOK_break, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_continue (location_type l)
      {
        return symbol_type (token::TOK_continue, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_continue (const location_type& l)
      {
        return symbol_type (token::TOK_continue, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_return (location_type l)
      {
        return symbol_type (token::TOK_return, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_return (const location_type& l)
      {
        return symbol_type (token::TOK_return, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_comma (location_type l)
      {
        return symbol_type (token::TOK_comma, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_comma (const location_type& l)
      {
        return symbol_type (token::TOK_comma, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_semicolon (location_type l)
      {
        return symbol_type (token::TOK_semicolon, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_semicolon (const location_type& l)
      {
        return symbol_type (token::TOK_semicolon, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_colon (location_type l)
      {
        return symbol_type (token::TOK_colon, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_colon (const location_type& l)
      {
        return symbol_type (token::TOK_colon, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_question_mark (location_type l)
      {
        return symbol_type (token::TOK_question_mark, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_question_mark (const location_type& l)
      {
        return symbol_type (token::TOK_question_mark, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_assign (location_type l)
      {
        return symbol_type (token::TOK_assign, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_assign (const location_type& l)
      {
        return symbol_type (token::TOK_assign, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_plus_assign (location_type l)
      {
        return symbol_type (token::TOK_plus_assign, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_plus_assign (const location_type& l)
      {
        return symbol_type (token::TOK_plus_assign, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_minus_assign (location_type l)
      {
        return symbol_type (token::TOK_minus_assign, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_minus_assign (const location_type& l)
      {
        return symbol_type (token::TOK_minus_assign, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_star_assign (location_type l)
      {
        return symbol_type (token::TOK_star_assign, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_star_assign (const location_type& l)
      {
        return symbol_type (token::TOK_star_assign, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_slash_assign (location_type l)
      {
        return symbol_type (token::TOK_slash_assign, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_slash_assign (const location_type& l)
      {
        return symbol_type (token::TOK_slash_assign, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_type (location_type l)
      {
        return symbol_type (token::TOK_type, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_type (const location_type& l)
      {
        return symbol_type (token::TOK_type, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_relop (location_type l)
      {
        return symbol_type (token::TOK_relop, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_relop (const location_type& l)
      {
        return symbol_type (token::TOK_relop, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_binop (location_type l)
      {
        return symbol_type (token::TOK_binop, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_binop (const location_type& l)
      {
        return symbol_type (token::TOK_binop, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_unop (location_type l)
      {
        return symbol_type (token::TOK_unop, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_unop (const location_type& l)
      {
        return symbol_type (token::TOK_unop, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TOK_uminus (location_type l)
      {
        return symbol_type (token::TOK_uminus, std::move (l));
      }
#else
      static
      symbol_type
      make_TOK_uminus (const location_type& l)
      {
        return symbol_type (token::TOK_uminus, l);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef signed char state_type;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);

#if YYDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if YYDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yylast_ = 267,     ///< Last index in yytable_.
      yynnts_ = 32,  ///< Number of nonterminal symbols.
      yyfinal_ = 9 ///< Termination state number.
    };


    // User arguments.
    yyscan_t lexer;
    std::unique_ptr<Node>& root;

  };

  inline
  parser::symbol_kind_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
    };
    const int user_token_number_max_ = 300;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= user_token_number_max_)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case 3: // HI
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case 47: // root
        value.copy< std::unique_ptr<Node> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case 3: // HI
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case 47: // root
        value.move< std::unique_ptr<Node> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  inline
  void
  parser::by_kind::clear ()
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

} // yy
#line 2073 "/home/memojigsaw/ece467/ece467-1002654950/cmake-build-debug/src/parser.hpp"





#endif // !YY_YY_HOME_MEMOJIGSAW_ECE467_ECE467_1002654950_CMAKE_BUILD_DEBUG_SRC_PARSER_HPP_INCLUDED