#include<stdio.h>

int main()
{
	int choice;
	
	printf("Enter 1 for Round Robin Algorithm.\nEnter 2 for Shortest Remaining Time(SRT) Algorithm.\nEnter 3 to Exit.\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			printf("\n\n***Round Robin Algorithm***\n\n");
			roundRobin();
			break;
			
		case 2:
			printf("\n\n***Shortest Remaining Time(SRT) Algorithm***\n\n");
			srt();
			break;
			
		case 3:
			return 0;
			
		default:
			printf("Please enter a valid choice.\n");
	}
}



void roundRobin()
{
	int i, count, n, tq, temp1, sq=0, swt=0, stat=0;
	int st[10], tat[10], bt[10], wt[10];
	float awt=0.0, atat=0.0;
	
	printf("Enter the total number of processes : \n");
	scanf("%d",&n);
	
	printf("Enter the Time Quantum : \n");
	scanf("%d",&tq);
	
	printf("Enter the Burst Time for the %d processes :\n",n);
	for(i=0;i<n;i++)
	{
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
		printf("Average Waiting time is = %f \nAverage Turn Around Time = %f\n",awt,atat);
	}
	return 0;
}	

void srt()
{
	int at[10],bt[10],temp[10];
	int i,smallest,count=0,time,n;
	double wt=0,tt=0,end;
	float awt,att;
	
	printf("Enter the total number of processes : \n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter the arrival time : \n");
		scanf("%d",&at[i]);
		
		printf("Enter Burst Time :\n");
		scanf("%d",&bt[i]);
		
		temp[i]=bt[i];
	}
	
	bt[9]=9999;
	
	for(time=0;count!=n;time++)
	{
		smallest=9;
		for(i=0;i<n;i++)
		{
			if(at[i]<=time && bt[i]<bt[smallest] && bt[i]>0)
			{
				smallest=i;
			}
		}
		
		bt[smallest]--;
		
		if(bt[smallest]==0)
		{
			count++;
			end=time+1;
			wt=wt+end-at[smallest]-temp[smallest];
			tt=tt+end-at[smallest];
		}
	}
	
	awt=wt/n;
	att=tt/n;
	
	printf("Average Waiting Time : %.2f\n",awt);
	printf("Average Turnaround Time : %.2f\n",att);
	return 0;
}		
