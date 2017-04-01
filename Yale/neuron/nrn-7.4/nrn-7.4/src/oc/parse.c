/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "parse.y" /* yacc.c:339  */


#include <../../nrnconf.h>
/* changes as of 2-jan-89 */
/*  version 7.2.1 2-jan-89 short form of the for statement */

#if AIX
#pragma alloca
#endif

#include "hoc.h"
#include "ocmisc.h"
#include "hocparse.h"
#include "code.h"
#include "equation.h"
#include "nrnfilewrap.h"

#if LINT
Inst *inlint;
#define code	inlint = Code
#else
#define code	Code
#endif

#define paction(arg) fprintf(stderr, "%s\n", arg)

/* maintain a list of ierr addresses so we can clear them */
#define HOCERRSIZE 20
static int** hoc_err;
static int hoc_errp;
static int localcnt;

static void clean_err(void) {
	int i;
	for (i=0; i < hoc_errp; ++i) {
		*hoc_err[i] = 0;
	}
	hoc_errp = 0;
}

static void pusherr(int* ip) {
	if (!hoc_err) {
		hoc_err = (int**)ecalloc(HOCERRSIZE, sizeof(int*));
		hoc_errp = 0;
	}
	if (hoc_errp >= HOCERRSIZE) {
		clean_err();
		hoc_execerror("error stack full", (char*)0);
	}
	hoc_err[hoc_errp++] = ip;
}

static void yyerror(const char* s);

#if YYBISON
#define myerr(arg) static int ierr=0;\
if (!(ierr++)){pusherr(&ierr);yyerror(arg);} --yyssp; --yyvsp; YYERROR
#else
#define myerr(arg) static int ierr=0;\
if (!(ierr++)){pusherr(&ierr);yyerror(arg);} YYERROR
#endif

#define code2(c1,c2)	code(c1); codein(c2)
#define code3(c1,c2,c3)	code(c1); codesym(c2); code(c3)
#define relative(ip1,ip2,offset)	((ip1-ip2) - offset)
#define CHECK 1	/* check syntactically the consistency of arrays */
#define NOCHECK 0 /* don't check syntactically. For object components */
#define PN pushi(NUMBER)	/* for type checking. expressions are usually numbers */
#define TPD hoc_ob_check(NUMBER);
#define TPDYNAM hoc_ob_check(0);

static Inst *prog_error;			/* needed for stmtlist loc if error */
static int ntab;			/* auto indentation */

static Inst* argrefcode(Pfrv pfrv, int i, int j);
static Inst* argcode(Pfrv pfrv, int i);
static void hoc_opasgn_invalid(int op);
 

#line 146 "parse.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_PARSE_H_INCLUDED
# define YY_YY_PARSE_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    EQNEQ = 258,
    NUMBER = 259,
    STRING = 260,
    PRINT = 261,
    parseDELETE = 262,
    VAR = 263,
    BLTIN = 264,
    UNDEF = 265,
    WHILE = 266,
    IF = 267,
    ELSE = 268,
    FOR = 269,
    FUNCTION = 270,
    PROCEDURE = 271,
    RETURN = 272,
    FUNC = 273,
    parsePROC = 274,
    HOCOBJFUNC = 275,
    READ = 276,
    parseDOUBLE = 277,
    DEBUG = 278,
    EDIT = 279,
    FUN_BLTIN = 280,
    DEPENDENT = 281,
    EQUATION = 282,
    LOCAL = 283,
    HOCOBJFUNCTION = 284,
    BREAK = 285,
    CONTINUE = 286,
    AUTO = 287,
    STRDEF = 288,
    STOPSTMT = 289,
    CSTRING = 290,
    PARALLEL = 291,
    HELP = 292,
    ITERATOR = 293,
    ITERKEYWORD = 294,
    ITERSTMT = 295,
    STRINGFUNC = 296,
    OBJECTFUNC = 297,
    LOCALOBJ = 298,
    AUTOOBJ = 299,
    ARG = 300,
    NUMZERO = 301,
    ARGREF = 302,
    INTERNALSECTIONNAME = 303,
    SECTIONKEYWORD = 304,
    SECTION = 305,
    CONNECTKEYWORD = 306,
    ACCESSKEYWORD = 307,
    RANGEVAR = 308,
    MECHANISM = 309,
    INSERTKEYWORD = 310,
    FORALL = 311,
    NRNPNTVAR = 312,
    FORSEC = 313,
    IFSEC = 314,
    UNINSERTKEYWORD = 315,
    SETPOINTERKEYWORD = 316,
    SECTIONREF = 317,
    BEGINTEMPLATE = 318,
    ENDTEMPLATE = 319,
    NEW = 320,
    OBJECTVAR = 321,
    TEMPLATE = 322,
    OBJVARDECL = 323,
    PUBLICDECL = 324,
    EXTERNALDECL = 325,
    OBFUNCTION = 326,
    STRFUNCTION = 327,
    OBJECTARG = 328,
    STRINGARG = 329,
    ROP = 330,
    OR = 331,
    AND = 332,
    GT = 333,
    GE = 334,
    LT = 335,
    LE = 336,
    EQ = 337,
    NE = 338,
    UNARYMINUS = 339,
    NOT = 340
  };
#endif
/* Tokens.  */
#define EQNEQ 258
#define NUMBER 259
#define STRING 260
#define PRINT 261
#define parseDELETE 262
#define VAR 263
#define BLTIN 264
#define UNDEF 265
#define WHILE 266
#define IF 267
#define ELSE 268
#define FOR 269
#define FUNCTION 270
#define PROCEDURE 271
#define RETURN 272
#define FUNC 273
#define parsePROC 274
#define HOCOBJFUNC 275
#define READ 276
#define parseDOUBLE 277
#define DEBUG 278
#define EDIT 279
#define FUN_BLTIN 280
#define DEPENDENT 281
#define EQUATION 282
#define LOCAL 283
#define HOCOBJFUNCTION 284
#define BREAK 285
#define CONTINUE 286
#define AUTO 287
#define STRDEF 288
#define STOPSTMT 289
#define CSTRING 290
#define PARALLEL 291
#define HELP 292
#define ITERATOR 293
#define ITERKEYWORD 294
#define ITERSTMT 295
#define STRINGFUNC 296
#define OBJECTFUNC 297
#define LOCALOBJ 298
#define AUTOOBJ 299
#define ARG 300
#define NUMZERO 301
#define ARGREF 302
#define INTERNALSECTIONNAME 303
#define SECTIONKEYWORD 304
#define SECTION 305
#define CONNECTKEYWORD 306
#define ACCESSKEYWORD 307
#define RANGEVAR 308
#define MECHANISM 309
#define INSERTKEYWORD 310
#define FORALL 311
#define NRNPNTVAR 312
#define FORSEC 313
#define IFSEC 314
#define UNINSERTKEYWORD 315
#define SETPOINTERKEYWORD 316
#define SECTIONREF 317
#define BEGINTEMPLATE 318
#define ENDTEMPLATE 319
#define NEW 320
#define OBJECTVAR 321
#define TEMPLATE 322
#define OBJVARDECL 323
#define PUBLICDECL 324
#define EXTERNALDECL 325
#define OBFUNCTION 326
#define STRFUNCTION 327
#define OBJECTARG 328
#define STRINGARG 329
#define ROP 330
#define OR 331
#define AND 332
#define GT 333
#define GE 334
#define LT 335
#define LE 336
#define EQ 337
#define NE 338
#define UNARYMINUS 339
#define NOT 340

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 82 "parse.y" /* yacc.c:355  */
				/* stack type */
	Symbol	*sym;			/* symbol table pointer */
	Inst	*inst;			/* machine instruction */
	int	narg;			/* number of arguments */
	void*	ptr;

#line 363 "parse.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 378 "parse.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2865

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  105
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  97
/* YYNRULES -- Number of rules.  */
#define YYNRULES  280
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  545

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   340

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      93,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    89,   104,     2,
      94,    95,    87,    85,    99,    86,    98,    88,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   102,   103,
       2,    76,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    96,     2,    97,    92,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   100,     2,   101,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    77,    78,    79,    80,    81,    82,    83,    84,    90,
      91
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   138,   138,   139,   140,   141,   143,   145,   147,   149,
     151,   155,   161,   161,   162,   172,   176,   178,   181,   185,
     191,   197,   201,   201,   203,   205,   207,   209,   212,   217,
     220,   221,   221,   231,   234,   235,   238,   239,   240,   241,
     242,   244,   247,   249,   251,   253,   256,   266,   268,   271,
     273,   278,   280,   285,   287,   290,   291,   293,   297,   299,
     303,   305,   307,   320,   322,   323,   325,   327,   328,   330,
     332,   334,   343,   347,   353,   355,   357,   359,   361,   363,
     368,   379,   383,   378,   390,   394,   389,   402,   406,   410,
     416,   415,   421,   424,   425,   427,   429,   431,   431,   434,
     436,   438,   440,   442,   444,   447,   451,   456,   455,   464,
     467,   463,   473,   472,   480,   479,   486,   485,   492,   491,
     499,   498,   510,   515,   515,   521,   521,   523,   530,   531,
     531,   541,   543,   545,   547,   550,   558,   560,   562,   562,
     565,   567,   569,   571,   572,   578,   580,   584,   586,   589,
     591,   594,   597,   600,   604,   607,   610,   611,   622,   623,
     628,   630,   632,   634,   636,   639,   641,   645,   648,   649,
     651,   653,   655,   657,   659,   661,   663,   665,   667,   669,
     671,   673,   675,   677,   679,   681,   683,   685,   687,   689,
     691,   694,   695,   696,   697,   699,   702,   707,   710,   712,
     715,   718,   721,   720,   727,   735,   770,   777,   778,   782,
     784,   786,   788,   791,   796,   795,   802,   801,   808,   807,
     814,   813,   820,   826,   827,   828,   829,   831,   831,   838,
     839,   841,   843,   846,   848,   850,   851,   856,   859,   858,
     864,   866,   869,   870,   872,   871,   876,   876,   881,   881,
     886,   887,   889,   896,   908,   909,   911,   921,   932,   940,
     940,   940,   940,   940,   940,   940,   940,   941,   941,   941,
     941,   941,   941,   941,   942,   942,   942,   942,   942,   942,
     943
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EQNEQ", "NUMBER", "STRING", "PRINT",
  "parseDELETE", "VAR", "BLTIN", "UNDEF", "WHILE", "IF", "ELSE", "FOR",
  "FUNCTION", "PROCEDURE", "RETURN", "FUNC", "parsePROC", "HOCOBJFUNC",
  "READ", "parseDOUBLE", "DEBUG", "EDIT", "FUN_BLTIN", "DEPENDENT",
  "EQUATION", "LOCAL", "HOCOBJFUNCTION", "BREAK", "CONTINUE", "AUTO",
  "STRDEF", "STOPSTMT", "CSTRING", "PARALLEL", "HELP", "ITERATOR",
  "ITERKEYWORD", "ITERSTMT", "STRINGFUNC", "OBJECTFUNC", "LOCALOBJ",
  "AUTOOBJ", "ARG", "NUMZERO", "ARGREF", "INTERNALSECTIONNAME",
  "SECTIONKEYWORD", "SECTION", "CONNECTKEYWORD", "ACCESSKEYWORD",
  "RANGEVAR", "MECHANISM", "INSERTKEYWORD", "FORALL", "NRNPNTVAR",
  "FORSEC", "IFSEC", "UNINSERTKEYWORD", "SETPOINTERKEYWORD", "SECTIONREF",
  "BEGINTEMPLATE", "ENDTEMPLATE", "NEW", "OBJECTVAR", "TEMPLATE",
  "OBJVARDECL", "PUBLICDECL", "EXTERNALDECL", "OBFUNCTION", "STRFUNCTION",
  "OBJECTARG", "STRINGARG", "ROP", "'='", "OR", "AND", "GT", "GE", "LT",
  "LE", "EQ", "NE", "'+'", "'-'", "'*'", "'/'", "'%'", "UNARYMINUS", "NOT",
  "'^'", "'\\n'", "'('", "')'", "'['", "']'", "'.'", "','", "'{'", "'}'",
  "':'", "';'", "'&'", "$accept", "list", "$@1", "asgn", "object", "$@2",
  "ob", "ob1", "$@3", "func_or_range_array_case", "template", "objvarlist",
  "objvarlst1", "obvarname", "publiclist", "externallist", "strnasgn",
  "string1", "string2", "strlist", "string", "stmt", "@4", "@5", "@6",
  "@7", "$@8", "$@9", "@10", "$@11", "@12", "@13", "@14", "@15", "@16",
  "@17", "iterator", "$@18", "section", "$@19", "section_or_ob", "@20",
  "sectiondecl", "sectionname", "rangevar", "rangevar1", "$@21", "pointer",
  "for_init", "for_st", "for_cond", "for_inc", "cond", "while", "if",
  "begin", "end", "stmtlist", "expr", "function", "doublelist", "newarray",
  "numdimen", "newname", "varname", "$@22", "wholearray", "argrefdim",
  "array", "prlist", "delsym", "defn", "$@23", "$@24", "$@25", "$@26",
  "procname", "procstmt", "$@27", "arglist", "arglist1", "arglist2",
  "eqn_list", "$@28", "dep_list", "equation", "$@29", "lhs", "$@30", "rhs",
  "$@31", "local", "local1", "localobj", "local2", "ckvar", "anyname", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,    61,   331,   332,   333,
     334,   335,   336,   337,   338,    43,    45,    42,    47,    37,
     339,   340,    94,    10,    40,    41,    91,    93,    46,    44,
     123,   125,    58,    59,    38
};
# endif

#define YYPACT_NINF -428

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-428)))

#define YYTABLE_NINF -157

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -428,  1136,  -428,  -428,  -428,  -428,  2125,    18,  -428,   -82,
    -428,  -428,    17,  -428,  -428,  2180,   147,   147,   147,   -62,
    -428,   -27,   -22,  -428,    25,    25,  -428,  -428,  -428,  -428,
    -428,  -428,  -428,    24,  -428,   147,  -428,  -428,  -428,  -428,
       1,  -428,  -428,  -428,  -428,  -428,    14,    74,  -428,    26,
    -428,  -428,  -428,    27,    85,  2403,  2463,   929,   -11,  -428,
    2463,    79,  -428,  -428,  -428,  -428,  2286,  2286,  -428,  1962,
    -428,    -4,  -428,  1888,   -57,     2,  -428,    -5,     7,  -428,
      19,  1032,     8,    22,  1694,   -54,  -428,  -428,    29,    29,
    2756,  -428,    28,   -39,    41,  -428,  -428,  -428,   -48,  -428,
    -428,    23,   -33,  2773,    40,  -428,  -428,  -428,  2286,  -428,
    1398,    45,   106,  -428,    51,  2463,  -428,  2773,  -428,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,  -428,    25,   138,  -428,
    -428,  -428,    49,    54,    57,  -428,  -428,  -428,  2463,  -428,
      25,    65,  -428,  -428,    67,    73,  2286,    95,    77,  2463,
    -428,    80,    76,   -13,  -428,    82,  -428,  -428,  -428,  -428,
     167,   167,  -428,    83,    84,  -428,  -428,  -428,  -428,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,
    -428,  -428,  -428,  2286,  2463,  -428,  -428,    90,    90,  -428,
    2566,  1233,  -428,  -428,  -428,  2773,  2070,  2463,  -428,  2463,
     169,  -428,  -428,   167,  2463,  -428,     5,  -428,  2286,  2286,
    2286,  2286,  1888,  1888,  2286,  2286,  2286,  2286,  2286,  2286,
    2286,  2286,  2286,  2286,  2286,  2286,  2286,  2286,  -428,    97,
     138,  2015,  1307,  -428,  2233,  2286,  2125,  -428,  2585,  -428,
      89,   -47,   186,   103,  1888,   -13,   120,  1307,   105,   107,
     109,   110,   111,  -428,   104,  -428,    25,  -428,  1307,  -428,
    -428,  -428,  -428,   116,  1307,  1307,  2773,  2286,  2286,   114,
     104,  -428,  -428,  -428,  2286,  2286,  -428,  -428,  1888,  -428,
    -428,  -428,  -428,   152,  2286,   -13,  -428,  2482,   115,   104,
    -428,  -428,  -428,  1498,  -428,  2463,  -428,  2773,  -428,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,  2773,   666,   117,  2773,
    2604,  -428,  -428,   277,   422,   101,   101,   101,   101,   101,
     101,    12,    12,    90,    90,    90,    90,  1307,  -428,  -428,
    2773,  2463,   261,  -428,  2773,   123,   124,  -428,  2623,  -428,
    2773,  -428,  -428,  -428,  -428,  -428,  1307,  -428,  -428,  2286,
     129,  1307,   130,   134,   135,  -428,  2286,   139,  -428,     0,
     141,   144,   142,   143,   148,  2773,  2503,  2463,   139,    77,
    2642,   -55,  2773,  -428,  1888,  1888,  1888,  1888,  2661,   145,
    -428,  2463,   139,  -428,  -428,  -428,   151,  -428,   171,  2286,
    1791,  1888,  -428,  -428,   234,   153,   155,  -428,  -428,     3,
    -428,  -428,  -428,  1307,  -428,  1888,  2286,   156,  -428,   804,
    -428,   157,   150,   150,   150,  2524,  2286,  -428,  -428,  -428,
     252,  2286,  -428,  2286,   150,  -428,  -428,  -428,   104,  -428,
    2286,  -428,  -428,  -428,  -428,  -428,   158,   261,   104,  1307,
     162,  2286,  2680,  -428,   165,  -428,  1888,  -428,  1307,  -428,
    2286,  -428,  -428,  2699,  -428,  2286,  -428,   233,  -428,  -428,
    -428,  -428,  2545,  -428,  2286,  -428,  -428,  2773,  2459,  -428,
     139,  2718,  -428,  -428,  -428,  -428,   261,  -428,   139,   170,
    1307,  -428,  2773,   187,  -428,  -428,  -428,   173,  2737,  -428,
    -428,  2773,  2463,   227,   174,  -428,  2773,   269,  2286,  -428,
    -428,  -428,   179,  2286,  -428,  -428,  -428,  1888,  1888,  -428,
    2463,  -428,   176,  2463,  -428,  2773,  -428,   765,  -428,  -428,
    -428,  1233,  2463,  -428,  -428,  1888,  2286,  -428,  -428,  1596,
    -428,  -428,  2773,  -428,  -428
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,    14,   160,    58,     0,     0,   154,     0,
     147,   153,   154,   191,   154,   154,     0,     0,     0,     0,
     154,     0,     0,   192,     0,     0,   154,   154,   154,   154,
     154,   154,    56,     0,    12,     0,   154,   154,   154,    25,
     163,   161,   207,   127,   154,   125,   129,     0,   138,     0,
     154,   154,   154,     0,   154,     0,     0,     0,     0,   154,
       0,     0,   193,   194,    24,    59,     0,     0,     3,     0,
      90,   168,    30,   167,    29,     0,    66,    37,    38,    67,
       0,     0,    64,     0,     0,   165,   136,   147,     0,     0,
       0,   154,    65,   162,     0,    92,   168,   167,    29,   210,
      55,     0,   165,   209,    78,   213,    69,   202,     0,   152,
       0,     0,   123,    81,     0,     0,    70,    71,   258,   223,
     224,   226,   225,   214,   222,   216,   220,     0,     0,     8,
       9,   240,   237,     0,     0,    74,    76,   201,     0,    75,
       0,     0,   218,    73,     0,     0,     0,   164,   206,     0,
     154,     0,     0,     0,   100,    29,    99,   154,   101,   112,
       0,     0,   102,     0,     0,    97,    40,   259,   260,   275,
     261,   262,   263,   264,   277,   271,   278,   279,   280,   272,
     265,   266,   274,   267,   273,   268,   269,   270,   276,    36,
      39,    33,   154,     0,     0,    47,    49,   181,   190,   174,
       0,     0,     5,    68,   155,    63,     0,     0,    11,     0,
       0,    10,    54,     0,     0,     6,     0,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     7,     0,
       0,     0,   229,     4,     0,     0,     0,   154,     0,   146,
       0,   162,     0,     0,     0,     0,     0,   229,     0,     0,
       0,     0,     0,   195,     0,   200,     0,   238,   229,    60,
      62,    84,    13,     0,   229,   229,    16,     0,     0,    93,
     131,   135,   207,   126,     0,     0,   130,   139,     0,   118,
     114,   120,   116,     0,     0,     0,    23,     0,    41,    42,
      46,   173,   159,     0,   104,     0,    52,    20,    31,    48,
      50,    53,    51,    61,   204,   137,    18,     0,     0,   148,
       0,   155,   155,   189,   188,   182,   183,   184,   185,   186,
     187,   175,   176,   177,   178,   179,   180,   229,   196,    21,
      15,     0,     0,   233,   234,     0,   230,   231,     0,   212,
     211,   203,   172,   145,   107,   109,   229,   155,   124,     0,
       0,   229,     0,     0,     0,   171,     0,   197,   241,   246,
       0,     0,     0,     0,     0,    17,     0,     0,   132,   205,
       0,     0,    94,   155,     0,     0,     0,     0,     0,     0,
      26,     0,    43,   157,    91,   158,     0,   154,   166,     0,
       0,     0,   151,    87,    88,     0,     0,   144,   142,     0,
     235,   140,   170,     0,   166,     0,     0,     0,    79,     0,
      77,     0,     0,     0,     0,     0,     0,   248,   244,   239,
       0,     0,    28,     0,     0,    57,    27,   208,   133,   128,
       0,   113,   155,   155,   155,   155,     0,     0,    44,   229,
      34,     0,     0,   150,     0,   155,     0,   169,   229,   143,
       0,   232,   155,     0,   122,     0,    72,   250,   215,   217,
     221,   198,     0,   243,     0,   246,   242,   247,     0,   219,
     134,     0,   119,   115,   121,   117,     0,    98,    45,     0,
     229,    32,   106,     0,   149,    80,   155,     0,     0,   108,
     110,    82,     0,   254,   251,   199,   249,     0,     0,    95,
      96,    19,     0,     0,    89,   236,   141,     0,     0,   252,
       0,   227,   255,     0,   248,    85,    35,     0,   155,   155,
     256,     0,     0,   253,   245,     0,     0,   111,    83,     0,
     257,   155,   105,   228,    86
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -428,  -428,  -428,   276,  -428,  -428,    -1,     4,  -428,  -428,
    -428,  -428,  -428,  -113,  -428,  -428,  -428,   420,   467,  -428,
      66,   270,  -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,  -428,  -428,    44,  -428,
    -428,  -428,  -428,   -98,     9,  -209,  -428,  -427,  -428,   194,
    -428,  -428,   193,  -428,  -428,  2355,  -313,  -248,   366,  -428,
    -428,    46,  -269,  -428,    10,  -428,  -155,  -428,     6,  -428,
    -428,  -428,  -428,  -428,  -428,  -428,    61,  -298,  -428,  -251,
    -428,  -129,  -428,  -428,  -428,  -428,  -428,  -190,  -428,  -235,
    -428,  -428,  -428,  -428,  -428,  -127,   -41
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   141,    96,    72,   192,    97,    98,   397,   491,
      75,    76,   298,   299,    77,    78,    79,   203,    81,    82,
     269,   395,   256,   518,   371,   535,   201,   295,   415,   416,
     517,   288,   385,   387,   384,   386,   254,   255,   101,   150,
     152,   153,   279,   280,   102,    86,   157,   410,    87,   109,
     318,   401,   222,    88,    89,   282,   304,   303,   205,    91,
      92,   263,   367,   264,    93,   247,   283,   147,   148,   104,
     106,    94,   259,   260,   273,   261,   123,   468,   531,   345,
     346,   347,    95,   369,   132,   429,   475,   430,   431,   473,
     474,   503,   504,   521,   522,   124,   270
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,   265,   287,   427,   459,    74,   360,   315,   403,   404,
      85,   378,   108,   314,   189,   190,    26,   370,   206,   195,
     487,   218,   113,   373,   374,     8,   105,   244,   241,    38,
     392,    39,   127,     8,   131,   133,   241,   296,   140,   440,
     219,   207,   218,   216,   418,    84,   154,   242,   354,    29,
     207,   155,   355,    57,    58,   242,   111,    29,    48,   510,
      64,   245,    43,   164,    45,    43,   129,    45,   111,   111,
     441,   130,    73,    43,   258,    45,   146,    74,   125,   126,
     158,   162,    85,    73,   315,   193,   405,   196,    74,   202,
     151,   156,   351,    85,   209,   208,   142,   460,   163,   234,
     235,   236,   428,    26,   237,   417,   210,   214,   281,    73,
     421,   110,   211,   265,    74,   215,    38,    84,    39,    85,
     251,   216,    43,   221,    45,   469,   470,   240,    84,   482,
     483,   484,   485,    43,   243,    45,   479,   262,    48,   246,
      57,    58,   495,   252,   253,   257,   118,    64,   266,   499,
     271,   268,   286,   300,    84,   118,   267,   155,   272,   289,
     291,   274,   119,   120,   155,   155,   308,   275,   309,   480,
     277,   111,     5,   278,   284,   285,   121,   310,   294,   488,
     207,   293,   237,   514,   111,   122,   232,   233,   234,   235,
     236,   337,   353,   237,   314,   359,    26,   356,   489,   361,
     366,   362,    32,   363,   364,    48,   365,   497,    37,    38,
     372,    39,   311,   377,   391,   537,   538,   155,   412,   433,
     400,    73,    73,   413,   420,   422,    74,    74,   544,   423,
     424,    85,    85,    57,    58,   426,   432,   434,   435,   512,
      64,    65,   450,   436,   447,   449,   451,   456,   457,   458,
     467,   464,   466,    73,   358,   476,   490,   486,    74,   155,
     494,   502,   513,    85,   396,   511,    84,    84,   515,     8,
     520,    83,   524,   523,   526,   532,   368,    71,   448,   438,
     313,   220,   223,   539,   461,   507,   338,    73,   379,   534,
      26,     0,    74,    29,   389,     0,     0,    85,    84,   155,
     406,     0,    73,    38,     0,    39,     0,    74,   407,    43,
     111,    45,    85,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    57,    58,   381,
       0,     0,    84,     0,    64,     0,   281,     0,     0,     0,
       0,   408,     0,   204,     0,     0,   155,    84,     0,     0,
     300,   409,   411,     0,   217,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,    90,     0,   237,
       0,     0,   103,     0,     0,     0,     0,     0,     0,     0,
     250,   117,     0,    73,    73,    73,    73,     0,    74,    74,
      74,    74,     0,    85,    85,    85,    85,     0,     0,    73,
      73,     0,     0,     0,    74,    74,     0,     0,     0,    85,
      85,     0,     0,     0,    73,     0,     0,     0,     0,    74,
       0,    80,     0,     0,    85,     0,    99,     0,    84,    84,
      84,    84,   197,   198,     0,   200,     0,     0,     0,     0,
       0,     0,     0,     0,    84,    84,   408,     0,     0,     0,
       0,   155,     0,     0,     0,    73,   409,   411,     0,    84,
      74,   519,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,   100,   248,     0,     0,     0,     0,   530,
       0,     0,   533,     0,     0,   408,     0,     0,     0,     0,
     155,   540,   321,   322,     0,   409,   411,     0,     0,     0,
      84,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   276,     0,   237,     0,    73,    73,     0,     0,
       0,    74,    74,     0,   357,     0,    85,    85,     0,     0,
       0,     0,     0,     0,    73,     0,     0,     0,    73,    74,
       0,     0,     0,    74,    85,     0,     0,     0,    85,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   383,   297,
       0,    84,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   307,     0,     0,     0,     0,     0,     0,    84,
     290,   292,     0,    84,   316,   317,   319,   320,     0,     0,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,     0,     0,     0,   340,   344,     0,
     307,   348,   350,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   344,     0,     0,   306,   100,   100,     0,
       0,     0,     0,   312,   344,     0,     0,     0,     0,     0,
     344,   344,     0,   375,   376,     0,     0,     0,     0,     0,
     380,   382,     0,     0,   442,   443,   444,   445,     0,     0,
     388,     0,   343,     0,     0,     0,   349,     0,     0,     0,
     454,   455,     0,   100,     0,     0,     0,   343,     0,     0,
     100,     0,     0,     0,     0,   462,     0,     0,   343,     0,
       0,     0,     0,     0,   343,   343,     0,     0,     0,     0,
       0,     0,     0,   344,     0,     0,     0,     0,     0,   100,
       0,     0,     0,   100,     0,     0,     0,     0,     0,     0,
       0,     0,   344,     0,   100,   419,   496,   344,     0,     0,
       0,     0,   425,     0,     0,   100,     0,     0,     0,     0,
       0,   100,   100,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,     0,   343,   237,     0,
       0,   398,     0,     0,     0,   452,     0,     0,   399,     0,
       0,     0,     0,     0,     0,     0,   343,     0,     0,   344,
       0,   343,   463,     0,     0,     0,     0,   528,   529,     0,
       0,     0,   472,     0,     0,     0,     0,   477,     0,   478,
       0,     0,     0,     0,   100,   541,   481,     0,     0,     0,
       0,     0,     0,     0,     0,   344,     0,   492,     0,     0,
       0,     0,     0,   100,   344,     0,   498,     0,   100,     0,
       0,   501,     0,   343,     0,     0,     0,     0,     0,     0,
     506,     0,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   344,   237,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   536,     0,   343,
       0,     0,     0,     0,   525,     0,     0,     0,   343,   527,
     100,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     0,     0,   237,     0,     0,     0,
       0,     0,   542,   465,     0,     0,     0,     0,     0,     0,
     343,     0,     0,     0,     0,     0,   100,     0,     0,     0,
       0,     0,     0,     0,     0,   100,     0,     0,     0,     0,
     191,     0,   -22,   -22,   -22,   -22,   -22,   -22,   -22,     0,
     -22,   -22,   -22,   -22,   -22,   -22,   -22,     0,     0,     0,
     -22,   -22,     0,     0,   -22,   -22,   -22,   100,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,     0,     0,     0,   -22,
     -22,   -22,     0,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,     0,   -22,   -22,     0,   -22,   -22,   -22,
     -22,     0,     0,     0,     0,   -22,   -22,   -22,     0,     0,
     -22,   -22,   -22,   -22,   -22,     0,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,     0,
     -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,   212,     0,     0,   -55,   -55,   -55,   -55,
     -55,   -55,     0,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
       0,     0,     0,   -55,   -55,     0,     0,   -55,   -55,   -55,
       0,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,     0,
       0,     0,   -55,   -55,   -55,     0,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,     0,   -55,   -55,     0,
     -55,   -55,   -55,   -55,     0,     0,     0,     0,   -55,   -55,
     -55,     0,     0,   -55,   -55,   -55,   -55,   213,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -55,     0,
       0,     0,     0,   -55,     0,   -55,   -55,   -55,     0,     0,
       0,     0,   -55,   -55,     0,   -55,     2,     3,     0,     0,
       4,     5,     6,     7,     8,     9,     0,    10,    11,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,    29,    30,
      31,    32,    33,    34,     0,    35,    36,    37,    38,     0,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,    49,    50,     0,    51,    52,    53,    54,     0,    55,
      56,     0,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,     0,     0,     0,     0,    67,     0,    68,
      69,     0,     0,     0,   302,     0,    70,  -156,  -156,  -156,
    -156,  -156,  -156,     0,  -156,  -156,     0,  -156,  -156,  -156,
    -156,     0,     0,     0,  -156,  -156,     0,     0,  -156,  -156,
    -156,     0,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,
       0,     0,     0,  -156,  -156,  -156,     0,  -156,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,     0,  -156,  -156,
       0,  -156,  -156,  -156,  -156,     0,     0,     0,     0,  -156,
    -156,  -156,     0,     0,  -156,  -156,  -156,  -156,     0,     0,
       0,     4,     5,     0,     0,     8,     9,     0,     0,  -156,
       0,     0,    13,     0,  -156,     0,  -156,  -156,    19,     0,
       0,     0,    23,  -156,  -156,     0,    26,     0,     0,    29,
       0,     0,    32,     0,     0,     0,     0,     0,    37,    38,
       0,    39,    40,    41,    42,    43,     0,    45,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   341,    57,    58,     0,     0,     0,    62,    63,
      64,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,     0,     0,     0,     0,    67,     0,
       0,    69,     4,     5,     6,     7,     8,     9,     0,    10,
      11,   342,    12,    13,    14,    15,     0,     0,     0,    19,
      20,     0,     0,    23,    24,    25,     0,    26,    27,    28,
      29,    30,    31,    32,    33,     0,     0,     0,    36,    37,
      38,     0,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,    49,    50,     0,    51,    52,    53,    54,
       0,     0,     0,     0,    57,    58,    59,     0,     0,    62,
      63,    64,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    66,     0,     0,     0,     0,    67,
       0,     0,    69,     0,     0,     0,     0,     0,    70,     0,
       0,   249,     4,     5,     6,     7,     8,     9,     0,    10,
      11,     0,    12,    13,    14,    15,     0,     0,     0,    19,
      20,     0,     0,    23,    24,    25,     0,    26,    27,    28,
      29,    30,    31,    32,    33,     0,     0,     0,    36,    37,
      38,     0,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,    49,    50,     0,    51,    52,    53,    54,
       0,     0,     0,     0,    57,    58,    59,     0,     0,    62,
      63,    64,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    66,     0,     0,     0,     0,    67,
       0,   393,    69,     0,     0,     0,     0,     0,    70,   394,
       4,     5,     6,     7,     8,     9,     0,    10,    11,     0,
      12,    13,    14,    15,     0,     0,     0,    19,    20,     0,
       0,    23,    24,    25,     0,    26,    27,    28,    29,    30,
      31,    32,    33,     0,     0,     0,    36,    37,    38,     0,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,    49,    50,     0,    51,    52,    53,    54,     0,     0,
       0,     0,    57,    58,    59,     0,     0,    62,    63,    64,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    66,     0,     0,     0,     0,    67,     0,   393,
      69,     0,     0,     0,     0,     0,    70,   543,     4,     5,
       6,     7,     8,     9,     0,    10,    11,     0,    12,    13,
      14,    15,     0,     0,     0,    19,    20,     0,     0,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,     0,     0,     0,    36,    37,    38,     0,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,    49,
      50,     0,    51,    52,    53,    54,     0,     0,     0,     0,
      57,    58,    59,     0,     0,    62,    63,    64,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      66,     0,     0,     0,     0,    67,     0,     0,    69,     0,
       0,     0,   216,     0,    70,     4,     5,     6,     7,     8,
       9,     0,    10,    11,     0,    12,    13,    14,    15,     0,
       0,     0,    19,    20,     0,     0,    23,    24,    25,     0,
      26,    27,    28,    29,    30,    31,    32,    33,     0,     0,
       0,    36,    37,    38,     0,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,    49,    50,     0,    51,
      52,    53,    54,     0,     0,     0,     0,    57,    58,    59,
       0,     0,    62,    63,    64,    65,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    66,     0,     0,
       0,     0,    67,     0,     0,    69,   453,     0,     0,     0,
       0,    70,     4,     5,     6,     7,     8,     9,     0,    10,
      11,     0,    12,    13,    14,    15,     0,     0,     0,    19,
      20,     0,     0,    23,    24,    25,     0,    26,    27,    28,
      29,    30,    31,    32,    33,     0,     0,     0,    36,    37,
      38,     0,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,     0,    49,    50,     0,    51,    52,    53,    54,
       0,     0,     0,     0,    57,    58,    59,     0,     0,    62,
      63,    64,    65,   199,     0,     0,     4,     0,     0,     0,
       8,     9,     0,     0,    66,     0,     0,    13,     0,    67,
       0,     0,    69,    19,     0,     0,     0,    23,    70,     0,
       0,    26,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,    39,    40,    41,    42,
      43,     0,    45,     0,     0,    48,   339,     0,     0,     4,
       0,     0,     0,     8,     9,     0,     0,     0,    57,    58,
      13,     0,     0,    62,    63,    64,    19,     0,     0,     0,
      23,     0,     0,     0,    26,     0,     0,    29,    66,     0,
       0,     0,     0,    67,     0,     0,    69,    38,     0,    39,
      40,    41,    42,    43,     0,    45,     0,     0,    48,     0,
       0,     0,     0,     0,     4,     5,     0,     0,     8,     9,
       0,    57,    58,     0,     0,    13,    62,    63,    64,     0,
       0,    19,     0,     0,     0,    23,     0,     0,     0,    26,
       0,    66,    29,     0,     0,    32,    67,     0,     0,    69,
       0,    37,    38,     0,    39,    40,    41,    42,    43,     0,
      45,     0,     0,    48,     0,     0,     0,     0,     0,     4,
       5,     0,     0,     8,     9,   305,    57,    58,     0,     0,
      13,    62,    63,    64,    65,     0,    19,     0,     0,     0,
      23,     0,     0,     0,    26,     0,    66,    29,     0,     0,
      32,    67,     0,     0,    69,     0,    37,    38,     0,    39,
      40,    41,    42,    43,     0,    45,     0,     0,    48,     0,
       0,     0,     0,     0,     4,     0,     0,     0,     8,     9,
       0,    57,    58,     0,     0,    13,    62,    63,    64,    65,
       0,    19,     0,     0,     0,    23,     0,     0,     0,    26,
       0,    66,    29,     0,     0,     0,    67,     0,     0,    69,
       0,     0,    38,     0,    39,    40,    41,    42,    43,     0,
      45,     0,     0,    48,     0,     0,     0,     4,     0,     0,
       0,     8,     9,     0,     0,   115,    57,    58,    13,     0,
       0,    62,    63,    64,    19,     0,     0,     0,    23,     0,
       0,     0,    26,     0,     0,    29,    66,     0,     0,     0,
       0,    67,     0,     0,    69,    38,     0,    39,    40,    41,
      42,    43,     0,    45,     0,     0,    48,     0,     0,     0,
       4,     0,     0,     0,     8,     9,     0,     0,   305,    57,
      58,    13,     0,     0,    62,    63,    64,    19,     0,     0,
       0,    23,     0,     0,     0,    26,     0,     0,    29,    66,
       0,     0,     0,     0,    67,     0,     0,    69,    38,     0,
      39,    40,    41,    42,    43,     0,    45,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    57,    58,     0,     0,     0,    62,    63,    64,
       0,     0,     0,   107,     0,     0,     0,   112,     0,   114,
     116,     0,    66,     0,     0,   128,     0,    67,     0,     0,
      69,   134,   135,   136,   137,   138,   139,     0,     0,     0,
       0,   143,   144,   145,     0,     0,     0,     0,     0,   149,
       0,     0,     0,     0,   166,   159,   160,   161,   167,   165,
       0,   168,   169,   170,   194,     0,     0,     0,   171,   172,
       0,     0,     0,     0,     0,     0,     0,     0,   173,     0,
       0,     0,   174,     0,     0,   175,     0,     0,     0,     0,
       0,   176,     0,     0,   177,   178,   239,   179,     0,     0,
       0,     0,     0,   180,     0,     0,   181,   182,     0,     0,
     183,     0,     0,     0,     0,   184,     0,     0,   167,   185,
     186,   168,   169,   170,   187,   188,     0,     0,   171,   172,
       0,     0,     0,     0,     0,     0,     0,     0,   173,     0,
       0,     0,   174,     0,     0,   175,     0,     0,     0,     0,
       0,   176,     0,     0,   177,   178,     0,   179,     0,     0,
       0,     0,     0,   180,     0,     0,   181,   182,     0,     0,
     183,     0,     0,     0,     0,   184,     0,     0,     0,   185,
     186,     0,     0,     0,   187,   188,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     0,
       0,   237,     0,     0,     0,     0,     0,     0,   508,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     0,     0,   237,     0,     0,     0,     0,   390,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,     0,   237,     0,     0,     0,     0,
     437,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     0,     0,   237,     0,     0,     0,
       0,   471,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,     0,   237,     0,     0,
       0,     0,   505,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,     0,     0,   237,     0,
       0,   301,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,     0,   237,     0,     0,
     352,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     0,     0,   237,     0,     0,   402,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,     0,   237,     0,     0,   414,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     0,     0,   237,     0,     0,   439,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     0,     0,   237,     0,     0,   446,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,     0,   237,     0,     0,   493,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     0,
       0,   237,     0,     0,   500,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,     0,     0,
     237,     0,     0,   509,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     0,     0,   237,
       0,     0,   516,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,     0,     0,   237,   238,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,     0,   237
};

static const yytype_int16 yycheck[] =
{
       1,   128,   157,     3,     1,     1,   257,   216,   321,   322,
       1,   280,    94,     8,    55,    56,    29,   268,    75,    60,
     447,    75,    12,   274,   275,     8,     8,    75,    75,    42,
     299,    44,    94,     8,    24,    25,    75,   192,    14,    94,
      94,    98,    75,    98,   357,     1,    47,    94,    95,    32,
      98,    47,    99,    66,    67,    94,    12,    32,    53,   486,
      73,    94,    48,    54,    50,    48,    93,    50,    24,    25,
     383,    93,    73,    48,   115,    50,    75,    73,    17,    18,
      54,    54,    73,    84,   293,    96,   337,     8,    84,    93,
      46,    47,   247,    84,    99,    93,    35,    94,    54,    87,
      88,    89,   102,    29,    92,   356,    99,    99,   149,   110,
     361,    94,    93,   240,   110,    93,    42,    73,    44,   110,
     110,    98,    48,    94,    50,   423,   424,    99,    84,   442,
     443,   444,   445,    48,    93,    50,   434,   127,    53,    99,
      66,    67,   455,    98,    38,    94,     8,    73,    99,   462,
     140,    94,   153,   194,   110,     8,   102,   153,    93,   160,
     161,    94,    15,    16,   160,   161,   207,    94,   209,   438,
      75,   127,     5,    96,    94,    99,    29,     8,    94,   448,
      98,    98,    92,   496,   140,    38,    85,    86,    87,    88,
      89,    94,   103,    92,     8,    75,    29,    94,   449,    94,
      96,    94,    35,    94,    94,    53,    95,   458,    41,    42,
      94,    44,   213,    99,    99,   528,   529,   213,    95,    75,
     103,   222,   223,    99,    95,    95,   222,   223,   541,    95,
      95,   222,   223,    66,    67,    96,    95,    95,    95,   490,
      73,    74,   397,    95,    99,    94,    75,    13,    95,    94,
     100,    95,    95,   254,   255,     3,    94,    99,   254,   255,
      95,    28,    75,   254,   305,    95,   222,   223,    95,     8,
      43,     1,     3,    99,    95,    99,   266,     1,   391,   377,
     214,    87,    89,   531,   413,   475,   240,   288,   282,   524,
      29,    -1,   288,    32,   295,    -1,    -1,   288,   254,   295,
     341,    -1,   303,    42,    -1,    44,    -1,   303,    47,    48,
     266,    50,   303,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,   285,
      -1,    -1,   288,    -1,    73,    -1,   377,    -1,    -1,    -1,
      -1,   342,    -1,    73,    -1,    -1,   342,   303,    -1,    -1,
     391,   342,   342,    -1,    84,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     1,    -1,    92,
      -1,    -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,    15,    -1,   384,   385,   386,   387,    -1,   384,   385,
     386,   387,    -1,   384,   385,   386,   387,    -1,    -1,   400,
     401,    -1,    -1,    -1,   400,   401,    -1,    -1,    -1,   400,
     401,    -1,    -1,    -1,   415,    -1,    -1,    -1,    -1,   415,
      -1,     1,    -1,    -1,   415,    -1,     6,    -1,   384,   385,
     386,   387,    66,    67,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   400,   401,   447,    -1,    -1,    -1,
      -1,   447,    -1,    -1,    -1,   456,   447,   447,    -1,   415,
     456,   502,    -1,    -1,    -1,   456,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,   108,    -1,    -1,    -1,    -1,   520,
      -1,    -1,   523,    -1,    -1,   486,    -1,    -1,    -1,    -1,
     486,   532,   222,   223,    -1,   486,   486,    -1,    -1,    -1,
     456,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,   146,    -1,    92,    -1,   517,   518,    -1,    -1,
      -1,   517,   518,    -1,   254,    -1,   517,   518,    -1,    -1,
      -1,    -1,    -1,    -1,   535,    -1,    -1,    -1,   539,   535,
      -1,    -1,    -1,   539,   535,    -1,    -1,    -1,   539,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   288,   193,
      -1,   517,   518,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,   535,
     160,   161,    -1,   539,   218,   219,   220,   221,    -1,    -1,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,    -1,    -1,    -1,   241,   242,    -1,
     244,   245,   246,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   257,    -1,    -1,   206,   160,   161,    -1,
      -1,    -1,    -1,   213,   268,    -1,    -1,    -1,    -1,    -1,
     274,   275,    -1,   277,   278,    -1,    -1,    -1,    -1,    -1,
     284,   285,    -1,    -1,   384,   385,   386,   387,    -1,    -1,
     294,    -1,   242,    -1,    -1,    -1,   246,    -1,    -1,    -1,
     400,   401,    -1,   206,    -1,    -1,    -1,   257,    -1,    -1,
     213,    -1,    -1,    -1,    -1,   415,    -1,    -1,   268,    -1,
      -1,    -1,    -1,    -1,   274,   275,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   337,    -1,    -1,    -1,    -1,    -1,   242,
      -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   356,    -1,   257,   359,   456,   361,    -1,    -1,
      -1,    -1,   366,    -1,    -1,   268,    -1,    -1,    -1,    -1,
      -1,   274,   275,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,   337,    92,    -1,
      -1,    95,    -1,    -1,    -1,   399,    -1,    -1,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   356,    -1,    -1,   413,
      -1,   361,   416,    -1,    -1,    -1,    -1,   517,   518,    -1,
      -1,    -1,   426,    -1,    -1,    -1,    -1,   431,    -1,   433,
      -1,    -1,    -1,    -1,   337,   535,   440,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   449,    -1,   451,    -1,    -1,
      -1,    -1,    -1,   356,   458,    -1,   460,    -1,   361,    -1,
      -1,   465,    -1,   413,    -1,    -1,    -1,    -1,    -1,    -1,
     474,    -1,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,   490,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,   449,
      -1,    -1,    -1,    -1,   508,    -1,    -1,    -1,   458,   513,
     413,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    -1,    92,    -1,    -1,    -1,
      -1,    -1,   536,    99,    -1,    -1,    -1,    -1,    -1,    -1,
     490,    -1,    -1,    -1,    -1,    -1,   449,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   458,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      21,    22,    -1,    -1,    25,    26,    27,   490,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    40,
      41,    42,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    -1,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,
      71,    72,    73,    74,    75,    -1,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,     1,    -1,    -1,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    21,    22,    -1,    -1,    25,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    41,    42,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    -1,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,    67,
      68,    -1,    -1,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    91,    -1,    93,    94,    95,    -1,    -1,
      -1,    -1,   100,   101,    -1,   103,     0,     1,    -1,    -1,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    40,    41,    42,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    -1,    58,    59,    60,    61,    -1,    63,
      64,    -1,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    91,    -1,    93,
      94,    -1,    -1,    -1,     1,    -1,   100,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    14,    15,    16,
      17,    -1,    -1,    -1,    21,    22,    -1,    -1,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    40,    41,    42,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    66,
      67,    68,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,     4,     5,    -1,    -1,     8,     9,    -1,    -1,    86,
      -1,    -1,    15,    -1,    91,    -1,    93,    94,    21,    -1,
      -1,    -1,    25,   100,   101,    -1,    29,    -1,    -1,    32,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    41,    42,
      -1,    44,    45,    46,    47,    48,    -1,    50,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    67,    -1,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    94,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,   104,    14,    15,    16,    17,    -1,    -1,    -1,    21,
      22,    -1,    -1,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    40,    41,
      42,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    -1,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,   100,    -1,
      -1,   103,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    14,    15,    16,    17,    -1,    -1,    -1,    21,
      22,    -1,    -1,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    40,    41,
      42,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    -1,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,    91,
      -1,    93,    94,    -1,    -1,    -1,    -1,    -1,   100,   101,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      14,    15,    16,    17,    -1,    -1,    -1,    21,    22,    -1,
      -1,    25,    26,    27,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    41,    42,    -1,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    -1,    58,    59,    60,    61,    -1,    -1,
      -1,    -1,    66,    67,    68,    -1,    -1,    71,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    91,    -1,    93,
      94,    -1,    -1,    -1,    -1,    -1,   100,   101,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    14,    15,
      16,    17,    -1,    -1,    -1,    21,    22,    -1,    -1,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    41,    42,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    -1,    58,    59,    60,    61,    -1,    -1,    -1,    -1,
      66,    67,    68,    -1,    -1,    71,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    98,    -1,   100,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    14,    15,    16,    17,    -1,
      -1,    -1,    21,    22,    -1,    -1,    25,    26,    27,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    40,    41,    42,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    -1,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    66,    67,    68,
      -1,    -1,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    94,    95,    -1,    -1,    -1,
      -1,   100,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    14,    15,    16,    17,    -1,    -1,    -1,    21,
      22,    -1,    -1,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    40,    41,
      42,    -1,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    -1,    58,    59,    60,    61,
      -1,    -1,    -1,    -1,    66,    67,    68,    -1,    -1,    71,
      72,    73,    74,     1,    -1,    -1,     4,    -1,    -1,    -1,
       8,     9,    -1,    -1,    86,    -1,    -1,    15,    -1,    91,
      -1,    -1,    94,    21,    -1,    -1,    -1,    25,   100,    -1,
      -1,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    44,    45,    46,    47,
      48,    -1,    50,    -1,    -1,    53,     1,    -1,    -1,     4,
      -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    66,    67,
      15,    -1,    -1,    71,    72,    73,    21,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    29,    -1,    -1,    32,    86,    -1,
      -1,    -1,    -1,    91,    -1,    -1,    94,    42,    -1,    44,
      45,    46,    47,    48,    -1,    50,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,    -1,     8,     9,
      -1,    66,    67,    -1,    -1,    15,    71,    72,    73,    -1,
      -1,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,
      -1,    86,    32,    -1,    -1,    35,    91,    -1,    -1,    94,
      -1,    41,    42,    -1,    44,    45,    46,    47,    48,    -1,
      50,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,     4,
       5,    -1,    -1,     8,     9,    65,    66,    67,    -1,    -1,
      15,    71,    72,    73,    74,    -1,    21,    -1,    -1,    -1,
      25,    -1,    -1,    -1,    29,    -1,    86,    32,    -1,    -1,
      35,    91,    -1,    -1,    94,    -1,    41,    42,    -1,    44,
      45,    46,    47,    48,    -1,    50,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,     4,    -1,    -1,    -1,     8,     9,
      -1,    66,    67,    -1,    -1,    15,    71,    72,    73,    74,
      -1,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,
      -1,    86,    32,    -1,    -1,    -1,    91,    -1,    -1,    94,
      -1,    -1,    42,    -1,    44,    45,    46,    47,    48,    -1,
      50,    -1,    -1,    53,    -1,    -1,    -1,     4,    -1,    -1,
      -1,     8,     9,    -1,    -1,    65,    66,    67,    15,    -1,
      -1,    71,    72,    73,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    -1,    -1,    32,    86,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    94,    42,    -1,    44,    45,    46,
      47,    48,    -1,    50,    -1,    -1,    53,    -1,    -1,    -1,
       4,    -1,    -1,    -1,     8,     9,    -1,    -1,    65,    66,
      67,    15,    -1,    -1,    71,    72,    73,    21,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    29,    -1,    -1,    32,    86,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    94,    42,    -1,
      44,    45,    46,    47,    48,    -1,    50,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    67,    -1,    -1,    -1,    71,    72,    73,
      -1,    -1,    -1,     8,    -1,    -1,    -1,    12,    -1,    14,
      15,    -1,    86,    -1,    -1,    20,    -1,    91,    -1,    -1,
      94,    26,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,     1,    50,    51,    52,     5,    54,
      -1,     8,     9,    10,    59,    -1,    -1,    -1,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    41,    42,    91,    44,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,
      57,    -1,    -1,    -1,    -1,    62,    -1,    -1,     5,    66,
      67,     8,     9,    10,    71,    72,    -1,    -1,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    -1,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    41,    42,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    53,    54,    -1,    -1,
      57,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    66,
      67,    -1,    -1,    -1,    71,    72,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    -1,    92,    -1,    -1,    -1,    -1,    97,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      97,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    -1,    92,    -1,    -1,    -1,
      -1,    97,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    97,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    -1,    92,    -1,
      -1,    95,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    -1,    -1,    92,    -1,    -1,
      95,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    -1,    -1,    92,    -1,    -1,    95,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    92,    -1,    -1,    95,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    -1,    -1,    92,    -1,    -1,    95,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    -1,    -1,    92,    -1,    -1,    95,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      -1,    -1,    92,    -1,    -1,    95,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    -1,
      -1,    92,    -1,    -1,    95,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    -1,    -1,
      92,    -1,    -1,    95,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    -1,    -1,    92,
      -1,    -1,    95,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    -1,    -1,    92,    93,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    -1,    -1,    92
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   106,     0,     1,     4,     5,     6,     7,     8,     9,
      11,    12,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    39,    40,    41,    42,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    55,
      56,    58,    59,    60,    61,    63,    64,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    86,    91,    93,    94,
     100,   108,   109,   111,   112,   115,   116,   119,   120,   121,
     122,   123,   124,   126,   143,   149,   150,   153,   158,   159,
     163,   164,   165,   169,   176,   187,   108,   111,   112,   122,
     123,   143,   149,   163,   174,     8,   175,   160,    94,   154,
      94,   143,   160,   169,   160,    65,   160,   163,     8,    15,
      16,    29,    38,   181,   200,   181,   181,    94,   160,    93,
      93,   169,   189,   169,   160,   160,   160,   160,   160,   160,
      14,   107,   181,   160,   160,   160,    75,   172,   173,   160,
     144,   143,   145,   146,   111,   112,   143,   151,    54,   160,
     160,   160,    54,   143,   149,   160,     1,     5,     8,     9,
      10,    15,    16,    25,    29,    32,    38,    41,    42,    44,
      50,    53,    54,    57,    62,    66,    67,    71,    72,   201,
     201,     1,   110,    96,   160,   201,     8,   163,   163,     1,
     163,   131,    93,   122,   126,   163,    75,    98,    93,    99,
      99,    93,     1,    75,    99,    93,    98,   126,    75,    94,
     154,    94,   157,   157,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    92,    93,   160,
      99,    75,    94,    93,    75,    94,    99,   170,   163,   103,
     126,   169,    98,    38,   141,   142,   127,    94,   201,   177,
     178,   180,   169,   166,   168,   200,    99,   102,    94,   125,
     201,   169,    93,   179,    94,    94,   163,    75,    96,   147,
     148,   201,   160,   171,    94,    99,   111,   171,   136,   111,
     122,   111,   122,    98,    94,   132,   171,   163,   117,   118,
     201,    95,     1,   162,   161,    65,   122,   163,   201,   201,
       8,   111,   122,   125,     8,   150,   163,   163,   155,   163,
     163,   126,   126,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,    94,   166,     1,
     163,    65,   104,   122,   163,   184,   185,   186,   163,   122,
     163,   171,    95,   103,    95,    99,    94,   126,   111,    75,
     184,    94,    94,    94,    94,    95,    96,   167,   169,   188,
     184,   129,    94,   184,   184,   163,   163,    99,   167,   173,
     163,   143,   163,   126,   139,   137,   140,   138,   163,   111,
      97,    99,   167,    93,   101,   126,   201,   113,    95,   102,
     103,   156,    95,   161,   161,   184,   201,    47,   111,   149,
     152,   169,    95,    99,    95,   133,   134,   184,   161,   163,
      95,   184,    95,    95,    95,   163,    96,     3,   102,   190,
     192,   193,    95,    75,    95,    95,    95,    97,   148,    95,
      94,   161,   126,   126,   126,   126,    95,    99,   118,    94,
     171,    75,   163,    95,   126,   126,    13,    95,    94,     1,
      94,   186,   126,   163,    95,    99,    95,   100,   182,   182,
     182,    97,   163,   194,   195,   191,     3,   163,   163,   182,
     167,   163,   161,   161,   161,   161,    99,   152,   167,   184,
      94,   114,   163,    95,    95,   161,   126,   184,   163,   161,
      95,   163,    28,   196,   197,    97,   163,   192,    99,    95,
     152,    95,   184,    75,   161,    95,    95,   135,   128,   201,
      43,   198,   199,    99,     3,   163,    95,   163,   126,   126,
     201,   183,    99,   201,   194,   130,   102,   161,   161,   162,
     201,   126,   163,   101,   161
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   105,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   107,   106,   106,   108,   108,   108,   108,   108,
     108,   108,   110,   109,   109,   109,   109,   109,   109,   111,
     112,   113,   112,   112,   114,   114,   115,   115,   115,   115,
     115,   116,   117,   117,   117,   117,   118,   119,   119,   120,
     120,   121,   121,   121,   121,   122,   122,   122,   123,   123,
     124,   124,   125,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   127,   128,   126,   129,   130,   126,   126,   126,   126,
     131,   126,   126,   126,   126,   126,   126,   132,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   133,   126,   134,
     135,   126,   136,   126,   137,   126,   138,   126,   139,   126,
     140,   126,   141,   142,   141,   144,   143,   143,   145,   146,
     145,   147,   147,   147,   147,   148,   149,   149,   151,   150,
     152,   152,   152,   152,   152,   153,   153,   154,   155,   156,
     156,   157,   158,   159,   160,   161,   162,   162,   162,   162,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   164,   164,   164,   164,   165,   165,   166,   167,   167,
     168,   169,   170,   169,   169,   171,   172,   173,   173,   174,
     174,   174,   174,   175,   177,   176,   178,   176,   179,   176,
     180,   176,   181,   181,   181,   181,   181,   183,   182,   184,
     184,   185,   185,   186,   186,   186,   186,   187,   188,   187,
     189,   189,   190,   190,   191,   190,   193,   192,   195,   194,
     196,   196,   197,   197,   198,   198,   199,   199,   200,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     0,     4,     2,     3,     3,     4,     3,     7,
       3,     3,     0,     3,     1,     1,     4,     5,     5,     1,
       1,     0,     6,     2,     0,     3,     2,     1,     1,     2,
       2,     3,     1,     2,     3,     4,     1,     2,     3,     2,
       3,     3,     3,     3,     2,     1,     1,     5,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     6,     2,     2,     2,     2,     5,     2,     5,
       6,     0,     0,    10,     0,     0,    11,     4,     4,     7,
       0,     4,     1,     3,     4,     7,     7,     0,     6,     2,
       2,     2,     2,     2,     3,    10,     6,     0,     7,     0,
       0,    10,     0,     5,     0,     6,     0,     6,     0,     6,
       0,     6,     4,     0,     2,     0,     3,     1,     4,     0,
       2,     1,     2,     3,     4,     1,     1,     3,     0,     3,
       1,     4,     1,     2,     1,     4,     3,     0,     1,     3,
       2,     3,     2,     1,     0,     0,     0,     2,     2,     1,
       1,     1,     1,     1,     2,     1,     4,     1,     1,     5,
       4,     4,     4,     3,     2,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     1,     1,     1,     3,     3,     2,     3,     4,
       1,     2,     0,     4,     3,     2,     1,     0,     4,     1,
       1,     3,     3,     1,     0,     6,     0,     6,     0,     6,
       0,     6,     1,     1,     1,     1,     1,     0,     6,     0,
       1,     1,     3,     1,     1,     2,     5,     2,     0,     5,
       1,     3,     2,     2,     0,     5,     0,     2,     0,     2,
       0,     1,     2,     3,     0,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 138 "parse.y" /* yacc.c:1646  */
    { ntab = 0;}
#line 2326 "parse.c" /* yacc.c:1646  */
    break;

  case 3:
#line 139 "parse.y" /* yacc.c:1646  */
    { return '\n';}
#line 2332 "parse.c" /* yacc.c:1646  */
    break;

  case 4:
#line 140 "parse.y" /* yacc.c:1646  */
    { return '\n';}
#line 2338 "parse.c" /* yacc.c:1646  */
    break;

  case 5:
#line 142 "parse.y" /* yacc.c:1646  */
    { hoc_ob_check(-1); code2(nopop, STOP); return 1; }
#line 2344 "parse.c" /* yacc.c:1646  */
    break;

  case 6:
#line 144 "parse.y" /* yacc.c:1646  */
    { codein(STOP); return 1; }
#line 2350 "parse.c" /* yacc.c:1646  */
    break;

  case 7:
#line 146 "parse.y" /* yacc.c:1646  */
    { TPDYNAM; code2(print, STOP); return 1; }
#line 2356 "parse.c" /* yacc.c:1646  */
    break;

  case 8:
#line 148 "parse.y" /* yacc.c:1646  */
    { debug(); return '\n';}
#line 2362 "parse.c" /* yacc.c:1646  */
    break;

  case 9:
#line 150 "parse.y" /* yacc.c:1646  */
    { return 'e';}
#line 2368 "parse.c" /* yacc.c:1646  */
    break;

  case 10:
#line 152 "parse.y" /* yacc.c:1646  */
    {code(prstr); code2(hoc_newline, STOP); return 1; }
#line 2374 "parse.c" /* yacc.c:1646  */
    break;

  case 11:
#line 155 "parse.y" /* yacc.c:1646  */
    { return '\n';}
#line 2380 "parse.c" /* yacc.c:1646  */
    break;

  case 12:
#line 161 "parse.y" /* yacc.c:1646  */
    {hoc_help();}
#line 2386 "parse.c" /* yacc.c:1646  */
    break;

  case 13:
#line 161 "parse.y" /* yacc.c:1646  */
    { return '\n'; }
#line 2392 "parse.c" /* yacc.c:1646  */
    break;

  case 14:
#line 163 "parse.y" /* yacc.c:1646  */
    {clean_err(); hoc_execerror("parse error", (char*)0);
#if LINT
if (0) {
if(yydebug);
goto yynewstate;
}
#endif
		}
#line 2405 "parse.c" /* yacc.c:1646  */
    break;

  case 15:
#line 173 "parse.y" /* yacc.c:1646  */
    {Symbol *s; TPD; s = spop();
		hoc_obvar_declare(s, VAR, 1);
		code3(varpush, s, assign); codei((yyvsp[-1].narg)); PN;}
#line 2413 "parse.c" /* yacc.c:1646  */
    break;

  case 16:
#line 177 "parse.y" /* yacc.c:1646  */
    {  TPD; defnonly("$"); argcode(argassign, (yyvsp[-2].narg)); codei((yyvsp[-1].narg)); (yyval.inst)=(yyvsp[0].inst); PN;}
#line 2419 "parse.c" /* yacc.c:1646  */
    break;

  case 17:
#line 179 "parse.y" /* yacc.c:1646  */
    { TPD; defnonly("$&"); argrefcode(hoc_argrefasgn, (yyvsp[-3].narg), (yyvsp[-2].narg)); codei((yyvsp[-1].narg)); (yyval.inst)=(yyvsp[0].inst); PN;}
#line 2425 "parse.c" /* yacc.c:1646  */
    break;

  case 18:
#line 182 "parse.y" /* yacc.c:1646  */
    { TPD; code(range_const); codesym(spop()); codei((yyvsp[-1].narg)); PN;}
#line 2431 "parse.c" /* yacc.c:1646  */
    break;

  case 19:
#line 186 "parse.y" /* yacc.c:1646  */
    { Inst* p; hoc_opasgn_invalid((yyvsp[-5].narg));
		 code(hoc_newobj); codesym(hoc_which_template((yyvsp[-3].sym))); codei((yyvsp[-1].narg));
		 p = (Inst*)spop();
		 if (p) { p->i += 2; }
		}
#line 2441 "parse.c" /* yacc.c:1646  */
    break;

  case 20:
#line 192 "parse.y" /* yacc.c:1646  */
    {Inst* p; TPDYNAM; code(hoc_object_asgn); codei((yyvsp[-1].narg));
		 p = (Inst*)spop();
		 if (p) { p->i += 2; }
		}
#line 2450 "parse.c" /* yacc.c:1646  */
    break;

  case 21:
#line 197 "parse.y" /* yacc.c:1646  */
    {myerr("assignment to variable, make sure right side is a number");}
#line 2456 "parse.c" /* yacc.c:1646  */
    break;

  case 22:
#line 201 "parse.y" /* yacc.c:1646  */
    {pushi(OBJECTVAR);pushs((yyvsp[0].sym)); pushi(CHECK);}
#line 2462 "parse.c" /* yacc.c:1646  */
    break;

  case 23:
#line 202 "parse.y" /* yacc.c:1646  */
    {(yyval.inst) = (yyvsp[0].inst); code(hoc_objectvar); spop(); codesym((yyvsp[-2].sym));}
#line 2468 "parse.c" /* yacc.c:1646  */
    break;

  case 24:
#line 204 "parse.y" /* yacc.c:1646  */
    {defnonly("$o"); (yyval.inst) = argcode(hoc_objectarg, (yyvsp[0].narg)); pushi(OBJECTVAR);}
#line 2474 "parse.c" /* yacc.c:1646  */
    break;

  case 25:
#line 206 "parse.y" /* yacc.c:1646  */
    {(yyval.inst) = code(hoc_autoobject); codesym((yyvsp[0].sym)); pushi(OBJECTVAR);}
#line 2480 "parse.c" /* yacc.c:1646  */
    break;

  case 26:
#line 208 "parse.y" /* yacc.c:1646  */
    {TPD; (yyval.inst) = (yyvsp[-1].inst); code(hoc_constobject); codesym((yyvsp[-3].sym)); pushi(OBJECTVAR);}
#line 2486 "parse.c" /* yacc.c:1646  */
    break;

  case 27:
#line 210 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-3].inst); code(call); codesym((yyvsp[-4].sym)); codei((yyvsp[-1].narg));
		  code(hoc_known_type); codei(OBJECTVAR); pushi(OBJECTVAR);}
#line 2493 "parse.c" /* yacc.c:1646  */
    break;

  case 28:
#line 213 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-3].inst); code(call); codesym((yyvsp[-4].sym)); codei((yyvsp[-1].narg));
		  code(hoc_known_type); codei(OBJECTVAR); pushi(OBJECTVAR);}
#line 2500 "parse.c" /* yacc.c:1646  */
    break;

  case 29:
#line 217 "parse.y" /* yacc.c:1646  */
    { spop(); }
#line 2506 "parse.c" /* yacc.c:1646  */
    break;

  case 30:
#line 220 "parse.y" /* yacc.c:1646  */
    { pushs((Symbol*)0); }
#line 2512 "parse.c" /* yacc.c:1646  */
    break;

  case 31:
#line 221 "parse.y" /* yacc.c:1646  */
    {pushs((yyvsp[0].sym));pushi(NOCHECK);}
#line 2518 "parse.c" /* yacc.c:1646  */
    break;

  case 32:
#line 222 "parse.y" /* yacc.c:1646  */
    {int isfunc; Inst* p;
		 isfunc = ipop();
		 code(hoc_object_component); codesym(spop()); codei(ipop());
		 codei((yyvsp[0].narg));
		 codei(0); codesym(0);
		 p = codei(isfunc); /* for USE_PYTHON */
		 spop();
		 pushs((Symbol*)p); /* in case assigning to a PythonObject we will want to update isfunc to 2 */
		}
#line 2532 "parse.c" /* yacc.c:1646  */
    break;

  case 33:
#line 231 "parse.y" /* yacc.c:1646  */
    {myerr("object syntax is o1.o2.o3.");}
#line 2538 "parse.c" /* yacc.c:1646  */
    break;

  case 34:
#line 234 "parse.y" /* yacc.c:1646  */
    {(yyval.narg) = 0; pushi(0);}
#line 2544 "parse.c" /* yacc.c:1646  */
    break;

  case 35:
#line 236 "parse.y" /* yacc.c:1646  */
    {(yyval.narg) = (yyvsp[-1].narg); pushi(1);}
#line 2550 "parse.c" /* yacc.c:1646  */
    break;

  case 36:
#line 238 "parse.y" /* yacc.c:1646  */
    {hoc_begintemplate((yyvsp[0].sym));}
#line 2556 "parse.c" /* yacc.c:1646  */
    break;

  case 39:
#line 241 "parse.y" /* yacc.c:1646  */
    {hoc_endtemplate((yyvsp[0].sym));}
#line 2562 "parse.c" /* yacc.c:1646  */
    break;

  case 40:
#line 242 "parse.y" /* yacc.c:1646  */
    {myerr("begintemplate Name\npublic namelist\nexternal namelist\n...\nendtemplate Name");}
#line 2568 "parse.c" /* yacc.c:1646  */
    break;

  case 41:
#line 245 "parse.y" /* yacc.c:1646  */
    {(yyval.inst) = (yyvsp[-1].inst);}
#line 2574 "parse.c" /* yacc.c:1646  */
    break;

  case 42:
#line 248 "parse.y" /* yacc.c:1646  */
    {code(hoc_objvardecl); codesym((yyvsp[0].sym)); codei(0);}
#line 2580 "parse.c" /* yacc.c:1646  */
    break;

  case 43:
#line 250 "parse.y" /* yacc.c:1646  */
    {code(hoc_objvardecl); codesym((yyvsp[-1].sym)); codei((yyvsp[0].narg));}
#line 2586 "parse.c" /* yacc.c:1646  */
    break;

  case 44:
#line 252 "parse.y" /* yacc.c:1646  */
    {code(hoc_objvardecl); codesym((yyvsp[0].sym)); codei(0);}
#line 2592 "parse.c" /* yacc.c:1646  */
    break;

  case 45:
#line 254 "parse.y" /* yacc.c:1646  */
    {code(hoc_objvardecl); codesym((yyvsp[-1].sym)); codei((yyvsp[0].narg));}
#line 2598 "parse.c" /* yacc.c:1646  */
    break;

  case 46:
#line 257 "parse.y" /* yacc.c:1646  */
    {
		  Symbol* s;
		  s = hoc_decl((yyvsp[0].sym));
		  if (s->type != UNDEF && s->type != OBJECTVAR) {
			acterror(s->name, " already declared");
		  }
		  (yyval.sym) = s;
		}
#line 2611 "parse.c" /* yacc.c:1646  */
    break;

  case 47:
#line 267 "parse.y" /* yacc.c:1646  */
    {hoc_add_publiclist((yyvsp[0].sym));}
#line 2617 "parse.c" /* yacc.c:1646  */
    break;

  case 48:
#line 269 "parse.y" /* yacc.c:1646  */
    {hoc_add_publiclist((yyvsp[0].sym));}
#line 2623 "parse.c" /* yacc.c:1646  */
    break;

  case 49:
#line 272 "parse.y" /* yacc.c:1646  */
    {hoc_external_var((yyvsp[0].sym));}
#line 2629 "parse.c" /* yacc.c:1646  */
    break;

  case 50:
#line 274 "parse.y" /* yacc.c:1646  */
    {hoc_external_var((yyvsp[0].sym));}
#line 2635 "parse.c" /* yacc.c:1646  */
    break;

  case 51:
#line 279 "parse.y" /* yacc.c:1646  */
    {hoc_opasgn_invalid((yyvsp[-1].narg)); code(assstr);}
#line 2641 "parse.c" /* yacc.c:1646  */
    break;

  case 52:
#line 281 "parse.y" /* yacc.c:1646  */
    {Inst* p = (Inst*) spop(); pushi(STRING); TPDYNAM; code(hoc_object_asgn);
		 hoc_opasgn_invalid((yyvsp[-1].narg)); codei((yyvsp[-1].narg)); hoc_ob_check(-1); code(nopop);
		 if (p) { p->i += 2; }
		}
#line 2650 "parse.c" /* yacc.c:1646  */
    break;

  case 53:
#line 286 "parse.y" /* yacc.c:1646  */
    {code(hoc_asgn_obj_to_str); hoc_opasgn_invalid((yyvsp[-1].narg)); }
#line 2656 "parse.c" /* yacc.c:1646  */
    break;

  case 54:
#line 287 "parse.y" /* yacc.c:1646  */
    {myerr("string assignment: both sides need to be a string");}
#line 2662 "parse.c" /* yacc.c:1646  */
    break;

  case 56:
#line 292 "parse.y" /* yacc.c:1646  */
    {(yyval.inst) = code(hoc_push_string); codesym((yyvsp[0].sym));}
#line 2668 "parse.c" /* yacc.c:1646  */
    break;

  case 57:
#line 294 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-3].inst); code(call); codesym((yyvsp[-4].sym)); codei((yyvsp[-1].narg));}
#line 2674 "parse.c" /* yacc.c:1646  */
    break;

  case 58:
#line 298 "parse.y" /* yacc.c:1646  */
    {(yyval.inst) = code(hoc_push_string); codesym((yyvsp[0].sym));}
#line 2680 "parse.c" /* yacc.c:1646  */
    break;

  case 59:
#line 300 "parse.y" /* yacc.c:1646  */
    {defnonly("$s"); (yyval.inst) = argcode(hoc_stringarg, (yyvsp[0].narg));}
#line 2686 "parse.c" /* yacc.c:1646  */
    break;

  case 60:
#line 304 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-1].inst); }
#line 2692 "parse.c" /* yacc.c:1646  */
    break;

  case 62:
#line 308 "parse.y" /* yacc.c:1646  */
    {
			Symbol* s = hoc_decl((yyvsp[0].sym));
			if (s->type == UNDEF) {
				hoc_obvar_declare(s, STRING, 0);
				OPSTR(s) = (char**)emalloc(sizeof(char*));
				*OPSTR(s) = 0;
			}else if (s->type != STRING) {
				acterror(s->name, " already declared");
			}
			hoc_assign_str(OPSTR(s), "");
		}
#line 2708 "parse.c" /* yacc.c:1646  */
    break;

  case 63:
#line 321 "parse.y" /* yacc.c:1646  */
    { code(nopop); hoc_ob_check(-1); /*don't check*/}
#line 2714 "parse.c" /* yacc.c:1646  */
    break;

  case 68:
#line 329 "parse.y" /* yacc.c:1646  */
    { code(nopop); }
#line 2720 "parse.c" /* yacc.c:1646  */
    break;

  case 69:
#line 331 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[0].inst);}
#line 2726 "parse.c" /* yacc.c:1646  */
    break;

  case 70:
#line 333 "parse.y" /* yacc.c:1646  */
    { defnonly("return"); (yyval.inst)=(yyvsp[0].inst); code(procret); }
#line 2732 "parse.c" /* yacc.c:1646  */
    break;

  case 71:
#line 335 "parse.y" /* yacc.c:1646  */
    {  if (indef == 3) {
			TPDYNAM; (yyval.inst) = (yyvsp[0].inst);
			code(hocobjret);
		   }else{
			TPD; defnonly("return"); (yyval.inst)=(yyvsp[0].inst);
			code(funcret);
		   }
		}
#line 2745 "parse.c" /* yacc.c:1646  */
    break;

  case 72:
#line 344 "parse.y" /* yacc.c:1646  */
    {(yyval.inst) = code(hoc_newobj_ret); codesym(hoc_which_template((yyvsp[-3].sym))); codei((yyvsp[-1].narg));
		 code(hocobjret);
		}
#line 2753 "parse.c" /* yacc.c:1646  */
    break;

  case 73:
#line 348 "parse.y" /* yacc.c:1646  */
    { if (indef != 2) {
acterror("iterator_statement used outside an iterator declaration", 0);
		  }
			code(hoc_iterator_stmt);
		}
#line 2763 "parse.c" /* yacc.c:1646  */
    break;

  case 74:
#line 354 "parse.y" /* yacc.c:1646  */
    { code(Break); (yyval.inst) = (yyvsp[0].inst); }
#line 2769 "parse.c" /* yacc.c:1646  */
    break;

  case 75:
#line 356 "parse.y" /* yacc.c:1646  */
    { code(Stop); (yyval.inst) = (yyvsp[0].inst); }
#line 2775 "parse.c" /* yacc.c:1646  */
    break;

  case 76:
#line 358 "parse.y" /* yacc.c:1646  */
    { code(Continue); (yyval.inst) = (yyvsp[0].inst); }
#line 2781 "parse.c" /* yacc.c:1646  */
    break;

  case 77:
#line 360 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-3].inst); code(call); codesym((yyvsp[-4].sym)); codei((yyvsp[-1].narg)); code(nopop); }
#line 2787 "parse.c" /* yacc.c:1646  */
    break;

  case 78:
#line 362 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[0].inst); code(hoc_newline); }
#line 2793 "parse.c" /* yacc.c:1646  */
    break;

  case 79:
#line 364 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-3].inst);
		  ((yyvsp[-2].inst))[0].i = relative((yyvsp[-1].inst), (yyvsp[-2].inst), 0); /* body */
		  ((yyvsp[-2].inst))[1].i = relative((yyvsp[0].inst), (yyvsp[-2].inst), 1); /* exit */
		}
#line 2802 "parse.c" /* yacc.c:1646  */
    break;

  case 80:
#line 369 "parse.y" /* yacc.c:1646  */
    {
			((yyvsp[-4].inst))[1].i =relative((yyvsp[-1].inst), (yyvsp[-4].inst), 1);	/* body */
			((yyvsp[-4].inst))[2].i =relative((yyvsp[0].inst), (yyvsp[-4].inst), 2); /* exit from the for */
			((yyvsp[-4].inst))[3].i  =relative((yyvsp[-2].inst), (yyvsp[-4].inst), 3);	/* increment */
			(yyval.inst) = (yyvsp[-5].inst);
#if LINT
if (0){YYERROR;}
#endif
			}
#line 2816 "parse.c" /* yacc.c:1646  */
    break;

  case 81:
#line 379 "parse.y" /* yacc.c:1646  */
    { Symbol *s; (yyval.inst) = Code(varpush); codesym(s = spop());
			hoc_obvar_declare(s, VAR, 1);
		  }
#line 2824 "parse.c" /* yacc.c:1646  */
    break;

  case 82:
#line 383 "parse.y" /* yacc.c:1646  */
    {TPD; TPD; hoc_opasgn_invalid((yyvsp[-3].narg)); 
		    (yyval.inst) = code(shortfor); codei(0); codei(0);}
#line 2831 "parse.c" /* yacc.c:1646  */
    break;

  case 83:
#line 386 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-8].inst); ((yyvsp[-2].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-2].inst), 1); /* body */
			   ((yyvsp[-2].inst))[2].i = relative((yyvsp[0].inst), (yyvsp[-2].inst), 2); /* exit */
		  }
#line 2839 "parse.c" /* yacc.c:1646  */
    break;

  case 84:
#line 390 "parse.y" /* yacc.c:1646  */
    { Symbol *s; (yyval.inst) = Code(varpush); codesym(s = spop());
			hoc_obvar_declare(s, VAR, 1);
		  }
#line 2847 "parse.c" /* yacc.c:1646  */
    break;

  case 85:
#line 394 "parse.y" /* yacc.c:1646  */
    {TPD; TPD; hoc_opasgn_invalid((yyvsp[-3].narg)); 
		     code(hoc_parallel_begin);
		     (yyval.inst) = code(shortfor); codei(0); codei(0);}
#line 2855 "parse.c" /* yacc.c:1646  */
    break;

  case 86:
#line 398 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-8].inst); ((yyvsp[-2].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-2].inst), 1); /* body */
			   ((yyvsp[-2].inst))[2].i = relative((yyvsp[0].inst), (yyvsp[-2].inst), 2); /* exit */
			code(hoc_parallel_end);
		  }
#line 2864 "parse.c" /* yacc.c:1646  */
    break;

  case 87:
#line 403 "parse.y" /* yacc.c:1646  */
    {
		((yyvsp[-3].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-3].inst), 1);	/* body of loop */
		((yyvsp[-3].inst))[2].i = relative((yyvsp[0].inst), (yyvsp[-3].inst), 2); }
#line 2872 "parse.c" /* yacc.c:1646  */
    break;

  case 88:
#line 407 "parse.y" /* yacc.c:1646  */
    {
		((yyvsp[-3].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-3].inst), 1);	/* thenpart */
		((yyvsp[-3].inst))[3].i = relative((yyvsp[0].inst), (yyvsp[-3].inst), 3); }
#line 2880 "parse.c" /* yacc.c:1646  */
    break;

  case 89:
#line 411 "parse.y" /* yacc.c:1646  */
    {
		((yyvsp[-6].inst))[1].i = relative((yyvsp[-4].inst), (yyvsp[-6].inst), 1);	/* thenpart */
		((yyvsp[-6].inst))[2].i = relative((yyvsp[-1].inst), (yyvsp[-6].inst), 2);	/* elsepart */
		((yyvsp[-6].inst))[3].i = relative((yyvsp[0].inst), (yyvsp[-6].inst), 3); }
#line 2889 "parse.c" /* yacc.c:1646  */
    break;

  case 90:
#line 416 "parse.y" /* yacc.c:1646  */
    { ntab++;}
#line 2895 "parse.c" /* yacc.c:1646  */
    break;

  case 91:
#line 418 "parse.y" /* yacc.c:1646  */
    {
		ntab--; (yyval.inst) = (yyvsp[-1].inst);
		}
#line 2903 "parse.c" /* yacc.c:1646  */
    break;

  case 93:
#line 424 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-1].inst); }
#line 2909 "parse.c" /* yacc.c:1646  */
    break;

  case 94:
#line 426 "parse.y" /* yacc.c:1646  */
    { TPD; (yyval.inst) = (yyvsp[-2].inst); code(connectsection);}
#line 2915 "parse.c" /* yacc.c:1646  */
    break;

  case 95:
#line 428 "parse.y" /* yacc.c:1646  */
    { TPD; (yyval.inst) = (yyvsp[-5].inst); code(simpleconnectsection);}
#line 2921 "parse.c" /* yacc.c:1646  */
    break;

  case 96:
#line 430 "parse.y" /* yacc.c:1646  */
    { TPD; (yyval.inst) = (yyvsp[-5].inst); code(connectpointer); codesym(spop());}
#line 2927 "parse.c" /* yacc.c:1646  */
    break;

  case 97:
#line 431 "parse.y" /* yacc.c:1646  */
    {code(nrn_cppp);}
#line 2933 "parse.c" /* yacc.c:1646  */
    break;

  case 98:
#line 432 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-4].inst); code(connect_point_process_pointer);
			 hoc_ob_check(-1);}
#line 2940 "parse.c" /* yacc.c:1646  */
    break;

  case 99:
#line 435 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[0].inst); code(sec_access);}
#line 2946 "parse.c" /* yacc.c:1646  */
    break;

  case 100:
#line 437 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[0].inst); hoc_ob_check(SECTION); code(sec_access_object);}
#line 2952 "parse.c" /* yacc.c:1646  */
    break;

  case 101:
#line 439 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = Code(mech_access); codesym((yyvsp[0].sym));}
#line 2958 "parse.c" /* yacc.c:1646  */
    break;

  case 102:
#line 441 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = Code(mech_uninsert); codesym((yyvsp[0].sym));}
#line 2964 "parse.c" /* yacc.c:1646  */
    break;

  case 103:
#line 443 "parse.y" /* yacc.c:1646  */
    { code(sec_access_pop);}
#line 2970 "parse.c" /* yacc.c:1646  */
    break;

  case 104:
#line 445 "parse.y" /* yacc.c:1646  */
    { code(sec_access_pop); hoc_ob_check(-1);
			insertcode((yyvsp[-1].inst), (yyvsp[0].inst), ob_sec_access);}
#line 2977 "parse.c" /* yacc.c:1646  */
    break;

  case 105:
#line 448 "parse.y" /* yacc.c:1646  */
    { TPD; TPD; TPD; TPD; code(range_interpolate); codesym(spop());
		  codei((yyvsp[-3].narg));
		}
#line 2985 "parse.c" /* yacc.c:1646  */
    break;

  case 106:
#line 452 "parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(range_interpolate_single); codesym(spop());
		  codei((yyvsp[-1].narg));
		}
#line 2993 "parse.c" /* yacc.c:1646  */
    break;

  case 107:
#line 456 "parse.y" /* yacc.c:1646  */
    {Symbol *s; code(varpush); codesym(s = spop());
		 hoc_obvar_declare(s, VAR, 1);
		 (yyval.inst) = code(for_segment); codei(0); codei(0);}
#line 3001 "parse.c" /* yacc.c:1646  */
    break;

  case 108:
#line 460 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-4].inst); ((yyvsp[-2].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-2].inst), 1); /* body */
			((yyvsp[-2].inst))[2].i = relative((yyvsp[0].inst), (yyvsp[-2].inst), 2); /* exit */
		}
#line 3009 "parse.c" /* yacc.c:1646  */
    break;

  case 109:
#line 464 "parse.y" /* yacc.c:1646  */
    {Symbol *s; code(varpush); codesym(s = spop());
		hoc_obvar_declare(s, VAR, 1);}
#line 3016 "parse.c" /* yacc.c:1646  */
    break;

  case 110:
#line 467 "parse.y" /* yacc.c:1646  */
    { TPD; (yyval.inst) = code(for_segment1); codei(0); codei(0);}
#line 3022 "parse.c" /* yacc.c:1646  */
    break;

  case 111:
#line 469 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-7].inst); ((yyvsp[-2].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-2].inst), 1); /* body */
			((yyvsp[-2].inst))[2].i = relative((yyvsp[0].inst), (yyvsp[-2].inst), 2); /* exit */
		}
#line 3030 "parse.c" /* yacc.c:1646  */
    break;

  case 112:
#line 473 "parse.y" /* yacc.c:1646  */
    {	code(hoc_push_string); codesym((Symbol*)0);
			(yyval.inst) = code(forall_section); codei(0); codei(0);}
#line 3037 "parse.c" /* yacc.c:1646  */
    break;

  case 113:
#line 476 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-3].inst); ((yyvsp[-2].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-2].inst), 1); /* body */
			((yyvsp[-2].inst))[2].i = relative((yyvsp[0].inst), (yyvsp[-2].inst), 2); /* exit */
		}
#line 3045 "parse.c" /* yacc.c:1646  */
    break;

  case 114:
#line 480 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = code(forall_section); codei(0); codei(0);}
#line 3051 "parse.c" /* yacc.c:1646  */
    break;

  case 115:
#line 482 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-4].inst); ((yyvsp[-2].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-2].inst), 1); /* body */
			((yyvsp[-2].inst))[2].i = relative((yyvsp[0].inst), (yyvsp[-2].inst), 2); /* exit */
		}
#line 3059 "parse.c" /* yacc.c:1646  */
    break;

  case 116:
#line 486 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = code(hoc_ifsec); codei(0); codei(0);}
#line 3065 "parse.c" /* yacc.c:1646  */
    break;

  case 117:
#line 488 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-4].inst); ((yyvsp[-2].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-2].inst), 1); /* body */
			((yyvsp[-2].inst))[2].i = relative((yyvsp[0].inst), (yyvsp[-2].inst), 2); /* exit */
		}
#line 3073 "parse.c" /* yacc.c:1646  */
    break;

  case 118:
#line 492 "parse.y" /* yacc.c:1646  */
    {hoc_ob_check(-1);
		(yyval.inst) = code(forall_sectionlist); codei(0); codei(0); }
#line 3080 "parse.c" /* yacc.c:1646  */
    break;

  case 119:
#line 495 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-4].inst); ((yyvsp[-2].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-2].inst), 1); /* body */
			((yyvsp[-2].inst))[2].i = relative((yyvsp[0].inst), (yyvsp[-2].inst), 2); /* exit */
		}
#line 3088 "parse.c" /* yacc.c:1646  */
    break;

  case 120:
#line 499 "parse.y" /* yacc.c:1646  */
    { hoc_ob_check(-1);
		 (yyval.inst) = code(hoc_ifseclist); codei(0); codei(0);
		}
#line 3096 "parse.c" /* yacc.c:1646  */
    break;

  case 121:
#line 504 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-4].inst); ((yyvsp[-2].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-2].inst), 1); /* body */
			((yyvsp[-2].inst))[2].i = relative((yyvsp[0].inst), (yyvsp[-2].inst), 2); /* exit */
		}
#line 3104 "parse.c" /* yacc.c:1646  */
    break;

  case 122:
#line 511 "parse.y" /* yacc.c:1646  */
    {
		  code(hoc_iterator); codesym((yyvsp[-3].sym)); codei((yyvsp[-1].narg));
		  (yyval.inst) = progp; codein(STOP); codein(STOP);
		}
#line 3113 "parse.c" /* yacc.c:1646  */
    break;

  case 123:
#line 515 "parse.y" /* yacc.c:1646  */
    {code(hoc_push_current_object);}
#line 3119 "parse.c" /* yacc.c:1646  */
    break;

  case 124:
#line 516 "parse.y" /* yacc.c:1646  */
    {codei(ITERATOR);
		  (yyval.inst) = progp; codein(STOP); codein(STOP);
		}
#line 3127 "parse.c" /* yacc.c:1646  */
    break;

  case 125:
#line 521 "parse.y" /* yacc.c:1646  */
    {pushs((yyvsp[0].sym)); pushi(CHECK);}
#line 3133 "parse.c" /* yacc.c:1646  */
    break;

  case 126:
#line 522 "parse.y" /* yacc.c:1646  */
    {code(sec_access_push); codesym(spop()); (yyval.inst) = (yyvsp[0].inst);}
#line 3139 "parse.c" /* yacc.c:1646  */
    break;

  case 127:
#line 524 "parse.y" /* yacc.c:1646  */
    {
		  (yyval.inst) = code(hoc_sec_internal_push);
		  hoc_codeptr((yyvsp[0].ptr));
		}
#line 3148 "parse.c" /* yacc.c:1646  */
    break;

  case 128:
#line 530 "parse.y" /* yacc.c:1646  */
    {TPD;}
#line 3154 "parse.c" /* yacc.c:1646  */
    break;

  case 129:
#line 531 "parse.y" /* yacc.c:1646  */
    {(yyval.inst) = progp; code(connect_obsec_syntax);}
#line 3160 "parse.c" /* yacc.c:1646  */
    break;

  case 130:
#line 532 "parse.y" /* yacc.c:1646  */
    {
#if 0
		 acterror("Sorry. The \"connect ob.sec...\" syntax ",
			"is not implemented");
#endif
		 hoc_ob_check(SECTION); code(ob_sec_access);
		}
#line 3172 "parse.c" /* yacc.c:1646  */
    break;

  case 131:
#line 542 "parse.y" /* yacc.c:1646  */
    { code(add_section); codesym((yyvsp[0].sym)); codei(0);}
#line 3178 "parse.c" /* yacc.c:1646  */
    break;

  case 132:
#line 544 "parse.y" /* yacc.c:1646  */
    { code(add_section); codesym((yyvsp[-1].sym)); codei((yyvsp[0].narg));}
#line 3184 "parse.c" /* yacc.c:1646  */
    break;

  case 133:
#line 546 "parse.y" /* yacc.c:1646  */
    {code(add_section); codesym((yyvsp[0].sym)); codei(0);}
#line 3190 "parse.c" /* yacc.c:1646  */
    break;

  case 134:
#line 548 "parse.y" /* yacc.c:1646  */
    { code(add_section); codesym((yyvsp[-1].sym)); codei((yyvsp[0].narg));}
#line 3196 "parse.c" /* yacc.c:1646  */
    break;

  case 135:
#line 551 "parse.y" /* yacc.c:1646  */
    {
			Symbol* s;
			s = hoc_decl((yyvsp[0].sym));
			if (s->type != UNDEF && s->type != SECTION)
				acterror(s->name, " already declared");
		}
#line 3207 "parse.c" /* yacc.c:1646  */
    break;

  case 136:
#line 559 "parse.y" /* yacc.c:1646  */
    { code(sec_access_push); codesym((Symbol *)0);}
#line 3213 "parse.c" /* yacc.c:1646  */
    break;

  case 138:
#line 562 "parse.y" /* yacc.c:1646  */
    {pushs((yyvsp[0].sym)); pushi(CHECK);}
#line 3219 "parse.c" /* yacc.c:1646  */
    break;

  case 139:
#line 563 "parse.y" /* yacc.c:1646  */
    {(yyval.inst) = (yyvsp[0].inst);}
#line 3225 "parse.c" /* yacc.c:1646  */
    break;

  case 140:
#line 566 "parse.y" /* yacc.c:1646  */
    { code3(varpush, spop(), hoc_evalpointer);}
#line 3231 "parse.c" /* yacc.c:1646  */
    break;

  case 141:
#line 568 "parse.y" /* yacc.c:1646  */
    { TPD; code(rangevarevalpointer); codesym(spop());}
#line 3237 "parse.c" /* yacc.c:1646  */
    break;

  case 142:
#line 570 "parse.y" /* yacc.c:1646  */
    {hoc_ipop(); code(hoc_ob_pointer);}
#line 3243 "parse.c" /* yacc.c:1646  */
    break;

  case 143:
#line 571 "parse.y" /* yacc.c:1646  */
    {myerr("rangevariable needs explicit arc position,eg. v(.5)");}
#line 3249 "parse.c" /* yacc.c:1646  */
    break;

  case 144:
#line 573 "parse.y" /* yacc.c:1646  */
    {(yyval.inst) = argcode(hoc_argrefarg, (yyvsp[0].narg));}
#line 3255 "parse.c" /* yacc.c:1646  */
    break;

  case 145:
#line 579 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-1].inst);}
#line 3261 "parse.c" /* yacc.c:1646  */
    break;

  case 146:
#line 581 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = progp; }
#line 3267 "parse.c" /* yacc.c:1646  */
    break;

  case 147:
#line 584 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = code(forcode); codei(0); codei(0); codei(0); }
#line 3273 "parse.c" /* yacc.c:1646  */
    break;

  case 148:
#line 587 "parse.y" /* yacc.c:1646  */
    { TPD; (yyval.inst) = (yyvsp[0].inst); codein(STOP);}
#line 3279 "parse.c" /* yacc.c:1646  */
    break;

  case 149:
#line 590 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-1].inst); codein(STOP);}
#line 3285 "parse.c" /* yacc.c:1646  */
    break;

  case 150:
#line 592 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = progp; codein(STOP);}
#line 3291 "parse.c" /* yacc.c:1646  */
    break;

  case 151:
#line 595 "parse.y" /* yacc.c:1646  */
    { TPD; codein(STOP); (yyval.inst) = (yyvsp[-1].inst);}
#line 3297 "parse.c" /* yacc.c:1646  */
    break;

  case 152:
#line 598 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[0].inst); }
#line 3303 "parse.c" /* yacc.c:1646  */
    break;

  case 153:
#line 601 "parse.y" /* yacc.c:1646  */
    { (yyval.inst)=code(ifcode); codei(0); codei(0); codei(0); }
#line 3309 "parse.c" /* yacc.c:1646  */
    break;

  case 154:
#line 604 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = progp; }
#line 3315 "parse.c" /* yacc.c:1646  */
    break;

  case 155:
#line 607 "parse.y" /* yacc.c:1646  */
    { codein(STOP); (yyval.inst) = progp; }
#line 3321 "parse.c" /* yacc.c:1646  */
    break;

  case 156:
#line 610 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = progp; prog_error = (yyval.inst); }
#line 3327 "parse.c" /* yacc.c:1646  */
    break;

  case 157:
#line 612 "parse.y" /* yacc.c:1646  */
    {
			prog_parse_recover = progp;
			prog_error = (yyval.inst);
			if (nrn_fw_eq(fin, stdin) && !pipeflag)
			{	int i;
				Printf(">");
				for (i = 0; i < ntab; i++)
					Printf("	");
			}
		}
#line 3342 "parse.c" /* yacc.c:1646  */
    break;

  case 159:
#line 624 "parse.y" /* yacc.c:1646  */
    {myerr("syntax error in compound statement");}
#line 3348 "parse.c" /* yacc.c:1646  */
    break;

  case 160:
#line 629 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = code(constpush); codesym((yyvsp[0].sym)); PN;}
#line 3354 "parse.c" /* yacc.c:1646  */
    break;

  case 161:
#line 631 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = code(pushzero); PN;}
#line 3360 "parse.c" /* yacc.c:1646  */
    break;

  case 162:
#line 633 "parse.y" /* yacc.c:1646  */
    { code3(varpush, spop(), eval); PN;}
#line 3366 "parse.c" /* yacc.c:1646  */
    break;

  case 163:
#line 635 "parse.y" /* yacc.c:1646  */
    { defnonly("$"); (yyval.inst) = argcode(arg, (yyvsp[0].narg)); PN;}
#line 3372 "parse.c" /* yacc.c:1646  */
    break;

  case 164:
#line 637 "parse.y" /* yacc.c:1646  */
    { defnonly("$&"); (yyval.inst) = argrefcode(hoc_argref, (yyvsp[-1].narg), (yyvsp[0].narg)); PN;}
#line 3378 "parse.c" /* yacc.c:1646  */
    break;

  case 165:
#line 640 "parse.y" /* yacc.c:1646  */
    {code(rangepoint); codesym(spop()); PN;}
#line 3384 "parse.c" /* yacc.c:1646  */
    break;

  case 166:
#line 642 "parse.y" /* yacc.c:1646  */
    { TPD; code(rangevareval); codesym(spop()); PN;}
#line 3390 "parse.c" /* yacc.c:1646  */
    break;

  case 167:
#line 646 "parse.y" /* yacc.c:1646  */
    {code(hoc_object_eval);}
#line 3396 "parse.c" /* yacc.c:1646  */
    break;

  case 169:
#line 650 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-3].inst); code(call); codesym((yyvsp[-4].sym)); codei((yyvsp[-1].narg)); PN;}
#line 3402 "parse.c" /* yacc.c:1646  */
    break;

  case 170:
#line 652 "parse.y" /* yacc.c:1646  */
    { code(call); codesym(spop()); codei((yyvsp[-1].narg)); PN;}
#line 3408 "parse.c" /* yacc.c:1646  */
    break;

  case 171:
#line 654 "parse.y" /* yacc.c:1646  */
    { (yyval.inst)=(yyvsp[-1].inst); code(varread); codesym(spop()); PN;}
#line 3414 "parse.c" /* yacc.c:1646  */
    break;

  case 172:
#line 656 "parse.y" /* yacc.c:1646  */
    { TPD; (yyval.inst) = (yyvsp[-1].inst); code(bltin); codesym((yyvsp[-3].sym)); PN;}
#line 3420 "parse.c" /* yacc.c:1646  */
    break;

  case 173:
#line 658 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-1].inst); }
#line 3426 "parse.c" /* yacc.c:1646  */
    break;

  case 174:
#line 660 "parse.y" /* yacc.c:1646  */
    {myerr("syntax error in expression");}
#line 3432 "parse.c" /* yacc.c:1646  */
    break;

  case 175:
#line 662 "parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(add); PN; }
#line 3438 "parse.c" /* yacc.c:1646  */
    break;

  case 176:
#line 664 "parse.y" /* yacc.c:1646  */
    { TPD; TPD;code(hoc_sub); PN;}
#line 3444 "parse.c" /* yacc.c:1646  */
    break;

  case 177:
#line 666 "parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(mul); PN;}
#line 3450 "parse.c" /* yacc.c:1646  */
    break;

  case 178:
#line 668 "parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(hoc_div); PN;}
#line 3456 "parse.c" /* yacc.c:1646  */
    break;

  case 179:
#line 670 "parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(hoc_cyclic); PN;}
#line 3462 "parse.c" /* yacc.c:1646  */
    break;

  case 180:
#line 672 "parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(power); PN;}
#line 3468 "parse.c" /* yacc.c:1646  */
    break;

  case 181:
#line 674 "parse.y" /* yacc.c:1646  */
    { TPD; (yyval.inst) = (yyvsp[0].inst); code(negate); PN;}
#line 3474 "parse.c" /* yacc.c:1646  */
    break;

  case 182:
#line 676 "parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(gt); PN;}
#line 3480 "parse.c" /* yacc.c:1646  */
    break;

  case 183:
#line 678 "parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(ge); PN;}
#line 3486 "parse.c" /* yacc.c:1646  */
    break;

  case 184:
#line 680 "parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(lt); PN;}
#line 3492 "parse.c" /* yacc.c:1646  */
    break;

  case 185:
#line 682 "parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(le); PN;}
#line 3498 "parse.c" /* yacc.c:1646  */
    break;

  case 186:
#line 684 "parse.y" /* yacc.c:1646  */
    { hoc_ob_check(-1); hoc_ob_check(-1); code(eq); PN;}
#line 3504 "parse.c" /* yacc.c:1646  */
    break;

  case 187:
#line 686 "parse.y" /* yacc.c:1646  */
    { hoc_ob_check(-1); hoc_ob_check(-1); code(ne); PN;}
#line 3510 "parse.c" /* yacc.c:1646  */
    break;

  case 188:
#line 688 "parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(hoc_and); PN;}
#line 3516 "parse.c" /* yacc.c:1646  */
    break;

  case 189:
#line 690 "parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(hoc_or); PN;}
#line 3522 "parse.c" /* yacc.c:1646  */
    break;

  case 190:
#line 692 "parse.y" /* yacc.c:1646  */
    { TPD; (yyval.inst) = (yyvsp[0].inst); code(hoc_not); PN;}
#line 3528 "parse.c" /* yacc.c:1646  */
    break;

  case 195:
#line 700 "parse.y" /* yacc.c:1646  */
    {Symbol *s; code(varpush); codesym(s=spop()); (yyval.inst) = (yyvsp[-1].inst);
		code(arayinstal); codei((yyvsp[0].narg)); hoc_obvar_declare(s, VAR, 0);}
#line 3535 "parse.c" /* yacc.c:1646  */
    break;

  case 196:
#line 703 "parse.y" /* yacc.c:1646  */
    {Symbol *s; code(varpush); codesym(s = spop());
		code(arayinstal); codei((yyvsp[0].narg)); hoc_obvar_declare(s, VAR, 0);}
#line 3542 "parse.c" /* yacc.c:1646  */
    break;

  case 197:
#line 708 "parse.y" /* yacc.c:1646  */
    {pushs((yyvsp[-1].sym)); (yyval.narg) = (yyvsp[0].narg);}
#line 3548 "parse.c" /* yacc.c:1646  */
    break;

  case 198:
#line 711 "parse.y" /* yacc.c:1646  */
    {  TPD; (yyval.narg) = 1; }
#line 3554 "parse.c" /* yacc.c:1646  */
    break;

  case 199:
#line 713 "parse.y" /* yacc.c:1646  */
    {  TPD;(yyval.narg) = (yyval.narg) + 1; }
#line 3560 "parse.c" /* yacc.c:1646  */
    break;

  case 201:
#line 719 "parse.y" /* yacc.c:1646  */
    { pushs((yyvsp[-1].sym)); (yyval.inst) = (yyvsp[0].inst); }
#line 3566 "parse.c" /* yacc.c:1646  */
    break;

  case 202:
#line 721 "parse.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].sym)->subtype == USERPROPERTY) {
			code(sec_access_push); codesym((Symbol *)0);
		  }
		pushs((yyvsp[-1].sym)); pushi(CHECK);
		}
#line 3576 "parse.c" /* yacc.c:1646  */
    break;

  case 203:
#line 726 "parse.y" /* yacc.c:1646  */
    {(yyval.inst) = (yyvsp[-2].inst);}
#line 3582 "parse.c" /* yacc.c:1646  */
    break;

  case 204:
#line 728 "parse.y" /* yacc.c:1646  */
    { if ((yyvsp[0].sym)->subtype != USERPROPERTY) {
			acterror((yyvsp[0].sym)->name, "not a section variable");
		  }
		(yyval.inst) = (yyvsp[-2].inst); pushs((yyvsp[0].sym));
		}
#line 3592 "parse.c" /* yacc.c:1646  */
    break;

  case 205:
#line 742 "parse.y" /* yacc.c:1646  */
    {
		int d1, chk;
		Symbol *sym;
		d1 = ipop();
		chk = ipop();
		sym = spop();
   if (chk) {
	if (!ISARRAY(sym)) {
		if (d1)
			acterror(sym->name, "not an array variable");
	}else{
		if ( d1 == 0 ) { /*fake index list with all 0's*/
			int i;
			for (i=0; i<sym->arayinfo->nsub; i++) {
				code(pushzero);
			}
		}			
		else if ( d1 != sym->arayinfo->nsub) {
			acterror("wrong # of subscripts",sym->name);
		}
	}
   }else {
	pushi(d1); /* must check dynamically */
   }
		pushs(sym);
		}
#line 3623 "parse.c" /* yacc.c:1646  */
    break;

  case 206:
#line 771 "parse.y" /* yacc.c:1646  */
    {
			(yyval.narg) = ipop();
		}
#line 3631 "parse.c" /* yacc.c:1646  */
    break;

  case 207:
#line 777 "parse.y" /* yacc.c:1646  */
    { pushi(0); }
#line 3637 "parse.c" /* yacc.c:1646  */
    break;

  case 208:
#line 779 "parse.y" /* yacc.c:1646  */
    {  TPD;pushi(ipop() + 1); }
#line 3643 "parse.c" /* yacc.c:1646  */
    break;

  case 209:
#line 783 "parse.y" /* yacc.c:1646  */
    { TPDYNAM; code(prexpr);}
#line 3649 "parse.c" /* yacc.c:1646  */
    break;

  case 210:
#line 785 "parse.y" /* yacc.c:1646  */
    { code(prstr); }
#line 3655 "parse.c" /* yacc.c:1646  */
    break;

  case 211:
#line 787 "parse.y" /* yacc.c:1646  */
    { TPDYNAM; code(prexpr);}
#line 3661 "parse.c" /* yacc.c:1646  */
    break;

  case 212:
#line 789 "parse.y" /* yacc.c:1646  */
    { code(prstr); }
#line 3667 "parse.c" /* yacc.c:1646  */
    break;

  case 213:
#line 792 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = code(hoc_delete_symbol); codesym((yyvsp[0].sym)); }
#line 3673 "parse.c" /* yacc.c:1646  */
    break;

  case 214:
#line 796 "parse.y" /* yacc.c:1646  */
    {(yyvsp[0].sym)->type=FUNCTION; indef=1; }
#line 3679 "parse.c" /* yacc.c:1646  */
    break;

  case 215:
#line 798 "parse.y" /* yacc.c:1646  */
    { code(procret); hoc_define((yyvsp[-4].sym));
		 (yyvsp[-4].sym)->u.u_proc->nobjauto = (yyvsp[0].narg) - localcnt;
		 (yyvsp[-4].sym)->u.u_proc->nauto=(yyvsp[0].narg); indef=0; }
#line 3687 "parse.c" /* yacc.c:1646  */
    break;

  case 216:
#line 802 "parse.y" /* yacc.c:1646  */
    { (yyvsp[0].sym)->type=PROCEDURE; indef=1; }
#line 3693 "parse.c" /* yacc.c:1646  */
    break;

  case 217:
#line 804 "parse.y" /* yacc.c:1646  */
    { code(procret); hoc_define((yyvsp[-4].sym));
		 (yyvsp[-4].sym)->u.u_proc->nobjauto = (yyvsp[0].narg) - localcnt;
		 (yyvsp[-4].sym)->u.u_proc->nauto=(yyvsp[0].narg); indef=0; }
#line 3701 "parse.c" /* yacc.c:1646  */
    break;

  case 218:
#line 808 "parse.y" /* yacc.c:1646  */
    { (yyvsp[0].sym)->type = ITERATOR; indef=2; }
#line 3707 "parse.c" /* yacc.c:1646  */
    break;

  case 219:
#line 810 "parse.y" /* yacc.c:1646  */
    {code(procret); hoc_define((yyvsp[-4].sym));
		 (yyvsp[-4].sym)->u.u_proc->nobjauto = (yyvsp[0].narg) - localcnt;
		 (yyvsp[-4].sym)->u.u_proc->nauto = (yyvsp[0].narg); indef = 0; }
#line 3715 "parse.c" /* yacc.c:1646  */
    break;

  case 220:
#line 814 "parse.y" /* yacc.c:1646  */
    { (yyvsp[0].sym)->type=HOCOBJFUNCTION; indef=3; }
#line 3721 "parse.c" /* yacc.c:1646  */
    break;

  case 221:
#line 816 "parse.y" /* yacc.c:1646  */
    { code(procret); hoc_define((yyvsp[-4].sym));
		 (yyvsp[-4].sym)->u.u_proc->nobjauto = (yyvsp[0].narg) - localcnt;
		 (yyvsp[-4].sym)->u.u_proc->nauto=(yyvsp[0].narg); indef=0; }
#line 3729 "parse.c" /* yacc.c:1646  */
    break;

  case 222:
#line 821 "parse.y" /* yacc.c:1646  */
    { Symbol *s; s=yylval.sym;
		if(s->type != UNDEF) acterror(s->name, "already defined");
		s->u.u_proc = (Proc *)emalloc(sizeof(Proc));
		s->u.u_proc->defn.in = STOP;
		s->u.u_proc->list = (Symlist *)0; }
#line 3739 "parse.c" /* yacc.c:1646  */
    break;

  case 227:
#line 831 "parse.y" /* yacc.c:1646  */
    {ntab++;}
#line 3745 "parse.c" /* yacc.c:1646  */
    break;

  case 228:
#line 832 "parse.y" /* yacc.c:1646  */
    {
		ntab--;
		(yyval.narg) = (yyvsp[-4].narg) + (yyvsp[-3].narg);
		}
#line 3754 "parse.c" /* yacc.c:1646  */
    break;

  case 229:
#line 838 "parse.y" /* yacc.c:1646  */
    { (yyval.narg) = 0; }
#line 3760 "parse.c" /* yacc.c:1646  */
    break;

  case 231:
#line 842 "parse.y" /* yacc.c:1646  */
    {(yyval.narg) = 1;}
#line 3766 "parse.c" /* yacc.c:1646  */
    break;

  case 232:
#line 844 "parse.y" /* yacc.c:1646  */
    {(yyval.narg) = (yyvsp[-2].narg) + 1;}
#line 3772 "parse.c" /* yacc.c:1646  */
    break;

  case 233:
#line 847 "parse.y" /* yacc.c:1646  */
    {}
#line 3778 "parse.c" /* yacc.c:1646  */
    break;

  case 234:
#line 849 "parse.y" /* yacc.c:1646  */
    { hoc_ob_check(-1);}
#line 3784 "parse.c" /* yacc.c:1646  */
    break;

  case 236:
#line 852 "parse.y" /* yacc.c:1646  */
    {
		 code(hoc_newobj_arg); codesym(hoc_which_template((yyvsp[-3].sym))); codei((yyvsp[-1].narg));
		}
#line 3792 "parse.c" /* yacc.c:1646  */
    break;

  case 237:
#line 857 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[0].inst); }
#line 3798 "parse.c" /* yacc.c:1646  */
    break;

  case 238:
#line 859 "parse.y" /* yacc.c:1646  */
    {code3(varpush, spop(), eqn_name);
		do_equation = 1; }
#line 3805 "parse.c" /* yacc.c:1646  */
    break;

  case 239:
#line 862 "parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-3].inst); do_equation = 0; }
#line 3811 "parse.c" /* yacc.c:1646  */
    break;

  case 240:
#line 865 "parse.y" /* yacc.c:1646  */
    {Symbol *s; code3(varpush,s= spop(), dep_make); hoc_obvar_declare(s, VAR, 0);}
#line 3817 "parse.c" /* yacc.c:1646  */
    break;

  case 241:
#line 867 "parse.y" /* yacc.c:1646  */
    {Symbol *s; code3(varpush, s=spop(), dep_make); hoc_obvar_declare(s, VAR, 0);}
#line 3823 "parse.c" /* yacc.c:1646  */
    break;

  case 244:
#line 872 "parse.y" /* yacc.c:1646  */
    { code(eqn_init); }
#line 3829 "parse.c" /* yacc.c:1646  */
    break;

  case 246:
#line 876 "parse.y" /* yacc.c:1646  */
    { code(eqn_lhs); }
#line 3835 "parse.c" /* yacc.c:1646  */
    break;

  case 247:
#line 878 "parse.y" /* yacc.c:1646  */
    { codein(STOP); TPD; }
#line 3841 "parse.c" /* yacc.c:1646  */
    break;

  case 248:
#line 881 "parse.y" /* yacc.c:1646  */
    { code(eqn_rhs); }
#line 3847 "parse.c" /* yacc.c:1646  */
    break;

  case 249:
#line 883 "parse.y" /* yacc.c:1646  */
    { codein(STOP); TPD; }
#line 3853 "parse.c" /* yacc.c:1646  */
    break;

  case 250:
#line 886 "parse.y" /* yacc.c:1646  */
    { (yyval.narg) = 0; localcnt = (yyval.narg);}
#line 3859 "parse.c" /* yacc.c:1646  */
    break;

  case 252:
#line 890 "parse.y" /* yacc.c:1646  */
    {
		Symbol *sp;
		(yyval.narg) = 1; localcnt = (yyval.narg);
		sp = install((yyvsp[0].sym)->name, AUTO, 0.0, &p_symlist);
		sp->u.u_auto = (yyval.narg);
		}
#line 3870 "parse.c" /* yacc.c:1646  */
    break;

  case 253:
#line 897 "parse.y" /* yacc.c:1646  */
    {
		Symbol *sp;
		(yyval.narg) = (yyvsp[-2].narg) + 1; localcnt = (yyval.narg);
		if (hoc_table_lookup((yyvsp[0].sym)->name, p_symlist)) {
			acterror((yyvsp[0].sym)->name, "already declared local");
		}
		sp = install((yyvsp[0].sym)->name, AUTO, 0.0, &p_symlist);
		sp->u.u_auto = (yyval.narg);
		}
#line 3884 "parse.c" /* yacc.c:1646  */
    break;

  case 254:
#line 908 "parse.y" /* yacc.c:1646  */
    { (yyval.narg) = 0;}
#line 3890 "parse.c" /* yacc.c:1646  */
    break;

  case 256:
#line 912 "parse.y" /* yacc.c:1646  */
    {
		Symbol *sp;
		(yyval.narg) = 1;
		if (hoc_table_lookup((yyvsp[0].sym)->name, p_symlist)) {
			acterror((yyvsp[0].sym)->name, "already declared local");
		}
		sp = install((yyvsp[0].sym)->name, AUTOOBJ, 0.0, &p_symlist);
		sp->u.u_auto = (yyval.narg) + localcnt;
		}
#line 3904 "parse.c" /* yacc.c:1646  */
    break;

  case 257:
#line 922 "parse.y" /* yacc.c:1646  */
    {
		Symbol *sp;
		(yyval.narg) = (yyvsp[-2].narg) + 1;
		if (hoc_table_lookup((yyvsp[0].sym)->name, p_symlist)) {
			acterror((yyvsp[0].sym)->name, "already declared local");
		}
		sp = install((yyvsp[0].sym)->name, AUTOOBJ, 0.0, &p_symlist);
		sp->u.u_auto = (yyval.narg) + localcnt;
		}
#line 3918 "parse.c" /* yacc.c:1646  */
    break;

  case 258:
#line 933 "parse.y" /* yacc.c:1646  */
    {  Symbol* s;
	   s = hoc_decl((yyvsp[0].sym));
	   if (s->subtype != NOTUSER)
		acterror("can't redeclare user variable", s->name);
	   (yyval.sym) = s;
	}
#line 3929 "parse.c" /* yacc.c:1646  */
    break;


#line 3933 "parse.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 945 "parse.y" /* yacc.c:1906  */

	/* end of grammar */

static void yyerror(const char* s)	/* called for yacc syntax error */
{
	execerror(s, (char *)0);
}

void acterror(const char* s, const char*t)	/* recover from action error while parsing */
{
	execerror(s,t);
}

static Inst* argrefcode(Pfrv pfrv, int i, int j){
	Inst* in;
	in = argcode(pfrv, i);
	codei(j);
	return in;
}

static Inst* argcode(Pfrv pfrv, int i) {
	Inst* in;
	if (i == 0) {
		Symbol* si = hoc_lookup("i");
		if (si->type != AUTO) {
			acterror("arg index used and i is not a LOCAL variable", 0);
		}
		in = code3(varpush, si, eval);		
		Code(pfrv);
		codei(0);
	}else{
		in = Code(pfrv);
		codei(i);
	}
	return in;
}

static void hoc_opasgn_invalid(int op) {
        if (op) {
                acterror("Invalid assignment operator.", "Only '=' allowed. ");
        }
} 

