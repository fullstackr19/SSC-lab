#include<stdio.h>
int main()
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
