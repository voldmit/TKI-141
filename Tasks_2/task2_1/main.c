#include <stdio.h>
#include <errno.h>
#include <locale.h>

/**
* @brief Расчитывает ззначание числа увеличенного в несколько раз.
* @param a - число.
* @param b - коэффициент.
* @return значение a увеличенного в b раз
*/
double getn(const double a, const double b);

/**
* @brief считывает вещественное число
* @return вещественное число
*/
double Input(void);

main(void)
{
	setlocale(LC_ALL, "Rus");
	puts("Пожалуйста введите число: ");
	double a = Input();
	printf("Пожалуйста введите значение во сколько раз(в 1,2,3) вы хотите увеличть число %lf: \n", a);
	double b = Input();
	if (b == 1)
	{
		printf("Значение числа %lf увеличенного в %lf раз(а) равно %lf", a, b, getn(a, b));
	}
	else if (b == 2)
	{
		printf("Значение числа %lf увеличенного в %lf раз(а) равно %lf", a, b, getn(a, b));
	}
	else if (b == 3)
	{
		printf("Значение числа %lf увеличенного в %lf раз(а) равно %lf", a, b, getn(a, b));
	}
	else
	{
		errno = EIO;
		perror("введено неверное значение");
	}

	return 0;

}

double Input(void)
{
	double num = 0.0;
	scanf_s("%lf", &num);
	return num;

}

double getn(const double a, const double b)
{
	double c = a * b;
	return c;
}



