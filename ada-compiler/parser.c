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
  YYSYMBOL_TOKEN_EOF = 18,                 /* TOKEN_EOF  */
  YYSYMBOL_TOKEN_ASSIGN = 19,              /* TOKEN_ASSIGN  */
  YYSYMBOL_TOKEN_SEMI = 20,                /* TOKEN_SEMI  */
  YYSYMBOL_TOKEN_COLON = 21,               /* TOKEN_COLON  */
  YYSYMBOL_TOKEN_DOT = 22,                 /* TOKEN_DOT  */
  YYSYMBOL_TOKEN_IF = 23,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_THEN = 24,                /* TOKEN_THEN  */
  YYSYMBOL_TOKEN_ELSE = 25,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_WHILE = 26,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_LOOP = 27,                /* TOKEN_LOOP  */
  YYSYMBOL_TOKEN_WITH = 28,                /* TOKEN_WITH  */
  YYSYMBOL_TOKEN_USE = 29,                 /* TOKEN_USE  */
  YYSYMBOL_TOKEN_PROC = 30,                /* TOKEN_PROC  */
  YYSYMBOL_TOKEN_IS = 31,                  /* TOKEN_IS  */
  YYSYMBOL_TOKEN_BEGIN = 32,               /* TOKEN_BEGIN  */
  YYSYMBOL_TOKEN_END = 33,                 /* TOKEN_END  */
  YYSYMBOL_TOKEN_LPAREN = 34,              /* TOKEN_LPAREN  */
  YYSYMBOL_TOKEN_RPAREN = 35,              /* TOKEN_RPAREN  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_program = 37,                   /* program  */
  YYSYMBOL_stm_list = 38,                  /* stm_list  */
  YYSYMBOL_stm = 39,                       /* stm  */
  YYSYMBOL_dclr_list = 40,                 /* dclr_list  */
  YYSYMBOL_dclr = 41,                      /* dclr  */
  YYSYMBOL_expr = 42,                      /* expr  */
  YYSYMBOL_arExpr = 43,                    /* arExpr  */
  YYSYMBOL_boolExpr = 44,                  /* boolExpr  */
  YYSYMBOL_pckg_list = 45,                 /* pckg_list  */
  YYSYMBOL_pckg = 46                       /* pckg  */
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
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   114

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  36
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  88

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


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
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    77,    77,    83,    86,    92,    95,    98,   101,   104,
     107,   110,   113,   119,   121,   124,   129,   132,   137,   140,
     146,   149,   152,   155,   158,   161,   164,   167,   173,   176,
     179,   182,   185,   188,   194,   197,   203
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
  "TOKEN_EOF", "TOKEN_ASSIGN", "TOKEN_SEMI", "TOKEN_COLON", "TOKEN_DOT",
  "TOKEN_IF", "TOKEN_THEN", "TOKEN_ELSE", "TOKEN_WHILE", "TOKEN_LOOP",
  "TOKEN_WITH", "TOKEN_USE", "TOKEN_PROC", "TOKEN_IS", "TOKEN_BEGIN",
  "TOKEN_END", "TOKEN_LPAREN", "TOKEN_RPAREN", "$accept", "program",
  "stm_list", "stm", "dclr_list", "dclr", "expr", "arExpr", "boolExpr",
  "pckg_list", "pckg", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-27)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      52,   -15,    12,    12,     1,     1,    13,    20,    52,   -27,
      12,    12,   -27,   -27,   -27,     5,    76,   -27,    -5,   -27,
      22,   -27,    49,    -6,   -27,   -27,    21,    10,    52,    12,
      12,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      52,   -27,     1,   -27,    41,   -27,    27,    -2,    24,    24,
     -27,   -27,   -27,     2,     2,     2,     2,     2,     2,    25,
     -27,    29,     0,   -27,   -27,    52,    37,    38,    74,    52,
     -27,    33,    85,    86,    17,    44,    84,   -27,   -27,    12,
     -27,   103,    89,    90,    91,   -27,   -27,   -27
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       0,     0,    21,    22,    20,     0,    18,    19,     0,    36,
       0,    34,     0,     0,     1,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,     0,    10,    13,     5,     0,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     0,
      35,     0,     0,    14,    12,     0,     0,     0,     0,     0,
      15,     0,     0,     0,     0,     0,     0,     6,     8,     0,
      16,     0,     0,     0,     0,     7,    17,    11
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -27,   -27,   -26,    -7,   -27,    50,    -3,    65,   -27,   108,
      72
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9,    62,    63,    15,    16,    17,    20,
      21
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      18,    25,    47,     1,    10,    61,    19,    26,    27,    29,
      30,    31,    32,    33,    59,    12,    13,    14,    23,    11,
      24,     2,    40,    65,     3,    44,     4,     5,     6,    28,
       1,    66,    69,    31,    32,    33,    79,    80,     1,    71,
      25,    45,    41,    75,    42,    46,    61,    64,     2,     1,
      68,     3,    25,     4,     5,     6,     2,     1,    67,     3,
      72,     4,     5,     6,    25,    73,    76,     2,    25,    43,
       3,    42,     4,     5,     6,     2,    83,    81,     3,    74,
       4,     5,     6,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    77,    78,    82,    84,    85,
      86,    87,    70,    22,    60
};

static const yytype_int8 yycheck[] =
{
       3,     8,    28,     5,    19,     5,     5,    10,    11,     7,
       8,     9,    10,    11,    40,     3,     4,     5,     5,    34,
       0,    23,    27,    25,    26,    31,    28,    29,    30,    24,
       5,    33,    32,     9,    10,    11,    19,    20,     5,    65,
      47,    20,    20,    69,    22,    35,     5,    20,    23,     5,
      21,    26,    59,    28,    29,    30,    23,     5,    33,    26,
      23,    28,    29,    30,    71,    27,    33,    23,    75,    20,
      26,    22,    28,    29,    30,    23,    79,    33,    26,     5,
      28,    29,    30,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    20,    20,    23,     5,    20,
      20,    20,    62,     5,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    23,    26,    28,    29,    30,    37,    38,    39,
      19,    34,     3,     4,     5,    42,    43,    44,    42,     5,
      45,    46,    45,     5,     0,    39,    42,    42,    24,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      27,    20,    22,    20,    31,    20,    35,    38,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    38,
      46,     5,    40,    41,    20,    25,    33,    33,    21,    32,
      41,    38,    23,    27,     5,    38,    33,    20,    20,    19,
      20,    33,    23,    42,     5,    20,    20,    20
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    39,    39,    39,
      39,    39,    39,    40,    40,    40,    41,    41,    42,    42,
      43,    43,    43,    43,    43,    43,    43,    43,    44,    44,
      44,    44,    44,    44,    45,    45,    46
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     4,     7,     9,     7,     3,
       3,     9,     5,     0,     1,     2,     4,     6,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     1
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
#line 77 "parser.bison"
             {
        program = (yyval.stm_val) = (yyvsp[0].stm_val); }
#line 1170 "parser.c"
    break;

  case 3: /* stm_list: stm  */
#line 83 "parser.bison"
        {
        (yyval.stm_val) = (yyvsp[0].stm_val); }
#line 1177 "parser.c"
    break;

  case 4: /* stm_list: stm_list stm  */
#line 86 "parser.bison"
                 {
        (yyval.stm_val) = stm_compound((yyvsp[-1].stm_val), (yyvsp[0].stm_val)); }
#line 1184 "parser.c"
    break;

  case 5: /* stm: TOKEN_ID TOKEN_ASSIGN expr TOKEN_SEMI  */
#line 92 "parser.bison"
                                          {
        (yyval.stm_val) = stm_assign((yyvsp[-3].string_val), (yyvsp[-1].expr_val)); }
#line 1191 "parser.c"
    break;

  case 6: /* stm: TOKEN_IF expr TOKEN_THEN stm_list TOKEN_END TOKEN_IF TOKEN_SEMI  */
#line 95 "parser.bison"
                                                                    {
        (yyval.stm_val) = stm_if_then((yyvsp[-5].expr_val), (yyvsp[-3].stm_val)); }
#line 1198 "parser.c"
    break;

  case 7: /* stm: TOKEN_IF expr TOKEN_THEN stm_list TOKEN_ELSE stm_list TOKEN_END TOKEN_IF TOKEN_SEMI  */
#line 98 "parser.bison"
                                                                                        {
        (yyval.stm_val) = stm_if_then_else((yyvsp[-7].expr_val), (yyvsp[-5].stm_val), (yyvsp[-3].stm_val)); }
#line 1205 "parser.c"
    break;

  case 8: /* stm: TOKEN_WHILE expr TOKEN_LOOP stm_list TOKEN_END TOKEN_LOOP TOKEN_SEMI  */
#line 101 "parser.bison"
                                                                         {
        (yyval.stm_val) = stm_while((yyvsp[-5].expr_val), (yyvsp[-3].stm_val)); }
#line 1212 "parser.c"
    break;

  case 9: /* stm: TOKEN_WITH pckg_list TOKEN_SEMI  */
#line 104 "parser.bison"
                                    {
        (yyval.stm_val) = stm_with((yyvsp[-1].pckg_val)); }
#line 1219 "parser.c"
    break;

  case 10: /* stm: TOKEN_USE pckg_list TOKEN_SEMI  */
#line 107 "parser.bison"
                                   {
        (yyval.stm_val) = stm_use((yyvsp[-1].pckg_val)); }
#line 1226 "parser.c"
    break;

  case 11: /* stm: TOKEN_PROC TOKEN_ID TOKEN_IS dclr_list TOKEN_BEGIN stm_list TOKEN_END TOKEN_ID TOKEN_SEMI  */
#line 110 "parser.bison"
                                                                                              {
        (yyval.stm_val) = stm_procedure((yyvsp[-7].string_val), (yyvsp[-5].dclr_val), (yyvsp[-3].stm_val)); }
#line 1233 "parser.c"
    break;

  case 12: /* stm: TOKEN_ID TOKEN_LPAREN expr TOKEN_RPAREN TOKEN_SEMI  */
#line 113 "parser.bison"
                                                       {
        (yyval.stm_val) = stm_function((yyvsp[-4].string_val), (yyvsp[-2].expr_val)); }
#line 1240 "parser.c"
    break;

  case 13: /* dclr_list: %empty  */
#line 119 "parser.bison"
           {}
#line 1246 "parser.c"
    break;

  case 14: /* dclr_list: dclr  */
#line 121 "parser.bison"
         {
        (yyval.dclr_val) = (yyvsp[0].dclr_val); }
#line 1253 "parser.c"
    break;

  case 15: /* dclr_list: dclr_list dclr  */
#line 124 "parser.bison"
                   {
        (yyval.dclr_val) = dclr_compound((yyvsp[-1].dclr_val), (yyvsp[0].dclr_val)); }
#line 1260 "parser.c"
    break;

  case 16: /* dclr: TOKEN_ID TOKEN_COLON TOKEN_ID TOKEN_SEMI  */
#line 129 "parser.bison"
                                             {
        (yyval.dclr_val) = dclr_simple((yyvsp[-3].string_val), (yyvsp[-1].string_val)); }
#line 1267 "parser.c"
    break;

  case 17: /* dclr: TOKEN_ID TOKEN_COLON TOKEN_ID TOKEN_ASSIGN expr TOKEN_SEMI  */
#line 132 "parser.bison"
                                                               {
        (yyval.dclr_val) = dclr_assignment((yyvsp[-5].string_val), (yyvsp[-3].string_val), (yyvsp[-1].expr_val)); }
#line 1274 "parser.c"
    break;

  case 18: /* expr: arExpr  */
#line 137 "parser.bison"
           {
        (yyval.expr_val) = expr_arithmetic((yyvsp[0].arExpr_val)); }
#line 1281 "parser.c"
    break;

  case 19: /* expr: boolExpr  */
#line 140 "parser.bison"
             {
        (yyval.expr_val) = expr_boolean((yyvsp[0].boolExpr_val)); }
#line 1288 "parser.c"
    break;

  case 20: /* arExpr: TOKEN_ID  */
#line 146 "parser.bison"
             {
        (yyval.arExpr_val) = ar_expr_identifier((yyvsp[0].string_val)); }
#line 1295 "parser.c"
    break;

  case 21: /* arExpr: TOKEN_INT  */
#line 149 "parser.bison"
              {
        (yyval.arExpr_val) = ar_expr_integer((yyvsp[0].int_val)); }
#line 1302 "parser.c"
    break;

  case 22: /* arExpr: TOKEN_FLOAT  */
#line 152 "parser.bison"
                {
        (yyval.arExpr_val) = ar_expr_float((yyvsp[0].float_val)); }
#line 1309 "parser.c"
    break;

  case 23: /* arExpr: arExpr TOKEN_PLUS arExpr  */
#line 155 "parser.bison"
                             {
        (yyval.arExpr_val) = ar_expr_operation(PLUS, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1316 "parser.c"
    break;

  case 24: /* arExpr: arExpr TOKEN_MINUS arExpr  */
#line 158 "parser.bison"
                              {
        (yyval.arExpr_val) = ar_expr_operation(MINUS, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1323 "parser.c"
    break;

  case 25: /* arExpr: arExpr TOKEN_MULT arExpr  */
#line 161 "parser.bison"
                             {
        (yyval.arExpr_val) = ar_expr_operation(TIMES, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1330 "parser.c"
    break;

  case 26: /* arExpr: arExpr TOKEN_DIV arExpr  */
#line 164 "parser.bison"
                            {
        (yyval.arExpr_val) = ar_expr_operation(DIV, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1337 "parser.c"
    break;

  case 27: /* arExpr: arExpr TOKEN_MOD arExpr  */
#line 167 "parser.bison"
                            {
        (yyval.arExpr_val) = ar_expr_operation(MOD, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1344 "parser.c"
    break;

  case 28: /* boolExpr: arExpr TOKEN_EQUAL arExpr  */
#line 173 "parser.bison"
                              {
        (yyval.boolExpr_val) = bool_expr_operation(EQUAL, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1351 "parser.c"
    break;

  case 29: /* boolExpr: arExpr TOKEN_DIFF arExpr  */
#line 176 "parser.bison"
                             {
        (yyval.boolExpr_val) = bool_expr_operation(DIFF, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1358 "parser.c"
    break;

  case 30: /* boolExpr: arExpr TOKEN_LESS arExpr  */
#line 179 "parser.bison"
                             {
        (yyval.boolExpr_val) = bool_expr_operation(LESS, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1365 "parser.c"
    break;

  case 31: /* boolExpr: arExpr TOKEN_GREATER arExpr  */
#line 182 "parser.bison"
                                {
        (yyval.boolExpr_val) = bool_expr_operation(GREATER, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1372 "parser.c"
    break;

  case 32: /* boolExpr: arExpr TOKEN_LESS_EQUAL arExpr  */
#line 185 "parser.bison"
                                   {
        (yyval.boolExpr_val) = bool_expr_operation(LESS_EQUAL, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1379 "parser.c"
    break;

  case 33: /* boolExpr: arExpr TOKEN_GREATER_EQUAL arExpr  */
#line 188 "parser.bison"
                                      {
        (yyval.boolExpr_val) = bool_expr_operation(GREATER_EQUAL, (yyvsp[-2].arExpr_val), (yyvsp[0].arExpr_val)); }
#line 1386 "parser.c"
    break;

  case 34: /* pckg_list: pckg  */
#line 194 "parser.bison"
         {
        (yyval.pckg_val) = (yyvsp[0].pckg_val); }
#line 1393 "parser.c"
    break;

  case 35: /* pckg_list: pckg_list TOKEN_DOT pckg  */
#line 197 "parser.bison"
                             {
        (yyval.pckg_val) = pckg_compound((yyvsp[-2].pckg_val), (yyvsp[0].pckg_val)); }
#line 1400 "parser.c"
    break;

  case 36: /* pckg: TOKEN_ID  */
#line 203 "parser.bison"
             {
        (yyval.pckg_val) = pckg_simple((yyvsp[0].string_val)); }
#line 1407 "parser.c"
    break;


#line 1411 "parser.c"

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

#line 207 "parser.bison"


void yyerror(const char* err) {
   printf("Line %d: %s - '%s'\n", yyline, err, yytext);
}
