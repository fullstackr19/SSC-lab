#include<stdio.h>

int main()
{
	int i, count, n, tq, temp1, sq=0, swt=0, stat=0;
	int st[10], tat[10], bt[10], wt[10];
	float awt=0.0, atat=0.0;
	
	printf("Enter the total number of processes : \n");
	scanf("%d",&n);
	
	printf("Enter the Time Quantum : \n");
	scanf("%d",&tq);
	
	for(i=0;i<n;i++)
	{
		printf("Enter Burst Time :\n");
		scanf("%d",&bt[i]);
		st[i]=bt[i];
		
	}
	
while(1)
{ 
	for(i=0,count=0;i<n;i++)
	{
		temp1=tq;
		if(st[i]==0)
		{
			count++;
			continue;
		}
		
		if(st[i]>tq)
			st[i]=st[i]-tq;
		else
			if(st[i]>=0)
			{
				temp1=st[i];
				st[i]=0;
			}
			
		sq=sq+temp1;			
		tat[i]=sq;
	}
	
	if(n==count)
		break;
}

for(i=0;i<n;i++)
{
	wt[i]=tat[i]-bt[i];
	swt=swt+wt[i];
	stat=stat+tat[i];
}

awt=(float)swt/n;
atat=(float)stat/n;
printf("Process No.	Burst Time	Wait Time	Turn Around Time\n");
for(i=0;i<n;i++)
{
	printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
	printf("Average Waiting time is = %f \n Average Turn Around Time = %f\n",awt,atat);
}
return 0;
}	
