#include <stdio.h>
#include <errno.h>
#include <locale.h>

/**
* @brief ����������� ��������� ����� ������������ � ��������� ���.
* @param a - �����.
* @param b - �����������.
* @return �������� a ������������ � b ���
*/
double getn(const double a, const double b);

/**
* @brief ��������� ������������ �����
* @return ������������ �����
*/
double Input(void);

main(void)
{
	setlocale(LC_ALL, "Rus");
	puts("���������� ������� �����: ");
	double a = Input();
	printf("���������� ������� �������� �� ������� ���(� 1,2,3) �� ������ �������� ����� %lf: \n", a);
	double b = Input();
	if (b == 1)
	{
		printf("�������� ����� %lf ������������ � %lf ���(�) ����� %lf", a, b, getn(a, b));
	}
	else if (b == 2)
	{
		printf("�������� ����� %lf ������������ � %lf ���(�) ����� %lf", a, b, getn(a, b));
	}
	else if (b == 3)
	{
		printf("�������� ����� %lf ������������ � %lf ���(�) ����� %lf", a, b, getn(a, b));
	}
	else
	{
		errno = EIO;
		perror("������� �������� ��������");
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



