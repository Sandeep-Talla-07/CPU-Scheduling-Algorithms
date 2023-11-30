#include<stdio.h>
int main()
{
    int n = 4, i, j, min, temp;
    int total_tat = 0, total_wt = 0;
    int at[20] = {0, 0, 0, 0},
        bt[20] = {5, 4, 12, 7}, 
        pid[20] = {1, 2, 3, 4},
        wt[20], tat[20];

    // printf("Enter the number of processes: ");
    // scanf("%d",&n);

    // printf("\nEnter the burst time of processes: ");
    // for (i = 0; i < n; i++)
    // {
    //     scanf("%d", &bt[i]);
    //     at[i] = i+1;
    // }

    // for(i=0; i<n; i++)
    // {
    //     printf("%d ", at[i]);
    // }
    // Sorting the burst time in ascending order using selection sort
    for(i=0; i<n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
        {
            if(bt[j] < bt[min])
            {
                min = j;
            }
        }

        temp = bt[i];
        bt[i] = bt[min];
        bt[min] = temp;

        temp = pid[i];
        pid[i] = pid[min];
        pid[min] = temp;
        
    }

    wt[0] = 0;

    for(i = 1; i < n; i++)
    {
        wt[i] = 0;
        for(j = 0; j < i; j++)
        {
            wt[i] = wt[i] + bt[j];

            total_wt = total_wt + wt[i];
        }
    }

    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];

        total_tat = total_tat + tat[i]; 
    }

    printf("\n\nPID\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", pid[i],at[i], bt[i], wt[i], tat[i]);
    }

    printf("\n\nThe Total Turn Around Time is: %d", total_tat);
    printf("\n\nThe Total Waiting Time is: %d", total_wt);
    
    float avg_tat = total_tat / n;
    float avg_wt = total_wt / n;

    printf("\n\nThe Average Turn Around Time is: %f", avg_wt);
    printf("\n\nThe Average Waiting Time is: %f", avg_wt);
    printf("\n\n");

    

}
