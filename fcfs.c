#include<stdio.h>
int main()
{
    int n,bt[20],wt[20],tat[20],total=0,i,j;
    float avwt,avtat;
    printf("Enter total number of processes: ");
    scanf("%d",&n);

    printf("\nEnter Process Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]: ",i+1);
        scanf("%d",&bt[i]);
    }

    wt[0]=0;    //waiting time for first process is 0

     //calculating waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        total=total+wt[i];
    }
    avwt=total/n;
    total=0;

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        total=total+tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }

    avtat=total/n;
    printf("\n\nAverage Waiting Time:%f",avwt);
    printf("\nAverage Turnaround Time:%f",avtat);
    printf("\n\n");

       return 0;
       }
