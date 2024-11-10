#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

double getA(const double x, const double y, const double z);

double getB(const double x, const double y, const double z);

int main()
{
	const double x = 0.5;
	const double y = 0.05;
	const double z = 0.7;
	const double a = getA(x, y, z);
	const double b = getB(x, y, z);
	printf_s("x = %f, y = %f, z = %f, a = %f, b = %f\n", x, y,
		z, a, b);
	return 0;
}
double getA(const double x, const double y, const double z)
{
	return ((x * x * (x + 1)) / (y - (sin(x + z) * (x + z))));
}
double getB(const double x, const double y, const double z)
{
	return (sqrt((x * y) / z) + (cos((x + y) * (x + y)) * cos((x + y) * (x + y))));
}