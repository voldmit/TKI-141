#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <float.h>
#include <locale.h>

/**
* @brief варианты уранения
*/
enum comparison
{
	moreequal,
	less
};

/**
* @brief Расчет значения функции по заданной формуле.
* @param a - константа.
* @param y - значение аргумента функции.
* @param z - значение аргумента функции.
* @return значение функции
*/
double get_Y(double x, double a, enum comparison b);

/**
* @brief считывает вещественное число
* @return вещественное число
*/
double input(void);

/**
* @brief выполняет задачу
* @return 0 в случае успеха, 1 в случае провала
*/
int main(void)
{
	setlocale(LC_ALL, "Rus");
	double a = 1.5;
	puts("Введите число:");
	double x = input();
	if ((a * x) < DBL_EPSILON)
	{
		errno = EDOM;
		perror("Функция не существует");
		return 1;
	}
	int b = ((a * x) >= (1.0 + DBL_EPSILON));
	printf_s("Функция равна %lf", get_Y(x, a, b));
	return 0;
}

double get_Y(double x, double a, enum comparison b)
{
	switch (b)
	{
	case less:
		return ((a * x) - log10(a * x));
	case moreequal:
		return ((a * x) + log10(a * x));
	}
}

double input(void)
{
	double num = 0.0;
	int p = scanf_s("%lf", &num);
	if (p == 0)
	{
		errno = EIO;
		perror("Ошибка ввода");
		exit(1);
	}
	return num;
}

