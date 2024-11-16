#include <stdio.h>
#include <math.h> 

/**
* @brief Расчет значения функции по заданной формуле.
* @param x - значение аргумента функции.
* @return значение функции
*/
double fun(const double x);

int main(void)
{
	double x = 0;

	while (x <= 1)
	{
		printf(" x = %lf || y = %lf\n",x ,fun(x));
		x = x + 0.1;
	}
}

double fun(const double x)
{
	return sqrt(1 - x) - cos(sqrt(1 - x));
}