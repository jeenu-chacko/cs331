/** 
 * @file program 1/sjf.c
 * @author Jeenu Chacko
 * 
 * cs331 System Software Lab 
 * 
 * Implementation of priority scheduling algorithm
 * CPU Scheduling Algorithm for finding turnaround time and waiting time.
 *  
 */



#include<stdio.h>

struct process 
{ 
 int pin; 
 int burst_time;
 int arrival_time;
 int c_time;
 float tat;
 float wt;
 int pr;
}p[20],temp,wt;


int main()
{
int i,j,n,flag=0,k,z,x;
float avg_wt=0,avg_tat=0;
	
	printf("Enter the no of process");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	printf("Enter the process id ");
	scanf("%d",&p[i].pin);
	printf("Enter the process arival time (ms) ");
	scanf("%d",&p[i].arrival_time);
	printf("Enter the process burst time (ms) ");
	scanf("%d",&p[i].burst_time);
	printf("Enter the process priority(eg:priority 1>priority 2) ");
	scanf("%d",&p[i].pr);
	p[i].c_time=0;
	
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
		p[i].c_time=p[i].burst_time+p[i].arrival_time;
		}	
		
		else
		{
		




	for(k=i;k<n-1;k++)
	{
		
		for(j=i+1;j<n;j++)
		{
			if((p[k].pr > p[j].pr) && (p[k].arrival_time <= p[i-1].c_time) && (p[j].arrival_time <= p[i-1].c_time) && (p[k].c_time==0) && (p[j].c_time==0))
			{
			temp = p[j];
			p[j] = p[k];
			p[k] = temp;
			
			}
			if((p[k].pr==p[j].pr) && (p[k].arrival_time <= p[i-1].c_time) && (p[j].arrival_time <= p[i-1].c_time) && (p[k].c_time==0) && (p[j].c_time==0))
			{
				if(p[k].arrival_time>p[j].arrival_time)
					{
					temp = p[j];
					p[j] = p[k];
					p[k] = temp;
					}				
				
			
			}
				
			
			
		}
	}







		p[i].c_time=p[i-1].c_time+p[i].burst_time;



		}



	
	}	


	for(i=0;i<n;i++)
	{	
	printf("%d %d\n",p[i].pin,p[i].c_time);
	}
	


	printf("\n\n");
	printf("\tProcess\t\tTurn around time\tWaiting Time\n\n");

	for(i=0;i<n;i++)
	{	p[i].tat=p[i].c_time-p[i].arrival_time;
		avg_tat=avg_tat+p[i].tat;
		p[i].wt = p[i].tat-p[i].burst_time;
		avg_wt=avg_wt+p[i].wt;
		printf("\t%d \t\t %f \t \t%f\n",p[i].pin,p[i].tat,p[i].wt);
		printf("\n");
	}
	printf("\n");

	printf("Average waiting time is %f\n",avg_wt/n);
	printf("Average turn around time is %f\n",avg_tat/n);
	
	
return 0;
}
