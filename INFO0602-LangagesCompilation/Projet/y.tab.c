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
    0,    3,    3,    4,    4,    5,    6,    7,    7,    8,
    8,    9,   11,   10,   10,   10,   10,   10,   10,   10,
   10,   10,   10,   10,   10,   10,   10,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    2,    2,    2,    2,
    2,    2,    2,    2,    2,
};
static const YYINT yylen[] = {                            2,
    1,    2,    0,    1,    1,    4,    0,    2,    0,    1,
    1,    8,    6,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    4,    4,    4,    1,    1,    1,    1,    3,
    3,    2,    3,    3,    3,    3,    3,    3,    4,    4,
    4,    4,    4,    3,    3,
};
static const YYINT yydefred[] = {                         3,
    0,    0,    7,    0,    0,    5,    2,    4,    9,    0,
    0,    0,    0,    0,    0,    0,    0,   28,   29,    0,
    0,    0,   44,    0,   45,    0,    0,    0,    0,    0,
    6,    0,   11,    8,   10,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   36,    0,
    0,   33,   34,   35,    0,    0,    0,    0,    0,   15,
   16,   17,   18,   19,   20,   21,   22,    0,    0,    0,
   26,   27,    0,   14,    0,    0,    0,    0,   12,    0,
    0,    0,    0,    0,   23,   24,   25,    0,   13,
};
static const YYINT yydgoto[] = {                          1,
   22,    6,    2,    7,    8,    9,   17,   34,   35,   73,
   74,
};
static const YYINT yysindex[] = {                         0,
    0, -253,    0,  -51,  -30,    0,    0,    0,    0,  -40,
  -34,  -37,  -45,  -43,  -36,  -40, -256,    0,    0,  -40,
  -40,  122,    0,  -40,    0,  -40,  -40,  -40,  -40,  122,
    0,  -12,    0,    0,    0,  124,   50,  -40,  -40,  -40,
  -40,  -40,  122,  122,  122,  122,  122,  -40,    0,  124,
  124,    0,    0,    0,   -7,  -40,   30, -161,  -11,    0,
    0,    0,    0,    0,    0,    0,    0,   -8,   -1,    3,
    0,    0,   12,    0,  -40,  -40,  -40,  -40,    0,   85,
   94,  101,  108,  -40,    0,    0,    0,  115,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,   33,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   14,    0,    0,    0,    0,    0,    0,    0,   21,
    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,
    0,    0,   26,   34,   41,   48,   61,    0,    0,    6,
   11,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   42,   40,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
#define YYTABLESIZE 337
static const YYINT yytable[] = {                         21,
   32,   31,   32,    3,   20,   30,   15,   25,   23,   10,
   31,   13,   11,   37,   12,   27,   14,   28,    4,    5,
   38,    4,    5,   26,   29,   39,   24,   48,   75,   42,
   16,   76,    1,   40,   40,   38,   56,   39,   77,   41,
   41,   32,   78,   32,   32,   32,   30,   42,   30,   30,
   30,   31,   79,   31,   31,   31,   33,   30,    0,    0,
   43,   36,   37,    0,    0,   43,   42,   44,   45,   46,
   47,   40,   38,   58,   39,    0,   41,    0,    0,   50,
   51,   52,   53,   54,    0,    0,   42,    0,    0,   55,
   49,   40,   38,    0,   39,    0,   41,   57,   59,   60,
   61,   62,   63,   64,   65,   66,   67,   68,   69,   70,
   71,   72,    0,    0,    0,    0,   80,   81,   82,   83,
    0,   42,    0,    0,    0,   88,   40,   38,   84,   39,
   42,   41,    0,    0,   85,   40,   38,   42,   39,    0,
   41,   86,   40,   38,   42,   39,    0,   41,   87,   40,
   38,   42,   39,    0,   41,   89,   40,   38,   42,   39,
   42,   41,    0,   40,   38,   40,   39,    0,   41,    0,
   41,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   18,    0,   19,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   32,   32,   32,
    0,    0,   30,   30,   30,    0,    0,   31,   31,   31,
   37,   37,   37,    0,    0,   32,   32,   38,   38,   38,
   30,   30,   39,   39,   39,   31,   31,    0,   37,   37,
   40,   40,   40,    0,    0,   38,   38,   41,   41,   41,
   39,   39,    0,    0,   42,   42,   42,    0,   40,   40,
    0,    0,    0,    0,    0,   41,   41,   43,   43,   43,
    0,    0,   42,   42,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   43,   43,
};
static const YYINT yycheck[] = {                         40,
    0,  258,  259,  257,   45,    0,   37,   45,   43,   61,
    0,   42,   43,    0,   45,   61,   47,   61,  275,  276,
    0,  275,  276,   61,   61,    0,   61,   40,   40,   37,
   61,   40,    0,    0,   42,   43,   44,   45,   40,   47,
    0,   41,   40,   43,   44,   45,   41,    0,   43,   44,
   45,   41,   41,   43,   44,   45,   17,   16,   -1,   -1,
    0,   20,   21,   -1,   -1,   24,   37,   26,   27,   28,
   29,   42,   43,   44,   45,   -1,   47,   -1,   -1,   38,
   39,   40,   41,   42,   -1,   -1,   37,   -1,   -1,   48,
   41,   42,   43,   -1,   45,   -1,   47,   56,  260,  261,
  262,  263,  264,  265,  266,  267,  268,  269,  270,  271,
  272,  273,   -1,   -1,   -1,   -1,   75,   76,   77,   78,
   -1,   37,   -1,   -1,   -1,   84,   42,   43,   44,   45,
   37,   47,   -1,   -1,   41,   42,   43,   37,   45,   -1,
   47,   41,   42,   43,   37,   45,   -1,   47,   41,   42,
   43,   37,   45,   -1,   47,   41,   42,   43,   37,   45,
   37,   47,   -1,   42,   43,   42,   45,   -1,   47,   -1,
   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  274,   -1,  276,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
   -1,   -1,  257,  258,  259,   -1,   -1,  257,  258,  259,
  257,  258,  259,   -1,   -1,  275,  276,  257,  258,  259,
  275,  276,  257,  258,  259,  275,  276,   -1,  275,  276,
  257,  258,  259,   -1,   -1,  275,  276,  257,  258,  259,
  275,  276,   -1,   -1,  257,  258,  259,   -1,  275,  276,
   -1,   -1,   -1,   -1,   -1,  275,  276,  257,  258,  259,
   -1,   -1,  275,  276,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  275,  276,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 276
#define YYUNDFTOKEN 290
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
0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : EXEC",
"EXEC : GLOBAL_LIST",
"GLOBAL_LIST : GLOBAL_LIST GLOBAL_CONTENT",
"GLOBAL_LIST :",
"GLOBAL_CONTENT : LEVEL_BLOCK",
"GLOBAL_CONTENT : ASSIGNMENT",
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
#line 264 "analyser.yacc.y"

#line 346 "y.tab.c"

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
case 1:
#line 61 "analyser.yacc.y"
	{
	printf(GREEN"\nValid input!\n"RESET);
}
break;
case 6:
#line 70 "analyser.yacc.y"
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
case 7:
#line 93 "analyser.yacc.y"
	{
	depth += 1;
	level_init(&lvl);
}
break;
case 12:
#line 102 "analyser.yacc.y"
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
case 13:
#line 127 "analyser.yacc.y"
	{

	/* Check if the position is valid*/
	if (yystack.l_mark[-3].value < 0 || yystack.l_mark[-3].value >= WIDTH || yystack.l_mark[-1].value < 0 || yystack.l_mark[-1].value >= HEIGHT)
		yyerror("Invalid position.");

	/* Get the item*/
	v_block = level_get_block(&lvl, yystack.l_mark[-3].value, yystack.l_mark[-1].value);
}
break;
case 15:
#line 138 "analyser.yacc.y"
	{ v_block = (block_t){ROBOT_B, 0}; }
break;
case 16:
#line 139 "analyser.yacc.y"
	{ v_block = (block_t){PROBE_B, 0}; }
break;
case 17:
#line 140 "analyser.yacc.y"
	{ v_block = (block_t){EMPTY_B, 0}; }
break;
case 18:
#line 141 "analyser.yacc.y"
	{ v_block = (block_t){BLOCK_B, 0}; }
break;
case 19:
#line 142 "analyser.yacc.y"
	{ v_block = (block_t){TRAP_B, 0}; }
break;
case 20:
#line 143 "analyser.yacc.y"
	{ v_block = (block_t){LADDER_B, 0}; }
break;
case 21:
#line 144 "analyser.yacc.y"
	{ v_block = (block_t){BOMB_B, 0}; }
break;
case 22:
#line 145 "analyser.yacc.y"
	{ v_block = (block_t){LIFE_B, 0}; }
break;
case 23:
#line 146 "analyser.yacc.y"
	{
		if (yystack.l_mark[-1].value < 1 || yystack.l_mark[-1].value > 4)
			yyerror("Invalid key value (must be between 1 and 4).");
		v_block = (block_t){KEY_B, yystack.l_mark[-1].value};
	}
break;
case 24:
#line 151 "analyser.yacc.y"
	{
		if (yystack.l_mark[-1].value < 1 || yystack.l_mark[-1].value > 4)
			yyerror("Invalid gate value (must be between 1 and 4).");
		v_block = (block_t){GATE_B, yystack.l_mark[-1].value};
	}
break;
case 25:
#line 156 "analyser.yacc.y"
	{
		if (yystack.l_mark[-1].value < 1 || yystack.l_mark[-1].value > 99)
			yyerror("Invalid door value (must be between 1 and 99).");
		v_block = (block_t){DOOR_B, yystack.l_mark[-1].value};
	}
break;
case 26:
#line 161 "analyser.yacc.y"
	{ v_block = (block_t){START_B, 0}; }
break;
case 27:
#line 162 "analyser.yacc.y"
	{ v_block = (block_t){EXIT_B, 0}; }
break;
case 29:
#line 166 "analyser.yacc.y"
	{
		/* Recherche de la variable dans la table des symboles*/
		symbol = getSymbolFromTable(yystack.l_mark[0].symbol.name, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		yyval.value = symbol->data.i;
	}
break;
case 30:
#line 173 "analyser.yacc.y"
	{ yyval.value = yystack.l_mark[-2].value + yystack.l_mark[0].value; }
break;
case 31:
#line 174 "analyser.yacc.y"
	{ yyval.value = yystack.l_mark[-2].value - yystack.l_mark[0].value; }
break;
case 32:
#line 175 "analyser.yacc.y"
	{ yyval.value = -yystack.l_mark[0].value; }
break;
case 33:
#line 176 "analyser.yacc.y"
	{ yyval.value = yystack.l_mark[-2].value * yystack.l_mark[0].value; }
break;
case 34:
#line 177 "analyser.yacc.y"
	{
		if (yystack.l_mark[0].value == 0) {
			printf("Error: division by zero : %d / %d\n", yystack.l_mark[-2].value, yystack.l_mark[0].value);
			yyerror("division by zero");
		}
		else
			yyval.value = yystack.l_mark[-2].value / yystack.l_mark[0].value;
	}
break;
case 35:
#line 185 "analyser.yacc.y"
	{
		if (yystack.l_mark[0].value == 0) {
			printf("Error: modulo by zero : %d %% %d\n", yystack.l_mark[-2].value, yystack.l_mark[0].value);
			yyerror("modulo by zero");
		}
		else
			yyval.value = yystack.l_mark[-2].value % yystack.l_mark[0].value;
	}
break;
case 36:
#line 193 "analyser.yacc.y"
	{ yyval.value = yystack.l_mark[-1].value; }
break;
case 37:
#line 196 "analyser.yacc.y"
	{
		/* Ajout de la variable dans la table des symboles*/
		symbol = getSymbolFromTable(yystack.l_mark[-2].ptr, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		symbol->data.i = yystack.l_mark[0].value;
		printf(GREEN"[+] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
case 38:
#line 204 "analyser.yacc.y"
	{
		/* Modification de la variable dans la table des symboles*/
		symbol = getSymbolFromTable(yystack.l_mark[-2].symbol.name, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		symbol->data.i = yystack.l_mark[0].value;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
case 39:
#line 212 "analyser.yacc.y"
	{
		symbol = getSymbolFromTable(yystack.l_mark[-3].symbol.name, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		symbol->data.i += yystack.l_mark[0].value;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
case 40:
#line 219 "analyser.yacc.y"
	{
		symbol = getSymbolFromTable(yystack.l_mark[-3].symbol.name, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		symbol->data.i -= yystack.l_mark[0].value;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
case 41:
#line 226 "analyser.yacc.y"
	{
		symbol = getSymbolFromTable(yystack.l_mark[-3].symbol.name, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		symbol->data.i *= yystack.l_mark[0].value;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
case 42:
#line 233 "analyser.yacc.y"
	{
		symbol = getSymbolFromTable(yystack.l_mark[-3].symbol.name, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		symbol->data.i /= yystack.l_mark[0].value;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
case 43:
#line 240 "analyser.yacc.y"
	{
		symbol = getSymbolFromTable(yystack.l_mark[-3].symbol.name, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		symbol->data.i %= yystack.l_mark[0].value;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
case 44:
#line 247 "analyser.yacc.y"
	{
		symbol = getSymbolFromTable(yystack.l_mark[-2].symbol.name, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		symbol->data.i++;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
case 45:
#line 254 "analyser.yacc.y"
	{
		symbol = getSymbolFromTable(yystack.l_mark[-2].symbol.name, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		symbol->data.i--;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
break;
#line 834 "y.tab.c"
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
