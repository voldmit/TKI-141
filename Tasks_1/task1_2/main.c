#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/**
* @brief считывает вещественное число
* @return вещественное число
*/
double Input();
/**
* @brief рассчитывает 3 сторону
* @param x - вектор 1
* @param y - вектор 2
* @param z - угол между векторами
* @return вещественное число
*/
double Third(const double x, const double y, const double z);
/**
* @brief рассчитывает площадь треугольника
* @param x - вектор 1
* @param y - вектор 2
* @param z - угол между векторами
* @return площадь треугольника
*/
double Area(const double x, const double y, const double z);
/**
* @brief рассчитывает радиус описанного треугольника
* @param k - вектор 1
* @param z - угол между векторами
* @return радиус
*/
double Radius(const double k, const double z);

int main(void)
{
	setlocale(LC_ALL, "Rus");
	puts("Введите первую сторону:");
	double x = Input();
	puts("\nВведите вторую сторону:");
	double y = Input();
	puts("\nВведите угол в градусах:");
	double z = Input();
	double k = Third(x, y, z);
	printf("третья сторона = %lf\nПлощадь = %lf\nРадиус = %lf", Third(x, y, z), Area(x, y, z), Radius(k, z));
	return 0;
}

double Third(const double x, const double y, const double z)
{
	return sqrt(x * x + y * y - 2 * x * y * cos((2 * z * M_PI) / 360));
}

double Area(const double x, const double y, const double z)
{
	return (x * y * sin((2 * z * M_PI) / 360) / 2);
}

double Radius(const double k, const double z)
{
	return k / 2 * sin((2 * z * M_PI) / 360);
}

double Input(void)
{
	double value = 0.0;
	scanf_s("%lf", &value);
	return value;
}