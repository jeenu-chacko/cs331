#include<stdio.h>
#include<string.h>
struct address 
{ 
 int pin; 
 int burst_time;
 int arrival_time;
 int c_time;
 float tat;
 float wt;
}p[20],temp,wt;

int main()
{
int i,a[20],j,n;
float avg_wt=0,avg_tat=0;
	
	printf("Enter the no of process");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("enter the process id");
	scanf("%d",&p[i].pin);
	printf("enter the process arival time (ms) ");
	scanf("%d",&p[i].arrival_time);
	printf("enter the process burst time (ms) ");
	scanf("%d",&p[i].burst_time);
	
	}

	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].arrival_time > p[j].arrival_time)
			{
			temp = p[j];
			p[j] = p[i];
			p[i] = temp;
			}	
			else if(p[i].arrival_time==p[j].arrival_time)
			{
				if(p[i].burst_time > p[j].burst_time)
				{
					temp = p[j];
					p[j] = p[i];
					p[i] = temp;
				}

			}
		}
	}



	for(i=0;i<n;i++)
	{		
			if(i==0)
			{
			p[i].c_time=p[i].burst_time;
			}	
			else
			{
			p[i].c_time=p[i-1].c_time+p[i].burst_time;
			}
	
	}

	

	printf("\n\n");
	printf("First Come First Serve\n\n");
	printf("\tProcess\t\tTurn around time\tWaiting Time\n\n");

	for(i=0;i<5;i++)
	{	p[i].tat=p[i].c_time-p[i].arrival_time;
		avg_tat=avg_tat+p[i].tat;
		p[i].wt = p[i].tat-p[i].burst_time;
		avg_wt=avg_wt+p[i].wt;
		printf("\t%d \t\t %f \t \t%f\n",p[i].pin,p[i].tat,p[i].wt);
		printf("\n");
	}
	printf("\n");

	printf("Average waiting time is %f\n",avg_wt/5);
	printf("Average turn around time is %f\n",avg_tat/5);
	
	
return 0;
}
