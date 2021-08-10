#include<stdio.h>
#include<stdlib.h>

int available[10], allocation[10][10], max[10][10], need[10][10], c[10], i, j, k, l=0, n, r, seq[10];

int grant()
{
	int x;
	for(x=0;x<r;x++)
	{
		if(!(need[i][x]<=available[x]))
			return 0;
	}
	
	return 1;
}

void insert(int ele)
{
	seq[l++]=ele;
}

void display()
{
	printf("Safe Sequence: <");
	for(i=0;i<l;i++)
	printf("%d,", seq[i]);
	printf("%d>\n",seq[i]);
	
}

int main(int argc, char *argv[])
{
	int sum,p[i],z=0,allow;
	
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	
	printf("Enter the number of resources: ");
	scanf("%d", &r);
	
	printf("Enter the Resource(i.e., Available) matrix:\n");
	for(i=0;i<r;i++)
		scanf("%d", &available[i]);
	
	printf("Enter the Allocation matrix: \n");
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d", &allocation[i][j]);
		}
	}
	
	printf("Enter the Maximum matrix \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d", &max[i][j]);
			need[i][j]=max[i][j]-allocation[i][j];
		}
	}
	
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			allow=grant();
			if(allow!=0 && p[i]!=1)
			{
				insert(i);
				p[i]=1;
				for(j=0;j<r;j++)
				{
					available[j]=available[j]+allocation[i][j];
				}
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		if(p[i]==0)
		{
			printf("Unsafe State\n");
			exit(0);
		}
	}
	
	printf("Safe State\n");
	display();
	return 0;
}
