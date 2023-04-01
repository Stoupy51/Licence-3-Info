#define level 257
#define end 258
#define put 259
#define get 260
#define robot 261
#define probe 262
#define empty 263
#define block 264
#define trap 265
#define ladder 266
#define bomb 267
#define life 268
#define key 269
#define gate 270
#define door 271
#define start 272
#define exite 273
#define integer 274
#define id 275
#define variable 276
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int value;
	char ptr[MAX_NAME];
	symbol_t symbol;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
