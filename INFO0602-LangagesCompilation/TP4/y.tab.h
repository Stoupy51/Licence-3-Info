#ifndef _yy_defines_h_
#define _yy_defines_h_

#define level 257
#define end 258
#define put 259
#define robot 260
#define probe 261
#define empty 262
#define block 263
#define trap 264
#define ladder 265
#define bomb 266
#define life 267
#define key 268
#define gate 269
#define door 270
#define start 271
#define exite 272
#define integer 273
#define id 274
#define variable 275
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
	int value;
	char ptr[MAX_NAME];
	symbol_t symbol;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
