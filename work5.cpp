#include <stdio.h>
#include <string.h>
#include <windows.h>

int main(void)
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int i;
    char search[20];
    int found = 0;

    struct student
    {
        char famil[20];
        char name[20];
        char facult[20];
        int Nomzach;
    } stud[3];

    for (i = 0; i < 3; i++)
    {
        printf("Введите фамилию студента: ");
        scanf_s("%19s", stud[i].famil, 20);

        printf("Введите имя студента: ");
        scanf_s("%19s", stud[i].name, 20);

        printf("Введите факультет: ");
        scanf_s("%19s", stud[i].facult, 20);

        printf("Введите номер зачётной книжки: ");
        scanf_s("%d", &stud[i].Nomzach);

        printf("\n");
    }

    printf("Введите фамилию для поиска: ");
    scanf_s("%19s", search, 20);

    for (i = 0; i < 3; i++)
    {
        if (strcmp(stud[i].famil, search) == 0)
        {
            printf("\nСтудент найден:\n");
            printf("Фамилия: %s\n", stud[i].famil);
            printf("Имя: %s\n", stud[i].name);
            printf("Факультет: %s\n", stud[i].facult);
            printf("Номер зачётной книжки: %d\n", stud[i].Nomzach);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nСтудент не найден.\n");
    }

    return 0;
}