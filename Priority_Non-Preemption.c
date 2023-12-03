// The arival time of all proccess are 0.

#include<stdio.h>
int main()
{
    int i, j, min, temp, n = 4;
    int pid[20] = {1, 2, 3, 4},
        bt[20] = {5, 7, 2, 3},
        priority[20] = {1, 6, 4, 5};

    // Lowest number is the highest priority
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i; j < n; j++) // If want highest number is the highest priority then change the sign to '>'
        {
            if(priority[j] < priority[min])
            {
                min = j;
            }
        }

        temp = priority[i];
        priority[i] = priority[min];
        priority[min] = temp;

        temp = bt[i];
        bt[i] = bt[min];
        bt[min] = temp;

        temp = pid[i];
        pid[i] = pid[min];
        pid[min] = temp;

    }
    
    printf("\n\t\tBEFORE CALCULATIONS\n");
    printf("==========================================\n");
    printf("| Proccess ID  |  Burst Time  |\tPriority |\n");
    for (i = 0; i < n; i++)
    {
        printf("------------------------------------------\n");
        printf("| %d\t       |  %d\t      |  %d\t |\n", pid[i], bt[i], priority[i]);
    }
    printf("==========================================\n");
    

    int waint_time = 0;

    printf("\n\t\t\t   AFTER CALCULATIONS\n");
    printf("=============================================================================\n");
    printf("| Proccess ID  | Burst Time  | Priority  |  Waiting_Time | Turn_Around_Time |\n");
    for(i =0 ; i<n; i++)
    {  
        printf("-----------------------------------------------------------------------------\n");
        printf("| %d\t       |  %d\t     |  %d\t |   %d\t         |  %d\t   \t    |\n", pid[i], bt[i], priority[i], waint_time, waint_time + bt[i]);
        waint_time = waint_time + bt[i];
    }
    printf("=============================================================================\n");
    printf("\n\n");
}