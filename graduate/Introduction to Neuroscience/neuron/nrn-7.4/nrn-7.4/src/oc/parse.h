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
#line 82 "parse.y" /* yacc.c:1909  */
				/* stack type */
	Symbol	*sym;			/* symbol table pointer */
	Inst	*inst;			/* machine instruction */
	int	narg;			/* number of arguments */
	void*	ptr;

#line 231 "parse.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSE_H_INCLUDED  */
