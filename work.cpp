#define _CRT_SECURE_NO_WARNINGS // Required for scanf in Visual Studio
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ============ ЗАДАНИЯ 1-3 ============
    printf("\n========== ЗАДАНИЯ 1-3 ==========\n");

    int* a;
    int n;
    int i;
    int max, min;

    printf("Введите размер массива: ");
    scanf("%d", &n);

    a = (int*)malloc(n * sizeof(int));

    if (a == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    srand((unsigned)time(NULL));

    printf("\nСгенерированный массив:\n");
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    printf("\n");

    max = a[0];
    min = a[0];

    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];

        if (a[i] < min)
            min = a[i];
    }

    printf("\nМаксимальный элемент: %d\n", max);
    printf("Минимальный элемент: %d\n", min);
    printf("Разница (max - min) = %d\n", max - min);

    free(a);

    // ============ ЗАДАНИЕ 4 ============
    printf("\n\n========== ЗАДАНИЕ 4 ==========\n");

    int** matrix;
    int size;
    int sum = 0;
    int row, col, j; // Added j and col here

    printf("Введите размерность квадратной матрицы: ");
    scanf("%d", &size);

    matrix = (int**)malloc(size * sizeof(int*));
    if (matrix == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    for (row = 0; row < size; row++)
    {
        matrix[row] = (int*)malloc(size * sizeof(int));
        if (matrix[row] == NULL)
        {
            printf("Ошибка выделения памяти!\n");
            for (int k = 0; k < row; k++)
                free(matrix[k]);
            free(matrix);
            return 1;
        }
    }

    srand((unsigned)time(NULL));

    printf("\nСгенерированная матрица %dx%d:\n", size, size);
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            matrix[i][j] = rand() % 31 - 10; // Range -10 to 20
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Calculate sum of elements on and above the main diagonal
    sum = 0;
    for (i = 0; i < size; i++)
    {
        for (j = i; j < size; j++) // j starts from i (main diagonal) to end of row
        {
            sum += matrix[i][j];
        }
    }

    printf("\nСумма элементов главной диагонали и выше: %d\n", sum);

    // Free matrix memory correctly
    for (i = 0; i < size; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    printf("\n");

    // ============ ЗАДАНИЕ 5 ============
    printf("\n\n========== ЗАДАНИЕ 5 ==========\n");
    struct student
    {
        char famil[20];
        char name[20];
        char facult[20];
        int Nomzach;
    };

    int count; // Renamed to avoid conflict with previous 'n'
    int found = 0;
    char search[20];

    printf("Введите количество студентов: ");
    scanf("%d", &count);

    struct student* stud;

    stud = (struct student*)malloc(count * sizeof(struct student));

    if (stud == NULL)
    {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    printf("\nВведите данные о студентах:\n\n");

    for (i = 0; i < count; i++)
    {
        printf("Студент %d:\n", i + 1);

        printf("  Фамилия: ");
        scanf("%19s", stud[i].famil); // scanf_s not strictly needed here if _CRT_SECURE_NO_WARNINGS is defined

        printf("  Имя: ");
        scanf("%19s", stud[i].name);

        printf("  Факультет: ");
        scanf("%19s", stud[i].facult);

        printf("  Номер зачётной книжки: ");
        scanf("%d", &stud[i].Nomzach);

        printf("\n");
    }

    printf("Введите строку для поиска: ");
    scanf("%19s", search);

    for (i = 0; i < count; i++)
    {
        char nomzach[20];

        sprintf(nomzach, "%d", stud[i].Nomzach);

        if (strstr(stud[i].famil, search) != NULL ||
            strstr(stud[i].name, search) != NULL ||
            strstr(stud[i].facult, search) != NULL ||
            strstr(nomzach, search) != NULL)
        {
            printf("\nСтудент найден:\n");
            printf("  Фамилия: %s\n", stud[i].famil);
            printf("  Имя: %s\n", stud[i].name);
            printf("  Факультет: %s\n", stud[i].facult);
            printf("  Номер зачётной книжки: %d\n", stud[i].Nomzach);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nСовпадений не найдено.\n");
    }

    free(stud);

    printf("\nПамять освобождена.\n");

    return 0;
}
