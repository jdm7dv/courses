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
#line 1 "parse1.y" /* yacc.c:339  */

/* /local/src/master/nrn/src/nmodl/parse1.y,v 4.11 1999/03/24 18:34:08 hines Exp */

#include <../../nmodlconf.h>
#include "modl.h"
#include <stdlib.h>

#if defined(__STDC__)
#define sdebug(arg1,arg2) {}
#define qdebug(arg1,arg2) {}
#else
#define sdebug(arg1,arg2) {Fprintf(stderr,"arg1:%s\n", arg2); Fflush(stderr);}
#define qdebug(arg1,arg2) {Item *q; Fprintf(stderr,"arg1:");Fflush(stderr);\
	for (q=arg2; q->type != 0; q=q->next){\
		if (q->type == SYMBOL)\
			Fprintf(stderr,"%s\n", SYM(q)->name);\
		else if (q->type == STRING)\
			Fprintf(stderr,"%s\n", STR(q);\
		else\
			Fprintf(stderr,"Illegal Item type\n");\
		Fflush(stderr);}\
		Fprintf(stderr,"\n");Fflush(stderr);}
#endif

#define ldebug(arg1, arg2) qdebug(arg1, arg2->next)

extern int yylex(), yyparse();
static void yyerror();

#if YYBISON
#define myerr(arg) static int ierr=0;\
if (!(ierr++))yyerror(arg); --yyssp; --yyvsp; YYERROR
#else
#define myerr(arg) static int ierr=0;\
if (!(ierr++))yyerror(arg); --yyps; --yypv; YYERROR
#endif

int brkpnt_exists;
int assert_threadsafe;
int usederivstatearray;
extern int protect_;
extern int vectorize;
extern int in_comment_; /* allow non-ascii in a COMMENT */
extern char *modelline;
extern Item* protect_astmt(Item*, Item*);
extern List* toplocal_;
static List* toplocal1_;
extern List *firstlist; /* NAME symbols in order that they appear in file */
extern int lexcontext; /* ':' can return 3 different tokens */
extern List *solveforlist; /* List of symbols that are actually to be solved
				for in a block. See in_solvefor() */
static int stateblock; /* 0 if dependent, 1 if state */
static int blocktype;
static int saw_verbatim_; /* only print the notice once */
static int inequation; /* inside an equation?*/
static int nstate;	/* number of states seen in an expression */
static int leftside;	/* inside left hand side of equation? */
static int pstate;	/* number of state in a primary expression */
static int tstate;	/* number of states in a term */
static Item *lastok;	/* last token accepted by expr */
static int sensused;	/* a SENS statement occurred in this block */
static Symbol *matchindex; /* local symbol for implied MATCH loop */
static int model_level = 0; /* the model level prepended to declaration
				blocks by merge */
static int scopindep = 0;/* SCoP independent explicitly declared if 1 */
static int extdef2 = 0; /* flag that says we are in an EXTDEF2 function */
static List *table_list = LIST0; /* table information for TABLE statement */
static int forallindex = 0;	/* 0 not in FORALL, -1 just starting, 
					>0 index of arrays used (must all
					be the same */
static Item* astmt_end_;	/* see kinetic.c vectorizing */
static int nr_argcnt_, argcnt_; /* for matching number of args in NET_RECEIVE
				 and FOR_NETCONS */

#line 141 "parse1.c" /* yacc.c:339  */

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
    VERBATIM = 258,
    COMMENT = 259,
    MODEL = 260,
    CONSTANT = 261,
    INDEPENDENT = 262,
    DEPENDENT = 263,
    STATE = 264,
    INITIAL1 = 265,
    DERIVATIVE = 266,
    SOLVE = 267,
    USING = 268,
    WITH = 269,
    STEPPED = 270,
    DISCRETE = 271,
    FROM = 272,
    FORALL1 = 273,
    TO = 274,
    BY = 275,
    WHILE = 276,
    IF = 277,
    ELSE = 278,
    START1 = 279,
    STEP = 280,
    SENS = 281,
    SOLVEFOR = 282,
    PROCEDURE = 283,
    PARTIAL = 284,
    DEL = 285,
    DEL2 = 286,
    DEFINE1 = 287,
    IFERROR = 288,
    PARAMETER = 289,
    DERFUNC = 290,
    EQUATION = 291,
    TERMINAL = 292,
    LINEAR = 293,
    NONLINEAR = 294,
    FUNCTION1 = 295,
    LOCAL = 296,
    METHOD = 297,
    LIN1 = 298,
    NONLIN1 = 299,
    PUTQ = 300,
    GETQ = 301,
    TABLE = 302,
    DEPEND = 303,
    BREAKPOINT = 304,
    INCLUDE1 = 305,
    FUNCTION_TABLE = 306,
    PROTECT = 307,
    NRNMUTEXLOCK = 308,
    NRNMUTEXUNLOCK = 309,
    OR = 310,
    AND = 311,
    GT = 312,
    LT = 313,
    LE = 314,
    EQ = 315,
    NE = 316,
    NOT = 317,
    NAME = 318,
    PRIME = 319,
    REAL = 320,
    INTEGER = 321,
    DEFINEDVAR = 322,
    STRING = 323,
    PLOT = 324,
    VS = 325,
    LAG = 326,
    RESET = 327,
    MATCH = 328,
    MODEL_LEVEL = 329,
    SWEEP = 330,
    FIRST = 331,
    LAST = 332,
    KINETIC = 333,
    CONSERVE = 334,
    REACTION = 335,
    REACT1 = 336,
    COMPARTMENT = 337,
    UNITS = 338,
    UNITSON = 339,
    UNITSOFF = 340,
    LONGDIFUS = 341,
    NEURON = 342,
    SUFFIX = 343,
    NONSPECIFIC = 344,
    READ = 345,
    WRITE = 346,
    USEION = 347,
    VALENCE = 348,
    THREADSAFE = 349,
    GLOBAL = 350,
    SECTION = 351,
    RANGE = 352,
    POINTER = 353,
    EXTERNAL = 354,
    BEFORE = 355,
    AFTER = 356,
    WATCH = 357,
    ELECTRODE_CURRENT = 358,
    CONSTRUCTOR = 359,
    DESTRUCTOR = 360,
    NETRECEIVE = 361,
    FOR_NETCONS = 362,
    CONDUCTANCE = 363,
    GE = 364,
    UNARYMINUS = 365
  };
#endif
/* Tokens.  */
#define VERBATIM 258
#define COMMENT 259
#define MODEL 260
#define CONSTANT 261
#define INDEPENDENT 262
#define DEPENDENT 263
#define STATE 264
#define INITIAL1 265
#define DERIVATIVE 266
#define SOLVE 267
#define USING 268
#define WITH 269
#define STEPPED 270
#define DISCRETE 271
#define FROM 272
#define FORALL1 273
#define TO 274
#define BY 275
#define WHILE 276
#define IF 277
#define ELSE 278
#define START1 279
#define STEP 280
#define SENS 281
#define SOLVEFOR 282
#define PROCEDURE 283
#define PARTIAL 284
#define DEL 285
#define DEL2 286
#define DEFINE1 287
#define IFERROR 288
#define PARAMETER 289
#define DERFUNC 290
#define EQUATION 291
#define TERMINAL 292
#define LINEAR 293
#define NONLINEAR 294
#define FUNCTION1 295
#define LOCAL 296
#define METHOD 297
#define LIN1 298
#define NONLIN1 299
#define PUTQ 300
#define GETQ 301
#define TABLE 302
#define DEPEND 303
#define BREAKPOINT 304
#define INCLUDE1 305
#define FUNCTION_TABLE 306
#define PROTECT 307
#define NRNMUTEXLOCK 308
#define NRNMUTEXUNLOCK 309
#define OR 310
#define AND 311
#define GT 312
#define LT 313
#define LE 314
#define EQ 315
#define NE 316
#define NOT 317
#define NAME 318
#define PRIME 319
#define REAL 320
#define INTEGER 321
#define DEFINEDVAR 322
#define STRING 323
#define PLOT 324
#define VS 325
#define LAG 326
#define RESET 327
#define MATCH 328
#define MODEL_LEVEL 329
#define SWEEP 330
#define FIRST 331
#define LAST 332
#define KINETIC 333
#define CONSERVE 334
#define REACTION 335
#define REACT1 336
#define COMPARTMENT 337
#define UNITS 338
#define UNITSON 339
#define UNITSOFF 340
#define LONGDIFUS 341
#define NEURON 342
#define SUFFIX 343
#define NONSPECIFIC 344
#define READ 345
#define WRITE 346
#define USEION 347
#define VALENCE 348
#define THREADSAFE 349
#define GLOBAL 350
#define SECTION 351
#define RANGE 352
#define POINTER 353
#define EXTERNAL 354
#define BEFORE 355
#define AFTER 356
#define WATCH 357
#define ELECTRODE_CURRENT 358
#define CONSTRUCTOR 359
#define DESTRUCTOR 360
#define NETRECEIVE 361
#define FOR_NETCONS 362
#define CONDUCTANCE 363
#define GE 364
#define UNARYMINUS 365

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 76 "parse1.y" /* yacc.c:355  */

	Item	*qp;
	char	*str;
	List	*lp;
	int	i;

#line 408 "parse1.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 423 "parse1.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1310

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  128
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  166
/* YYNRULES -- Number of rules.  */
#define YYNRULES  391
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  767

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   365

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   126,     2,     2,
      57,    58,    63,    62,    69,    64,     2,    65,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    68,     2,
       2,    66,     2,     2,    61,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,    67,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,    70,     2,     2,     2,
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
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   127
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   133,   133,   134,   136,   137,   138,   151,   152,   153,
     153,   156,   155,   161,   170,   177,   178,   181,   185,   187,
     196,   198,   204,   204,   204,   204,   204,   205,   205,   205,
     205,   207,   209,   210,   214,   218,   220,   225,   227,   228,
     230,   230,   234,   235,   238,   239,   245,   247,   248,   251,
     255,   256,   258,   259,   261,   262,   269,   269,   271,   272,
     274,   275,   281,   283,   284,   286,   286,   291,   296,   298,
     300,   300,   302,   303,   306,   310,   316,   320,   326,   330,
     331,   334,   335,   340,   340,   342,   347,   349,   357,   361,
     362,   365,   365,   367,   367,   368,   368,   369,   369,   370,
     370,   371,   371,   372,   372,   373,   373,   374,   374,   375,
     375,   376,   376,   377,   377,   378,   378,   379,   379,   380,
     380,   381,   381,   382,   382,   384,   387,   390,   393,   393,
     394,   397,   399,   403,   402,   412,   414,   429,   444,   445,
     448,   449,   449,   451,   453,   454,   455,   456,   457,   458,
     459,   460,   470,   472,   473,   474,   475,   476,   477,   478,
     480,   481,   482,   486,   487,   488,   489,   490,   491,   492,
     495,   498,   498,   502,   502,   505,   509,   529,   538,   545,
     560,   583,   586,   590,   598,   599,   600,   601,   602,   603,
     604,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   629,   631,   636,   638,   641,   644,   647,   651,   657,
     663,   669,   670,   671,   673,   676,   681,   680,   698,   699,
     700,   701,   702,   704,   704,   727,   730,   731,   733,   733,
     752,   755,   757,   759,   760,   767,   768,   775,   779,   779,
     785,   791,   795,   800,   804,   806,   808,   811,   811,   813,
     841,   840,   869,   870,   870,   872,   876,   881,   900,   899,
     917,   919,   927,   930,   932,   935,   936,   940,   944,   946,
     950,   952,   954,   958,   961,   963,   965,   967,   969,   971,
     973,   975,   977,   980,   981,   983,   983,   993,   995,   996,
     997,   998,   999,  1000,  1001,  1002,  1003,  1006,  1007,  1010,
    1015,  1017,  1020,  1024,  1024,  1028,  1031,  1030,  1034,  1038,
    1037,  1041,  1044,  1045,  1047,  1054,  1054,  1056,  1058,  1060,
    1062,  1063,  1064,  1065,  1067,  1069,  1071,  1072,  1074,  1074,
    1077,  1078,  1080,  1082,  1089,  1093,  1095,  1100,  1104,  1105,
    1106,  1108,  1110,  1112,  1118,  1128,  1137,  1143,  1145,  1146,
    1153,  1168,  1171,  1172,  1174,  1176,  1180,  1181,  1184,  1187,
    1188,  1190,  1191,  1193,  1195,  1197,  1199,  1201,  1203,  1205,
    1208,  1210,  1212,  1214,  1217,  1218,  1220,  1224,  1225,  1228,
    1229,  1231
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VERBATIM", "COMMENT", "MODEL",
  "CONSTANT", "INDEPENDENT", "DEPENDENT", "STATE", "INITIAL1",
  "DERIVATIVE", "SOLVE", "USING", "WITH", "STEPPED", "DISCRETE", "FROM",
  "FORALL1", "TO", "BY", "WHILE", "IF", "ELSE", "START1", "STEP", "SENS",
  "SOLVEFOR", "PROCEDURE", "PARTIAL", "DEL", "DEL2", "DEFINE1", "IFERROR",
  "PARAMETER", "DERFUNC", "EQUATION", "TERMINAL", "LINEAR", "NONLINEAR",
  "FUNCTION1", "LOCAL", "METHOD", "LIN1", "NONLIN1", "PUTQ", "GETQ",
  "TABLE", "DEPEND", "BREAKPOINT", "INCLUDE1", "FUNCTION_TABLE", "PROTECT",
  "NRNMUTEXLOCK", "NRNMUTEXUNLOCK", "'{'", "'}'", "'('", "')'", "'['",
  "']'", "'@'", "'+'", "'*'", "'-'", "'/'", "'='", "'^'", "':'", "','",
  "'~'", "OR", "AND", "GT", "LT", "LE", "EQ", "NE", "NOT", "NAME", "PRIME",
  "REAL", "INTEGER", "DEFINEDVAR", "STRING", "PLOT", "VS", "LAG", "RESET",
  "MATCH", "MODEL_LEVEL", "SWEEP", "FIRST", "LAST", "KINETIC", "CONSERVE",
  "REACTION", "REACT1", "COMPARTMENT", "UNITS", "UNITSON", "UNITSOFF",
  "LONGDIFUS", "NEURON", "SUFFIX", "NONSPECIFIC", "READ", "WRITE",
  "USEION", "VALENCE", "THREADSAFE", "GLOBAL", "SECTION", "RANGE",
  "POINTER", "EXTERNAL", "BEFORE", "AFTER", "WATCH", "ELECTRODE_CURRENT",
  "CONSTRUCTOR", "DESTRUCTOR", "NETRECEIVE", "FOR_NETCONS", "CONDUCTANCE",
  "GE", "'%'", "UNARYMINUS", "$accept", "top", "all", "$@1", "$@2",
  "model", "line", "define1", "Name", "declare", "parmblk", "parmbody",
  "parmasgn", "units", "unit", "@3", "uniton", "limits", "stepblk",
  "stepbdy", "stepped", "numlist", "name", "number", "NUMBER", "integer",
  "real", "indepblk", "indepbody", "$@4", "indepdef", "withby", "depblk",
  "$@5", "depbody", "depdef", "opstart", "abstol", "stateblk", "$@6",
  "plotdecl", "pvlist", "optindex", "proc", "$@7", "$@8", "$@9", "$@10",
  "$@11", "$@12", "$@13", "$@14", "$@15", "$@16", "$@17", "$@18", "$@19",
  "$@20", "$@21", "$@22", "$@23", "initblk", "constructblk", "destructblk",
  "stmtlist", "$@24", "conducthint", "locallist", "$@25", "locallist1",
  "locoptarray", "stmtlist1", "$@26", "ostmt", "astmt", "$@27", "$@28",
  "asgn", "varname", "intexpr", "expr", "nonlineqn", "lineqn",
  "leftlinexpr", "linexpr", "primary", "term", "funccall", "$@29",
  "exprlist", "fromstmt", "$@30", "opinc", "forallstmt", "$@31",
  "whilestmt", "ifstmt", "optelseif", "optelse", "derivblk", "linblk",
  "$@32", "nonlinblk", "discretblk", "partialblk", "pareqn", "firstlast",
  "functableblk", "funcblk", "$@33", "arglist", "$@34", "arglist1",
  "procedblk", "netrecblk", "$@35", "initstmt", "solveblk", "ifsolerr",
  "solvefor", "solvefor1", "brkptblk", "terminalblk", "bablk", "watchstmt",
  "watch1", "watchdir", "fornetcon", "$@36", "aexpr", "sens", "senslist",
  "conserve", "$@37", "compart", "$@38", "ldifus", "$@39", "namelist",
  "kineticblk", "reaction", "$@40", "react", "lagstmt", "queuestmt",
  "matchblk", "$@41", "matchlist", "match", "matchname", "unitblk",
  "unitbody", "unitdef", "factordef", "constblk", "conststmt", "tablestmt",
  "tablst", "tablst1", "dependlst", "neuronblk", "nrnstmt", "nrnuse",
  "nrnlist", "optnrnlist", "valence", YY_NULLPTR
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
     305,   306,   307,   308,   309,   123,   125,    40,    41,    91,
      93,    64,    43,    42,    45,    47,    61,    94,    58,    44,
     126,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,    37,   365
};
# endif

#define YYPACT_NINF -563

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-563)))

#define YYTABLE_NINF -388

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     744,  -563,    46,   801,  -563,  -563,  -563,  -563,    -3,     6,
    -563,  -563,    25,   126,    57,   185,    97,     8,   216,   248,
    -563,  -563,   273,   448,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,   292,   312,  -563,  -563,   252,  -563,  -563,    28,  -563,
    -563,  -563,  -563,  -563,   342,   268,  -563,  -563,  -563,  -563,
     394,   425,   395,   417,   421,   430,   437,   353,   452,   488,
     487,   423,   405,   418,   490,   429,   431,   186,    23,  -563,
    -563,   277,  -563,    26,   491,   482,   479,  -563,   -48,   -48,
      41,   201,   327,   508,  -563,   492,  -563,   508,  -563,   494,
    -563,   518,  -563,   519,  -563,   522,  -563,    12,  -563,   508,
    -563,   528,  -563,   212,  -563,   530,  -563,   508,  -563,   508,
    -563,   533,  -563,   456,   456,  -563,   547,  -563,  -563,   599,
    -563,  -563,    40,    52,  -563,   552,  -563,  -563,  -563,   296,
    -563,    88,  -563,   543,   560,   342,   342,  -563,  -563,  -563,
    -563,   579,    56,  -563,  -563,  -563,   571,   220,   222,   267,
     220,   220,   220,   220,   220,   220,  -563,   610,   613,   508,
     618,   649,   649,   621,   629,  -563,   630,   631,   508,  -563,
     508,   649,   637,   648,   632,  -563,   508,   508,   508,   508,
    -563,  -563,   493,   493,   227,  -563,  -563,   254,  -563,  -563,
     493,    88,   493,   643,  -563,  -563,  -563,   650,   491,  -563,
    -563,  -563,   634,   306,  -563,   661,  -563,  -563,  -563,   652,
    -563,   132,   652,  -563,   652,   652,   652,   652,   652,   652,
    -563,  -563,  -563,   666,  -563,   230,  -563,   665,   508,   630,
     630,   677,   -48,  -563,   684,   686,   508,  -563,  -563,   630,
     687,   690,   700,   701,   499,  -563,   661,  -563,  -563,   739,
    -563,   493,   493,    88,   661,   -18,   697,   707,   661,   549,
    -563,  -563,  -563,  -563,  -563,   150,  -563,   661,  -563,   689,
     220,   220,  1203,  1214,  -563,  -563,  -563,   508,   691,   713,
     716,   717,  -563,   661,   702,  -563,  -563,   721,   729,  -563,
    -563,  -563,  -563,  -563,  -563,   493,   770,  -563,   731,   718,
     493,  -563,   493,   661,   643,   728,   726,  -563,  -563,  -563,
      94,   -50,  -563,  -563,  -563,   373,   741,   607,  -563,   706,
    -563,   745,   633,   260,  -563,   756,  -563,  -563,   661,   661,
     508,  -563,   -48,  -563,   661,   799,   493,   243,   549,  -563,
    -563,  -563,   643,  -563,   549,   661,   220,   496,  -563,  -563,
     250,  -563,    88,    64,  -563,  -563,  -563,   508,   232,   236,
     265,   757,   758,    85,   -48,   -48,   231,  -563,  -563,   -12,
     161,  -563,  -563,   112,   789,   795,    13,    37,   738,  -563,
     762,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
     750,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
     225,  -563,   633,  -563,   633,   633,   633,   661,  -563,  1124,
    -563,  -563,   633,   313,  -563,  -563,   754,   233,   285,  -563,
    -563,  -563,  -563,   508,   765,   661,  -563,  -563,    88,   798,
     493,   661,   751,  -563,   752,  -563,   -50,   549,  -563,   766,
    -563,   557,   769,  -563,    64,  -563,  -563,   584,   774,  -563,
       4,  -563,  -563,  -563,  -563,   633,   633,  -563,  -563,   763,
    -563,  -563,  -563,  -563,   783,   768,   760,   781,   775,  -563,
     828,   794,  -563,   682,   410,   843,   434,   866,  -563,   451,
    -563,  -563,   630,   742,  -563,   797,  -563,   209,  -563,   287,
    1159,   932,   788,   788,  -563,   633,   633,   633,   633,   633,
     633,   633,   633,   633,   633,   633,   633,   633,   633,   953,
     285,   260,   313,   313,   313,   313,   508,   800,  -563,  -563,
     798,   661,   838,   718,  -563,  -563,  -563,  -563,  -563,  1159,
     176,    64,   541,  -563,    64,    64,    64,    64,  -563,   816,
     508,  -563,   796,   508,   976,   996,   209,   738,   846,   738,
     821,   323,   802,   809,   167,   207,  -563,   810,  -563,   810,
    -563,   451,   451,   661,  -563,  -563,   473,   832,   824,  -563,
    -563,   682,   806,   825,  -563,  -563,   335,   788,   335,   788,
    1159,   788,   820,  1177,   636,   636,   636,   636,   636,   636,
    -563,   233,   285,   285,  -563,  -563,   853,  -563,   661,   718,
     493,  -563,  -563,   172,   664,  -563,   301,  -563,   301,  -563,
     878,   856,    64,   857,   508,   508,  -563,   768,   633,  -563,
     323,  -563,  -563,   862,   860,  -563,  -563,   439,    59,  -563,
     867,   633,   633,  -563,   279,   633,   318,   601,   858,  -563,
     451,   451,   451,   451,   451,  -563,  -563,   451,  -563,  -563,
     209,  -563,   869,   870,   682,  -563,  -563,  -563,   798,  -563,
    1159,  -563,  -563,  -563,   115,  -563,   876,   879,   608,   874,
     880,   905,   868,  -563,  -563,   633,  1159,   889,  -563,  -563,
     912,  -563,  -563,   415,   858,   415,   858,   858,   674,   508,
    -563,   633,   633,    14,   661,    64,  -563,  -563,   633,   882,
     633,   892,   890,  1017,   810,   810,   549,   899,  1040,  1060,
     633,   718,   356,   934,   447,   633,  1159,   891,  -563,   893,
     349,   366,  -563,  -563,  -563,  -563,  1140,  -563,    64,   508,
     120,  -563,   887,  1159,   900,   633,  -563,  -563,   633,   593,
     915,   916,   922,  -563,   910,  1159,  1081,  -563,   633,  -563,
     901,  -563,  1104,  -563,   508,   925,  -563
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     3,     0,    11,     1,    13,    14,    18,     0,     0,
      70,    83,     0,     0,     0,     0,     0,     0,     0,     0,
      42,    43,     0,    91,     5,     7,     8,    22,    15,    26,
      23,    24,    25,    27,     6,    29,    30,    28,    17,   358,
      63,     0,     0,    47,    20,     0,    32,   135,     0,    16,
      86,    21,    53,    52,    89,     0,     9,   348,   369,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      72,     0,    19,     0,   138,   134,     0,    87,     0,     0,
       0,     0,     0,     0,    92,     0,    94,     0,    96,     0,
      98,     0,   100,     0,   102,     0,   104,     0,   106,     0,
     108,     0,   110,     0,   112,     0,   114,     0,   116,     0,
     118,     0,   120,     0,     0,   357,     0,    68,    62,     0,
      65,    64,     0,     0,    46,     0,    48,    37,    31,    38,
      33,     0,   136,     0,     0,    89,    89,    10,   356,   347,
      40,     0,     0,   349,   350,   368,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   371,   128,     0,     0,
       0,   277,   277,     0,     0,   270,   263,     0,     0,   253,
       0,   277,     0,     0,     0,   288,     0,     0,     0,     0,
     122,   124,     0,     0,     0,    78,    71,    79,    73,    84,
       0,     0,     0,    44,    39,    58,    59,     0,   138,    90,
      88,    85,     0,     0,   352,     0,   370,   386,   384,   372,
     383,     0,   388,   379,   376,   374,   375,   377,   378,   373,
     140,   140,   125,     0,   282,     0,   248,   278,     0,   263,
     263,     0,     0,   283,     0,     0,     0,   126,   127,   263,
       0,     0,     0,     0,     0,    57,    38,    54,    56,     0,
      66,     0,     0,     0,    38,    38,     0,     0,    38,     0,
      35,   139,   137,    41,    60,     0,    61,     0,   351,     0,
       0,     0,   141,   141,   247,   281,   279,     0,     0,     0,
       0,     0,   268,    38,   264,   251,   252,     0,     0,   286,
     285,   287,   284,    55,   359,     0,     0,    80,     0,    81,
       0,    49,     0,    38,    44,     0,     0,   354,   353,   385,
     389,   389,   212,   211,   171,    21,   179,     0,   143,     0,
     170,     0,     0,     0,   175,     0,   280,   250,    38,    38,
       0,   265,     0,   324,    38,     0,     0,    79,     0,    74,
      51,    50,    44,    34,     0,     0,     0,     0,   380,   381,
       0,   226,     0,     0,   169,   151,   152,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,     0,
       0,   159,   338,     0,     0,     0,     0,     0,     0,   163,
       0,   150,   142,   144,   145,   146,   147,   161,   164,   149,
     165,   166,   153,   156,   154,   155,   157,   158,   160,   162,
       0,   174,     0,   210,     0,     0,     0,    38,   191,     0,
     193,   225,     0,     0,   222,   221,     0,   213,   214,   218,
     223,   249,   260,     0,     0,    38,   259,    69,     0,    79,
       0,    38,     0,    36,     0,   355,   389,     0,   390,    21,
     172,     0,   181,   190,     0,   183,   184,     0,     0,   274,
     275,   235,   233,   240,   238,     0,     0,   310,   311,   309,
     336,   337,   361,   364,   366,   363,     0,     0,     0,   335,
       0,     0,   315,     0,    21,     0,    21,     0,   291,     0,
     289,   297,   263,   131,   148,     0,   329,     0,   330,     0,
     176,     0,   209,   208,   192,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,     0,     0,     0,     0,     0,     0,     0,   269,   266,
      79,    38,     0,    81,    82,    45,   382,   391,   230,   229,
       0,     0,     0,   180,     0,     0,     0,     0,   271,     0,
       0,   272,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   316,     0,   319,     0,
     308,     0,     0,    38,   298,   300,     0,     0,     0,   290,
     331,     0,     0,     0,   325,   194,   195,   197,   196,   198,
     177,   199,   200,   201,   202,   203,   205,   206,   207,   204,
     224,   178,   216,   217,   219,   220,     0,   267,    38,    81,
       0,    75,   227,     0,     0,   185,   186,   188,   187,   189,
     275,     0,     0,     0,     0,     0,   312,   367,     0,   365,
       0,   257,   258,     0,     0,   334,   344,   342,     0,   340,
       0,     0,     0,   322,     0,     0,     0,     0,   307,   299,
       0,     0,     0,     0,     0,   293,   294,     0,   295,   132,
       0,   332,     0,     0,     0,   261,    67,    76,    79,   232,
     231,   182,   273,   276,     0,   239,     0,     0,     0,     0,
       0,     0,     0,   339,   341,     0,   314,     0,   318,   323,
       0,   321,   301,   302,   304,   303,   305,   306,     0,     0,
     333,     0,     0,     0,    38,     0,   241,   243,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,   236,   245,     0,     0,   256,     0,   346,     0,
       0,     0,   292,   296,   328,   327,     0,    77,     0,     0,
       0,   242,     0,   255,     0,     0,   317,   320,     0,   237,
       0,     0,     0,   360,     0,   343,     0,   234,     0,   246,
       0,   326,     0,   254,     0,     0,   244
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -348,   902,
    -563,  -563,  -563,  -235,   -65,  -563,   655,  -148,  -563,  -563,
    -563,  -563,   -15,  -177,   746,  -138,  -203,  -563,  -563,  -563,
     804,  -563,  -563,  -563,   913,  -563,  -342,  -532,  -563,  -563,
    -563,  -563,   361,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,   -97,  -563,  -563,   834,  -563,  -563,
     805,   771,  -563,  -563,  -563,  -563,  -563,   659,   -98,  -446,
      78,  -563,  -563,  -563,   489,  -412,   -23,  -240,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,   382,  -563,  -563,  -563,
    -205,  -563,  -563,  -563,  -563,  -563,  -563,  -563,   401,  -136,
    -563,  -563,  -563,   898,  -563,   536,  -563,  -563,  -563,  -435,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,  -562,  -563,
    -563,  -563,  -477,  -563,  -563,  -563,  -563,  -563,   385,  -563,
    -563,  -563,  -563,  -563,  -563,  -563,  -563,  -563,   475,  -563,
    -563,  -563,  -563,    -4,  -563,  -317
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    90,    23,    24,    38,    25,    53,    26,
      27,    83,   140,   203,   204,   212,    28,   270,    29,    81,
     136,   265,   326,   256,   257,   276,   417,    30,    78,   194,
     131,   438,    31,    41,   132,   198,   264,   349,    32,    42,
      33,    55,    87,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    94,   118,   120,   168,   230,   391,    34,    48,    85,
     142,   282,   327,   392,   328,   360,   329,   330,   418,   457,
     419,   332,   333,   426,   427,   428,   429,   420,   451,   540,
     393,   552,   739,   394,   553,   395,   396,   723,   741,    96,
     100,   287,   102,   112,   114,   397,   633,   122,   104,   526,
     241,   242,   294,   106,   108,   340,   398,   399,   551,   236,
     237,    98,   110,   190,   400,   490,   657,   401,   699,   576,
     402,   469,   403,   483,   404,   642,   405,   645,   644,   116,
     411,   664,   499,   406,   407,   408,   481,   638,   639,   640,
      35,    91,   153,   154,    36,    77,   409,   474,   475,   558,
      37,    92,   166,   219,   223,   358
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     170,   611,    54,   207,   359,   441,   565,   646,   542,    50,
     277,   520,   177,   175,   488,   455,   259,   549,   476,   279,
     182,   304,   183,   266,   127,   268,   152,   137,   473,   309,
     311,    51,    52,   314,   290,   291,   238,   550,   491,   150,
     493,   195,   334,   334,   298,   246,     4,     8,     9,    10,
      11,   310,    39,   195,   258,   258,    12,   214,   341,   357,
     636,    40,   258,   267,   258,   453,   315,   477,   478,   176,
     489,   720,   233,   145,   146,    14,   581,   667,   352,   128,
      43,   244,   138,   245,   306,   307,   467,    51,    52,   250,
     251,   252,   253,   430,   492,   614,   196,   531,   616,   617,
     618,   619,   129,   432,   433,   139,   455,    84,   199,   436,
     602,   603,    46,   482,   130,   683,   258,   197,   197,    51,
      52,   454,   215,   258,   258,   308,    17,    44,   345,   536,
     424,    51,    52,   350,   705,   351,   647,   648,    51,    52,
      19,   289,   751,    51,    22,   442,   205,   206,   275,   297,
     278,   444,   730,   731,   448,   222,   224,   225,   226,   227,
     228,   229,   479,   279,   449,    52,   353,   258,   636,   439,
     205,   206,   258,   413,   258,   167,   674,   544,   545,   546,
     547,    49,   504,   430,   331,   331,    47,   703,   608,   737,
     335,  -313,  -313,   455,  -313,  -313,   455,   455,   455,   455,
     529,   356,   148,   357,   443,    45,   533,   150,   258,   473,
     317,   629,   318,   179,   316,   693,   694,   695,   696,   697,
     424,   217,   698,   220,   452,   456,   496,   293,   127,   414,
     390,   285,   472,   459,   612,   425,   415,   461,   280,   281,
      51,    52,   125,   434,   537,   613,    51,    52,  -362,   575,
     416,   325,    52,   274,   205,   206,   669,   149,   150,   722,
     440,   421,   331,   532,  -133,   126,   463,   262,   217,   581,
     458,   261,   497,   641,   455,   468,   320,   321,   262,  -362,
     151,   430,   430,   430,   430,   430,   573,   577,   449,    52,
     445,   180,   749,   322,   323,   522,   609,   523,    56,   218,
     530,   221,   258,    57,   449,    52,   129,   205,   206,   286,
      51,   460,   498,   263,   421,   462,   456,   422,   424,   424,
     424,   424,   424,  -387,   423,   425,   704,   435,    58,   449,
      52,   575,   575,   134,    82,   688,   527,    88,   649,   325,
      52,   274,   205,   206,   464,   497,   218,    79,   524,   581,
     525,   582,   446,   150,    89,   201,   135,   455,   689,   470,
     471,   583,   202,   150,   545,   480,   547,    80,   573,   573,
     422,  -387,  -387,   666,   691,  -387,   738,  -387,  -387,  -387,
    -387,  -387,  -387,   155,   584,   498,  -387,   274,   205,   206,
     455,   574,   325,    52,   274,   205,   206,   689,   506,   580,
     508,    86,   510,   456,    93,   746,   456,   456,   456,   456,
     575,   575,   575,   575,   575,   631,   632,   575,   544,   545,
     546,   547,   747,   425,   425,   425,   425,   425,   689,   606,
     361,   156,   157,   668,   362,   158,    95,   159,   160,   161,
     162,   163,   164,   660,    97,   689,   165,   573,   573,   573,
     573,   573,   570,   621,   573,    99,   623,   185,   626,   -93,
     101,   742,   485,   487,  -109,   105,   186,   361,   187,   721,
     103,   362,   258,   574,   574,   107,  -103,  -111,   651,   566,
     653,   188,   654,   661,   456,  -107,   -97,   -99,  -101,   109,
     500,   361,   501,   502,   503,   362,  -345,   -95,   682,  -119,
     519,   604,   605,   568,   111,   189,   210,   211,   571,   505,
     506,   507,   508,   732,   510,   572,   113,   115,   511,   512,
     513,   514,   515,   516,   517,   117,   497,   676,   677,   539,
     325,    52,   274,   205,   206,   650,   651,   652,   653,   119,
     654,   121,  -113,   554,   555,   123,   655,   656,   124,   637,
     141,   143,   574,   574,   574,   574,   574,   254,   413,   574,
     447,   144,   700,   167,  -121,  -123,   498,   456,  -115,  -117,
    -105,   169,   518,   171,   255,   205,   206,   274,   205,   206,
     255,   205,   206,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   172,   173,   615,
     456,   174,   717,   544,   545,   546,   547,   178,   364,   181,
     365,   366,   184,   192,   414,  -228,   193,   367,   200,   368,
     209,   415,   208,   637,   369,   370,  -228,   708,   371,   372,
     274,   205,   206,   373,   413,   416,   325,    52,   274,   205,
     206,   538,   750,   752,   543,   213,   544,   545,   546,   547,
     216,    15,   374,   375,   376,   544,   545,   546,   547,   692,
     377,   378,   167,   650,   651,   652,   653,   765,   654,   232,
     505,   506,   507,   508,   234,   510,   235,   379,   239,   511,
     512,   513,   514,   515,   516,   517,   240,   243,  -262,   249,
     414,   670,   273,   247,   380,   381,   382,   415,   505,   506,
     507,   508,   383,   510,   248,   384,   678,    20,    21,   385,
     271,   416,   325,    52,   274,   205,   206,   269,   150,   686,
     687,   279,   284,   690,   671,   386,   544,   545,   546,   547,
     387,   388,   716,   518,   288,   292,   650,   651,   652,   653,
     295,   654,   296,   299,    -4,     1,   300,    -4,    -4,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,   301,   302,   305,    -4,
      -4,   449,    52,   713,   205,   206,   312,   313,   319,   337,
     336,   342,    -4,    -4,   338,   339,    -4,   343,    -4,   718,
     719,    -4,    -4,    -4,    -4,    -4,   724,   344,   726,   346,
     413,   347,   348,    -4,    -4,    -4,   413,   354,   736,   355,
     363,    -2,   410,   743,     5,     6,     7,     8,     9,    10,
      11,   412,   431,   437,   465,   466,    12,    51,   494,   495,
     521,   528,   262,   755,   534,   535,   756,   362,   541,    -4,
     548,   557,   556,    13,    -4,    14,   762,   559,    -4,   560,
     561,   562,    15,    -4,    -4,    -4,   414,    -4,   563,   564,
     578,    16,   414,   415,   489,   510,   607,   610,   620,   415,
      -4,    -4,   622,   628,    -4,    -4,    -4,   416,   484,    52,
     274,   205,   206,   416,   486,    52,   274,   205,   206,   662,
     630,   634,   505,   506,   507,   508,    17,   510,   635,   643,
     658,    18,   512,   513,   514,   515,   516,   517,   567,   663,
      19,    20,    21,   659,    22,   505,   506,   507,   508,   665,
     510,   550,   673,   675,   511,   512,   513,   514,   515,   516,
     517,   569,   680,   681,   685,   654,   701,   702,   505,   506,
     507,   508,   706,   510,   709,   707,   711,   511,   512,   513,
     514,   515,   516,   517,   714,   518,   710,   712,   725,   727,
     728,   505,   506,   507,   508,   733,   510,   740,   754,   745,
     511,   512,   513,   514,   515,   516,   517,   715,   518,   753,
     744,   757,   760,   758,   505,   506,   507,   508,   759,   510,
     763,   766,   389,   511,   512,   513,   514,   515,   516,   517,
     585,   518,   147,   133,   505,   506,   507,   508,   260,   510,
     303,   231,   283,   511,   512,   513,   514,   515,   516,   517,
     601,   600,   679,   272,   518,   505,   506,   507,   508,   450,
     510,   672,   191,   684,   511,   512,   513,   514,   515,   516,
     517,   579,   627,     0,   624,     0,     0,   518,   505,   506,
     507,   508,     0,   510,     0,     0,     0,   511,   512,   513,
     514,   515,   516,   517,   625,     0,     0,   518,   505,   506,
     507,   508,     0,   510,     0,     0,     0,   511,   512,   513,
     514,   515,   516,   517,     0,   729,     0,     0,   518,   505,
     506,   507,   508,     0,   510,     0,     0,     0,   511,   512,
     513,   514,   515,   516,   517,     0,     0,     0,   734,     0,
       0,   518,   505,   506,   507,   508,     0,   510,     0,     0,
       0,   511,   512,   513,   514,   515,   516,   517,   735,     0,
       0,   518,   505,   506,   507,   508,     0,   510,     0,     0,
       0,   511,   512,   513,   514,   515,   516,   517,     0,   761,
       0,     0,   518,   505,   506,   507,   508,     0,   510,     0,
       0,     0,   511,   512,   513,   514,   515,   516,   517,     0,
       0,     0,   764,     0,     0,   518,   505,   506,   507,   508,
       0,   510,     0,     0,     0,   511,   512,   513,   514,   515,
     516,   517,     0,     0,     0,   518,   505,   506,   507,   508,
     509,   510,     0,     0,     0,   511,   512,   513,   514,   515,
     516,   517,   505,   506,   507,   508,   518,   510,     0,   748,
       0,   511,   512,   513,   514,   515,   516,   517,     0,     0,
       0,   505,   506,   507,   508,     0,   510,     0,     0,   518,
     511,   512,   513,   514,   515,   516,   517,     0,     0,   505,
     506,   507,   508,     0,   510,     0,   322,   323,     0,   518,
     513,   514,   515,   516,   517,   324,     0,   322,   323,  -129,
       0,     0,     0,     0,     0,   518,   324,     0,     0,     0,
    -130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   325,    52,   518,     0,     0,     0,     0,     0,
       0,     0,     0,   325,    52,     0,     0,     0,     0,  -173,
       0,     0,   518,     0,     0,     0,     0,     0,     0,     0,
    -173
};

static const yytype_int16 yycheck[] =
{
      97,   533,    17,   141,   321,   347,   483,   569,   454,     1,
     213,   423,   109,     1,     1,   363,   193,    13,    30,    69,
     117,   256,   119,   200,     1,   202,    91,     1,   376,   264,
     265,    79,    80,   268,   239,   240,   172,    33,     1,    57,
     388,     1,   282,   283,   249,   181,     0,     6,     7,     8,
       9,    69,    55,     1,   192,   193,    15,     1,   293,   109,
       1,    55,   200,   201,   202,     1,   269,    79,    80,    57,
      57,    57,   169,    88,    89,    34,    62,   609,   313,    56,
      55,   178,    56,   180,   261,   262,     1,    79,    80,   186,
     187,   188,   189,   333,    57,   541,    56,   439,   544,   545,
     546,   547,    79,   338,   339,    79,   454,    79,    56,   344,
     522,   523,    55,     1,    91,    56,   254,   132,   133,    79,
      80,    57,    66,   261,   262,   263,    85,     1,   305,   446,
     333,    79,    80,   310,    19,   312,   571,   572,    79,    80,
      99,   238,    22,    79,   103,   348,    82,    83,   213,   246,
     215,   354,   714,   715,   357,   159,   160,   161,   162,   163,
     164,   165,     1,    69,    79,    80,   314,   305,     1,   346,
      82,    83,   310,     1,   312,    55,   622,    62,    63,    64,
      65,    84,   417,   423,   282,   283,     1,   664,   530,   721,
     287,    79,    80,   541,    82,    83,   544,   545,   546,   547,
     435,   107,     1,   109,   352,    79,   441,    57,   346,   557,
     275,   559,   277,     1,    64,   650,   651,   652,   653,   654,
     423,     1,   657,     1,   362,   363,     1,   242,     1,    57,
     327,     1,     1,     1,    58,   333,    64,     1,   106,   107,
      79,    80,    56,   340,   447,    69,    79,    80,    17,   489,
      78,    79,    80,    81,    82,    83,    84,    56,    57,   705,
      17,     1,   360,   440,    79,    79,     1,    24,     1,    62,
     367,    17,   410,    66,   622,   373,   280,   281,    24,    48,
      79,   521,   522,   523,   524,   525,   489,   492,    79,    80,
     355,    79,   738,    43,    44,    62,   531,    64,    82,    79,
     438,    79,   440,    55,    79,    80,    79,    82,    83,    79,
      79,    79,   410,    59,     1,    79,   454,    57,   521,   522,
     523,   524,   525,    56,    64,   423,   668,   342,    55,    79,
      80,   571,   572,    56,    82,    56,   433,    69,   573,    79,
      80,    81,    82,    83,    79,   483,    79,    55,    63,    62,
      65,    64,   356,    57,    86,    59,    79,   705,    79,   374,
     375,    74,    66,    57,    63,   380,    65,    55,   571,   572,
      57,   104,   105,   608,    56,   108,    20,   110,   111,   112,
     113,   114,   115,    56,    97,   483,   119,    81,    82,    83,
     738,   489,    79,    80,    81,    82,    83,    79,    63,   497,
      65,    59,    67,   541,    10,    56,   544,   545,   546,   547,
     650,   651,   652,   653,   654,    92,    93,   657,    62,    63,
      64,    65,    56,   521,   522,   523,   524,   525,    79,   526,
      57,   104,   105,   610,    61,   108,    11,   110,   111,   112,
     113,   114,   115,   581,    49,    79,   119,   650,   651,   652,
     653,   654,     1,   550,   657,    38,   553,     1,   556,    11,
      39,    14,   384,   385,    16,    28,    10,    57,    12,   704,
      40,    61,   610,   571,   572,   122,    28,    29,    63,    69,
      65,    25,    67,   581,   622,    37,    38,    39,    40,    37,
     412,    57,   414,   415,   416,    61,    57,    49,    59,    51,
     422,   524,   525,    69,    16,    49,   145,   146,    57,    62,
      63,    64,    65,   716,    67,    64,    29,    94,    71,    72,
      73,    74,    75,    76,    77,   120,   664,   624,   625,   451,
      79,    80,    81,    82,    83,    62,    63,    64,    65,   121,
      67,    51,    94,   465,   466,   116,    73,    74,   117,   564,
      59,    69,   650,   651,   652,   653,   654,    64,     1,   657,
      64,    82,   660,    55,   116,   117,   664,   705,   120,   121,
     122,    79,   125,    79,    81,    82,    83,    81,    82,    83,
      81,    82,    83,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,    79,    79,    58,
     738,    79,   699,    62,    63,    64,    65,    79,     1,    79,
       3,     4,    79,    66,    57,    58,    17,    10,    66,    12,
      60,    64,    79,   638,    17,    18,    69,    19,    21,    22,
      81,    82,    83,    26,     1,    78,    79,    80,    81,    82,
      83,    84,   739,   740,    60,    66,    62,    63,    64,    65,
      79,    41,    45,    46,    47,    62,    63,    64,    65,    58,
      53,    54,    55,    62,    63,    64,    65,   764,    67,    56,
      62,    63,    64,    65,    56,    67,    27,    70,    57,    71,
      72,    73,    74,    75,    76,    77,    57,    56,    58,    57,
      57,   613,    58,    56,    87,    88,    89,    64,    62,    63,
      64,    65,    95,    67,    56,    98,   628,   100,   101,   102,
      60,    78,    79,    80,    81,    82,    83,    74,    57,   641,
     642,    69,    56,   645,    60,   118,    62,    63,    64,    65,
     123,   124,    58,   125,    69,    58,    62,    63,    64,    65,
      56,    67,    56,    56,     0,     1,    56,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    56,    56,    19,    15,
      16,    79,    80,   685,    82,    83,    69,    60,    79,    56,
      79,    69,    28,    29,    58,    58,    32,    56,    34,   701,
     702,    37,    38,    39,    40,    41,   708,    58,   710,    19,
       1,    60,    74,    49,    50,    51,     1,    69,   720,    73,
      59,     0,    96,   725,     3,     4,     5,     6,     7,     8,
       9,    66,    56,    14,    57,    57,    15,    79,    56,    69,
      66,    56,    24,   745,    73,    73,   748,    61,    59,    85,
      56,    48,    69,    32,    90,    34,   758,    69,    94,    79,
      59,    66,    41,    99,   100,   101,    57,   103,    20,    55,
     108,    50,    57,    64,    57,    67,    56,    19,    42,    64,
     116,   117,    66,    17,   120,   121,   122,    78,    79,    80,
      81,    82,    83,    78,    79,    80,    81,    82,    83,    73,
      59,    79,    62,    63,    64,    65,    85,    67,    79,    79,
      58,    90,    72,    73,    74,    75,    76,    77,    55,    74,
      99,   100,   101,    79,   103,    62,    63,    64,    65,    56,
      67,    33,    56,    56,    71,    72,    73,    74,    75,    76,
      77,    55,    60,    63,    57,    67,    57,    57,    62,    63,
      64,    65,    56,    67,    60,    56,    31,    71,    72,    73,
      74,    75,    76,    77,    55,   125,    66,    79,    66,    57,
      60,    62,    63,    64,    65,    56,    67,    23,    58,    66,
      71,    72,    73,    74,    75,    76,    77,    55,   125,    82,
      79,    56,    62,    57,    62,    63,    64,    65,    56,    67,
      79,    56,   327,    71,    72,    73,    74,    75,    76,    77,
      58,   125,    90,    80,    62,    63,    64,    65,   194,    67,
     254,   167,   231,    71,    72,    73,    74,    75,    76,    77,
     521,    58,   630,   208,   125,    62,    63,    64,    65,   360,
      67,   620,   124,   638,    71,    72,    73,    74,    75,    76,
      77,   495,   557,    -1,    58,    -1,    -1,   125,    62,    63,
      64,    65,    -1,    67,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    58,    -1,    -1,   125,    62,    63,
      64,    65,    -1,    67,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    77,    -1,    58,    -1,    -1,   125,    62,
      63,    64,    65,    -1,    67,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    58,    -1,
      -1,   125,    62,    63,    64,    65,    -1,    67,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    58,    -1,
      -1,   125,    62,    63,    64,    65,    -1,    67,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    -1,    58,
      -1,    -1,   125,    62,    63,    64,    65,    -1,    67,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    58,    -1,    -1,   125,    62,    63,    64,    65,
      -1,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,   125,    62,    63,    64,    65,
      66,    67,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    77,    62,    63,    64,    65,   125,    67,    -1,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    67,    -1,    -1,   125,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    62,
      63,    64,    65,    -1,    67,    -1,    43,    44,    -1,   125,
      73,    74,    75,    76,    77,    52,    -1,    43,    44,    56,
      -1,    -1,    -1,    -1,    -1,   125,    52,    -1,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    80,   125,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    80,    -1,    -1,    -1,    -1,    96,
      -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   129,   130,     0,     3,     4,     5,     6,     7,
       8,     9,    15,    32,    34,    41,    50,    85,    90,    99,
     100,   101,   103,   132,   133,   135,   137,   138,   144,   146,
     155,   160,   166,   168,   195,   278,   282,   288,   134,    55,
      55,   161,   167,    55,     1,    79,    55,     1,   196,    84,
       1,    79,    80,   136,   150,   169,    82,    55,    55,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   283,   156,    55,
      55,   147,    82,   139,    79,   197,    59,   170,    69,    86,
     131,   279,   289,    10,   189,    11,   227,    49,   249,    38,
     228,    39,   230,    40,   236,    28,   241,   122,   242,    37,
     250,    16,   231,    29,   232,    94,   267,   120,   190,   121,
     191,    51,   235,   116,   117,    56,    79,     1,    56,    79,
      91,   158,   162,   162,    56,    79,   148,     1,    56,    79,
     140,    59,   198,    69,    82,   150,   150,   137,     1,    56,
      57,    79,   142,   280,   281,    56,   104,   105,   108,   110,
     111,   112,   113,   114,   115,   119,   290,    55,   192,    79,
     192,    79,    79,    79,    79,     1,    57,   192,    79,     1,
      79,    79,   192,   192,    79,     1,    10,    12,    25,    49,
     251,   251,    66,    17,   157,     1,    56,   150,   163,    56,
      66,    59,    66,   141,   142,    82,    83,   153,    79,    60,
     170,   170,   143,    66,     1,    66,    79,     1,    79,   291,
       1,    79,   291,   292,   291,   291,   291,   291,   291,   291,
     193,   195,    56,   192,    56,    27,   247,   248,   247,    57,
      57,   238,   239,    56,   192,   192,   247,    56,    56,    57,
     192,   192,   192,   192,    64,    81,   151,   152,   153,   151,
     158,    17,    24,    59,   164,   149,   151,   153,   151,    74,
     145,    60,   198,    58,    81,   142,   153,   154,   142,    69,
     106,   107,   199,   199,    56,     1,    79,   229,    69,   192,
     238,   238,    58,   150,   240,    56,    56,   192,   238,    56,
      56,    56,    56,   152,   141,    19,   151,   151,   153,   141,
      69,   141,    69,    60,   141,   154,    64,   142,   142,    79,
     291,   291,    43,    44,    52,    79,   150,   200,   202,   204,
     205,   206,   209,   210,   215,   192,    79,    56,    58,    58,
     243,   141,    69,    56,    58,   151,    19,    60,    74,   165,
     151,   151,   141,   145,    69,    73,   107,   109,   293,   293,
     203,    57,    61,    59,     1,     3,     4,    10,    12,    17,
      18,    21,    22,    26,    45,    46,    47,    53,    54,    70,
      87,    88,    89,    95,    98,   102,   118,   123,   124,   144,
     192,   194,   201,   218,   221,   223,   224,   233,   244,   245,
     252,   255,   258,   260,   262,   264,   271,   272,   273,   284,
      96,   268,    66,     1,    57,    64,    78,   154,   206,   208,
     215,     1,    57,    64,   154,   206,   211,   212,   213,   214,
     215,    56,   141,   141,   192,   150,   141,    14,   159,   151,
      17,   164,   154,   145,   154,   142,   291,    64,   154,    79,
     205,   216,   153,     1,    57,   136,   153,   207,   192,     1,
      79,     1,    79,     1,    79,    57,    57,     1,   206,   259,
     150,   150,     1,   136,   285,   286,    30,    79,    80,     1,
     150,   274,     1,   261,    79,   208,    79,   208,     1,    57,
     253,     1,    57,   136,    56,    69,     1,   153,   206,   270,
     208,   208,   208,   208,   141,    62,    63,    64,    65,    66,
      67,    71,    72,    73,    74,    75,    76,    77,   125,   208,
     213,    66,    62,    64,    63,    65,   237,   192,    56,   141,
     153,   164,   151,   141,    73,    73,   293,   154,    84,   208,
     217,    59,   207,    60,    62,    63,    64,    65,    56,    13,
      33,   246,   219,   222,   208,   208,    69,    48,   287,    69,
      79,    59,    66,    20,    55,   270,    69,    55,    69,    55,
       1,    57,    64,   154,   206,   215,   257,   238,   108,   253,
     206,    62,    64,    74,    97,    58,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
      58,   212,   213,   213,   214,   214,   192,    56,   164,   141,
      19,   165,    58,    69,   207,    58,   207,   207,   207,   207,
      42,   192,    66,   192,    58,    58,   206,   286,    17,   136,
      59,    92,    93,   234,    79,    79,     1,   150,   275,   276,
     277,    66,   263,    79,   266,   265,   266,   257,   257,   141,
      62,    63,    64,    65,    67,    73,    74,   254,    58,    79,
     153,   206,    73,    74,   269,    56,   141,   165,   151,    84,
     208,    60,   246,    56,   207,    56,   192,   192,   208,   234,
      60,    63,    59,    56,   276,    57,   208,   208,    56,    79,
     208,    56,    58,   257,   257,   257,   257,   257,   257,   256,
     206,    57,    57,   270,   164,    19,    56,    56,    19,    60,
      66,    31,    79,   208,    55,    55,    58,   192,   208,   208,
      57,   141,   207,   225,   208,    66,   208,    57,    60,    58,
     266,   266,   154,    56,    58,    58,   208,   165,    20,   220,
      23,   226,    14,   208,    79,    66,    56,    56,    69,   207,
     192,    22,   192,    82,    58,   208,   208,    56,    57,    56,
      62,    58,   208,    79,    58,   192,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   128,   129,   129,   130,   130,   130,   130,   130,   131,
     130,   132,   130,   130,   130,   130,   130,   133,   134,   135,
     135,   136,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   138,   139,   139,   140,   140,   140,   140,   141,   141,
     143,   142,   144,   144,   145,   145,   146,   147,   147,   148,
     149,   149,   150,   150,   151,   151,   152,   152,   153,   153,
     154,   154,   155,   156,   156,   157,   156,   158,   158,   159,
     161,   160,   162,   162,   163,   163,   163,   163,   163,   164,
     164,   165,   165,   167,   166,   168,   168,   169,   169,   170,
     170,   172,   171,   173,   171,   174,   171,   175,   171,   176,
     171,   177,   171,   178,   171,   179,   171,   180,   171,   181,
     171,   182,   171,   183,   171,   184,   171,   185,   171,   186,
     171,   187,   171,   188,   171,   189,   190,   191,   193,   192,
     192,   194,   194,   196,   195,   195,   197,   197,   198,   198,
     199,   200,   199,   199,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     202,   203,   202,   204,   202,   202,   205,   205,   205,   206,
     206,   206,   206,   207,   207,   207,   207,   207,   207,   207,
     207,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   208,   208,
     208,   209,   210,   211,   212,   212,   212,   212,   213,   213,
     213,   214,   214,   214,   214,   214,   216,   215,   217,   217,
     217,   217,   217,   219,   218,   218,   220,   220,   222,   221,
     221,   223,   224,   225,   225,   226,   226,   227,   229,   228,
     230,   231,   232,   232,   233,   233,   233,   234,   234,   235,
     237,   236,   238,   239,   238,   240,   240,   241,   243,   242,
     242,   244,   245,   245,   245,   246,   246,   247,   247,   248,
     248,   248,   249,   250,   251,   251,   251,   251,   251,   252,
     252,   252,   253,   254,   254,   256,   255,   255,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   258,
     258,   259,   259,   261,   260,   260,   263,   262,   262,   265,
     264,   264,   266,   266,   267,   269,   268,   268,   268,   268,
     270,   270,   270,   270,   271,   271,   272,   272,   274,   273,
     275,   275,   276,   276,   276,   277,   277,   278,   279,   279,
     279,   280,   280,   281,   281,   281,   281,   282,   283,   283,
     284,   284,   285,   285,   286,   286,   287,   287,   288,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     290,   290,   290,   290,   291,   291,   291,   292,   292,   293,
     293,   293
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     2,     2,     2,     2,     0,
       5,     0,     3,     2,     2,     2,     3,     2,     0,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     0,     2,     5,     3,     6,     1,     0,     1,
       0,     3,     1,     1,     0,     5,     4,     0,     2,     4,
       3,     3,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     4,     0,     2,     0,     4,     9,     1,     1,
       0,     5,     0,     2,     4,     7,     8,    11,     1,     0,
       2,     0,     3,     0,     5,     5,     2,     2,     4,     0,
       3,     0,     2,     0,     2,     0,     2,     0,     2,     0,
       2,     0,     2,     0,     2,     0,     2,     0,     2,     0,
       2,     0,     2,     0,     2,     0,     2,     0,     2,     0,
       2,     0,     3,     0,     3,     3,     3,     3,     0,     3,
       3,     2,     4,     0,     3,     2,     2,     4,     0,     3,
       0,     0,     3,     2,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     3,     0,     2,     1,     3,     4,     4,     1,
       4,     3,     6,     1,     1,     3,     3,     3,     3,     3,
       1,     1,     2,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       1,     1,     1,     1,     1,     2,     3,     3,     1,     3,
       3,     1,     1,     1,     3,     1,     0,     5,     0,     1,
       1,     3,     3,     0,    10,     2,     0,     2,     0,     5,
       2,     6,     8,     0,     8,     0,     3,     4,     0,     6,
       5,     4,     4,     2,    11,     8,     7,     1,     1,     6,
       0,     9,     0,     0,     2,     2,     4,     8,     0,     7,
       2,     3,     3,     5,     2,     0,     3,     0,     1,     2,
       3,     2,     3,     3,     3,     3,     3,     3,     1,     2,
       3,     2,     6,     1,     1,     0,     7,     2,     1,     2,
       1,     3,     3,     3,     3,     3,     3,     2,     1,     2,
       2,     1,     3,     0,     5,     2,     0,     8,     5,     0,
       8,     5,     1,     2,     5,     0,    10,     7,     7,     2,
       1,     2,     3,     4,     4,     2,     2,     2,     0,     5,
       1,     2,     1,     6,     1,     1,     4,     4,     0,     2,
       2,     3,     2,     4,     4,     6,     1,     4,     0,     5,
       9,     2,     0,     1,     1,     3,     0,     2,     4,     0,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     5,     7,     2,     1,     3,     1,     0,     1,     0,
       2,     3
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
#line 133 "parse1.y" /* yacc.c:1646  */
    {/*ldebug(top, intoken)*/;}
#line 2192 "parse1.c" /* yacc.c:1646  */
    break;

  case 3:
#line 134 "parse1.y" /* yacc.c:1646  */
    {diag("Illegal block", (char *)0);}
#line 2198 "parse1.c" /* yacc.c:1646  */
    break;

  case 6:
#line 140 "parse1.y" /* yacc.c:1646  */
    {Item* q; replacstr((yyvsp[0].qp), "static double");
		vectorize_substitute((yyvsp[0].qp), "/*Top LOCAL");
		vectorize_substitute(lastok->next, "*/\n");
		movelist((yyvsp[0].qp), lastok->next, firstlist);
		if (!toplocal_) {toplocal_ = newlist();}
		ITERATE(q, toplocal1_) {
			assert(SYM(q)->name[0] == '_' && SYM(q)->name[1] == 'l');
			SYM(q)->name[1] = 'z';
		}
		movelist(toplocal1_->next, toplocal1_->prev, toplocal_);
		}
#line 2214 "parse1.c" /* yacc.c:1646  */
    break;

  case 9:
#line 153 "parse1.y" /* yacc.c:1646  */
    {model_level = atoi(STR((yyvsp[0].qp)));}
#line 2220 "parse1.c" /* yacc.c:1646  */
    break;

  case 10:
#line 154 "parse1.y" /* yacc.c:1646  */
    {model_level = 0;}
#line 2226 "parse1.c" /* yacc.c:1646  */
    break;

  case 11:
#line 156 "parse1.y" /* yacc.c:1646  */
    {if (sensused)
			diag("sensitivity analysis not implemented for",
				" this block type");
		}
#line 2235 "parse1.c" /* yacc.c:1646  */
    break;

  case 13:
#line 163 "parse1.y" /* yacc.c:1646  */
    {inblock(SYM((yyvsp[0].qp))->name); replacstr((yyvsp[0].qp), "\n/*VERBATIM*/\n");
		if (!assert_threadsafe && !saw_verbatim_) {
 		 fprintf(stderr, "Notice: VERBATIM blocks are not thread safe\n");
		 saw_verbatim_ = 1;
		 vectorize = 0;
		}
		movelist((yyvsp[0].qp),intoken->prev, procfunc);}
#line 2247 "parse1.c" /* yacc.c:1646  */
    break;

  case 14:
#line 172 "parse1.y" /* yacc.c:1646  */
    {
		in_comment_ = 1;
		inblock(SYM((yyvsp[0].qp))->name); deltokens((yyvsp[0].qp), intoken->prev);
		in_comment_ = 0;
		}
#line 2257 "parse1.c" /* yacc.c:1646  */
    break;

  case 16:
#line 179 "parse1.y" /* yacc.c:1646  */
    {include_file((yyvsp[0].qp));}
#line 2263 "parse1.c" /* yacc.c:1646  */
    break;

  case 17:
#line 182 "parse1.y" /* yacc.c:1646  */
    {if (modelline == NULL) modelline = (yyvsp[0].str);
			deltokens((yyvsp[-1].qp), intoken->prev);}
#line 2270 "parse1.c" /* yacc.c:1646  */
    break;

  case 18:
#line 185 "parse1.y" /* yacc.c:1646  */
    {(yyval.str) = inputline();}
#line 2276 "parse1.c" /* yacc.c:1646  */
    break;

  case 19:
#line 190 "parse1.y" /* yacc.c:1646  */
    { Symbol *sp = SYM((yyvsp[-1].qp));
	 if (sp->subtype)
		diag(sp->name, " used before DEFINEed");
	 sp->u.str = STR((yyvsp[0].qp));
	 sp->type = DEFINEDVAR;
	 deltokens((yyvsp[-2].qp), (yyvsp[0].qp));}
#line 2287 "parse1.c" /* yacc.c:1646  */
    break;

  case 20:
#line 196 "parse1.y" /* yacc.c:1646  */
    {myerr("syntax: DEFINE name integer");}
#line 2293 "parse1.c" /* yacc.c:1646  */
    break;

  case 21:
#line 199 "parse1.y" /* yacc.c:1646  */
    { Symbol *checklocal();
		  SYM((yyvsp[0].qp)) = checklocal(SYM((yyvsp[0].qp)));  /* it was a bug
			when this was done to the lookahead token in lex */
		}
#line 2302 "parse1.c" /* yacc.c:1646  */
    break;

  case 31:
#line 207 "parse1.y" /* yacc.c:1646  */
    {deltokens((yyvsp[-3].qp), (yyvsp[0].qp));}
#line 2308 "parse1.c" /* yacc.c:1646  */
    break;

  case 33:
#line 211 "parse1.y" /* yacc.c:1646  */
    { explicit_decl(model_level, (yyvsp[0].qp));}
#line 2314 "parse1.c" /* yacc.c:1646  */
    break;

  case 34:
#line 217 "parse1.y" /* yacc.c:1646  */
    {parminstall(SYM((yyvsp[-4].qp)), STR((yyvsp[-2].qp)), (yyvsp[-1].str), (yyvsp[0].str));}
#line 2320 "parse1.c" /* yacc.c:1646  */
    break;

  case 35:
#line 219 "parse1.y" /* yacc.c:1646  */
    {parminstall(SYM((yyvsp[-2].qp)), "0", (yyvsp[-1].str), (yyvsp[0].str));}
#line 2326 "parse1.c" /* yacc.c:1646  */
    break;

  case 36:
#line 221 "parse1.y" /* yacc.c:1646  */
    { int i = atoi(STR((yyvsp[-3].qp)));
		  if (i < 1) diag("Array index must be > 0", (char*)0);
		  parm_array_install(SYM((yyvsp[-5].qp)), "0", (yyvsp[-1].str), (yyvsp[0].str), i);
		}
#line 2335 "parse1.c" /* yacc.c:1646  */
    break;

  case 37:
#line 225 "parse1.y" /* yacc.c:1646  */
    {diag("name = number", (char *)0);}
#line 2341 "parse1.c" /* yacc.c:1646  */
    break;

  case 38:
#line 227 "parse1.y" /* yacc.c:1646  */
    {(yyval.str) = stralloc("", (char *)0);}
#line 2347 "parse1.c" /* yacc.c:1646  */
    break;

  case 40:
#line 230 "parse1.y" /* yacc.c:1646  */
    {(yyval.str) = inputtopar();}
#line 2353 "parse1.c" /* yacc.c:1646  */
    break;

  case 41:
#line 232 "parse1.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[-1].str); delete((yyvsp[-2].qp)); delete((yyvsp[0].qp));}
#line 2359 "parse1.c" /* yacc.c:1646  */
    break;

  case 42:
#line 234 "parse1.y" /* yacc.c:1646  */
    {replacstr((yyvsp[0].qp), "");}
#line 2365 "parse1.c" /* yacc.c:1646  */
    break;

  case 43:
#line 235 "parse1.y" /* yacc.c:1646  */
    {replacstr((yyvsp[0].qp), "");}
#line 2371 "parse1.c" /* yacc.c:1646  */
    break;

  case 44:
#line 238 "parse1.y" /* yacc.c:1646  */
    {(yyval.str) = stralloc("", (char*)0);}
#line 2377 "parse1.c" /* yacc.c:1646  */
    break;

  case 45:
#line 240 "parse1.y" /* yacc.c:1646  */
    {
		 Sprintf(buf, "%s %s", STR((yyvsp[-3].qp)), STR((yyvsp[-1].qp)));
		 (yyval.str) = stralloc(buf, (char*)0);
		}
#line 2386 "parse1.c" /* yacc.c:1646  */
    break;

  case 46:
#line 245 "parse1.y" /* yacc.c:1646  */
    {deltokens((yyvsp[-3].qp), (yyvsp[0].qp));}
#line 2392 "parse1.c" /* yacc.c:1646  */
    break;

  case 48:
#line 249 "parse1.y" /* yacc.c:1646  */
    { explicit_decl(model_level, (yyvsp[0].qp)); }
#line 2398 "parse1.c" /* yacc.c:1646  */
    break;

  case 49:
#line 253 "parse1.y" /* yacc.c:1646  */
    {steppedinstall(SYM((yyvsp[-3].qp)), (yyvsp[-1].qp), lastok, (yyvsp[0].str));}
#line 2404 "parse1.c" /* yacc.c:1646  */
    break;

  case 54:
#line 261 "parse1.y" /* yacc.c:1646  */
    {lastok = (yyvsp[0].qp);}
#line 2410 "parse1.c" /* yacc.c:1646  */
    break;

  case 55:
#line 264 "parse1.y" /* yacc.c:1646  */
    { Sprintf(buf, "-%s", STR((yyvsp[0].qp)));
		 STR((yyvsp[0].qp)) = stralloc(buf, STR((yyvsp[0].qp))); (yyval.qp) = (yyvsp[0].qp);
		delete((yyvsp[-1].qp)); lastok = (yyvsp[0].qp);
		}
#line 2419 "parse1.c" /* yacc.c:1646  */
    break;

  case 59:
#line 272 "parse1.y" /* yacc.c:1646  */
    {replacstr((yyvsp[0].qp), SYM((yyvsp[0].qp))->u.str);}
#line 2425 "parse1.c" /* yacc.c:1646  */
    break;

  case 60:
#line 274 "parse1.y" /* yacc.c:1646  */
    {lastok = (yyvsp[0].qp);}
#line 2431 "parse1.c" /* yacc.c:1646  */
    break;

  case 61:
#line 276 "parse1.y" /* yacc.c:1646  */
    {Sprintf(buf, "%s.0", STR((yyvsp[0].qp)));
		STR((yyvsp[0].qp)) = stralloc(buf, STR((yyvsp[0].qp)));
		lastok = (yyvsp[0].qp);
		}
#line 2440 "parse1.c" /* yacc.c:1646  */
    break;

  case 62:
#line 281 "parse1.y" /* yacc.c:1646  */
    {deltokens((yyvsp[-3].qp), (yyvsp[0].qp));}
#line 2446 "parse1.c" /* yacc.c:1646  */
    break;

  case 64:
#line 285 "parse1.y" /* yacc.c:1646  */
    { explicit_decl(model_level, (yyvsp[0].qp)); }
#line 2452 "parse1.c" /* yacc.c:1646  */
    break;

  case 65:
#line 286 "parse1.y" /* yacc.c:1646  */
    {scopindep = 1;}
#line 2458 "parse1.c" /* yacc.c:1646  */
    break;

  case 66:
#line 287 "parse1.y" /* yacc.c:1646  */
    { explicit_decl(model_level, (yyvsp[0].qp));
		  scopindep = 0;
		}
#line 2466 "parse1.c" /* yacc.c:1646  */
    break;

  case 67:
#line 293 "parse1.y" /* yacc.c:1646  */
    {indepinstall(SYM((yyvsp[-8].qp)), STR((yyvsp[-6].qp)),
		 STR((yyvsp[-4].qp)), STR((yyvsp[-2].qp)), (yyvsp[-1].qp), (yyvsp[0].str), scopindep);
		}
#line 2474 "parse1.c" /* yacc.c:1646  */
    break;

  case 68:
#line 296 "parse1.y" /* yacc.c:1646  */
    {diag("name FROM number TO number WITH integer\n", (char *)0);}
#line 2480 "parse1.c" /* yacc.c:1646  */
    break;

  case 70:
#line 300 "parse1.y" /* yacc.c:1646  */
    {stateblock = 0;}
#line 2486 "parse1.c" /* yacc.c:1646  */
    break;

  case 71:
#line 300 "parse1.y" /* yacc.c:1646  */
    {deltokens((yyvsp[-4].qp), (yyvsp[0].qp));}
#line 2492 "parse1.c" /* yacc.c:1646  */
    break;

  case 73:
#line 304 "parse1.y" /* yacc.c:1646  */
    { explicit_decl(model_level, (yyvsp[0].qp));}
#line 2498 "parse1.c" /* yacc.c:1646  */
    break;

  case 74:
#line 308 "parse1.y" /* yacc.c:1646  */
    {depinstall(stateblock, SYM((yyvsp[-3].qp)), 0, "0", "1", (yyvsp[-1].str), (yyvsp[-2].qp), 1, (yyvsp[0].str));
		 }
#line 2505 "parse1.c" /* yacc.c:1646  */
    break;

  case 75:
#line 311 "parse1.y" /* yacc.c:1646  */
    {int i = atoi(STR((yyvsp[-4].qp)));
		 if (i < 1) diag("Array index must be > 0", (char *)0);
		 depinstall(stateblock, SYM((yyvsp[-6].qp)), i,
			 "0", "1", (yyvsp[-1].str), (yyvsp[-2].qp), 1, (yyvsp[0].str));
		}
#line 2515 "parse1.c" /* yacc.c:1646  */
    break;

  case 76:
#line 317 "parse1.y" /* yacc.c:1646  */
    {depinstall(stateblock, SYM((yyvsp[-7].qp)), 0, STR((yyvsp[-5].qp)),
		 STR((yyvsp[-3].qp)), (yyvsp[-1].str), (yyvsp[-2].qp), 1, (yyvsp[0].str));
		}
#line 2523 "parse1.c" /* yacc.c:1646  */
    break;

  case 77:
#line 321 "parse1.y" /* yacc.c:1646  */
    {int i = atoi(STR((yyvsp[-8].qp)));
		 if (i < 1) diag("Array index must be > 0", (char *)0);
		 depinstall(stateblock, SYM((yyvsp[-10].qp)), i,
		 STR((yyvsp[-5].qp)), STR((yyvsp[-3].qp)), (yyvsp[-1].str), (yyvsp[-2].qp), 1, (yyvsp[0].str));
		}
#line 2533 "parse1.c" /* yacc.c:1646  */
    break;

  case 78:
#line 326 "parse1.y" /* yacc.c:1646  */
    {
diag("name FROM number TO number START number\n",
"FROM...TO and START are optional, name can be name[integer]\n");}
#line 2541 "parse1.c" /* yacc.c:1646  */
    break;

  case 79:
#line 330 "parse1.y" /* yacc.c:1646  */
    {(yyval.qp) = ITEM0;}
#line 2547 "parse1.c" /* yacc.c:1646  */
    break;

  case 80:
#line 331 "parse1.y" /* yacc.c:1646  */
    {(yyval.qp) = (yyvsp[0].qp);}
#line 2553 "parse1.c" /* yacc.c:1646  */
    break;

  case 81:
#line 334 "parse1.y" /* yacc.c:1646  */
    { (yyval.str) = stralloc("", (char*)0);}
#line 2559 "parse1.c" /* yacc.c:1646  */
    break;

  case 82:
#line 336 "parse1.y" /* yacc.c:1646  */
    {
			(yyval.str) = stralloc(STR((yyvsp[-1].qp)), (char*)0);
		}
#line 2567 "parse1.c" /* yacc.c:1646  */
    break;

  case 83:
#line 340 "parse1.y" /* yacc.c:1646  */
    {stateblock = 1;}
#line 2573 "parse1.c" /* yacc.c:1646  */
    break;

  case 84:
#line 340 "parse1.y" /* yacc.c:1646  */
    {deltokens((yyvsp[-4].qp), (yyvsp[0].qp));}
#line 2579 "parse1.c" /* yacc.c:1646  */
    break;

  case 85:
#line 344 "parse1.y" /* yacc.c:1646  */
    { Item *q;
		 q = linsertsym(plotlist, SYM((yyvsp[-1].qp))); Insertstr(q->next, (yyvsp[0].str)); }
#line 2586 "parse1.c" /* yacc.c:1646  */
    break;

  case 86:
#line 347 "parse1.y" /* yacc.c:1646  */
    { diag("PLOT namelist VS name", (char *)0);}
#line 2592 "parse1.c" /* yacc.c:1646  */
    break;

  case 87:
#line 350 "parse1.y" /* yacc.c:1646  */
    { if (plotlist->next == plotlist) {
			Lappendsym(plotlist, SYM((yyvsp[-1].qp)));
			Lappendstr(plotlist, (yyvsp[0].str));
		  }else{
			diag("Only one PLOT declaration allowed", (char *)0);
		  }
		}
#line 2604 "parse1.c" /* yacc.c:1646  */
    break;

  case 88:
#line 358 "parse1.y" /* yacc.c:1646  */
    { Lappendsym(plotlist, SYM((yyvsp[-1].qp))); Lappendstr(plotlist, (yyvsp[0].str));}
#line 2610 "parse1.c" /* yacc.c:1646  */
    break;

  case 89:
#line 361 "parse1.y" /* yacc.c:1646  */
    { (yyval.str) = "-1";}
#line 2616 "parse1.c" /* yacc.c:1646  */
    break;

  case 90:
#line 363 "parse1.y" /* yacc.c:1646  */
    { (yyval.str) = STR((yyvsp[-1].qp));}
#line 2622 "parse1.c" /* yacc.c:1646  */
    break;

  case 91:
#line 365 "parse1.y" /* yacc.c:1646  */
    {blocktype = INITIAL1;}
#line 2628 "parse1.c" /* yacc.c:1646  */
    break;

  case 93:
#line 367 "parse1.y" /* yacc.c:1646  */
    {lexcontext = NONLINEAR; blocktype = DERIVATIVE;}
#line 2634 "parse1.c" /* yacc.c:1646  */
    break;

  case 95:
#line 368 "parse1.y" /* yacc.c:1646  */
    {blocktype = BREAKPOINT;}
#line 2640 "parse1.c" /* yacc.c:1646  */
    break;

  case 97:
#line 369 "parse1.y" /* yacc.c:1646  */
    {lexcontext = blocktype = LINEAR;}
#line 2646 "parse1.c" /* yacc.c:1646  */
    break;

  case 99:
#line 370 "parse1.y" /* yacc.c:1646  */
    {lexcontext = blocktype = NONLINEAR;}
#line 2652 "parse1.c" /* yacc.c:1646  */
    break;

  case 101:
#line 371 "parse1.y" /* yacc.c:1646  */
    {blocktype = FUNCTION1;}
#line 2658 "parse1.c" /* yacc.c:1646  */
    break;

  case 103:
#line 372 "parse1.y" /* yacc.c:1646  */
    {blocktype = PROCEDURE;}
#line 2664 "parse1.c" /* yacc.c:1646  */
    break;

  case 105:
#line 373 "parse1.y" /* yacc.c:1646  */
    {blocktype = NETRECEIVE;}
#line 2670 "parse1.c" /* yacc.c:1646  */
    break;

  case 107:
#line 374 "parse1.y" /* yacc.c:1646  */
    {blocktype = TERMINAL;}
#line 2676 "parse1.c" /* yacc.c:1646  */
    break;

  case 109:
#line 375 "parse1.y" /* yacc.c:1646  */
    {blocktype = DISCRETE;}
#line 2682 "parse1.c" /* yacc.c:1646  */
    break;

  case 111:
#line 376 "parse1.y" /* yacc.c:1646  */
    {lexcontext = blocktype = PARTIAL;}
#line 2688 "parse1.c" /* yacc.c:1646  */
    break;

  case 113:
#line 377 "parse1.y" /* yacc.c:1646  */
    {lexcontext = blocktype = KINETIC;ostmt_start();}
#line 2694 "parse1.c" /* yacc.c:1646  */
    break;

  case 114:
#line 377 "parse1.y" /* yacc.c:1646  */
    {see_ostmt();}
#line 2700 "parse1.c" /* yacc.c:1646  */
    break;

  case 115:
#line 378 "parse1.y" /* yacc.c:1646  */
    {blocktype = CONSTRUCTOR;}
#line 2706 "parse1.c" /* yacc.c:1646  */
    break;

  case 117:
#line 379 "parse1.y" /* yacc.c:1646  */
    {blocktype = DESTRUCTOR;}
#line 2712 "parse1.c" /* yacc.c:1646  */
    break;

  case 119:
#line 380 "parse1.y" /* yacc.c:1646  */
    {blocktype = FUNCTION_TABLE;}
#line 2718 "parse1.c" /* yacc.c:1646  */
    break;

  case 121:
#line 381 "parse1.y" /* yacc.c:1646  */
    {blocktype = BEFORE;}
#line 2724 "parse1.c" /* yacc.c:1646  */
    break;

  case 123:
#line 382 "parse1.y" /* yacc.c:1646  */
    {blocktype = AFTER;}
#line 2730 "parse1.c" /* yacc.c:1646  */
    break;

  case 125:
#line 385 "parse1.y" /* yacc.c:1646  */
    {movelist((yyvsp[-1].qp), (yyvsp[0].qp), initfunc);}
#line 2736 "parse1.c" /* yacc.c:1646  */
    break;

  case 126:
#line 388 "parse1.y" /* yacc.c:1646  */
    {movelist((yyvsp[-1].qp), (yyvsp[0].qp), constructorfunc);}
#line 2742 "parse1.c" /* yacc.c:1646  */
    break;

  case 127:
#line 391 "parse1.y" /* yacc.c:1646  */
    {movelist((yyvsp[-1].qp), (yyvsp[0].qp), destructorfunc);}
#line 2748 "parse1.c" /* yacc.c:1646  */
    break;

  case 128:
#line 393 "parse1.y" /* yacc.c:1646  */
    {pushlocal();}
#line 2754 "parse1.c" /* yacc.c:1646  */
    break;

  case 129:
#line 393 "parse1.y" /* yacc.c:1646  */
    {poplocal();}
#line 2760 "parse1.c" /* yacc.c:1646  */
    break;

  case 130:
#line 395 "parse1.y" /* yacc.c:1646  */
    {poplocal();}
#line 2766 "parse1.c" /* yacc.c:1646  */
    break;

  case 131:
#line 398 "parse1.y" /* yacc.c:1646  */
    {conductance_hint(blocktype, (yyvsp[-1].qp), (yyvsp[0].qp));}
#line 2772 "parse1.c" /* yacc.c:1646  */
    break;

  case 132:
#line 400 "parse1.y" /* yacc.c:1646  */
    {conductance_hint(blocktype, (yyvsp[-3].qp), (yyvsp[0].qp));}
#line 2778 "parse1.c" /* yacc.c:1646  */
    break;

  case 133:
#line 403 "parse1.y" /* yacc.c:1646  */
    {
		  if (toplocal1_) {freelist(&toplocal1_);}
		  toplocal1_ = newlist();
		}
#line 2787 "parse1.c" /* yacc.c:1646  */
    break;

  case 134:
#line 408 "parse1.y" /* yacc.c:1646  */
    { replacstr((yyvsp[-2].qp), "double");
		  Insertstr(lastok->next, ";\n");
		  possible_local_current(blocktype, toplocal1_);
		}
#line 2796 "parse1.c" /* yacc.c:1646  */
    break;

  case 135:
#line 412 "parse1.y" /* yacc.c:1646  */
    {myerr("Illegal LOCAL declaration");}
#line 2802 "parse1.c" /* yacc.c:1646  */
    break;

  case 136:
#line 417 "parse1.y" /* yacc.c:1646  */
    {int a2; pushlocal();
		 a2 = SYM((yyvsp[-1].qp))->assigned_to_; /* in case marked threadsafe */
		 SYM((yyvsp[-1].qp)) = copylocal(SYM((yyvsp[-1].qp)));
		 SYM((yyvsp[-1].qp))->assigned_to_ = a2;
		 lappendsym(toplocal1_, SYM((yyvsp[-1].qp)));
		 if ((yyvsp[0].i)) {
			SYM((yyvsp[-1].qp))->araydim = (yyvsp[0].i);
			SYM((yyvsp[-1].qp))->subtype |= ARRAY;
		 }else{
			lastok = (yyvsp[-1].qp);
		 }
		}
#line 2819 "parse1.c" /* yacc.c:1646  */
    break;

  case 137:
#line 430 "parse1.y" /* yacc.c:1646  */
    {
		 int a2 = SYM((yyvsp[-1].qp))->assigned_to_; /* in case marked threadsafe */
		 SYM((yyvsp[-1].qp)) = copylocal(SYM((yyvsp[-1].qp)));
		 SYM((yyvsp[-1].qp))->assigned_to_ = a2;
		 lappendsym(toplocal1_, SYM((yyvsp[-1].qp)));
		 if ((yyvsp[0].i)) {
			SYM((yyvsp[-1].qp))->araydim = (yyvsp[0].i);
			SYM((yyvsp[-1].qp))->subtype |= ARRAY;
		 }else{
			lastok = (yyvsp[-1].qp);
		 }
		}
#line 2836 "parse1.c" /* yacc.c:1646  */
    break;

  case 138:
#line 444 "parse1.y" /* yacc.c:1646  */
    {(yyval.i) = 0;}
#line 2842 "parse1.c" /* yacc.c:1646  */
    break;

  case 139:
#line 446 "parse1.y" /* yacc.c:1646  */
    {(yyval.i) = atoi(STR((yyvsp[-1].qp))); lastok = (yyvsp[0].qp);}
#line 2848 "parse1.c" /* yacc.c:1646  */
    break;

  case 141:
#line 449 "parse1.y" /* yacc.c:1646  */
    {if (blocktype == KINETIC) see_ostmt();}
#line 2854 "parse1.c" /* yacc.c:1646  */
    break;

  case 142:
#line 450 "parse1.y" /* yacc.c:1646  */
    {if (blocktype == KINETIC) see_ostmt();}
#line 2860 "parse1.c" /* yacc.c:1646  */
    break;

  case 143:
#line 451 "parse1.y" /* yacc.c:1646  */
    {if (blocktype == KINETIC) { see_astmt((yyvsp[0].qp), astmt_end_); }}
#line 2866 "parse1.c" /* yacc.c:1646  */
    break;

  case 151:
#line 461 "parse1.y" /* yacc.c:1646  */
    {inblock(SYM((yyvsp[0].qp))->name);
		replacstr((yyvsp[0].qp), "\n/*VERBATIM*/\n");
		if (!assert_threadsafe && !saw_verbatim_) {
 		 fprintf(stderr, "Notice: VERBATIM blocks are not thread safe\n");
		 saw_verbatim_ = 1;
		 vectorize = 0;
		}
		}
#line 2879 "parse1.c" /* yacc.c:1646  */
    break;

  case 152:
#line 471 "parse1.y" /* yacc.c:1646  */
    {inblock(SYM((yyvsp[0].qp))->name); deltokens((yyvsp[0].qp), intoken->prev);}
#line 2885 "parse1.c" /* yacc.c:1646  */
    break;

  case 154:
#line 473 "parse1.y" /* yacc.c:1646  */
    {check_block(KINETIC, blocktype, "COMPARTMENT");}
#line 2891 "parse1.c" /* yacc.c:1646  */
    break;

  case 155:
#line 474 "parse1.y" /* yacc.c:1646  */
    {check_block(KINETIC, blocktype, "LONGDIFUS");}
#line 2897 "parse1.c" /* yacc.c:1646  */
    break;

  case 156:
#line 475 "parse1.y" /* yacc.c:1646  */
    {check_block(KINETIC, blocktype, "CONSERVE");}
#line 2903 "parse1.c" /* yacc.c:1646  */
    break;

  case 159:
#line 479 "parse1.y" /* yacc.c:1646  */
    { replacstr((yyvsp[0].qp), " _reset = 1;\n"); }
#line 2909 "parse1.c" /* yacc.c:1646  */
    break;

  case 162:
#line 483 "parse1.y" /* yacc.c:1646  */
    {if (blocktype !=FUNCTION1 && blocktype != PROCEDURE) {
			diag("TABLE valid only for FUNCTION or PROCEDURE", (char *)0);
		}}
#line 2917 "parse1.c" /* yacc.c:1646  */
    break;

  case 167:
#line 490 "parse1.y" /* yacc.c:1646  */
    { nrnmutex(1,(yyvsp[0].qp)); }
#line 2923 "parse1.c" /* yacc.c:1646  */
    break;

  case 168:
#line 491 "parse1.y" /* yacc.c:1646  */
    { nrnmutex(0,(yyvsp[0].qp)); }
#line 2929 "parse1.c" /* yacc.c:1646  */
    break;

  case 169:
#line 493 "parse1.y" /* yacc.c:1646  */
    {myerr("Illegal statement");}
#line 2935 "parse1.c" /* yacc.c:1646  */
    break;

  case 170:
#line 497 "parse1.y" /* yacc.c:1646  */
    {astmt_end_ = insertsym(lastok->next, semi);}
#line 2941 "parse1.c" /* yacc.c:1646  */
    break;

  case 171:
#line 498 "parse1.y" /* yacc.c:1646  */
    {protect_ = 1;}
#line 2947 "parse1.c" /* yacc.c:1646  */
    break;

  case 172:
#line 499 "parse1.y" /* yacc.c:1646  */
    {protect_ = 0; astmt_end_ = insertsym(lastok->next, semi);
			astmt_end_ = protect_astmt((yyvsp[-2].qp), astmt_end_);
		}
#line 2955 "parse1.c" /* yacc.c:1646  */
    break;

  case 173:
#line 502 "parse1.y" /* yacc.c:1646  */
    {inequation = 1;}
#line 2961 "parse1.c" /* yacc.c:1646  */
    break;

  case 174:
#line 502 "parse1.y" /* yacc.c:1646  */
    {
		(yyval.qp) = (yyvsp[0].qp); inequation = 0;
		astmt_end_ = insertstr(lastok->next->next->next, "");}
#line 2969 "parse1.c" /* yacc.c:1646  */
    break;

  case 175:
#line 506 "parse1.y" /* yacc.c:1646  */
    {astmt_end_ = insertsym(lastok->next, semi);}
#line 2975 "parse1.c" /* yacc.c:1646  */
    break;

  case 176:
#line 511 "parse1.y" /* yacc.c:1646  */
    { if (blocktype == DERIVATIVE && SYM((yyvsp[-2].qp))->type == PRIME) {
			/* put Dvar in a derivative used list */
			deriv_used(SYM((yyvsp[-2].qp)), (yyvsp[0].qp), lastok);
			}
		  if (blocktype == DERIVATIVE && (SYM((yyvsp[-2].qp))->subtype & STAT)) {
			Fprintf(stderr,
"WARNING: %s (a STATE) is assigned a value\
 in a DERIVATIVE block.\n Multistep integrators (such as Runge) may not\
 work correctly.\n", SYM((yyvsp[-2].qp))->name);
		  }
		  if (blocktype == DISCRETE && SYM((yyvsp[-2].qp))->type == NAME
			&& (SYM((yyvsp[-2].qp))->subtype & STAT)) {
			SYM((yyvsp[-2].qp))->used++;
			}
#if NOCMODL
		  nrn_var_assigned(SYM((yyvsp[-2].qp)));
#endif
		}
#line 2998 "parse1.c" /* yacc.c:1646  */
    break;

  case 177:
#line 531 "parse1.y" /* yacc.c:1646  */
    { inequation = 0;
		Insertstr((yyvsp[-2].qp), " -(");
		replacstr((yyvsp[-1].qp), ") + ");
		if (nstate == 0)
{yyerror("previous equation contains no state variables"); YYERROR;}
		 eqnqueue((yyvsp[-3].qp));
		}
#line 3010 "parse1.c" /* yacc.c:1646  */
    break;

  case 178:
#line 539 "parse1.y" /* yacc.c:1646  */
    { inequation = 0;
		delete((yyvsp[-1].qp));
		if (nstate == 0)
{yyerror("previous equation contains no state variables"); YYERROR;}
		}
#line 3020 "parse1.c" /* yacc.c:1646  */
    break;

  case 179:
#line 547 "parse1.y" /* yacc.c:1646  */
    {lastok = (yyvsp[0].qp);
		if (!extdef2){SYM((yyvsp[0].qp))->usage |= DEP;}
		if (SYM((yyvsp[0].qp))->subtype & ARRAY && !extdef2)
			{myerr("variable needs an index");}
		if (inequation && (SYM((yyvsp[0].qp))->subtype & STAT) && in_solvefor(SYM((yyvsp[0].qp)))) {
			SYM((yyvsp[0].qp))->used++;
			nstate++; pstate++; tstate++;
		}
		if (SYM((yyvsp[0].qp))->subtype & INTGER) {
			lastok = insertstr((yyvsp[0].qp)->next, ")");
			(yyvsp[0].qp) = insertstr((yyvsp[0].qp), "((double)");
		}
		}
#line 3038 "parse1.c" /* yacc.c:1646  */
    break;

  case 180:
#line 561 "parse1.y" /* yacc.c:1646  */
    {lastok = (yyvsp[0].qp);
		if (SYM((yyvsp[-3].qp))->type == PRIME) {
			usederivstatearray = 1;
		}
		SYM((yyvsp[-3].qp))->usage |= DEP;
		if ((SYM((yyvsp[-3].qp))->subtype & ARRAY) == 0)
			{myerr("variable is not an array");}
		if (inequation && (SYM((yyvsp[-3].qp))->subtype & STAT) && in_solvefor(SYM((yyvsp[-3].qp)))) {
			SYM((yyvsp[-3].qp))->used++;
			nstate++; pstate++; tstate++;
		}
		  if (forallindex) {
			if (forallindex == -1) {
				forallindex = SYM((yyvsp[-3].qp))->araydim;
			}
			if (forallindex != SYM((yyvsp[-3].qp))->araydim) {
Sprintf(buf, "%s dimension not same as other dimensions used in FORALL statement",
SYM((yyvsp[-3].qp))->name);
				diag(buf, (char *)0);
			}
		  }
		}
#line 3065 "parse1.c" /* yacc.c:1646  */
    break;

  case 181:
#line 584 "parse1.y" /* yacc.c:1646  */
    {lastok = (yyvsp[0].qp);
		SYM((yyvsp[-2].qp))->usage |= DEP; disc_var_seen((yyvsp[-2].qp), (yyvsp[-1].qp), (yyvsp[0].qp), 0);}
#line 3072 "parse1.c" /* yacc.c:1646  */
    break;

  case 182:
#line 587 "parse1.y" /* yacc.c:1646  */
    {lastok = (yyvsp[0].qp);
		SYM((yyvsp[-5].qp))->usage |= DEP; disc_var_seen((yyvsp[-5].qp), (yyvsp[-4].qp), (yyvsp[-3].qp), ARRAY);}
#line 3079 "parse1.c" /* yacc.c:1646  */
    break;

  case 183:
#line 591 "parse1.y" /* yacc.c:1646  */
    {lastok = (yyvsp[0].qp);
		 SYM((yyvsp[0].qp))->usage |= DEP;
		 if (!(SYM((yyvsp[0].qp))->subtype & INTGER)) {
		 	lastok = insertstr((yyvsp[0].qp)->next, ")");
			(yyvsp[0].qp) = insertstr((yyvsp[0].qp), "((int)");
		 }
		}
#line 3091 "parse1.c" /* yacc.c:1646  */
    break;

  case 184:
#line 598 "parse1.y" /* yacc.c:1646  */
    { lastok = (yyvsp[0].qp);}
#line 3097 "parse1.c" /* yacc.c:1646  */
    break;

  case 185:
#line 599 "parse1.y" /* yacc.c:1646  */
    { lastok = (yyvsp[0].qp);}
#line 3103 "parse1.c" /* yacc.c:1646  */
    break;

  case 190:
#line 604 "parse1.y" /* yacc.c:1646  */
    {myerr("Illegal integer expression");}
#line 3109 "parse1.c" /* yacc.c:1646  */
    break;

  case 194:
#line 609 "parse1.y" /* yacc.c:1646  */
    {lastok = (yyvsp[0].qp);}
#line 3115 "parse1.c" /* yacc.c:1646  */
    break;

  case 199:
#line 615 "parse1.y" /* yacc.c:1646  */
    { (yyval.qp) = insertstr((yyvsp[-2].qp), "pow("); replacstr((yyvsp[-1].qp), ",");
			lastok = insertstr(lastok->next, ")"); }
#line 3122 "parse1.c" /* yacc.c:1646  */
    break;

  case 200:
#line 617 "parse1.y" /* yacc.c:1646  */
    {replacstr((yyvsp[-1].qp), " ||");}
#line 3128 "parse1.c" /* yacc.c:1646  */
    break;

  case 201:
#line 618 "parse1.y" /* yacc.c:1646  */
    {replacstr((yyvsp[-1].qp), " &&");}
#line 3134 "parse1.c" /* yacc.c:1646  */
    break;

  case 206:
#line 623 "parse1.y" /* yacc.c:1646  */
    {replacstr((yyvsp[-1].qp), " ==");}
#line 3140 "parse1.c" /* yacc.c:1646  */
    break;

  case 207:
#line 624 "parse1.y" /* yacc.c:1646  */
    {replacstr((yyvsp[-1].qp), " !=");}
#line 3146 "parse1.c" /* yacc.c:1646  */
    break;

  case 208:
#line 625 "parse1.y" /* yacc.c:1646  */
    {replacstr((yyvsp[-1].qp), " !");}
#line 3152 "parse1.c" /* yacc.c:1646  */
    break;

  case 210:
#line 627 "parse1.y" /* yacc.c:1646  */
    {myerr("Illegal expression");}
#line 3158 "parse1.c" /* yacc.c:1646  */
    break;

  case 211:
#line 629 "parse1.y" /* yacc.c:1646  */
    {inequation = 1; nstate = 0;}
#line 3164 "parse1.c" /* yacc.c:1646  */
    break;

  case 212:
#line 633 "parse1.y" /* yacc.c:1646  */
    {inequation = 1; nstate = 0;
		pstate = 0; tstate = 0; init_lineq((yyvsp[0].qp)); leftside = -1;}
#line 3171 "parse1.c" /* yacc.c:1646  */
    break;

  case 213:
#line 636 "parse1.y" /* yacc.c:1646  */
    {leftside = 1;}
#line 3177 "parse1.c" /* yacc.c:1646  */
    break;

  case 214:
#line 640 "parse1.y" /* yacc.c:1646  */
    {linterm((yyvsp[0].qp), lastok, pstate, leftside); pstate = 0;}
#line 3183 "parse1.c" /* yacc.c:1646  */
    break;

  case 215:
#line 642 "parse1.y" /* yacc.c:1646  */
    {delete((yyvsp[-1].qp));
		linterm((yyvsp[0].qp), lastok, pstate, -leftside); pstate = 0;}
#line 3190 "parse1.c" /* yacc.c:1646  */
    break;

  case 216:
#line 645 "parse1.y" /* yacc.c:1646  */
    {delete((yyvsp[-1].qp));
		linterm((yyvsp[0].qp), lastok, pstate, leftside); pstate = 0;}
#line 3197 "parse1.c" /* yacc.c:1646  */
    break;

  case 217:
#line 648 "parse1.y" /* yacc.c:1646  */
    {delete((yyvsp[-1].qp));
		linterm((yyvsp[0].qp), lastok, pstate, -leftside); pstate = 0;}
#line 3204 "parse1.c" /* yacc.c:1646  */
    break;

  case 218:
#line 652 "parse1.y" /* yacc.c:1646  */
    { if (tstate == 1) {
			lin_state_term((yyvsp[0].qp), lastok);
		  }
		  tstate = 0;
		}
#line 3214 "parse1.c" /* yacc.c:1646  */
    break;

  case 219:
#line 658 "parse1.y" /* yacc.c:1646  */
    { if (tstate == 1) {
			lin_state_term((yyvsp[0].qp), lastok);
		  }
		  tstate = 0;
		}
#line 3224 "parse1.c" /* yacc.c:1646  */
    break;

  case 220:
#line 664 "parse1.y" /* yacc.c:1646  */
    { if (tstate) {
			diag("state ocurs in denominator", (char *)0);
		  }
		}
#line 3233 "parse1.c" /* yacc.c:1646  */
    break;

  case 223:
#line 671 "parse1.y" /* yacc.c:1646  */
    {if (tstate) diag("states not permitted in function calls",
			(char *)0);}
#line 3240 "parse1.c" /* yacc.c:1646  */
    break;

  case 224:
#line 673 "parse1.y" /* yacc.c:1646  */
    { lastok = (yyvsp[0].qp);
			if (tstate) diag("states not permitted between ",
				"parentheses");}
#line 3248 "parse1.c" /* yacc.c:1646  */
    break;

  case 225:
#line 677 "parse1.y" /* yacc.c:1646  */
    {diag("Some operators are not permitted in linear\n",
"expressions unless the terms containing them are\nenclosed in parentheses");}
#line 3255 "parse1.c" /* yacc.c:1646  */
    break;

  case 226:
#line 681 "parse1.y" /* yacc.c:1646  */
    { if (SYM((yyvsp[-1].qp))->subtype & EXTDEF2) { extdef2 = 1;}}
#line 3261 "parse1.c" /* yacc.c:1646  */
    break;

  case 227:
#line 683 "parse1.y" /* yacc.c:1646  */
    {lastok = (yyvsp[0].qp); SYM((yyvsp[-4].qp))->usage |= FUNCT;
		 if (SYM((yyvsp[-4].qp))->subtype & EXTDEF2) { extdef2 = 0;}
		 if (SYM((yyvsp[-4].qp))->subtype & EXTDEF3) { add_reset_args((yyvsp[-3].qp));}
		 if (SYM((yyvsp[-4].qp))->subtype & EXTDEF4) { add_nrnthread_arg((yyvsp[-3].qp));}
		 if (SYM((yyvsp[-4].qp))->subtype & EXTDEF5) {
			if (!assert_threadsafe) {
fprintf(stderr, "Notice: %s is not thread safe\n", SYM((yyvsp[-4].qp))->name);
				vectorize = 0;
			}
		 }
#if VECTORIZE
		 vectorize_use_func((yyvsp[-4].qp),(yyvsp[-3].qp),(yyvsp[-1].qp),(yyvsp[0].qp),blocktype);
#endif
		}
#line 3280 "parse1.c" /* yacc.c:1646  */
    break;

  case 228:
#line 698 "parse1.y" /* yacc.c:1646  */
    {(yyval.qp) = ITEM0;}
#line 3286 "parse1.c" /* yacc.c:1646  */
    break;

  case 233:
#line 704 "parse1.y" /* yacc.c:1646  */
    {pushlocal(); SYM((yyvsp[0].qp)) = copylocal(SYM((yyvsp[0].qp)));
			SYM((yyvsp[0].qp))->subtype |= INTGER;}
#line 3293 "parse1.c" /* yacc.c:1646  */
    break;

  case 234:
#line 708 "parse1.y" /* yacc.c:1646  */
    { replacstr((yyvsp[-9].qp), "{int ");
		poplocal();
		Insertstr((yyvsp[-6].qp), ";for (");
		Insertstr((yyvsp[-6].qp), SYM((yyvsp[-8].qp))->name);
		Insertstr((yyvsp[-4].qp), ";");
		Insertstr((yyvsp[-4].qp), SYM((yyvsp[-8].qp))->name);
		replacstr((yyvsp[-4].qp), "<=");
		if ((yyvsp[-2].qp)) {
			Insertstr((yyvsp[-2].qp), ";");
			Insertstr((yyvsp[-2].qp), SYM((yyvsp[-8].qp))->name);
			replacstr((yyvsp[-2].qp), "+=");
		} else {
			Insertstr((yyvsp[-1].qp), ";");
			Insertstr((yyvsp[-1].qp), SYM((yyvsp[-8].qp))->name);
			Insertstr((yyvsp[-1].qp), "++");
		}
		Insertstr((yyvsp[-1].qp), ")");
		Insertstr((yyvsp[0].qp), "}");
		}
#line 3317 "parse1.c" /* yacc.c:1646  */
    break;

  case 235:
#line 727 "parse1.y" /* yacc.c:1646  */
    {
myerr("FROM intvar = intexpr TO intexpr BY intexpr { statements }");}
#line 3324 "parse1.c" /* yacc.c:1646  */
    break;

  case 236:
#line 730 "parse1.y" /* yacc.c:1646  */
    {(yyval.qp) = ITEM0;}
#line 3330 "parse1.c" /* yacc.c:1646  */
    break;

  case 238:
#line 733 "parse1.y" /* yacc.c:1646  */
    {pushlocal(); SYM((yyvsp[0].qp)) = copylocal(SYM((yyvsp[0].qp)));
			  SYM((yyvsp[0].qp))->subtype |= INTGER;
			  if (forallindex) {
diag("Nested FORALL statements not allowed", (char *)0);
			  }
			  forallindex = -1;
			}
#line 3342 "parse1.c" /* yacc.c:1646  */
    break;

  case 239:
#line 742 "parse1.y" /* yacc.c:1646  */
    { replacstr((yyvsp[-4].qp), "{int ");
		poplocal();
		if (forallindex == -1) {
diag("FORALL range is undefined since no arrays used", " within the statement");
		}
		Sprintf(buf, "; for (%s=0; %s<%d; %s++)", SYM((yyvsp[-3].qp))->name,
			SYM((yyvsp[-3].qp))->name, forallindex, SYM((yyvsp[-3].qp))->name);
		Insertstr((yyvsp[-1].qp), buf);
		Insertstr((yyvsp[0].qp), "}");
		}
#line 3357 "parse1.c" /* yacc.c:1646  */
    break;

  case 240:
#line 752 "parse1.y" /* yacc.c:1646  */
    {
myerr("FORALL intvar { statements }");}
#line 3364 "parse1.c" /* yacc.c:1646  */
    break;

  case 244:
#line 761 "parse1.y" /* yacc.c:1646  */
    {
#if VECTORIZE
			vectorize_if_else_stmt(blocktype);
#endif
		}
#line 3374 "parse1.c" /* yacc.c:1646  */
    break;

  case 246:
#line 769 "parse1.y" /* yacc.c:1646  */
    {
#if VECTORIZE
			vectorize_if_else_stmt(blocktype);
#endif
		}
#line 3384 "parse1.c" /* yacc.c:1646  */
    break;

  case 247:
#line 777 "parse1.y" /* yacc.c:1646  */
    {massagederiv((yyvsp[-3].qp), (yyvsp[-2].qp), (yyvsp[-1].qp), (yyvsp[0].qp), sensused); sensused = 0;}
#line 3390 "parse1.c" /* yacc.c:1646  */
    break;

  case 248:
#line 779 "parse1.y" /* yacc.c:1646  */
    {init_linblk((yyvsp[-1].qp));}
#line 3396 "parse1.c" /* yacc.c:1646  */
    break;

  case 249:
#line 781 "parse1.y" /* yacc.c:1646  */
    {massage_linblk((yyvsp[-5].qp), (yyvsp[-4].qp), (yyvsp[-1].qp), (yyvsp[0].qp), sensused);
		lexcontext = 0; sensused = 0;
		}
#line 3404 "parse1.c" /* yacc.c:1646  */
    break;

  case 250:
#line 787 "parse1.y" /* yacc.c:1646  */
    {massagenonlin((yyvsp[-4].qp), (yyvsp[-3].qp), (yyvsp[-1].qp), (yyvsp[0].qp), sensused);
		lexcontext = 0; sensused = 0;
		}
#line 3412 "parse1.c" /* yacc.c:1646  */
    break;

  case 251:
#line 793 "parse1.y" /* yacc.c:1646  */
    {massagediscblk((yyvsp[-3].qp), (yyvsp[-2].qp), (yyvsp[-1].qp), (yyvsp[0].qp));}
#line 3418 "parse1.c" /* yacc.c:1646  */
    break;

  case 252:
#line 797 "parse1.y" /* yacc.c:1646  */
    {massagepartial((yyvsp[-3].qp), (yyvsp[-2].qp), (yyvsp[-1].qp), (yyvsp[0].qp));
		lexcontext = 0;
		}
#line 3426 "parse1.c" /* yacc.c:1646  */
    break;

  case 253:
#line 800 "parse1.y" /* yacc.c:1646  */
    {
diag("within the PARTIAL block must occur an equation with the syntax ---\n",
"~ V' = F*DEL2(V) + G\n"); }
#line 3434 "parse1.c" /* yacc.c:1646  */
    break;

  case 254:
#line 805 "parse1.y" /* yacc.c:1646  */
    {partial_eqn((yyvsp[-9].qp), (yyvsp[-7].qp), (yyvsp[-3].qp), (yyvsp[0].qp));}
#line 3440 "parse1.c" /* yacc.c:1646  */
    break;

  case 255:
#line 807 "parse1.y" /* yacc.c:1646  */
    {partial_bndry(0, (yyvsp[-5].qp), (yyvsp[-3].qp), (yyvsp[0].qp), lastok);}
#line 3446 "parse1.c" /* yacc.c:1646  */
    break;

  case 256:
#line 809 "parse1.y" /* yacc.c:1646  */
    {partial_bndry(2, (yyvsp[-5].qp), (yyvsp[-3].qp), (yyvsp[0].qp), lastok);}
#line 3452 "parse1.c" /* yacc.c:1646  */
    break;

  case 259:
#line 814 "parse1.y" /* yacc.c:1646  */
    {Item *b1, *b2;
		Symbol* s = SYM((yyvsp[-4].qp));
		s->varnum = argcnt_;
		b1 = insertstr((yyvsp[-1].qp)->next, "{\n");
		b2 = insertstr(b1->next, "}\n");

#define GLOBFUNCT 1
#if GLOBFUNCT && NMODL
		replacstr((yyvsp[-5].qp), "\ndouble");
#else
		replacstr((yyvsp[-5].qp), "\nstatic double");
#endif
		defarg((yyvsp[-3].qp), (yyvsp[-1].qp));
		movelist((yyvsp[-5].qp), b2, procfunc);
		if (SYM((yyvsp[-4].qp))->subtype & FUNCT) {
			diag(SYM((yyvsp[-4].qp))->name, " declared as FUNCTION twice");
		}
		SYM((yyvsp[-4].qp))->subtype |= FUNCT;
		SYM((yyvsp[-4].qp))->usage |= FUNCT;
#if HMODL || NMODL
		hocfunc(s, (yyvsp[-3].qp), (yyvsp[-1].qp));
#endif
		function_table(s, (yyvsp[-3].qp), (yyvsp[-1].qp), b1, b2);
		poplocal();
		}
#line 3482 "parse1.c" /* yacc.c:1646  */
    break;

  case 260:
#line 841 "parse1.y" /* yacc.c:1646  */
    {IGNORE(copylocal(SYM((yyvsp[-4].qp))));}
#line 3488 "parse1.c" /* yacc.c:1646  */
    break;

  case 261:
#line 845 "parse1.y" /* yacc.c:1646  */
    { Symbol *s = SYM((yyvsp[-7].qp));
		s->varnum = argcnt_;
		table_massage(table_list, (yyvsp[-8].qp), (yyvsp[-7].qp), (yyvsp[-5].lp)); freelist(&table_list);
#if GLOBFUNCT && NMODL
		replacstr((yyvsp[-8].qp), "\ndouble");
#else
		replacstr((yyvsp[-8].qp), "\nstatic double");
#endif
		defarg((yyvsp[-6].qp), (yyvsp[-4].qp));
		Sprintf(buf, "double _l%s;\n", s->name);
		Insertstr((yyvsp[-1].qp)->next, buf);
		Sprintf(buf, "\nreturn _l%s;\n", s->name);
		Insertstr((yyvsp[0].qp), buf);
		movelist((yyvsp[-8].qp), (yyvsp[0].qp), procfunc);
		if (SYM((yyvsp[-7].qp))->subtype & FUNCT) {
			diag(SYM((yyvsp[-7].qp))->name, " declared as FUNCTION twice");
		}
		SYM((yyvsp[-7].qp))->subtype |= FUNCT;
		SYM((yyvsp[-7].qp))->usage |= FUNCT;
#if HMODL || NMODL
		hocfunc(s, (yyvsp[-6].qp), (yyvsp[-4].qp));
#endif
		poplocal(); freelist(&(yyvsp[-5].lp));}
#line 3516 "parse1.c" /* yacc.c:1646  */
    break;

  case 262:
#line 869 "parse1.y" /* yacc.c:1646  */
    {pushlocal(); (yyval.lp) = LIST0; argcnt_ = 0;}
#line 3522 "parse1.c" /* yacc.c:1646  */
    break;

  case 263:
#line 870 "parse1.y" /* yacc.c:1646  */
    {pushlocal();}
#line 3528 "parse1.c" /* yacc.c:1646  */
    break;

  case 264:
#line 870 "parse1.y" /* yacc.c:1646  */
    {(yyval.lp) = (yyvsp[0].lp);}
#line 3534 "parse1.c" /* yacc.c:1646  */
    break;

  case 265:
#line 873 "parse1.y" /* yacc.c:1646  */
    {SYM((yyvsp[-1].qp)) = copylocal(SYM((yyvsp[-1].qp))); argcnt_ = 1;
		 (yyval.lp) = newlist(); Lappendsym((yyval.lp), SYM((yyvsp[-1].qp)));
		}
#line 3542 "parse1.c" /* yacc.c:1646  */
    break;

  case 266:
#line 877 "parse1.y" /* yacc.c:1646  */
    {SYM((yyvsp[-1].qp)) = copylocal(SYM((yyvsp[-1].qp))); Lappendsym((yyval.lp), SYM((yyvsp[-1].qp)));
		 ++argcnt_;
		}
#line 3550 "parse1.c" /* yacc.c:1646  */
    break;

  case 267:
#line 882 "parse1.y" /* yacc.c:1646  */
    {Symbol *s = SYM((yyvsp[-6].qp));
		s->u.i = 0; 	/* avoid objectcenter warning if solved */
		s->varnum = argcnt_; /* allow proper number of "double" in prototype */
		table_massage(table_list, (yyvsp[-7].qp), (yyvsp[-6].qp), (yyvsp[-4].lp)); freelist(&table_list);
		replacstr((yyvsp[-7].qp), "\nstatic int "); defarg((yyvsp[-5].qp), (yyvsp[-3].qp));
		Insertstr((yyvsp[0].qp), " return 0;");
		movelist((yyvsp[-7].qp), (yyvsp[0].qp), procfunc);
		if (SYM((yyvsp[-6].qp))->subtype & PROCED) {
			diag(SYM((yyvsp[-6].qp))->name, " declared as PROCEDURE twice");
		}
		SYM((yyvsp[-6].qp))->subtype |= PROCED;
		SYM((yyvsp[-6].qp))->usage |= FUNCT;
#if HMODL || NMODL
		hocfunc(s, (yyvsp[-5].qp), (yyvsp[-3].qp));
#endif
		poplocal(); freelist(&(yyvsp[-4].lp));}
#line 3571 "parse1.c" /* yacc.c:1646  */
    break;

  case 268:
#line 900 "parse1.y" /* yacc.c:1646  */
    {
			nr_argcnt_ = argcnt_;
			/* add flag arg */
			if ((yyvsp[-1].lp) == LIST0) {
diag("NET_RECEIVE block"," must have at least one argument");
			}
			Lappendsym((yyvsp[-1].lp), copylocal(install("flag", NAME)));
		}
#line 3584 "parse1.c" /* yacc.c:1646  */
    break;

  case 269:
#line 909 "parse1.y" /* yacc.c:1646  */
    {
		replacstr((yyvsp[-6].qp), "\nstatic void _net_receive");
		movelist((yyvsp[-6].qp), (yyvsp[0].qp), procfunc);
#if NMODL
		net_receive((yyvsp[-4].lp), (yyvsp[-5].qp), (yyvsp[-3].qp), (yyvsp[-1].qp), (yyvsp[0].qp));
#endif
		poplocal(); freelist(&(yyvsp[-4].lp));
		}
#line 3597 "parse1.c" /* yacc.c:1646  */
    break;

  case 270:
#line 917 "parse1.y" /* yacc.c:1646  */
    { myerr("syntax: NET_RECEIVE ( weight ) {stmtlist}");}
#line 3603 "parse1.c" /* yacc.c:1646  */
    break;

  case 271:
#line 920 "parse1.y" /* yacc.c:1646  */
    {
			check_block(NETRECEIVE, blocktype, "INITIAL");
#if NMODL
			net_init((yyvsp[-2].qp), (yyvsp[0].qp));
#endif
		}
#line 3614 "parse1.c" /* yacc.c:1646  */
    break;

  case 272:
#line 929 "parse1.y" /* yacc.c:1646  */
    { solvequeue((yyvsp[-1].qp), ITEM0, blocktype, (yyvsp[0].qp)); }
#line 3620 "parse1.c" /* yacc.c:1646  */
    break;

  case 273:
#line 931 "parse1.y" /* yacc.c:1646  */
    { solvequeue((yyvsp[-3].qp), (yyvsp[-1].qp), blocktype, (yyvsp[0].qp)); }
#line 3626 "parse1.c" /* yacc.c:1646  */
    break;

  case 274:
#line 932 "parse1.y" /* yacc.c:1646  */
    { myerr("Illegal SOLVE statement");}
#line 3632 "parse1.c" /* yacc.c:1646  */
    break;

  case 275:
#line 935 "parse1.y" /* yacc.c:1646  */
    { (yyval.qp) = ITEM0; }
#line 3638 "parse1.c" /* yacc.c:1646  */
    break;

  case 276:
#line 937 "parse1.y" /* yacc.c:1646  */
    { (yyval.qp) = (yyvsp[0].qp); }
#line 3644 "parse1.c" /* yacc.c:1646  */
    break;

  case 277:
#line 940 "parse1.y" /* yacc.c:1646  */
    { if (solveforlist) {
			freelist(&solveforlist);
		  }
		}
#line 3653 "parse1.c" /* yacc.c:1646  */
    break;

  case 279:
#line 947 "parse1.y" /* yacc.c:1646  */
    { solveforlist = newlist(); Lappendsym(solveforlist, SYM((yyvsp[0].qp)));
		  delete((yyvsp[-1].qp)); delete((yyvsp[0].qp));
		}
#line 3661 "parse1.c" /* yacc.c:1646  */
    break;

  case 280:
#line 951 "parse1.y" /* yacc.c:1646  */
    { Lappendsym(solveforlist, SYM((yyvsp[0].qp))); delete((yyvsp[-1].qp)); delete((yyvsp[0].qp));}
#line 3667 "parse1.c" /* yacc.c:1646  */
    break;

  case 281:
#line 952 "parse1.y" /* yacc.c:1646  */
    { myerr("Syntax: SOLVEFOR name, name, ...");}
#line 3673 "parse1.c" /* yacc.c:1646  */
    break;

  case 282:
#line 956 "parse1.y" /* yacc.c:1646  */
    {brkpnt_exists = 1; movelist((yyvsp[-1].qp), (yyvsp[0].qp), modelfunc);}
#line 3679 "parse1.c" /* yacc.c:1646  */
    break;

  case 283:
#line 959 "parse1.y" /* yacc.c:1646  */
    {movelist((yyvsp[-1].qp), (yyvsp[0].qp), termfunc);}
#line 3685 "parse1.c" /* yacc.c:1646  */
    break;

  case 284:
#line 962 "parse1.y" /* yacc.c:1646  */
    {bablk(blocktype, BREAKPOINT, (yyvsp[-1].qp), (yyvsp[0].qp));}
#line 3691 "parse1.c" /* yacc.c:1646  */
    break;

  case 285:
#line 964 "parse1.y" /* yacc.c:1646  */
    {bablk(blocktype, SOLVE, (yyvsp[-1].qp), (yyvsp[0].qp));}
#line 3697 "parse1.c" /* yacc.c:1646  */
    break;

  case 286:
#line 966 "parse1.y" /* yacc.c:1646  */
    {bablk(blocktype, INITIAL1, (yyvsp[-1].qp), (yyvsp[0].qp));}
#line 3703 "parse1.c" /* yacc.c:1646  */
    break;

  case 287:
#line 968 "parse1.y" /* yacc.c:1646  */
    {bablk(blocktype, STEP, (yyvsp[-1].qp), (yyvsp[0].qp));}
#line 3709 "parse1.c" /* yacc.c:1646  */
    break;

  case 288:
#line 969 "parse1.y" /* yacc.c:1646  */
    {myerr("[BEFORE AFTER] [BREAKPOINT SOLVE INITIAL STEP] { stmt }");}
#line 3715 "parse1.c" /* yacc.c:1646  */
    break;

  case 289:
#line 972 "parse1.y" /* yacc.c:1646  */
    {(yyval.qp) = (yyvsp[0].qp); delete((yyvsp[-1].qp));}
#line 3721 "parse1.c" /* yacc.c:1646  */
    break;

  case 290:
#line 974 "parse1.y" /* yacc.c:1646  */
    {delete((yyvsp[-1].qp));}
#line 3727 "parse1.c" /* yacc.c:1646  */
    break;

  case 291:
#line 975 "parse1.y" /* yacc.c:1646  */
    {myerr("WATCH (expr > expr) flag");}
#line 3733 "parse1.c" /* yacc.c:1646  */
    break;

  case 292:
#line 978 "parse1.y" /* yacc.c:1646  */
    {watchstmt((yyvsp[-5].qp), (yyvsp[-3].qp), (yyvsp[-1].qp), (yyvsp[0].qp), blocktype); (yyval.qp)=(yyvsp[0].qp);}
#line 3739 "parse1.c" /* yacc.c:1646  */
    break;

  case 295:
#line 983 "parse1.y" /* yacc.c:1646  */
    {
			if (blocktype != NETRECEIVE) {
				diag("\"FOR_NETCONS\" statement only allowed in NET_RECEIVE block", (char*)0);
			}
			if (argcnt_ != nr_argcnt_) {
				diag("FOR_NETCONS and NET_RECEIVE do not have same number of arguments", (char*)0);
			}
		}
#line 3752 "parse1.c" /* yacc.c:1646  */
    break;

  case 296:
#line 992 "parse1.y" /* yacc.c:1646  */
    {fornetcon((yyvsp[-6].qp), (yyvsp[-5].qp), (yyvsp[-4].lp), (yyvsp[-3].qp), (yyvsp[-1].qp), (yyvsp[0].qp)); (yyval.qp) = (yyvsp[0].qp); }
#line 3758 "parse1.c" /* yacc.c:1646  */
    break;

  case 297:
#line 993 "parse1.y" /* yacc.c:1646  */
    { myerr("syntax: FOR_NETCONS(args,like,netreceive) { stmtlist}");}
#line 3764 "parse1.c" /* yacc.c:1646  */
    break;

  case 301:
#line 998 "parse1.y" /* yacc.c:1646  */
    {lastok = (yyvsp[0].qp);}
#line 3770 "parse1.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1004 "parse1.y" /* yacc.c:1646  */
    { (yyval.qp) = insertstr((yyvsp[-2].qp), "pow("); replacstr((yyvsp[-1].qp), ",");
			lastok = insertstr(lastok->next, ")"); }
#line 3777 "parse1.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1007 "parse1.y" /* yacc.c:1646  */
    {myerr("Illegal expression");}
#line 3783 "parse1.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1012 "parse1.y" /* yacc.c:1646  */
    { sensused = 1;
		  delete((yyvsp[-1].qp));
		}
#line 3791 "parse1.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1015 "parse1.y" /* yacc.c:1646  */
    {myerr("syntax is SENS var1, var2, var3, etc");}
#line 3797 "parse1.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1019 "parse1.y" /* yacc.c:1646  */
    { sensparm((yyvsp[0].qp)); delete((yyvsp[0].qp));}
#line 3803 "parse1.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1021 "parse1.y" /* yacc.c:1646  */
    { sensparm((yyvsp[0].qp)); deltokens((yyvsp[-1].qp), (yyvsp[0].qp));}
#line 3809 "parse1.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1024 "parse1.y" /* yacc.c:1646  */
    {extdef2 = 0; }
#line 3815 "parse1.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1025 "parse1.y" /* yacc.c:1646  */
    {/* react originally designed for reactions and is unchanged*/
		extdef2 = 0;
		massageconserve((yyvsp[-4].qp), (yyvsp[-1].qp), lastok);}
#line 3823 "parse1.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1028 "parse1.y" /* yacc.c:1646  */
    {myerr("Illegal CONSERVE syntax");}
#line 3829 "parse1.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1031 "parse1.y" /* yacc.c:1646  */
    {pushlocal(); SYM((yyvsp[-1].qp)) = copylocal(SYM((yyvsp[-1].qp)));}
#line 3835 "parse1.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1033 "parse1.y" /* yacc.c:1646  */
    {massagecompart((yyvsp[-3].qp), (yyvsp[-2].qp), (yyvsp[0].qp), SYM((yyvsp[-6].qp))); poplocal();}
#line 3841 "parse1.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1035 "parse1.y" /* yacc.c:1646  */
    {massagecompart((yyvsp[-3].qp), (yyvsp[-2].qp), (yyvsp[0].qp), SYM0);}
#line 3847 "parse1.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1038 "parse1.y" /* yacc.c:1646  */
    {pushlocal(); SYM((yyvsp[-1].qp)) = copylocal(SYM((yyvsp[-1].qp)));}
#line 3853 "parse1.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1040 "parse1.y" /* yacc.c:1646  */
    {massageldifus((yyvsp[-3].qp), (yyvsp[-2].qp), (yyvsp[0].qp), SYM((yyvsp[-6].qp))); poplocal();}
#line 3859 "parse1.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1042 "parse1.y" /* yacc.c:1646  */
    {massageldifus((yyvsp[-3].qp), (yyvsp[-2].qp), (yyvsp[0].qp), SYM0);}
#line 3865 "parse1.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1050 "parse1.y" /* yacc.c:1646  */
    {massagekinetic((yyvsp[-4].qp), (yyvsp[-3].qp), (yyvsp[-1].qp), (yyvsp[0].qp), sensused);
		lexcontext = 0; sensused = 0;
		}
#line 3873 "parse1.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1054 "parse1.y" /* yacc.c:1646  */
    {leftreact();}
#line 3879 "parse1.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1055 "parse1.y" /* yacc.c:1646  */
    {massagereaction((yyvsp[-9].qp),(yyvsp[-7].qp),(yyvsp[-4].qp),(yyvsp[-2].qp),(yyvsp[0].qp));}
#line 3885 "parse1.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1057 "parse1.y" /* yacc.c:1646  */
    {flux((yyvsp[-6].qp), (yyvsp[-4].qp), (yyvsp[0].qp));}
#line 3891 "parse1.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1059 "parse1.y" /* yacc.c:1646  */
    {flux((yyvsp[-6].qp), (yyvsp[-4].qp), (yyvsp[0].qp));}
#line 3897 "parse1.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1060 "parse1.y" /* yacc.c:1646  */
    {myerr("Illegal reaction syntax");}
#line 3903 "parse1.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1062 "parse1.y" /* yacc.c:1646  */
    {reactname((yyvsp[0].qp), lastok, ITEM0);}
#line 3909 "parse1.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1063 "parse1.y" /* yacc.c:1646  */
    {reactname((yyvsp[0].qp), lastok, (yyvsp[-1].qp));}
#line 3915 "parse1.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1064 "parse1.y" /* yacc.c:1646  */
    {reactname((yyvsp[0].qp), lastok, ITEM0);}
#line 3921 "parse1.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1065 "parse1.y" /* yacc.c:1646  */
    {reactname((yyvsp[0].qp), lastok, (yyvsp[-1].qp));}
#line 3927 "parse1.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1068 "parse1.y" /* yacc.c:1646  */
    {lag_stmt((yyvsp[-3].qp), blocktype);}
#line 3933 "parse1.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1069 "parse1.y" /* yacc.c:1646  */
    {myerr("Lag syntax is: LAG name BY const");}
#line 3939 "parse1.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1071 "parse1.y" /* yacc.c:1646  */
    {queue_stmt((yyvsp[-1].qp), (yyvsp[0].qp));}
#line 3945 "parse1.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1072 "parse1.y" /* yacc.c:1646  */
    {queue_stmt((yyvsp[-1].qp), (yyvsp[0].qp));}
#line 3951 "parse1.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1074 "parse1.y" /* yacc.c:1646  */
    {checkmatch(blocktype);}
#line 3957 "parse1.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1075 "parse1.y" /* yacc.c:1646  */
    {deltokens((yyvsp[-4].qp), (yyvsp[0].qp));}
#line 3963 "parse1.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1081 "parse1.y" /* yacc.c:1646  */
    {matchinitial((yyvsp[0].qp));}
#line 3969 "parse1.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1083 "parse1.y" /* yacc.c:1646  */
    { matchbound((yyvsp[-5].qp), (yyvsp[-4].qp), (yyvsp[-2].qp), (yyvsp[0].qp), lastok, matchindex);
		  if (matchindex) {
			poplocal();
			matchindex = SYM0;
		  }
		}
#line 3980 "parse1.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1090 "parse1.y" /* yacc.c:1646  */
    {myerr("MATCH syntax is state0 or state(expr)=expr or\
state[i](expr(i)) = expr(i)");}
#line 3987 "parse1.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1094 "parse1.y" /* yacc.c:1646  */
    {matchindex = SYM0;}
#line 3993 "parse1.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1096 "parse1.y" /* yacc.c:1646  */
    { pushlocal();
		  matchindex = copylocal(SYM((yyvsp[-1].qp)));
		}
#line 4001 "parse1.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1101 "parse1.y" /* yacc.c:1646  */
    { deltokens((yyvsp[-3].qp),(yyvsp[0].qp));}
#line 4007 "parse1.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1104 "parse1.y" /* yacc.c:1646  */
    {modl_units();}
#line 4013 "parse1.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1109 "parse1.y" /* yacc.c:1646  */
    {install_units((yyvsp[-2].str), (yyvsp[0].str));}
#line 4019 "parse1.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1110 "parse1.y" /* yacc.c:1646  */
    {myerr("Unit definition syntax: (units) = (units)");}
#line 4025 "parse1.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1113 "parse1.y" /* yacc.c:1646  */
    { SYM((yyvsp[-3].qp))->subtype |= nmodlCONST;
		  Sprintf(buf, "static double %s = %s;\n", SYM((yyvsp[-3].qp))->name,
			STR((yyvsp[-1].qp)));
		  Lappendstr(firstlist, buf);
		}
#line 4035 "parse1.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1119 "parse1.y" /* yacc.c:1646  */
    {Item *q; double d, unit_mag();
		    Unit_push((yyvsp[-1].str));
			Unit_push((yyvsp[0].str)); unit_div();
		    SYM((yyvsp[-3].qp))->subtype |= nmodlCONST;
		    Sprintf(buf, "static double %s = %g;\n", SYM((yyvsp[-3].qp))->name,
			unit_mag());
		    Lappendstr(firstlist, buf);
		    unit_pop();
		}
#line 4049 "parse1.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1129 "parse1.y" /* yacc.c:1646  */
    { double unit_mag();
		    Unit_push((yyvsp[-3].str)); Unit_push((yyvsp[0].str)); unit_div();
		    SYM((yyvsp[-5].qp))->subtype |= nmodlCONST;
		    Sprintf(buf, "static double %s = %g;\n", SYM((yyvsp[-5].qp))->name,
			unit_mag());
		    Lappendstr(firstlist, buf);
		    unit_pop();
		}
#line 4062 "parse1.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1137 "parse1.y" /* yacc.c:1646  */
    {myerr("Unit factor syntax: examples:\n\
foot2inch = (foot) -> (inch)\n\
F = 96520 (coulomb)\n\
R = (k-mole) (joule/degC)");
		}
#line 4072 "parse1.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1147 "parse1.y" /* yacc.c:1646  */
    { SYM((yyvsp[-3].qp))->subtype |= nmodlCONST;
		  Sprintf(buf, "static double %s = %s;\n", SYM((yyvsp[-3].qp))->name,
			STR((yyvsp[-1].qp)));
		  Lappendstr(firstlist, buf);
		}
#line 4082 "parse1.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1154 "parse1.y" /* yacc.c:1646  */
    { Item *q;
		  if (table_list) {
			diag("only one TABLE per function", (char *)0);
		  }
		  table_list = newlist();
		  Lappendlst(table_list, (yyvsp[-7].lp));
		  q = lappendlst(table_list, newlist());
		  movelist((yyvsp[-5].qp)->next, (yyvsp[-3].qp)->prev, LST(q));
		  q = lappendlst(table_list, newlist());
		  movelist((yyvsp[-3].qp)->next, (yyvsp[-1].qp)->prev, LST(q));
		  Lappendstr(table_list, STR((yyvsp[0].qp)));
		  Lappendlst(table_list, (yyvsp[-6].lp));
		  deltokens((yyvsp[-8].qp), (yyvsp[0].qp));
		}
#line 4101 "parse1.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1168 "parse1.y" /* yacc.c:1646  */
    { myerr("syntax: TABLE [list] [DEPEND list] FROM expr TO expr WITH integer");}
#line 4107 "parse1.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1171 "parse1.y" /* yacc.c:1646  */
    {(yyval.lp) = LIST0;}
#line 4113 "parse1.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1175 "parse1.y" /* yacc.c:1646  */
    {(yyval.lp) = newlist(); Lappendsym((yyval.lp), SYM((yyvsp[0].qp)));}
#line 4119 "parse1.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1177 "parse1.y" /* yacc.c:1646  */
    { Lappendsym((yyvsp[-2].lp), SYM((yyvsp[0].qp)));}
#line 4125 "parse1.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1180 "parse1.y" /* yacc.c:1646  */
    {(yyval.lp) = LIST0;}
#line 4131 "parse1.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1182 "parse1.y" /* yacc.c:1646  */
    {(yyval.lp) = (yyvsp[0].lp);}
#line 4137 "parse1.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1185 "parse1.y" /* yacc.c:1646  */
    { deltokens((yyvsp[-3].qp),(yyvsp[0].qp));}
#line 4143 "parse1.c" /* yacc.c:1646  */
    break;

  case 370:
#line 1189 "parse1.y" /* yacc.c:1646  */
    { nrn_list((yyvsp[-1].qp), (yyvsp[0].qp));}
#line 4149 "parse1.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1192 "parse1.y" /* yacc.c:1646  */
    { nrn_list((yyvsp[-1].qp),(yyvsp[0].qp));}
#line 4155 "parse1.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1194 "parse1.y" /* yacc.c:1646  */
    { nrn_list((yyvsp[-1].qp),(yyvsp[0].qp));}
#line 4161 "parse1.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1196 "parse1.y" /* yacc.c:1646  */
    { nrn_list((yyvsp[-1].qp), (yyvsp[0].qp));}
#line 4167 "parse1.c" /* yacc.c:1646  */
    break;

  case 375:
#line 1198 "parse1.y" /* yacc.c:1646  */
    { nrn_list((yyvsp[-1].qp), (yyvsp[0].qp));}
#line 4173 "parse1.c" /* yacc.c:1646  */
    break;

  case 376:
#line 1200 "parse1.y" /* yacc.c:1646  */
    { nrn_list((yyvsp[-1].qp), (yyvsp[0].qp));}
#line 4179 "parse1.c" /* yacc.c:1646  */
    break;

  case 377:
#line 1202 "parse1.y" /* yacc.c:1646  */
    { nrn_list((yyvsp[-1].qp), (yyvsp[0].qp));}
#line 4185 "parse1.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1204 "parse1.y" /* yacc.c:1646  */
    { nrn_list((yyvsp[-1].qp), (yyvsp[0].qp));}
#line 4191 "parse1.c" /* yacc.c:1646  */
    break;

  case 379:
#line 1206 "parse1.y" /* yacc.c:1646  */
    { threadsafe_seen((yyvsp[-1].qp), (yyvsp[0].qp)); }
#line 4197 "parse1.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1209 "parse1.y" /* yacc.c:1646  */
    {nrn_use((yyvsp[-3].qp), (yyvsp[-1].qp), ITEM0, (yyvsp[0].qp));}
#line 4203 "parse1.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1211 "parse1.y" /* yacc.c:1646  */
    {nrn_use((yyvsp[-3].qp), ITEM0, (yyvsp[-1].qp), (yyvsp[0].qp));}
#line 4209 "parse1.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1213 "parse1.y" /* yacc.c:1646  */
    {nrn_use((yyvsp[-5].qp), (yyvsp[-3].qp), (yyvsp[-1].qp), (yyvsp[0].qp));}
#line 4215 "parse1.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1215 "parse1.y" /* yacc.c:1646  */
    {myerr("syntax is: USEION ion READ list WRITE list");}
#line 4221 "parse1.c" /* yacc.c:1646  */
    break;

  case 385:
#line 1219 "parse1.y" /* yacc.c:1646  */
    { delete((yyvsp[-1].qp)); (yyval.qp) = (yyvsp[0].qp);}
#line 4227 "parse1.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1221 "parse1.y" /* yacc.c:1646  */
    {myerr("syntax is: keyword name , name, ..., name");}
#line 4233 "parse1.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1224 "parse1.y" /* yacc.c:1646  */
    {(yyval.qp) = NULL;}
#line 4239 "parse1.c" /* yacc.c:1646  */
    break;

  case 389:
#line 1228 "parse1.y" /* yacc.c:1646  */
    {(yyval.qp) = ITEM0;}
#line 4245 "parse1.c" /* yacc.c:1646  */
    break;

  case 390:
#line 1230 "parse1.y" /* yacc.c:1646  */
    {(yyval.qp) = (yyvsp[0].qp);}
#line 4251 "parse1.c" /* yacc.c:1646  */
    break;

  case 391:
#line 1233 "parse1.y" /* yacc.c:1646  */
    { Sprintf(buf, "-%s", STR((yyvsp[0].qp)));
		 STR((yyvsp[0].qp)) = stralloc(buf, STR((yyvsp[0].qp))); (yyval.qp) = (yyvsp[0].qp);
		delete((yyvsp[-1].qp)); lastok = (yyvsp[0].qp);
		}
#line 4260 "parse1.c" /* yacc.c:1646  */
    break;


#line 4264 "parse1.c" /* yacc.c:1646  */
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
#line 1238 "parse1.y" /* yacc.c:1906  */

void yyerror(s)	/* called for yacc syntax error */
	char *s;
{
	Fprintf(stderr, "%s:\n ", s);
}


#if !NMODL
void nrn_list(q1, q2)
	Item *q1, *q2;
{
	/*ARGSUSED*/
}
void nrn_use(q1, q2, q3, q4)
	Item *q1, *q2, *q3, *q4;
{
	/*ARGSUSED*/
}
#endif
