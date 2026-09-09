#include "stdafx.h"
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
    scanf_s("%d", &n);

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
    int sumDiag = 0;
	int row, col;

    printf("Введите размерность квадратной матрицы:\n");
	scanf_s("%d", &size);

	matrix = (int**)malloc(size * sizeof(int*));
	if (matrix == NULL)
	{
		printf("Ошибка выделения памяти!\n");
		return 1;
	}

	for (row=0; row < size; row++)
	{
		matrix[row] = (int*)malloc(size * sizeof(int));
		if (matrix[row] == NULL)
		{
			printf("Ошибка выделения памяти!\n");
			for (int k = 0; k < i; k++)
				free(matrix[k]);
			free(matrix);
			return 1;
		}
	}

	srand((unsigned)time(NULL));

	printf("\nСгенерированная матрица %dx%d:\n", size, size);
	for (i = 0; i < size; i++)
	{
		for(j=0; j < size; j++)
		{
			matrix[i][j] = rand() % 31 - 10;
			printf("%4d ", matrix[i][j]);
		}
		printf("\n");
	}

	sum = 0;
	for (i=0; i < size; i++)
	{
		sum += matrix[i][j];

		for (j = i + 1; j < size; j++)
		{
			sum += matrix[i][j];
		}
	}

	printf("\nСумма элементов главной диагонали и выше: %d\n", sum);

	for (i = 0, j < size; i++)
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
    } stud[3];

    char search[20];
    int found = 0;

    printf("Введите данные о 3 студентах:\n\n");

    for (i = 0; i < 3; i++)
    {
        printf("Студент %d:\n", i + 1);

        printf("  Фамилия: ");
        scanf_s("%19s", stud[i].famil, 20);

        printf("  Имя: ");
        scanf_s("%19s", stud[i].name, 20);

        printf("  Факультет: ");
        scanf_s("%19s", stud[i].facult, 20);

        printf("  Номер зачётной книжки: ");
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
            printf("  Фамилия: %s\n", stud[i].famil);
            printf("  Имя: %s\n", stud[i].name);
            printf("  Факультет: %s\n", stud[i].facult);
            printf("  Номер зачётной книжки: %d\n", stud[i].Nomzach);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nСтудент с фамилией '%s' не найден.\n", search);
    }

    printf("\n\nПрограмма завершена.\n");

    return 0;
}
# дополнить 4 задание, спрашиваем размерность квадратной матрицы, динамически выделяем память. Заполняем матрицу элементами в диапазоне -10 до 20. Найти сумму элементов располагающихся на и выше главной диагонали.
# дополнить 5 задание, спрашиваем колво записей, динамически выделяем память и осуществляем поиск по неполному совпадению заданной строки по всем параметрам
