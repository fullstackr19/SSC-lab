%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
void yyerror(const char *s);
int id=0,op=0,key=0;
%}

%token ID OP KEY

%%
prog: ID prog{++id;}
|OP prog{++op;}
|KEY prog{++key;}
|ID {++id;}
|OP{++op;}
|KEY{++key;}
;
%%

extern FILE*yyin;

int main()
{
yyin = fopen("Source.c","r");
yyparse();
printf("Identifier : %d\n",id);
printf("Operator :%d\n",op);
printf("Keyword : %d\n",key);
return 0;
}

void yyerror(const char *s)
{
printf("Some Error Occured.\n");
exit(0);
}

