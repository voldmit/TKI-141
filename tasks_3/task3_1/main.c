#include <float.h>
#include <stdio.h>
#include <math.h> 
#include <errno.h>
#include <locale.h>
#include <stdlib.h>

/**
* @brief вычисляет функцию
* @param x - вещественное число
* @return результат функции
*/
double fun(const double x);

/**
* @brief считывает вещественное число
* @return вещественное число
*/
double input(void);

/**
* @brief выполняет задачу
* @return 0 в случае успеха
*/
int main(void)
{
	setlocale(LC_ALL, "Rus");
	puts("Введите начало последовательности:");
	double x1 = input();
	if (x1 >= 1 + DBL_EPSILON)
	{
		errno = EDOM;
		perror("Функцию не протубулировать на данном отрезке");
		return 1;
	}
	puts("\nВведите конец последовательности:");
	double x2 = input();
	if (x1 > x2)
	{
		errno = EDOM;
		perror("Введен несуществующий отрезок");
		return 1;
	}
	puts("\nВведите шаг:");	
	double z = input();
	if (z <= DBL_EPSILON)
	{
		errno = EDOM;
		perror("Шаг должен быть строго положительным");
		return 1;
	}
	
	for (x1; x2 >= x1 + DBL_EPSILON ; x1 += z)
	{
		if (fun(x1) != fun(x1))
		{
			puts("Дальнейшие значения не существуют");
			break
		}
		printf(" x = %lf || y = %lf\n", x1, fun(x1));
		
	}
	return 0;

		
}

double fun(const double x1)
{
	return sqrt(1 - x1) - cos(sqrt(1 - x1));
}

double input(void)
{
	double number = 0.0;
	if (scanf_s("%lf", &number) != 1)
	{
		errno = EIO;
		perror("Введено неверное значение");
		exit(1);
	}
	return number;
}
