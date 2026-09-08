#include <stdio.h>

int main()
{
    int a[3][4];
    int i, j;
    int sum;

        printf("Vvedite elementi massiva 3x4:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf_s("%d", &a[i][j]);
        }
    }

    printf("\nSumma kazhdogo stolbca:\n");

    for (j = 0; j < 4; j++)
    {
        sum = 0;

        for (i = 0; i < 3; i++)
        {
            sum = sum + a[i][j];
        }

        printf("Stolbec %d: %d\n", j, sum);
    }

    return 0;

}
