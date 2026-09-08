#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* a;
    int n;
    int i;

        printf("Vvedite razmer massiva: ");
    scanf_s("%d", &n);

    a = (int*)malloc(n * sizeof(int));

    if (a == NULL)
    {
        printf("Oshibka vydeleniya pamyati!\n");
        return 1;
    }

    printf("Vvedite elementi massiva:\n");

    for (i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf_s("%d", &a[i]);
    }

    printf("\nMassiv:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    free(a);

    return 0;

}

