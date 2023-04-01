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
extern int depth;

#line 43 "analyser.yacc.y"
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
#line 55 "y.tab.c"

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
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    3,    4,    5,    5,    6,    6,    7,    9,
    8,    8,    8,    8,    8,    8,    8,    8,    8,    8,
    8,    8,    8,    8,    1,    1,    1,    1,    1,    1,
    1,    1,    2,    2,
};
static const YYINT yylen[] = {                            2,
    2,    1,    4,    0,    2,    0,    1,    1,    8,    6,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    4,
    4,    4,    1,    1,    1,    1,    3,    3,    2,    3,
    3,    3,    3,    3,
};
static const YYINT yydefred[] = {                         0,
    4,    0,    0,    6,    1,    0,    3,    0,    0,    0,
    8,    5,    7,    0,    0,    0,   25,   26,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   32,    0,    0,   30,   31,    0,    0,    0,   12,   13,
   14,   15,   16,   17,   18,   19,    0,    0,    0,   23,
   24,    0,   11,    0,    0,    0,    0,    9,    0,    0,
    0,    0,    0,   20,   21,   22,    0,   10,
};
static const YYINT yydgoto[] = {                          2,
   21,   11,    3,    4,    6,   12,   13,   52,   53,
};
static const YYINT yysindex[] = {                      -256,
    0,    0, -256,    0,    0, -237,    0,  -38,  -58,  -51,
    0,    0,    0,  -40,  -40,  -40,    0,    0,  -40,  -40,
   68,   86,   86,   -7,    5,  -40,  -40,  -40,  -40,  -40,
    0,   -7,   -7,    0,    0,   74, -192,  -25,    0,    0,
    0,    0,    0,    0,    0,    0,  -11,   -4,   -3,    0,
    0,    8,    0,  -40,  -40,  -40,  -40,    0,   80,   41,
   48,   55,  -40,    0,    0,    0,   62,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,   51,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -233, -231,  -37,    0,    0,    0,    0,    0,    0,
    0,  -32,  -27,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                        38,
    4,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 249
static const YYINT yytable[] = {                         20,
    1,   14,   15,   29,   19,   29,   29,   29,   27,   16,
   27,   27,   27,   28,   54,   28,   28,   28,   22,   23,
    7,    8,   24,   25,   33,   33,   34,   34,   55,   32,
   33,   34,   35,   36,   28,   56,   57,    9,   10,   29,
    5,   33,   33,   34,   34,   31,   28,   26,   58,   27,
    2,   29,    0,    0,    0,    0,    0,   59,   60,   61,
   62,    0,    0,    0,    0,    0,   67,   38,   39,   40,
   41,   42,   43,   44,   45,   46,   47,   48,   49,   50,
   51,   64,   28,   26,    0,   27,    0,   29,   65,   28,
   26,    0,   27,    0,   29,   66,   28,   26,    0,   27,
    0,   29,   68,   28,   26,    0,   27,    0,   29,   28,
   26,   30,   27,    0,   29,   28,   26,   37,   27,    0,
   29,   28,   26,   63,   27,    0,   29,   28,   26,    0,
   27,    0,   29,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   29,   29,    0,    0,    0,   27,   27,    0,    0,    0,
   28,   28,    0,   17,    0,   18,    0,   29,   29,    0,
    0,    0,   27,   27,    0,    0,    0,   28,   28,
};
static const YYINT yycheck[] = {                         40,
  257,   40,   61,   41,   45,   43,   44,   45,   41,   61,
   43,   44,   45,   41,   40,   43,   44,   45,   15,   16,
  258,  259,   19,   20,  258,  259,  258,  259,   40,   26,
   27,   28,   29,   30,   42,   40,   40,  275,  276,   47,
    3,  275,  276,  275,  276,   41,   42,   43,   41,   45,
    0,   47,   -1,   -1,   -1,   -1,   -1,   54,   55,   56,
   57,   -1,   -1,   -1,   -1,   -1,   63,  260,  261,  262,
  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,
  273,   41,   42,   43,   -1,   45,   -1,   47,   41,   42,
   43,   -1,   45,   -1,   47,   41,   42,   43,   -1,   45,
   -1,   47,   41,   42,   43,   -1,   45,   -1,   47,   42,
   43,   44,   45,   -1,   47,   42,   43,   44,   45,   -1,
   47,   42,   43,   44,   45,   -1,   47,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  258,  259,   -1,   -1,   -1,  258,  259,   -1,   -1,   -1,
  258,  259,   -1,  274,   -1,  276,   -1,  275,  276,   -1,
   -1,   -1,  275,  276,   -1,   -1,   -1,  275,  276,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 276
#define YYUNDFTOKEN 288
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
"level","end","put","get","robot","probe","empty","block","trap","ladder",
"bomb","life","key","gate","door","start","exite","integer","id","variable",0,0,
0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : EXEC",
"EXEC : LEVEL_BLOCK EXEC",
"EXEC : LEVEL_BLOCK",
"LEVEL_BLOCK : level ENTER_LEVEL_BLOCK CONTENT_LIST end",
"ENTER_LEVEL_BLOCK :",
"CONTENT_LIST : CONTENT_LIST CONTENT",
"CONTENT_LIST :",
"CONTENT : PUT_FUNC",
"CONTENT : ASSIGNMENT",
"PUT_FUNC : put '(' EXPRESSION ',' EXPRESSION ',' ITEM ')'",
"GET_FUNC : get '(' EXPRESSION ',' EXPRESSION ')'",
"ITEM : GET_FUNC",
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
"EXPRESSION : variable",
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
#line 178 "analyser.yacc.y"

#line 306 "y.tab.c"

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
#line 60 "analyser.yacc.y"
	{
	printf(GREEN"\nValid input!\n"RESET);
}
break;
case 3:
#line 65 "analyser.yacc.y"
	{
	level_display(&lvl);
	removeSymbolDepth(depth, &t_d_s);
	depth -= 1;
}
break;
case 4:
#line 70 "analyser.yacc.y"
	{
	depth += 1;
	level_init(&lvl);
}
break;
case 9:
#line 79 "analyser.yacc.y"
	{

	/* Check if the position is valid*/
	if (yystack.l_mark[-5].value < 0 || yystack.l_mark[-5].value >= WIDTH || yystack.l_mark[-3].value < 0 || yystack.l_mark[-3].value >= HEIGHT)
		yyerror("Invalid position.");

	/* Put the item*/
	switch (v_block.type) {
		case ROBOT_B : level_add_robot(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value); break;
		case PROBE_B : level_add_probe(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value); break;
		case EMPTY_B : level_add_empty(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value); break;
		case BLOCK_B : level_add_block(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value); break;
		case TRAP_B : level_add_trap(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value); break;
		case LADDER_B : level_add_ladder(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value); break;
		case BOMB_B : level_add_bomb(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value); break;
		case LIFE_B : level_add_life(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value); break;
		case KEY_B : level_add_key(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value, v_block.value); break;
		case GATE_B : level_add_gate(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value, v_block.value); break;
		case DOOR_B : level_add_door(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value, v_block.value); break;
		case START_B : level_add_start(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value); break;
		case EXIT_B : level_add_exit(&lvl, yystack.l_mark[-5].value, yystack.l_mark[-3].value); break;
		default : break;
	}
}
break;
case 10:
#line 104 "analyser.yacc.y"
	{

	/* Check if the position is valid*/
	if (yystack.l_mark[-3].value < 0 || yystack.l_mark[-3].value >= WIDTH || yystack.l_mark[-1].value < 0 || yystack.l_mark[-1].value >= HEIGHT)
		yyerror("Invalid position.");

	/* Get the item*/
	v_block = level_get_block(&lvl, yystack.l_mark[-3].value, yystack.l_mark[-1].value);
}
break;
case 12:
#line 115 "analyser.yacc.y"
	{ v_block = (block_t){ROBOT_B, 0}; }
break;
case 13:
#line 116 "analyser.yacc.y"
	{ v_block = (block_t){PROBE_B, 0}; }
break;
case 14:
#line 117 "analyser.yacc.y"
	{ v_block = (block_t){EMPTY_B, 0}; }
break;
case 15:
#line 118 "analyser.yacc.y"
	{ v_block = (block_t){BLOCK_B, 0}; }
break;
case 16:
#line 119 "analyser.yacc.y"
	{ v_block = (block_t){TRAP_B, 0}; }
break;
case 17:
#line 120 "analyser.yacc.y"
	{ v_block = (block_t){LADDER_B, 0}; }
break;
case 18:
#line 121 "analyser.yacc.y"
	{ v_block = (block_t){BOMB_B, 0}; }
break;
case 19:
#line 122 "analyser.yacc.y"
	{ v_block = (block_t){LIFE_B, 0}; }
break;
case 20:
#line 123 "analyser.yacc.y"
	{
		if (yystack.l_mark[-1].value < 1 || yystack.l_mark[-1].value > 4)
			yyerror("Invalid key value (must be between 1 and 4).");
		v_block = (block_t){KEY_B, yystack.l_mark[-1].value};
	}
break;
case 21:
#line 128 "analyser.yacc.y"
	{
		if (yystack.l_mark[-1].value < 1 || yystack.l_mark[-1].value > 4)
			yyerror("Invalid gate value (must be between 1 and 4).");
		v_block = (block_t){GATE_B, yystack.l_mark[-1].value};
	}
break;
case 22:
#line 133 "analyser.yacc.y"
	{
		if (yystack.l_mark[-1].value < 1 || yystack.l_mark[-1].value > 99)
			yyerror("Invalid door value (must be between 1 and 99).");
		v_block = (block_t){DOOR_B, yystack.l_mark[-1].value};
	}
break;
case 23:
#line 138 "analyser.yacc.y"
	{ v_block = (block_t){START_B, 0}; }
break;
case 24:
#line 139 "analyser.yacc.y"
	{ v_block = (block_t){EXIT_B, 0}; }
break;
case 26:
#line 143 "analyser.yacc.y"
	{
		/* Recherche de la variable dans la table des symboles*/
		symbol = getSymbolFromTable(yystack.l_mark[0].symbol.name, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		else
			yyval.value = symbol->data.i;
	}
break;
case 27:
#line 151 "analyser.yacc.y"
	{ yyval.value = yystack.l_mark[-2].value + yystack.l_mark[0].value; }
break;
case 28:
#line 152 "analyser.yacc.y"
	{ yyval.value = yystack.l_mark[-2].value - yystack.l_mark[0].value; }
break;
case 29:
#line 153 "analyser.yacc.y"
	{ yyval.value = -yystack.l_mark[0].value; }
break;
case 30:
#line 154 "analyser.yacc.y"
	{ yyval.value = yystack.l_mark[-2].value * yystack.l_mark[0].value; }
break;
case 31:
#line 155 "analyser.yacc.y"
	{
		if (yystack.l_mark[0].value == 0) {
			printf("Error: division by zero : %d / %d\n", yystack.l_mark[-2].value, yystack.l_mark[0].value);
			yyerror("division by zero");
		}
		else
			yyval.value = yystack.l_mark[-2].value / yystack.l_mark[0].value;
	}
break;
case 32:
#line 163 "analyser.yacc.y"
	{ yyval.value = yystack.l_mark[-1].value; }
break;
case 33:
#line 166 "analyser.yacc.y"
	{
		/* Ajout de la variable dans la table des symboles*/
		symbol->data.i = yystack.l_mark[0].value;
		printf(GREEN"[+] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
case 34:
#line 171 "analyser.yacc.y"
	{
		/* Modification de la variable dans la table des symboles*/
		symbol->data.i = yystack.l_mark[0].value;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
#line 690 "y.tab.c"
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
