// All Proccess are arrived at '0' time

#include<stdio.h>
int main()
{
    int i, j, n = 3;
    int bt[20] = {24, 3, 4},
        pid[20] = {1, 2, 3},
        wt[20], tat[20];

    wt[0] = 0;
    float avg_wating_time = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        avg_wating_time += wt[i];
    }

    float avg_turn_around_time = 0;
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avg_turn_around_time += tat[i];
    }
    
    printf("\n\n");
    printf("\n\t\t\tAFTER CALCULATIONS\n");
    printf("=================================================================\n");
    printf("| Proccess ID  |  Burst Time  | Waiting Time | Turn Around Time |\n");
    for (i = 0; i < n; i++)
    {
        printf("-----------------------------------------------------------------\n");
        printf("| %d\t       |  %d\t      |  %d\t     |  %d\t\t|\n", pid[i], bt[i], wt[i], tat[i]);
    }
    printf("=================================================================\n");

    printf("\nAverage Waiting Time: %f\n\n", avg_wating_time/n);
    printf("Average Turn Around Time: %f\n", avg_turn_around_time/n);  

    printf("\n\n");  
    return 0;
}