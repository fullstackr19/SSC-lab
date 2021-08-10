//Input File for 6a Lab Program

#include<stdio.h>

int main()
{
/*Sample C program to
  multiply 2 numbers*/

	int a,b,res; //Required Variables//
	printf("Enter the Multiplicand : "); 
	scanf("%d",&a);


	printf("\nEnter the Multiplier : ");
	scanf("%d",&b);
	
	res = a*b;
	
	printf("\nResult = %d\n", res); /*Prints The result*/ 
	
	return 0;
}


