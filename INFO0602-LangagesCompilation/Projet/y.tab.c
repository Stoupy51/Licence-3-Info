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
extern char* outputFileContent;
extern struct symbol_t *symbol;
extern symbol_table t_d_s;
extern int depth;

#line 44 "analyser.yacc.y"
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
#line 56 "y.tab.c"

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
    1,    1,    1,    2,    2,    2,    2,    2,    2,    2,
    2,    2,
};
static const YYINT yylen[] = {                            2,
    2,    1,    4,    0,    2,    0,    1,    1,    8,    6,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    4,
    4,    4,    1,    1,    1,    1,    3,    3,    2,    3,
    3,    3,    3,    3,    3,    4,    4,    4,    4,    4,
    3,    3,
};
static const YYINT yydefred[] = {                         0,
    4,    0,    0,    6,    1,    0,    3,    0,    0,    0,
    8,    5,    7,    0,    0,    0,    0,    0,    0,    0,
    0,   25,   26,    0,    0,    0,    0,   41,    0,   42,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   33,    0,
    0,   30,   31,   32,    0,    0,    0,   12,   13,   14,
   15,   16,   17,   18,   19,    0,    0,    0,   23,   24,
    0,   11,    0,    0,    0,    0,    9,    0,    0,    0,
    0,    0,   20,   21,   22,    0,   10,
};
static const YYINT yydgoto[] = {                          2,
   26,   11,    3,    4,    6,   12,   13,   71,   72,
};
static const YYINT yysindex[] = {                      -256,
    0,    0, -256,    0,    0, -236,    0,  -25,  -58,   11,
    0,    0,    0,  -40,  -40,  -41,  -35,  -34,  -31,  -30,
  -40,    0,    0,  -40,  -40,   52,  132,    0,  -40,    0,
  -40,  -40,  -40,  -40,  132,  134,   79,  -40,  -40,  -40,
  -40,  -40,  -40,  132,  132,  132,  132,  132,    0,  134,
  134,    0,    0,    0,   86, -158,  -19,    0,    0,    0,
    0,    0,    0,    0,    0,  -16,   -8,   -6,    0,    0,
   14,    0,  -40,  -40,  -40,  -40,    0,   95,  104,  111,
  118,  -40,    0,    0,    0,  125,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,   41,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -209,    0,    0,    0,
    0,    0,    0,    0, -207,  -37,    0,    0,    0,    0,
    0,    0,    0, -194, -188, -185, -183, -175,    0,  -32,
  -27,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                        54,
    4,    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 249
static const YYINT yytable[] = {                         25,
    1,   28,   15,   29,   24,   29,   29,   29,   27,   30,
   27,   27,   27,   28,   14,   28,   28,   28,   27,   29,
   73,    7,    8,   74,   35,   31,   32,   36,   37,   33,
   34,   75,   44,   76,   45,   46,   47,   48,    9,   10,
    2,   50,   51,   52,   53,   54,   55,   20,   34,   34,
   35,   35,   18,   16,   77,   17,    5,   19,    0,    0,
    0,    0,    0,   36,   36,   34,   34,   35,   35,   37,
   37,   21,   38,   38,   39,   39,   78,   79,   80,   81,
   36,   36,   40,   40,    0,   86,   37,   37,   42,   38,
   38,   39,   39,   40,   38,   43,   39,    0,   41,   40,
   40,   57,   58,   59,   60,   61,   62,   63,   64,   65,
   66,   67,   68,   69,   70,   42,    0,    0,    0,   49,
   40,   38,   42,   39,    0,   41,    0,   40,   38,   56,
   39,   42,   41,    0,    0,    0,   40,   38,   82,   39,
   42,   41,    0,    0,   83,   40,   38,   42,   39,    0,
   41,   84,   40,   38,   42,   39,    0,   41,   85,   40,
   38,   42,   39,    0,   41,   87,   40,   38,   42,   39,
   42,   41,    0,   40,   38,   40,   39,    0,   41,    0,
   41,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   29,   29,    0,    0,    0,   27,   27,    0,    0,    0,
   28,   28,    0,   22,    0,   23,    0,   29,   29,    0,
    0,    0,   27,   27,    0,    0,    0,   28,   28,
};
static const YYINT yycheck[] = {                         40,
  257,   43,   61,   41,   45,   43,   44,   45,   41,   45,
   43,   44,   45,   41,   40,   43,   44,   45,   15,   61,
   40,  258,  259,   40,   21,   61,   61,   24,   25,   61,
   61,   40,   29,   40,   31,   32,   33,   34,  275,  276,
    0,   38,   39,   40,   41,   42,   43,   37,  258,  259,
  258,  259,   42,   43,   41,   45,    3,   47,   -1,   -1,
   -1,   -1,   -1,  258,  259,  275,  276,  275,  276,  258,
  259,   61,  258,  259,  258,  259,   73,   74,   75,   76,
  275,  276,  258,  259,   -1,   82,  275,  276,   37,  275,
  276,  275,  276,   42,   43,   44,   45,   -1,   47,  275,
  276,  260,  261,  262,  263,  264,  265,  266,  267,  268,
  269,  270,  271,  272,  273,   37,   -1,   -1,   -1,   41,
   42,   43,   37,   45,   -1,   47,   -1,   42,   43,   44,
   45,   37,   47,   -1,   -1,   -1,   42,   43,   44,   45,
   37,   47,   -1,   -1,   41,   42,   43,   37,   45,   -1,
   47,   41,   42,   43,   37,   45,   -1,   47,   41,   42,
   43,   37,   45,   -1,   47,   41,   42,   43,   37,   45,
   37,   47,   -1,   42,   43,   42,   45,   -1,   47,   -1,
   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
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
0,0,0,"'%'",0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
0,0,0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"level","end","put","get","robot","probe","empty","block","trap","ladder",
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
"EXPRESSION : EXPRESSION '%' EXPRESSION",
"EXPRESSION : '(' EXPRESSION ')'",
"ASSIGNMENT : id '=' EXPRESSION",
"ASSIGNMENT : variable '=' EXPRESSION",
"ASSIGNMENT : variable '+' '=' EXPRESSION",
"ASSIGNMENT : variable '-' '=' EXPRESSION",
"ASSIGNMENT : variable '*' '=' EXPRESSION",
"ASSIGNMENT : variable '/' '=' EXPRESSION",
"ASSIGNMENT : variable '%' '=' EXPRESSION",
"ASSIGNMENT : variable '+' '+'",
"ASSIGNMENT : variable '-' '-'",

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
#line 241 "analyser.yacc.y"

#line 323 "y.tab.c"

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
#line 61 "analyser.yacc.y"
	{
	printf(GREEN"\nValid input!\n"RESET);
}
break;
case 3:
#line 66 "analyser.yacc.y"
	{
	/* Display the level*/
	level_display(&lvl);

	/* Save the level in the output file*/
	if (outputFileContent != NULL) {
		/* Get char* from level_t*/
		char* levelStr = level_get_string(&lvl);

		/* Concatenate the level to the output file*/
		strcat(outputFileContent, levelStr);
		strcat(outputFileContent, "\n");

		/* Free the level string*/
		free(levelStr);
	}

	/* Free the symbols*/
	fprintf(stderr,YELLOW"Freeing symbols...\n"RESET);
	removeSymbolDepth(depth, &t_d_s);
	depth -= 1;
	fprintf(stderr,YELLOW"Level %d parsed.\n"RESET, depth);
}
break;
case 4:
#line 89 "analyser.yacc.y"
	{
	depth += 1;
	level_init(&lvl);
}
break;
case 9:
#line 98 "analyser.yacc.y"
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
#line 123 "analyser.yacc.y"
	{

	/* Check if the position is valid*/
	if (yystack.l_mark[-3].value < 0 || yystack.l_mark[-3].value >= WIDTH || yystack.l_mark[-1].value < 0 || yystack.l_mark[-1].value >= HEIGHT)
		yyerror("Invalid position.");

	/* Get the item*/
	v_block = level_get_block(&lvl, yystack.l_mark[-3].value, yystack.l_mark[-1].value);
}
break;
case 12:
#line 134 "analyser.yacc.y"
	{ v_block = (block_t){ROBOT_B, 0}; }
break;
case 13:
#line 135 "analyser.yacc.y"
	{ v_block = (block_t){PROBE_B, 0}; }
break;
case 14:
#line 136 "analyser.yacc.y"
	{ v_block = (block_t){EMPTY_B, 0}; }
break;
case 15:
#line 137 "analyser.yacc.y"
	{ v_block = (block_t){BLOCK_B, 0}; }
break;
case 16:
#line 138 "analyser.yacc.y"
	{ v_block = (block_t){TRAP_B, 0}; }
break;
case 17:
#line 139 "analyser.yacc.y"
	{ v_block = (block_t){LADDER_B, 0}; }
break;
case 18:
#line 140 "analyser.yacc.y"
	{ v_block = (block_t){BOMB_B, 0}; }
break;
case 19:
#line 141 "analyser.yacc.y"
	{ v_block = (block_t){LIFE_B, 0}; }
break;
case 20:
#line 142 "analyser.yacc.y"
	{
		if (yystack.l_mark[-1].value < 1 || yystack.l_mark[-1].value > 4)
			yyerror("Invalid key value (must be between 1 and 4).");
		v_block = (block_t){KEY_B, yystack.l_mark[-1].value};
	}
break;
case 21:
#line 147 "analyser.yacc.y"
	{
		if (yystack.l_mark[-1].value < 1 || yystack.l_mark[-1].value > 4)
			yyerror("Invalid gate value (must be between 1 and 4).");
		v_block = (block_t){GATE_B, yystack.l_mark[-1].value};
	}
break;
case 22:
#line 152 "analyser.yacc.y"
	{
		if (yystack.l_mark[-1].value < 1 || yystack.l_mark[-1].value > 99)
			yyerror("Invalid door value (must be between 1 and 99).");
		v_block = (block_t){DOOR_B, yystack.l_mark[-1].value};
	}
break;
case 23:
#line 157 "analyser.yacc.y"
	{ v_block = (block_t){START_B, 0}; }
break;
case 24:
#line 158 "analyser.yacc.y"
	{ v_block = (block_t){EXIT_B, 0}; }
break;
case 26:
#line 162 "analyser.yacc.y"
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
#line 170 "analyser.yacc.y"
	{ yyval.value = yystack.l_mark[-2].value + yystack.l_mark[0].value; }
break;
case 28:
#line 171 "analyser.yacc.y"
	{ yyval.value = yystack.l_mark[-2].value - yystack.l_mark[0].value; }
break;
case 29:
#line 172 "analyser.yacc.y"
	{ yyval.value = -yystack.l_mark[0].value; }
break;
case 30:
#line 173 "analyser.yacc.y"
	{ yyval.value = yystack.l_mark[-2].value * yystack.l_mark[0].value; }
break;
case 31:
#line 174 "analyser.yacc.y"
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
#line 182 "analyser.yacc.y"
	{
		if (yystack.l_mark[0].value == 0) {
			printf("Error: modulo by zero : %d %% %d\n", yystack.l_mark[-2].value, yystack.l_mark[0].value);
			yyerror("modulo by zero");
		}
		else
			yyval.value = yystack.l_mark[-2].value % yystack.l_mark[0].value;
	}
break;
case 33:
#line 190 "analyser.yacc.y"
	{ yyval.value = yystack.l_mark[-1].value; }
break;
case 34:
#line 193 "analyser.yacc.y"
	{
		/* Ajout de la variable dans la table des symboles*/
		symbol->data.i = yystack.l_mark[0].value;
		printf(GREEN"[+] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
case 35:
#line 198 "analyser.yacc.y"
	{
		/* Modification de la variable dans la table des symboles*/
		symbol->data.i = yystack.l_mark[0].value;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
case 36:
#line 203 "analyser.yacc.y"
	{
		/* Modification de la variable dans la table des symboles*/
		symbol->data.i += yystack.l_mark[0].value;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
case 37:
#line 208 "analyser.yacc.y"
	{
		/* Modification de la variable dans la table des symboles*/
		symbol->data.i -= yystack.l_mark[0].value;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
case 38:
#line 213 "analyser.yacc.y"
	{
		/* Modification de la variable dans la table des symboles*/
		symbol->data.i *= yystack.l_mark[0].value;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
case 39:
#line 218 "analyser.yacc.y"
	{
		/* Modification de la variable dans la table des symboles*/
		symbol->data.i /= yystack.l_mark[0].value;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
case 40:
#line 223 "analyser.yacc.y"
	{
		/* Modification de la variable dans la table des symboles*/
		symbol->data.i %= yystack.l_mark[0].value;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
case 41:
#line 228 "analyser.yacc.y"
	{
		/* Modification de la variable dans la table des symboles*/
		symbol->data.i++;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
case 42:
#line 233 "analyser.yacc.y"
	{
		/* Modification de la variable dans la table des symboles*/
		symbol->data.i--;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
#line 792 "y.tab.c"
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
