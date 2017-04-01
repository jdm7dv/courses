/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 76 "parse1.y" /* yacc.c:1909  */

	Item	*qp;
	char	*str;
	List	*lp;
	int	i;

#line 281 "parse1.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSE_H_INCLUDED  */
