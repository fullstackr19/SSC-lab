%{
#include<stdio.h>
#include<stdlib.h>
int com=0;
%}

%%
"/*"[a-zA-Z0-9' '\t\n]+"*/" {com++;}
"//"[^\n]+"//" {com++;}
"//".* {com++;}
%%

int main()
{
	yyin = fopen("Source.c","r");
	yyout = fopen("Destination.c","w");
	yylex();
	fclose(yyin);
	fclose(yyout);
	printf("Total number of comments in the given file = %d\n",com);
}
