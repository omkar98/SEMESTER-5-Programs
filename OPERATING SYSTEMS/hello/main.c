#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void cal_avg_wait_time();
void gantt_chart(int []);
void gantt_chart_parts(int, int, char);

int n;
struct process
{
   int process_id;
   int arrival_time;
   int burst_time;
};

struct process p[MAX];

int main()
{
    int i;
    //float waiting_time;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        p[i].process_id = i;
        printf("Enter arrival time of Process %d: ", p[i].process_id);
        scanf("%d", &p[i].arrival_time);
    }
    for(i=0;i<n;i++)
    {
        printf("Enter burst time of Process %d: ", p[i].process_id);
        scanf("%d", &p[i].burst_time);
    }

    cal_avg_wait_time();
    return 0;
}

void cal_avg_wait_time()
{
    int i, waiting_time;
    int time_interval[n+1];
    /*time_interval stores the time values, when each process has finished execution.*/
    time_interval[0] = 0;
    for(i=0;i<n;i++)
    {
        time_interval[i+1] = time_interval[i] + p[i].burst_time;
        waiting_time = time_interval[i] - p[i].arrival_time;
        printf("\nWaiting Time of Process - %d: %d", p[i].process_id, waiting_time);
    }
    gantt_chart(time_interval);
}

void gantt_chart(int time_interval[])
{
    gantt_chart_parts(1,2,'-');
    gantt_chart_parts(2,4,' ');
    gantt_chart_parts(1,2,'-');
    printf("\n");
}

void gantt_chart_parts(int row, int scale, char print)
{
    int no,i,j;
    printf("\n");
    printf("|");
    for(int i=0;i<n;i++)
    {
        no=p[i].burst_time/scale;
        if(row==1 && no%2==1) no++;
        for(j=0;j<no;j++) printf("%c", print);
        if(row==2)
        {
            printf("P%d", p[i].process_id);
            for(j=0;j<no;j++) printf(" ");
        }
        printf("|");
    }
}
