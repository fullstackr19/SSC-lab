%{
#include<stdio.h>
#include<stdlib.h>
int valid;
%}

%token A B

%%
str: A expr B
| expr1
;
expr: A expr|;
expr1: B ;
%%

int main()
{
printf("\nEnter the Expression : \n");
yyparse();
printf("The Grammar is valid.\n");
exit(0);
}

int yyerror()
{
printf("\nThe Grammar is Invalid.\n");
exit(0);
}

