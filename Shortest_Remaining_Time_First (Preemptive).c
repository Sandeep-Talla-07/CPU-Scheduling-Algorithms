#include<stdio.h>
int main()
{
    int i, smallest, time, n =4;
    int completionTime, remain = 0;
    int pid[20] = {1, 2, 3, 4}, at[20] = {0, 1, 2, 3}, bt[20] = {3, 1, 1, 2}, rt[20] = {3, 1, 1, 2};

    printf("\nEnter the no of proccess: ");
    scanf("%d", &n);

    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time of proccess P%d: ", i+1);
        scanf("%d", &at[i]);
        printf("\nEnter the burst time of each process P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
        pid[i] = i+1;
        printf("\n");
    }
    
    // printf("AT\tBT\t\tProcess ID\t TAT\t WT\t\n");
    printf("\t\tThe Initial Table\n");
    printf("===========================================\n");
    printf("| Proccess   |  Arival Time |  Burst Time |\t \n");
    for (i = 0; i < n; i++)
    {
        printf("-------------------------------------------\n");
        printf("| %d\t     | \t%d\t    |\t%d   \t  |\n",pid[i], at[i], bt[i]);
    }
    printf("===========================================\n");
    
    // printf("%d");
    
    printf("\n\t\tAfter Culculating\n");
    printf("==============================================\n");
    printf("| Proccess ID   |  Arival Time  |  Burst Time|\n");
    for (time = 0; remain != n; time++)
    {
        for (i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i])
            {
                smallest = i;
            }
        }

        rt[smallest]--;
        if(rt[smallest] == 0)
        {
            remain++;
            completionTime = time + 1;
            printf("----------------------------------------------\n");
            printf("| P%d\t\t|  %d\t\t|  %d \t     |\n", smallest+1, completionTime - at[smallest], completionTime - bt[smallest] - at[smallest]);
        }
        
    }
    printf("==============================================\n");
    
    printf("\n\n");
    
}