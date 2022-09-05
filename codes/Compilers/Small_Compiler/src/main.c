#include<stdio.h>
#include "../Language.tab.h"
extern unsigned int total;

int yyerror(char *c)
{
  printf("It's a bad: %s\n", c);
  return 0;
}

extern FILE *yyin;

int main(int argc, char **argv)
{
  yyin = fopen(argv[1], "r");
  if(!yyparse())
    printf("Success: %d\n",total);
  return 0;
}
