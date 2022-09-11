#include<stdio.h>
#define max 30

int main()
{
    int arrival_time[max],burst_time[max],rt[max],endTime,i,smallest;
    int remain=0,n,time,sum_wait=0,sum_turnaround=0;

    printf("Enter no of Processes : ");
    scanf("%d",&n);

    printf("Enter Process Arrival Time : \n");
      for(i = 0; i < n; i++)
      {
            printf("P[%d] : ", i+1);
            scanf("%d", &arrival_time[i]);
      }

    printf("Enter Process Burst Time : \n");
      for(i = 0; i < n; i++)
      {
            printf("P[%d] : ", i+1);
            scanf("%d", &burst_time[i]);
            rt[i]=burst_time[i];
    }

    printf("\n\nProcess\t|Turnaround Time| Waiting Time\n");
    rt[9]=999;

    for(time=0; remain!=n; time++)
    {
        smallest=9;
        for(i=0; i<n; i++)
        {
            if(arrival_time[i]<=time && rt[i]<rt[smallest] && rt[i]>0)
            {
                smallest=i;
            }
        }

        rt[smallest]--;
        if(rt[smallest]==0)

        {
            remain++;
            endTime=time+1;
            printf("\nP[%d]\t|\t%d\t|\t%d",smallest+1,endTime-arrival_time[smallest],
                   endTime-burst_time[smallest]-arrival_time[smallest]);
            sum_wait+=endTime-burst_time[smallest]-arrival_time[smallest];
            sum_turnaround+=endTime-arrival_time[smallest];
        }
    }
    printf("\n\nAverage waiting time = %.3f\n",(float)sum_wait/n);
    printf("Average Turnaround time = %.3f",(float)sum_turnaround/n);
    return 0;

}
