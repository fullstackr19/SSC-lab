%{
#include<stdio.h>
int id=0,op=0,br=0;
%}

%%
[a-zA-Z0-9]+ {id++; printf("\nThe identifier is :\n"); ECHO;}

[+|*|/|-]+ {op++; printf("\nThe operator is : \n"); ECHO;}

"(" {br++;}
")" {if(br==0) {br=1; return 0;} else br--;}
%%

int main()
{
printf("Enter the expression :\n");
yylex();
if((op+1)==id && br==0)
{
printf("Expression is valid. \n");
printf("Total number of identifiers are = %d \n",id);
printf("Total number of operators are = %d \n",op);
}
	
else
printf("Invalid Expression. \n");
}
