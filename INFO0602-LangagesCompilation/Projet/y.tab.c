/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 3 "analyser.yacc.y"
#include <stdio.h>
#include <stdlib.h>
#include "level.h"
#include "tree.h"
#include "symbol.h"
#include "table_des_symboles.h"

#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
void yyerror(const char *error_msg);
int yylex();

int x, y;
level_t lvl;
block_t v_block;
extern struct symbol_t *symbol;
extern symbol_table t_d_s;

#line 41 "analyser.yacc.y"
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
#line 54 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

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
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    5,    3,    4,    4,    6,    7,    8,    8,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    1,    1,    1,    1,    1,    1,    1,    2,    2,
};
static const YYINT yylen[] = {                            2,
    2,    1,    0,    4,    2,    0,    1,    8,    1,    1,
    1,    1,    1,    1,    1,    1,    4,    4,    4,    1,
    1,    1,    3,    3,    2,    3,    3,    3,    3,    3,
};
static const YYINT yydefred[] = {                         0,
    3,    0,    0,    6,    1,    0,    4,    0,    5,    7,
    0,   22,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   28,    0,    0,   26,   27,    0,    0,    9,
   10,   11,   12,   13,   14,   15,   16,    0,    0,    0,
   20,   21,    0,    0,    0,    0,    8,    0,    0,    0,
   17,   18,   19,
};
static const YYINT yydgoto[] = {                          2,
   15,    0,    3,    6,    4,    9,   10,   43,
};
static const YYINT yysindex[] = {                      -230,
    0,    0, -230,    0,    0, -255,    0,  -11,    0,    0,
  -40,    0,  -40,  -40,   14,   -2,  -17,  -40,  -40,  -40,
  -40,  -40,    0,   -2,   -2,    0,    0,   20, -249,    0,
    0,    0,    0,    0,    0,    0,    0,   -9,    7,   12,
    0,    0,   -3,  -40,  -40,  -40,    0,   -6,    1,    8,
    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,   54,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   25,    0,    0,    0,    0,
    0,    0,    0,   30,   35,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
static const YYINT yygindex[] = {                        57,
  -12,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 233
static const YYINT yytable[] = {                         14,
   16,   17,    7,    8,   13,   24,   25,   26,   27,   28,
   30,   31,   32,   33,   34,   35,   36,   37,   38,   39,
   40,   41,   42,   23,   20,   18,    1,   19,   11,   21,
   44,   48,   49,   50,   51,   20,   18,   47,   19,   20,
   21,   52,   20,   18,   21,   19,   45,   21,   53,   20,
   18,   46,   19,    2,   21,   20,   18,   22,   19,    5,
   21,   20,   18,   29,   19,   25,   21,   25,   25,   25,
   23,    0,   23,   23,   23,   24,    0,   24,   24,   24,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   12,
};
static const YYINT yycheck[] = {                         40,
   13,   14,  258,  259,   45,   18,   19,   20,   21,   22,
  260,  261,  262,  263,  264,  265,  266,  267,  268,  269,
  270,  271,  272,   41,   42,   43,  257,   45,   40,   47,
   40,   44,   45,   46,   41,   42,   43,   41,   45,   42,
   47,   41,   42,   43,   47,   45,   40,   47,   41,   42,
   43,   40,   45,    0,   47,   42,   43,   44,   45,    3,
   47,   42,   43,   44,   45,   41,   47,   43,   44,   45,
   41,   -1,   43,   44,   45,   41,   -1,   43,   44,   45,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  273,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 275
#define YYUNDFTOKEN 286
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,0,
0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"level","end","put","robot","probe","empty","block","trap","ladder","bomb",
"life","key","gate","door","start","exite","integer","id","variable",0,0,0,0,0,
0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : EXEC",
"EXEC : LEVEL_BLOCK EXEC",
"EXEC : LEVEL_BLOCK",
"$$1 :",
"LEVEL_BLOCK : level $$1 CONTENT_LIST end",
"CONTENT_LIST : CONTENT_LIST CONTENT",
"CONTENT_LIST :",
"CONTENT : PUT_FUNC",
"PUT_FUNC : put '(' EXPRESSION ',' EXPRESSION ',' ITEM ')'",
"ITEM : robot",
"ITEM : probe",
"ITEM : empty",
"ITEM : block",
"ITEM : trap",
"ITEM : ladder",
"ITEM : bomb",
"ITEM : life",
"ITEM : key '(' EXPRESSION ')'",
"ITEM : gate '(' EXPRESSION ')'",
"ITEM : door '(' EXPRESSION ')'",
"ITEM : start",
"ITEM : exite",
"EXPRESSION : integer",
"EXPRESSION : EXPRESSION '+' EXPRESSION",
"EXPRESSION : EXPRESSION '-' EXPRESSION",
"EXPRESSION : '-' EXPRESSION",
"EXPRESSION : EXPRESSION '*' EXPRESSION",
"EXPRESSION : EXPRESSION '/' EXPRESSION",
"EXPRESSION : '(' EXPRESSION ')'",
"ASSIGNMENT : id '=' EXPRESSION",
"ASSIGNMENT : variable '=' EXPRESSION",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 143 "analyser.yacc.y"

#line 293 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 2:
#line 58 "analyser.yacc.y"
	{
	printf(GREEN"\nValid input!\n"RESET);
}
break;
case 3:
#line 63 "analyser.yacc.y"
	{ level_init(&lvl); }
break;
case 4:
#line 63 "analyser.yacc.y"
	{ level_display(&lvl); }
break;
case 8:
#line 69 "analyser.yacc.y"
	{
	switch (v_block.type) {
		case 1 : level_add_robot(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value); break;
		case 2 : level_add_probe(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value); break;
		case 3 : level_add_empty(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value); break;
		case 4 : level_add_block(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value); break;
		case 5 : level_add_trap(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value); break;
		case 6 : level_add_ladder(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value); break;
		case 7 : level_add_bomb(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value); break;
		case 8 : level_add_life(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value); break;
		case 9 : level_add_key(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value, v_block.value); break;
		case 10 : level_add_gate(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value, v_block.value); break;
		case 11 : level_add_door(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value, v_block.value); break;
		case 12 : level_add_start(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value); break;
		case 13 : level_add_exit(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value); break;
		default : break;
	}
}
break;
case 9:
#line 88 "analyser.yacc.y"
	{ v_block = (block_t){1, 0}; }
break;
case 10:
#line 89 "analyser.yacc.y"
	{ v_block = (block_t){2, 0}; }
break;
case 11:
#line 90 "analyser.yacc.y"
	{ v_block = (block_t){3, 0}; }
break;
case 12:
#line 91 "analyser.yacc.y"
	{ v_block = (block_t){4, 0}; }
break;
case 13:
#line 92 "analyser.yacc.y"
	{ v_block = (block_t){5, 0}; }
break;
case 14:
#line 93 "analyser.yacc.y"
	{ v_block = (block_t){6, 0}; }
break;
case 15:
#line 94 "analyser.yacc.y"
	{ v_block = (block_t){7, 0}; }
break;
case 16:
#line 95 "analyser.yacc.y"
	{ v_block = (block_t){8, 0}; }
break;
case 17:
#line 96 "analyser.yacc.y"
	{
		if (yystack.l_mark[-1].value < 1 || yystack.l_mark[-1].value > 4)
			yyerror("Invalid key value (must be between 1 and 4).");
		v_block = (block_t){9, yystack.l_mark[-1].value};
	}
break;
case 18:
#line 101 "analyser.yacc.y"
	{
		if (yystack.l_mark[-1].value < 1 || yystack.l_mark[-1].value > 4)
			yyerror("Invalid gate value (must be between 1 and 4).");
		v_block = (block_t){10, yystack.l_mark[-1].value};
	}
break;
case 19:
#line 106 "analyser.yacc.y"
	{
		if (yystack.l_mark[-1].value < 1 || yystack.l_mark[-1].value > 99)
			yyerror("Invalid door value (must be between 1 and 99).");
		v_block = (block_t){11, yystack.l_mark[-1].value};
	}
break;
case 20:
#line 111 "analyser.yacc.y"
	{ v_block = (block_t){12, 0}; }
break;
case 21:
#line 112 "analyser.yacc.y"
	{ v_block = (block_t){13, 0}; }
break;
case 23:
#line 116 "analyser.yacc.y"
	{ yyval.value = yystack.l_mark[-2].value + yystack.l_mark[0].value; }
break;
case 24:
#line 117 "analyser.yacc.y"
	{ yyval.value = yystack.l_mark[-2].value - yystack.l_mark[0].value; }
break;
case 25:
#line 118 "analyser.yacc.y"
	{ yyval.value = -yystack.l_mark[0].value; }
break;
case 26:
#line 119 "analyser.yacc.y"
	{ yyval.value = yystack.l_mark[-2].value * yystack.l_mark[0].value; }
break;
case 27:
#line 120 "analyser.yacc.y"
	{
		if (yystack.l_mark[0].value == 0) {
			printf("Error: division by zero : %d / %d\n", yystack.l_mark[-2].value, yystack.l_mark[0].value);
			yyerror("division by zero");
		}
		else
			yyval.value = yystack.l_mark[-2].value / yystack.l_mark[0].value;
	}
break;
case 28:
#line 128 "analyser.yacc.y"
	{ yyval.value = yystack.l_mark[-1].value; }
break;
case 29:
#line 131 "analyser.yacc.y"
	{
		/* Ajout de la variable dans la table des symboles*/
		symbol->data.i = yystack.l_mark[0].value;
		printf(GREEN"[+] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
case 30:
#line 136 "analyser.yacc.y"
	{
		/* Modification de la variable dans la table des symboles*/
		symbol->data.i = yystack.l_mark[0].value;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
#line 641 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
