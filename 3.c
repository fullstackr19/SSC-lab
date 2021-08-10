/* Program to construct Predictive/LL(1) Parsing Table
   for the grammar rules : A->aBa, B->bB|@. (Note - @ is empty string)
   Use the table to parse the sentence: abba$
*/

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

char prod[3][10]={"A->aBa", "B->bB", "B->@"}; //Note - @ is considered to be the empty string.
char input[10], stack[25];

int top=-1;
int j=0,k,l;

//Push function for the stack
void push(char item){
	stack[++top]=item;
}

//Pop function for the stack
void pop(){
	top=top-1;
}

//Function to display the stack
void display(){
	int j;	
	for(j=top;j>=0;j--)
		printf("%c",stack[j]);
}

void stackpush(char p){
	if(p=='A'){
		pop();
		for(j=strlen(prod[0])-1; j>=3; j--)
			push(prod[0][j]);
	} else {
		pop();
		for(j=strlen(prod[1])-1; j>=3; j--)
			push(prod[1][j]);
	}
}

void main(){
	char c;
	int i;
	
	printf("Enter the input string terminated with $ to parse: ");
	scanf("%s",&input);
	
	for(i=0;input[i]!='\0';i++){
		if((input[i] != 'a') && (input[i] != 'b') && (input[i] != '$')){
			printf("Invalid String.\n");
			exit(0);
		}
	}
	
	if(input[i-1] != '$'){
		printf("\n Input String is enetred without the end marker $.\n");
		exit(0);
	}
	
	push('$');
	push('A');
	
	i=0;
	
	printf("\n\n");
	printf("Stack\tInput\tAction\n");
	
	while(i != strlen(input) && stack[top] != '$'){
		printf("\n");
		for(l=top; l>=0; l--)
			printf("%c",stack[l]);
		printf("\t");
		
		for(l=i; l<strlen(input); l++)
			printf("%c",input[l]);
		printf("\t");
		
		if(stack[top] == 'A'){
			printf("A->aBa");
			stackpush('A');
		} else if(stack[top] == 'B'){
			if(input[i] != 'b'){
				printf("B->@");
				printf("\t Matched @");
				pop();
			} else {
				printf("B->bB");
				stackpush('B');
			}
		} else {
			if(stack[top] == input[i]){
				printf("Pop %c",input[i]);
				printf("\t Matched  %c",input[i]);
				pop();
				i++;
			}
			else
				break;
		}
	}
	
	if(stack[top] == '$' && input[i] == '$'){
		printf("\n$\t$");
		printf("\nThe string is VALID and it is ACCEPTED.\n");
	} else
		printf("\nThe string is INVALID and thus is REJECTED.\n");
}
	

			
