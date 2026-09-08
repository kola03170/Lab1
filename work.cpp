#include <stdio.h>
#include <windows.h>
int main(void)
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int a[10];
    int i;
    int max, min;

        printf("Введите 10 элементов массива:\n");

    for (i = 0; i < 10; i++)
    {
        printf("a[%d] = ", i);
        scanf_s("%d", &a[i]);
    }

    max = a[0];
    min = a[0];

    for (i = 1; i < 10; i++)
    {
        if (a[i] > max)
            max = a[i];

        if (a[i] < min)
            min = a[i];
    }

    printf("\nMax = %d\n", max);
    printf("Min = %d\n", min);
    printf("Raznica = %d\n", max - min);

    return 0;

}
