#include<stdio.h>
#include<string.h>

int k=0,z=0,i=0,j=0,c=0;
char str[20], ac[20], stk[20], act[20];

void check();

void main() {
	puts("Grammar is \n E->E+E \n E->E*E \n E->(E) \n E->id");
	puts("Enter the input string");
	gets(str);
	
	puts("\nStack \t\t Input \t\t Action");
	c=strlen(str);
	strcpy(act,"SHIFT->");
	for(k=0,i=0; j<c; k++,i++,j++){
		if(str[j]=='i' && str[j+1]=='d'){
			stk[i]=str[j];
			stk[i+1]=str[j+1];
			stk[i+2]='\0';
			str[j]=' ';
			str[j+1]=' ';
			printf("$%s\t%s$\t%sid\n",stk,str,act);
			check();
		} else {
			stk[i]=str[j];
			stk[i+1]='\0';
			str[j]=' ';
			printf("$%s\t%s$\t%ssymbols\n",stk,str,act);
			check();
		}
	}
	
	printf("\n");
}


void check() {
	strcpy(ac,"REDUCE TO E");
	for(z=0; z<c; z++)
		if(stk[z] == 'i' && stk[z+1] == 'd'){
			stk[z] = 'E';
			stk[z+1] = '\0';
			printf("$%s\t%s$\t%s\n",stk,str,ac);
			j++;
		}
	for(z=0; z<c; z++)
		if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='E'){
			stk[z]='E';stk[z+1]='\0';
			stk[z+2]='\0';
			printf("$%s\t%s$\t%s\n",stk,str,ac);
			i=i-2;
		}
		
	for(z=0; z<c; z++)
		if(stk[z]=='E' && stk[z+1]=='*' && stk[z+2]=='E'){
			stk[z]='E';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("$%s\t%s$\t%s\n",stk,str,ac);
			i=i-2;
		}
		
	for(z=0; z<c; z++)
		if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')'){
			stk[z]='E';
			stk[z+1]='\0';
			stk[z+1]='\0';
			printf("$%s\t%s$\t%s\n",stk,str,ac);
			i=i-2;
		}
}
