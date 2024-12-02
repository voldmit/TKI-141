#include <stdio.h>
#include <math.h> 
#include <errno.h>
#include <locale.h>

/**
* @brief вычисл¤ет функцию
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
		errno = EIO;
		perror("Функцию не протубулировать на данном отрезке");
		return 1;
	}
	else
	{
		for (x ; y >= x; x += 0.1)
		{
			printf(" x = %lf || y = %lf\n", x, fun(x));

		}
		return 0;
	}

}

double fun(const double x)
{
	return sqrt(1 - x) - cos(sqrt(1 - x));
}

double input(void)
{
	double num = 0.0;
	scanf_s("%lf", &num);
	return num;
}
