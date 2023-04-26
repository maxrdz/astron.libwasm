/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_DCPARSER_HXX_INCLUDED
# define YY_YY_DCPARSER_HXX_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    UNSIGNED_INTEGER = 258,        /* UNSIGNED_INTEGER  */
    SIGNED_INTEGER = 259,          /* SIGNED_INTEGER  */
    REAL = 260,                    /* REAL  */
    STRING = 261,                  /* STRING  */
    HEX_STRING = 262,              /* HEX_STRING  */
    IDENTIFIER = 263,              /* IDENTIFIER  */
    KEYWORD = 264,                 /* KEYWORD  */
    KW_DCLASS = 265,               /* KW_DCLASS  */
    KW_STRUCT = 266,               /* KW_STRUCT  */
    KW_FROM = 267,                 /* KW_FROM  */
    KW_IMPORT = 268,               /* KW_IMPORT  */
    KW_TYPEDEF = 269,              /* KW_TYPEDEF  */
    KW_KEYWORD = 270,              /* KW_KEYWORD  */
    KW_SWITCH = 271,               /* KW_SWITCH  */
    KW_CASE = 272,                 /* KW_CASE  */
    KW_DEFAULT = 273,              /* KW_DEFAULT  */
    KW_BREAK = 274,                /* KW_BREAK  */
    KW_INT8 = 275,                 /* KW_INT8  */
    KW_INT16 = 276,                /* KW_INT16  */
    KW_INT32 = 277,                /* KW_INT32  */
    KW_INT64 = 278,                /* KW_INT64  */
    KW_UINT8 = 279,                /* KW_UINT8  */
    KW_UINT16 = 280,               /* KW_UINT16  */
    KW_UINT32 = 281,               /* KW_UINT32  */
    KW_UINT64 = 282,               /* KW_UINT64  */
    KW_FLOAT64 = 283,              /* KW_FLOAT64  */
    KW_STRING = 284,               /* KW_STRING  */
    KW_BLOB = 285,                 /* KW_BLOB  */
    KW_BLOB32 = 286,               /* KW_BLOB32  */
    KW_INT8ARRAY = 287,            /* KW_INT8ARRAY  */
    KW_INT16ARRAY = 288,           /* KW_INT16ARRAY  */
    KW_INT32ARRAY = 289,           /* KW_INT32ARRAY  */
    KW_UINT8ARRAY = 290,           /* KW_UINT8ARRAY  */
    KW_UINT16ARRAY = 291,          /* KW_UINT16ARRAY  */
    KW_UINT32ARRAY = 292,          /* KW_UINT32ARRAY  */
    KW_UINT32UINT8ARRAY = 293,     /* KW_UINT32UINT8ARRAY  */
    KW_CHAR = 294,                 /* KW_CHAR  */
    START_DC = 295,                /* START_DC  */
    START_PARAMETER_VALUE = 296,   /* START_PARAMETER_VALUE  */
    START_PARAMETER_DESCRIPTION = 297 /* START_PARAMETER_DESCRIPTION  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_DCPARSER_HXX_INCLUDED  */
