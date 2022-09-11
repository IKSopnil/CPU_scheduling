#include<stdio.h>
#define max 30

int main()
{
    int burst_time[max],waiting_time[max],turnaround_time[max],i,j,n;
    float avg_turnaround_time=0,avg_waiting_time=0;

    printf("Enter total number of processes : ");
    scanf("%d", &n);

    printf("\nEnter Process Burst Time : \n");
    for(i=0; i<n; i++)
    {
        printf("P[%d] : ", i+1);
        scanf("%d", &burst_time[i]);
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    for(i=0; i<n; i++)
    {
        waiting_time[i]=0;
        for(j=0; j<i; j++)
        {
            waiting_time[i]+=burst_time[j];
        }
        turnaround_time[i]=burst_time[i]+waiting_time[i];
        avg_waiting_time=avg_waiting_time+waiting_time[i];
        avg_turnaround_time=avg_turnaround_time+turnaround_time[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,burst_time[i],waiting_time[i],turnaround_time[i]);
    }
    avg_waiting_time=avg_waiting_time/i;
    avg_turnaround_time=avg_turnaround_time/i;
    printf("\n\nAverage Waiting Time : %.3f",avg_waiting_time);
    printf("\nAverage Turnaround Time : %.3f\n",avg_turnaround_time);

    printf("\nGantt Chart: \n");
    printf(" ");
    for(i=0; i<n; i++)
    {
        for(j=0; j<burst_time[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
    for(i=0; i<n; i++)
    {
        for(j=0; j<burst_time[i] - 1; j++) printf(" ");
        printf("P%d", i+1);
        for(j=0; j<burst_time[i] - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    for(i=0; i<n; i++)
    {
        for(j=0; j<burst_time[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n");
    printf("0");
    for(i=0; i<n; i++)
    {
        for(j=0; j<burst_time[i]; j++) printf("  ");
        if(turnaround_time[i] > 9) printf("\b");
        printf("%d", turnaround_time[i]);

    }

}
