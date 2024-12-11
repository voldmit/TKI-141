#include <stdio.h>
#include <math.h> 
#include <errno.h>
#include <locale.h>
#include <stdlib.h>

/**
* @brief вычисл¤ет функцию
* @param x - вещественное число
* @return результат функции
*/
double fun(const double x);

/**
* @brief считывает вещественное число
* @remarks Экстренно завершает работу программу в случае неправильного ввода.
* @return вещественное число
*/
double input(void);

/**
* @brief выполн¤ет задачу
* @return успешность задачи
*/
int main(void)
{
	setlocale(LC_ALL, "Rus");
	puts("Введите начало последовательности");
	double x = input();
	puts("\nВведите конец последовательности");
	double y = input();

	if (x > 1)
	{
		errno = EDOM;
		perror("Функцию не протабулировать на данном отрезке");
		return 1;
	}
	if (x > y)
	{
		errno = EDOM;
		perror("Введен несуществующий отрезок");
		return 1;
	}
	for (x; y >= x; x += 0.1)
	{
		printf(" x = %lf || y = %lf\n", x, fun(x));
	}
	return 0;
	

}

double fun(const double x)
{
	return sqrt(1 - x) - cos(sqrt(1 - x));
}

double input(void)
{
	double num = 0.0;
	if (scanf_s("%lf", &number) != 1))
	{
		errno = EIO;
		perror("Введено неверное значение");
		exit(1);
	}
	return num;
}
