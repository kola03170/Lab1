#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a[10];
    int i;

    srand(time(NULL));

    for (i = 0; i < 10; i++)
    {
        a[i] = rand() % 100;
    }

    printf("Massiv:\n");

    for (i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;

}
