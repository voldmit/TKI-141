#include <stdio.h>
#include <locale.h>
/**
* @brief считывает вещественное число.
* @return вещественное число
*/
double input(void);
/**
* @brief Расчет значения функции по заданной формуле.
* @param l - значение длины проводника.
* @param s - значение площади поперечного сечения проводника.
* @param p - удельное сопротивление алюминия.
* @return сопротивление проводника
*/
double Res(const double l, const double s, const double p);

int main(void)
{
	setlocale(LC_ALL, "Rus");
	double p = 0.028;
	puts("Введите площадь поперечного сечения в мм:\n");
	double s = input();
	puts("Введите длину в м:\n");
	double l = input();
	printf_s("\nСопротивление = %lf", Res(l, s, p));
	return 0;
}

double input(void)
{
	double value = 0.0;
	scanf_s("%lf", &value);
	return value;
}

double Res(const double l, const double s, const double p)
{
	return (p * l) / s;
}