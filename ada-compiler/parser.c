/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.bison"

  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include "ast.h"

  int yylex (void);
  void yyerror (char const *);

#line 81 "parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_INT = 3,                  /* TOKEN_INT  */
  YYSYMBOL_TOKEN_FLOAT = 4,                /* TOKEN_FLOAT  */
  YYSYMBOL_TOKEN_ID = 5,                   /* TOKEN_ID  */
  YYSYMBOL_TOKEN_STRING = 6,               /* TOKEN_STRING  */
  YYSYMBOL_TOKEN_PLUS = 7,                 /* TOKEN_PLUS  */
  YYSYMBOL_TOKEN_MINUS = 8,                /* TOKEN_MINUS  */
  YYSYMBOL_TOKEN_MULT = 9,                 /* TOKEN_MULT  */
  YYSYMBOL_TOKEN_DIV = 10,                 /* TOKEN_DIV  */
  YYSYMBOL_TOKEN_MOD = 11,                 /* TOKEN_MOD  */
  YYSYMBOL_TOKEN_EQUAL = 12,               /* TOKEN_EQUAL  */
  YYSYMBOL_TOKEN_DIFF = 13,                /* TOKEN_DIFF  */
  YYSYMBOL_TOKEN_LESS = 14,                /* TOKEN_LESS  */
  YYSYMBOL_TOKEN_GREATER = 15,             /* TOKEN_GREATER  */
  YYSYMBOL_TOKEN_LESS_EQUAL = 16,          /* TOKEN_LESS_EQUAL  */
  YYSYMBOL_TOKEN_GREATER_EQUAL = 17,       /* TOKEN_GREATER_EQUAL  */
  YYSYMBOL_TOKEN_AND = 18,                 /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 19,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_XOR = 20,                 /* TOKEN_XOR  */
  YYSYMBOL_TOKEN_NOT = 21,                 /* TOKEN_NOT  */
  YYSYMBOL_TOKEN_EOF = 22,                 /* TOKEN_EOF  */
  YYSYMBOL_TOKEN_ASSIGN = 23,              /* TOKEN_ASSIGN  */
  YYSYMBOL_TOKEN_SEMI = 24,                /* TOKEN_SEMI  */
  YYSYMBOL_TOKEN_COLON = 25,               /* TOKEN_COLON  */
  YYSYMBOL_TOKEN_DOT = 26,                 /* TOKEN_DOT  */
  YYSYMBOL_TOKEN_IF = 27,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_THEN = 28,                /* TOKEN_THEN  */
  YYSYMBOL_TOKEN_ELSE = 29,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_WHILE = 30,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_LOOP = 31,                /* TOKEN_LOOP  */
  YYSYMBOL_TOKEN_WITH = 32,                /* TOKEN_WITH  */
  YYSYMBOL_TOKEN_USE = 33,                 /* TOKEN_USE  */
  YYSYMBOL_TOKEN_PROC = 34,                /* TOKEN_PROC  */
  YYSYMBOL_TOKEN_IS = 35,                  /* TOKEN_IS  */
  YYSYMBOL_TOKEN_BEGIN = 36,               /* TOKEN_BEGIN  */
  YYSYMBOL_TOKEN_END = 37,                 /* TOKEN_END  */
  YYSYMBOL_TOKEN_LPAREN = 38,              /* TOKEN_LPAREN  */
  YYSYMBOL_TOKEN_RPAREN = 39,              /* TOKEN_RPAREN  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_program = 41,                   /* program  */
  YYSYMBOL_stm_list = 42,                  /* stm_list  */
  YYSYMBOL_stm = 43,                       /* stm  */
  YYSYMBOL_dclr_list = 44,                 /* dclr_list  */
  YYSYMBOL_dclr = 45,                      /* dclr  */
  YYSYMBOL_expr = 46,                      /* expr  */
  YYSYMBOL_arExpr = 47,                    /* arExpr  */
  YYSYMBOL_boolExpr = 48,                  /* boolExpr  */
  YYSYMBOL_pckg_list = 49,                 /* pckg_list  */
  YYSYMBOL_pckg = 50                       /* pckg  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   163

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  105

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    79,    79,    85,    88,    94,    97,   100,   103,   106,
     109,   112,   115,   121,   123,   126,   131,   134,   139,   142,
     145,   151,   154,   157,   160,   163,   166,   169,   172,   175,
     181,   184,   187,   190,   193,   196,   199,   202,   205,   208,
     211,   217,   220,   226
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_INT",
  "TOKEN_FLOAT", "TOKEN_ID", "TOKEN_STRING", "TOKEN_PLUS", "TOKEN_MINUS",
  "TOKEN_MULT", "TOKEN_DIV", "TOKEN_MOD", "TOKEN_EQUAL", "TOKEN_DIFF",
  "TOKEN_LESS", "TOKEN_GREATER", "TOKEN_LESS_EQUAL", "TOKEN_GREATER_EQUAL",
  "TOKEN_AND", "TOKEN_OR", "TOKEN_XOR", "TOKEN_NOT", "TOKEN_EOF",
  "TOKEN_ASSIGN", "TOKEN_SEMI", "TOKEN_COLON", "TOKEN_DOT", "TOKEN_IF",
  "TOKEN_THEN", "TOKEN_ELSE", "TOKEN_WHILE", "TOKEN_LOOP", "TOKEN_WITH",
  "TOKEN_USE", "TOKEN_PROC", "TOKEN_IS", "TOKEN_BEGIN", "TOKEN_END",
  "TOKEN_LPAREN", "TOKEN_RPAREN", "$accept", "program", "stm_list", "stm",
  "dclr_list", "dclr", "expr", "arExpr", "boolExpr", "pckg_list", "pckg", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-34)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     108,    48,    16,    16,    36,    36,    37,    55,   108,   -34,
      16,    16,   -34,   -34,   -34,   -34,    35,    35,    41,   136,
      -5,    43,   -34,    -8,   -34,    96,    45,   -34,   -34,    51,
      33,   136,   -34,    50,    64,   108,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,    35,    35,    35,
     108,   -34,    36,   -34,    83,   -34,    66,   -34,   -34,    65,
       6,    40,    40,   -34,   -34,   -34,   147,   147,   147,   147,
     147,   147,   -34,    73,    73,    74,   -34,    75,     7,   -34,
     -34,   108,    78,   122,    79,   112,   108,   -34,    82,   102,
     103,   -18,    91,   107,   -34,   -34,    16,   -34,   131,   113,
     115,   135,   -34,   -34,   -34
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     0,    22,    23,    21,    20,     0,     0,     0,    18,
      19,     0,    43,     0,    41,     0,     0,     1,     4,     0,
       0,     0,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,     0,    10,    13,     5,     0,    24,    30,     0,
       0,    25,    26,    27,    28,    29,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     0,    42,     0,     0,    14,
      12,     0,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,     0,     0,     6,     8,     0,    16,     0,     0,
       0,     0,     7,    17,    11
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -34,   -34,   -33,    -7,   -34,    84,    -3,   -13,    29,   155,
     111
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9,    78,    79,    18,    19,    20,    23,
      24
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      21,    28,    59,    31,    33,    96,    97,    29,    30,    12,
      13,    14,    77,    47,    48,    49,    51,    75,    52,    12,
      13,    14,    15,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    31,    31,    31,    16,    12,    13,
      14,    22,    26,    86,    60,    32,    34,    83,    88,    38,
      39,    40,    28,    92,    17,    27,    16,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    28,    35,
       1,    10,    56,    17,    50,    55,    72,    73,    74,     1,
      54,    28,    47,    48,    49,    28,    11,     1,    77,    57,
      80,    47,     2,   100,    81,     3,     1,     4,     5,     6,
      85,     2,    82,    58,     3,    89,     4,     5,     6,     2,
      90,    84,     3,     1,     4,     5,     6,    91,     2,    93,
      53,     3,    52,     4,     5,     6,    94,    95,    98,    36,
      37,    38,    39,    40,    99,     2,   101,   102,     3,   103,
       4,     5,     6,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    36,    37,    38,    39,    40,   104,
      25,    57,    87,    76
};

static const yytype_int8 yycheck[] =
{
       3,     8,    35,    16,    17,    23,    24,    10,    11,     3,
       4,     5,     5,    18,    19,    20,    24,    50,    26,     3,
       4,     5,     6,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    21,     3,     4,
       5,     5,     5,    36,    38,    16,    17,    60,    81,     9,
      10,    11,    59,    86,    38,     0,    21,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    75,    28,
       5,    23,    39,    38,    31,    24,    47,    48,    49,     5,
      35,    88,    18,    19,    20,    92,    38,     5,     5,    39,
      24,    18,    27,    96,    29,    30,     5,    32,    33,    34,
      25,    27,    37,    39,    30,    27,    32,    33,    34,    27,
      31,    37,    30,     5,    32,    33,    34,     5,    27,    37,
      24,    30,    26,    32,    33,    34,    24,    24,    37,     7,
       8,     9,    10,    11,    27,    27,     5,    24,    30,    24,
      32,    33,    34,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     7,     8,     9,    10,    11,    24,
       5,    39,    78,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    27,    30,    32,    33,    34,    41,    42,    43,
      23,    38,     3,     4,     5,     6,    21,    38,    46,    47,
      48,    46,     5,    49,    50,    49,     5,     0,    43,    46,
      46,    47,    48,    47,    48,    28,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      31,    24,    26,    24,    35,    24,    39,    39,    39,    42,
      38,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    48,    48,    48,    42,    50,     5,    44,    45,
      24,    29,    37,    47,    37,    25,    36,    45,    42,    27,
      31,     5,    42,    37,    24,    24,    23,    24,    37,    27,
      46,     5,    24,    24,    24
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    43,    43,
      43,    43,    43,    44,    44,    44,    45,    45,    46,    46,
      46,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    49,    50
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     4,     7,     9,     7,     3,
       3,     9,     5,     0,     1,     2,     4,     6,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: stm_list  */
#line 79 "parser.bison"
             {
        program = (yyval.stm_val) = (yyvsp[0].stm_val); }
#line 1193 "parser.c"
    break;

  case 3: /* stm_list: stm  */
#line 85 "parser.bison"
        {
        (yyval.stm_val) = (yyvsp[0].stm_val); }
#line 1200 "parser.c"
    break;

  case 4: /* stm_list: stm_list stm  */
#line 88 "parser.bison"
                 {
        (yyval.stm_val) = stm_compound((yyvsp[-1].stm_val), (yyvsp[0].stm_val)); }
#line 1207 "parser.c"
    break;

  case 5: /* stm: TOKEN_ID TOKEN_ASSIGN expr TOKEN_SEMI  */
#line 94 "parser.bison"
                                          {
        (yyval.stm_val) = stm_assign((yyvsp[-3].string_val), (yyvsp[-1].expr_val)); }
#line 1214 "parser.c"
    break;

  case 6: /* stm: TOKEN_IF expr TOKEN_THEN stm_list TOKEN_END TOKEN_IF TOKEN_SEMI  */
#line 97 "parser.bison"
                                                                    {
        (yyval.stm_val) = stm_if_then((yyvsp[-5].expr_val), (yyvsp[-3].stm_val)); }
#line 1221 "parser.c"
    break;

  case 7: /* stm: TOKEN_IF expr TOKEN_THEN stm_list TOKEN_ELSE stm_list TOKEN_END TOKEN_IF TOKEN_SEMI  */
#line 100 "parser.bison"
                                                                                        {
        (yyval.stm_val) = stm_if_then_else((yyvsp[-7].expr_val), (yyvsp[-5].stm_val), (yyvsp[-3].stm_val)); }
#line 1228 "parser.c"
    break;

  case 8: /* stm: TOKEN_WHILE expr TOKEN_LOOP stm_list TOKEN_END TOKEN_LOOP TOKEN_SEMI  */
#line 103 "parser.bison"
                                                                         {
        (yyval.stm_val) = stm_while((yyvsp[-5].expr_val), (yyvsp[-3].stm_val)); }
#line 1235 "parser.c"
    break;

  case 9: /* stm: TOKEN_WITH pckg_list TOKEN_SEMI  */
#line 106 "parser.bison"
                                    {
        (yyval.stm_val) = stm_with((yyvsp[-1].pckg_val)); }
#line 1242 "parser.c"
    break;

  case 10: /* stm: TOKEN_USE pckg_list TOKEN_SEMI  */
#line 109 "parser.bison"
                                   {
        (yyval.stm_val) = stm_use((yyvsp[-1].pckg_val)); }
#line 1249 "parser.c"
    break;

  case 11: /* stm: TOKEN_PROC TOKEN_ID TOKEN_IS dclr_list TOKEN_BEGIN stm_list TOKEN_END TOKEN_ID TOKEN_SEMI  */
#line 112 "parser.bison"
                                                                                              {
        (yyval.stm_val) = stm_procedure((yyvsp[-7].string_val), (yyvsp[-5].dclr_val), (yyvsp[-3].stm_val)); }
#line 1256 "parser.c"
    break;

  case 12: /* stm: TOKEN_ID TOKEN_LPAREN expr TOKEN_RPAREN TOKEN_SEMI  */
#line 115 "parser.bison"
                                                       {
        (yyval.stm_val) = stm_function((yyvsp[-4].string_val), (yyvsp[-2].expr_val)); }
#line 1263 "parser.c"
    break;

  case 13: /* dclr_list: %empty  */
#line 121 "parser.bison"
           {}
#line 1269 "parser.c"
    break;

  case 14: /* dclr_list: dclr  */
#line 123 "parser.bison"
         {
        (yyval.dclr_val) = (yyvsp[0].dclr_val); }
#line 1276 "parser.c"
    break;

  case 15: /* dclr_list: dclr_list dclr  */
#line 126 "parser.bison"
                   {
        (yyval.dclr_val) = dclr_compound((yyvsp[-1].dclr_val), (yyvsp[0].dclr_val)); }
#line 1283 "parser.c"
    break;

  case 16: /* dclr: TOKEN_ID TOKEN_COLON TOKEN_ID TOKEN_SEMI  */
#line 131 "parser.bison"
                                             {
        (yyval.dclr_val) = dclr_simple((yyvsp[-3].string_val), (yyvsp[-1].string_val)); }
#line 1290 "parser.c"
    break;

  case 17: /* dclr: TOKEN_ID TOKEN_COLON TOKEN_ID TOKEN_ASSIGN expr TOKEN_SEMI  */
#line 134 "parser.bison"
                                                               {
        (yyval.dclr_val) = dclr_assignment((yyvsp[-5].string_val), (yyvsp[-3].string_val), (yyvsp[-1].expr_val)); }
#line 1297 "parser.c"
    break;

  case 18: /* expr: arExpr  */
#line 139 "parser.bison"
           {
        (yyval.expr_val) = expr_arithmetic((yyvsp[0].arExpr_val)); }
#line 1304 "parser.c"
    break;

  case 19: /* expr: boolExpr  */
#line 142 "parser.bison"
             {
        (yyval.expr_val) = expr_boolean((yyvsp[0].boolExpr_val)); }
#line 1311 "parser.c"
    break;

  case 20: /* expr: TOKEN_STRING  */
#line 145 "parser.bison"
                 {
        (yyval.expr_val) = expr_string((yyvsp[0].string_val)); }
#line 1318 "parser.c"
    break;

  case 21: /* arExpr: TOKEN_ID  */
#line 151 "parser.bison"
             {
        (yyval.arExpr_val) = ar_expr_identifier((yyvsp[0].string_val)); }
#line 1325 "parser.c"
    break;

  case 22: /* arExpr: TOKEN_INT  */
#line 154 "parser.bison"
              {
        (yyval.arExpr_val) = ar_expr_integer((yyvsp[0].int_val)); }
#line 1332 "parser.c"
    break;

  case 23: /* arExpr: TOKEN_FLOAT  */
#line 157 "parser.bison"
                {
        (yyval.arExpr_val) = ar_expr_float((yyvsp[0].float_val)); }
#line 1339 "parser.c"
    break;

  case 24: /* arExpr: TOKEN_LPAREN arExpr TOKEN_RPAREN  */
#line 160 "parser.bison"
                                     {
        (yyval.arExpr_val) = ar_expr_delimited((yyvsp[-1].arExpr_val)); }
#line 1346 "parser.c"
    break;

  case 25: /* arExpr: arExpr TOKEN_PLUS arExpr  */
#line 163 "parser.bison"
                             {
        (yyval.arExpr_val) = ar_expr_operation(PLUS, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1353 "parser.c"
    break;

  case 26: /* arExpr: arExpr TOKEN_MINUS arExpr  */
#line 166 "parser.bison"
                              {
        (yyval.arExpr_val) = ar_expr_operation(MINUS, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1360 "parser.c"
    break;

  case 27: /* arExpr: arExpr TOKEN_MULT arExpr  */
#line 169 "parser.bison"
                             {
        (yyval.arExpr_val) = ar_expr_operation(TIMES, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1367 "parser.c"
    break;

  case 28: /* arExpr: arExpr TOKEN_DIV arExpr  */
#line 172 "parser.bison"
                            {
        (yyval.arExpr_val) = ar_expr_operation(DIV, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1374 "parser.c"
    break;

  case 29: /* arExpr: arExpr TOKEN_MOD arExpr  */
#line 175 "parser.bison"
                            {
        (yyval.arExpr_val) = ar_expr_operation(MOD, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1381 "parser.c"
    break;

  case 30: /* boolExpr: TOKEN_LPAREN boolExpr TOKEN_RPAREN  */
#line 181 "parser.bison"
                                       {
        (yyval.boolExpr_val) = bool_expr_delimited((yyvsp[-1].boolExpr_val)); }
#line 1388 "parser.c"
    break;

  case 31: /* boolExpr: arExpr TOKEN_EQUAL arExpr  */
#line 184 "parser.bison"
                              {
        (yyval.boolExpr_val) = bool_expr_operation(EQUAL, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1395 "parser.c"
    break;

  case 32: /* boolExpr: arExpr TOKEN_DIFF arExpr  */
#line 187 "parser.bison"
                             {
        (yyval.boolExpr_val) = bool_expr_operation(DIFF, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1402 "parser.c"
    break;

  case 33: /* boolExpr: arExpr TOKEN_LESS arExpr  */
#line 190 "parser.bison"
                             {
        (yyval.boolExpr_val) = bool_expr_operation(LESS, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1409 "parser.c"
    break;

  case 34: /* boolExpr: arExpr TOKEN_GREATER arExpr  */
#line 193 "parser.bison"
                                {
        (yyval.boolExpr_val) = bool_expr_operation(GREATER, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1416 "parser.c"
    break;

  case 35: /* boolExpr: arExpr TOKEN_LESS_EQUAL arExpr  */
#line 196 "parser.bison"
                                   {
        (yyval.boolExpr_val) = bool_expr_operation(LESS_EQUAL, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1423 "parser.c"
    break;

  case 36: /* boolExpr: arExpr TOKEN_GREATER_EQUAL arExpr  */
#line 199 "parser.bison"
                                      {
        (yyval.boolExpr_val) = bool_expr_operation(GREATER_EQUAL, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1430 "parser.c"
    break;

  case 37: /* boolExpr: boolExpr TOKEN_AND boolExpr  */
#line 202 "parser.bison"
                                {
        (yyval.boolExpr_val) = bool_expr_operation2(AND, (yyvsp[-2].boolExpr_val), (yyvsp[0].boolExpr_val)); }
#line 1437 "parser.c"
    break;

  case 38: /* boolExpr: boolExpr TOKEN_OR boolExpr  */
#line 205 "parser.bison"
                               {
        (yyval.boolExpr_val) = bool_expr_operation2(OR, (yyvsp[-2].boolExpr_val), (yyvsp[0].boolExpr_val)); }
#line 1444 "parser.c"
    break;

  case 39: /* boolExpr: boolExpr TOKEN_XOR boolExpr  */
#line 208 "parser.bison"
                                {
        (yyval.boolExpr_val) = bool_expr_operation2(XOR, (yyvsp[-2].boolExpr_val), (yyvsp[0].boolExpr_val)); }
#line 1451 "parser.c"
    break;

  case 40: /* boolExpr: TOKEN_NOT boolExpr  */
#line 211 "parser.bison"
                       {
        (yyval.boolExpr_val) = bool_expr_operation2(NOT, NULL, (yyvsp[0].boolExpr_val)); }
#line 1458 "parser.c"
    break;

  case 41: /* pckg_list: pckg  */
#line 217 "parser.bison"
         {
        (yyval.pckg_val) = (yyvsp[0].pckg_val); }
#line 1465 "parser.c"
    break;

  case 42: /* pckg_list: pckg_list TOKEN_DOT pckg  */
#line 220 "parser.bison"
                             {
        (yyval.pckg_val) = pckg_compound((yyvsp[-2].pckg_val), (yyvsp[0].pckg_val)); }
#line 1472 "parser.c"
    break;

  case 43: /* pckg: TOKEN_ID  */
#line 226 "parser.bison"
             {
        (yyval.pckg_val) = pckg_simple((yyvsp[0].string_val)); }
#line 1479 "parser.c"
    break;


#line 1483 "parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 230 "parser.bison"


void yyerror(const char* err) {
   printf("Line %d: %s - '%s'\n", yyline, err, yytext);
}
