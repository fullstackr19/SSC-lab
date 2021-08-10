%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
void yyerror(const char *s);
%}

%token NUM
%left '+''-'
%left '*''/'
%nonassoc UMINUS

%%
expr:NUM { $$ = $1; yylval=$$;}
| expr'+'expr {$$=$1+$3; yylval=$$;}
| expr'-'expr {$$=$1-$3; yylval=$$;}
| expr'*'expr {$$=$1*$3; yylval=$$;}
| expr'/'expr {if($3==0) { printf("Error : Divided by zero.\n"); exit(0);}
		else{ $$=$1/$3; yylval=$$;}}
|'('expr')' {$$=$2;}
| '-'expr %prec UMINUS {$$=-$2;yylval=$$;}
;

%%

int main()
{
printf("Enter a expression to evaluate: \n");
yyparse();
printf("The expression is valid.\n");
printf("\nResult = %d\n\n",yylval);
exit(0);
}

void yyerror(const char *s)
{
printf("The expression is invalid.\n");
exit(0);
}
