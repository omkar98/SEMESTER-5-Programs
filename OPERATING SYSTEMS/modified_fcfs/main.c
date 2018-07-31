#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 5

void cal_avg_wait_turn_time();
void gantt_chart(int []);
//void gantt_chart_parts(char, int, int, char, char);

int n;
struct process
{
   int process_id;
   int arrival_time;
   int burst_time;
};

struct process p[MAX];

struct chart
{
    int time;
    char type;
};
struct chart c[2*MAX];

int main()
{
    int i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        p[i].process_id = i;
        printf("Process P[%d]", p[i].process_id);
        printf("\n\tArrival Time :  ", p[i].process_id);
        scanf("%d", &p[i].arrival_time);
        printf("\tBurst Time : ", p[i].process_id);
        scanf("%d", &p[i].burst_time);
    }
    cal_avg_wait_turn_time();
    return 0;
}

void cal_avg_wait_turn_time()
{
    int i,j=1;
    printf("|\tProcess ID\t| Arrival  Time | Burst    Time | Wait     Time |Turn Around Time|\n ");
    if(p[0].arrival_time!=0)
    {
       c[0].time = 0;
       c[0].type = 'x';
    }
    for(i=0;i<n;i++)
    {
        printf("|\tProcess %2d\t|",p[i].process_id);


        //time_interval[i+1] = time_interval[i] + p[i].burst_time;
        //waiting_time[i] = time_interval[i] - p[i].arrival_time;
        //turn_around[i] = time_interval[i+1] - p[i].arrival_time;

        if((p[i].arrival_time + p[i].burst_time)<p[i+1].arrival_time)
        {
            c[j].time = p[i].arrival_time;
            c[j].type = 'p';
            j++;
            c[j].time = p[i].arrival_time + p[i].burst_time;
            c[j].type = 'x';
            j++;
        }
        else
        {
            if((p[i-1].arrival_time + p[i-1].burst_time)<p[i].arrival_time)
            {
                c[j].time = p[i].arrival_time;
                c[j].type = 'p';
                j++;
            }
            c[j].time = c[j-1].time + p[i].burst_time;
            c[j].type = 'p';
            j++;
        }
/*
        printf("\t%2d\t|",p[i].arrival_time);
        printf("\t%2d\t|",p[i].burst_time);
        printf("\t%2d\t|",waiting_time[i]);
        printf("\t%2d \t|\n",turn_around[i]);
*/
    }
    //gantt_chart(time_interval);

    for(i=0;i<j;i++)
    {
        printf("\n%d | ", i);
        printf(" c[%d].time = %d | ",i,c[i].time);
        printf("c[%d].type = %c\n",i,c[i].type);

    }
}

void gantt_chart(int time_interval[])
{
}
