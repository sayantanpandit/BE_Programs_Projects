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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    AUTO = 258,
    BREAK = 259,
    CASE = 260,
    CHAR = 261,
    CONST = 262,
    CONTINUE = 263,
    DEFAULT = 264,
    DO = 265,
    DOUBLE = 266,
    ELSE = 267,
    ENUM = 268,
    EXTERN = 269,
    FLOAT = 270,
    FOR = 271,
    GOTO = 272,
    IF = 273,
    INT = 274,
    LONG = 275,
    REGISTER = 276,
    RETURN = 277,
    SHORT = 278,
    SIGNED = 279,
    SIZEOF = 280,
    STATIC = 281,
    STRUCT = 282,
    SWITCH = 283,
    TYPEDEF = 284,
    UNION = 285,
    UNSIGNED = 286,
    VOID = 287,
    VOLATILE = 288,
    WHILE = 289,
    PLUS = 290,
    MINUS = 291,
    MULT = 292,
    DIVIDE = 293,
    LESS = 294,
    LESS_EQ = 295,
    GREATER = 296,
    GREATER_EQ = 297,
    EQUAL = 298,
    NOT_EQ = 299,
    NOT = 300,
    PLUS_EQ = 301,
    MINUS_EQ = 302,
    MULT_EQ = 303,
    DIV_EQ = 304,
    LEFT_PAREN = 305,
    RIGHT_PAREN = 306,
    LEFT_SQ_BRACKET = 307,
    RIGHT_SQ_BRACKET = 308,
    LEFT_CURLY = 309,
    RIGHT_CURLY = 310,
    COMMA = 311,
    UNDERSCORE = 312,
    SEMICOLON = 313,
    CONSTANT = 314,
    IDENTIFIER = 315,
    ASSIGN = 316
  };
#endif
/* Tokens.  */
#define AUTO 258
#define BREAK 259
#define CASE 260
#define CHAR 261
#define CONST 262
#define CONTINUE 263
#define DEFAULT 264
#define DO 265
#define DOUBLE 266
#define ELSE 267
#define ENUM 268
#define EXTERN 269
#define FLOAT 270
#define FOR 271
#define GOTO 272
#define IF 273
#define INT 274
#define LONG 275
#define REGISTER 276
#define RETURN 277
#define SHORT 278
#define SIGNED 279
#define SIZEOF 280
#define STATIC 281
#define STRUCT 282
#define SWITCH 283
#define TYPEDEF 284
#define UNION 285
#define UNSIGNED 286
#define VOID 287
#define VOLATILE 288
#define WHILE 289
#define PLUS 290
#define MINUS 291
#define MULT 292
#define DIVIDE 293
#define LESS 294
#define LESS_EQ 295
#define GREATER 296
#define GREATER_EQ 297
#define EQUAL 298
#define NOT_EQ 299
#define NOT 300
#define PLUS_EQ 301
#define MINUS_EQ 302
#define MULT_EQ 303
#define DIV_EQ 304
#define LEFT_PAREN 305
#define RIGHT_PAREN 306
#define LEFT_SQ_BRACKET 307
#define RIGHT_SQ_BRACKET 308
#define LEFT_CURLY 309
#define RIGHT_CURLY 310
#define COMMA 311
#define UNDERSCORE 312
#define SEMICOLON 313
#define CONSTANT 314
#define IDENTIFIER 315
#define ASSIGN 316

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 69 "ChkCProg.yacc" /* yacc.c:1909  */

    char* id;
    char* string;

#line 181 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
