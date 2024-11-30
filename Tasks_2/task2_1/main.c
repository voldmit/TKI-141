#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <errno.h>


/**
* @brief считывает вещественное число
* @return вещественное число
*/
double Input(void);

/**
* @brief варианты действия над числом
*/

enum operation
{
	A1 = 1,
	A2 = 2,
	A3 = 3
};

/**
* @brief рассчитывает вещественное число с коэффициентом
* @param a - число пользователя
* @return вещественное число
*/

double mult(double a, enum operation b);


/**
* @brief исполняет программу
* @return успешность программы
*/

main(void)
{
	setlocale(LC_ALL, "Rus");
	puts("Пожалуйста введите число: ");
	double a = Input();
	puts("\nВо сколько раз хотитпе увеличить число:");
	double b = Input();
	double result = mult(a, b);
	if(b != 1 & b != 2 & b != 3)
	{
		errno = EIO;
		perror("Ошибка ввода");
		return 1;
	}
	else
	{
		printf_s("Результат операции:%lf", result);
		return 0;
	}




}

double Input(void)
{
	double num = 0.0;
	scanf_s("%lf", &num);
	return num;

}

double mult(double a, enum operation b)
{

	switch (b)
	{
	case A1:
		return a;
	case A2:
		return a * 2;
	case A3:
		return a * 3;
	default:

		return 0;


	}

}
