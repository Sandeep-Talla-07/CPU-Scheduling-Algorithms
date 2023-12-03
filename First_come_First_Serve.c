// The all proccesses are arrived at different time.

#include<stdio.h>

int main()
{
    int i, j, n = 3, min, temp;
    int pid[20] = {1, 2, 3},
        at[20] = {3, 1, 2},
        bt[20] = {15, 3, 3},
        wt[20], tat[20];

        for (i = 0; i < n-1; i++)
        {
            min = i;
            for(j = i+1; j < n; j++)
            {
                if(at[j] < at[min])
                {
                    min = j;
                }
            }

            temp = at[i];
            at[i] = at[min];
            at[min] = temp;

            temp = bt[i];
            bt[i] = bt[min];
            bt[min] = temp;

            temp = pid[i];
            pid[i] = pid[min];
            pid[min] = temp;
        }

        float avg_wating_time = 0;
        wt[0] = 0;
        for (i = 1; i < n; i++)
        {
            wt[i] = wt[i-1] + bt[i-1];
            avg_wating_time += wt[i];
        }

        float avg_turn_around_time = 0;
        for (i = 0; i < n; i++)
        {
            tat[i] = wt[i] + bt[i];
            avg_turn_around_time +=tat[i];
        }

        printf("\n\n");
        printf("\n\t\t\tAFTER CALCULATIONS\n");
        printf("==================================================================================\n");
        printf("| Proccess ID  |  Arrival Time  |  Burst Time  | Waiting Time | Turn Around Time |\n");   
        for (i = 0; i < n; i++)
        {
            printf("----------------------------------------------------------------------------------\n");
            printf("| P%d\t       | %d\t\t| %d\t       | %d            | %d\t\t |\n",pid[i], at[i], bt[i], wt[i], tat[i]);
        }
        printf("==================================================================================\n");
        
        printf("\nThe Average Waiting Time is: %f\n\n", avg_wating_time/n);
        printf("The Average Turn Around Time is: %f\n", avg_turn_around_time/n);
        
        printf("\n\n");
        return 0;
}