%{
#define YYSTYPE int
#include "Language.tab.h"         /* Token values generated by bison */
%}

%option noyywrap

%%
[01]         { return BIT; }    /* Single character literal into token */
\n                              /* munch */
%%
