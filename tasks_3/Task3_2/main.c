#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>
#include <locale.h>

/**
 * @brief Ввод целого числа.
 * @remarks Экстренно завершает работу программу в случае неправильного ввода.
 * @returns Возвращает целое число.
 */
int input(void);

/**
 * @brief Вычисляет факториал целого числа.
 * @param[in] k Целое число, для которого нужно найти факториал.
 * @returns Возвращает факториал числа k.
 */
int factorial(int k);

/**
 * @brief Вычисляет сумму последовательности, начиная с k.
 * @param k Начальное значение для суммы.
 * @returns Возвращает результат вычисления суммы.
 */
double summ1tok(int k);

/**
 * @brief Вычисляет сумму последовательности, начиная с k.
 * @param k Начальное значение для суммы.
 * @returns Возвращает результат вычисления суммы.
 */
double summeplus(int k);

/**
 * @brief Главная функция программы.
 * Запрашивает ввод от пользователя и выводит результат вычисления суммы.
 * @returns Завершает выполнение программы с кодом возврата 0.
 */
int main()
{
    setlocale(LC_ALL, "ru-RU");
    int k = input();
    printf_s("%lf\n", summ1tok(k));
    return 0;
}

int input(void)
{
    int num = 0;
    int p = scanf_s("%i", &num);
    if (p != 1)
    {
        errno = EIO;
        perror("Введено неверное значение");
        exit(1);
    }
    return num;
}

int factorial(int k)
{
    if (k <= 1)
    {
        return 1;
    }
    return k * factorial(k - 1);
}

double summ1tok(int k)
{
    int s = -1.0;
    double sum = 0.0;
    double equa = 0.0;
    for (int i = 1; i <= k; i++)
    {
        double n = i;
        equa = ((pow(s, i) * n) / ((double)factorial(i + 1)));
        sum += equa;
    }
    return sum;
}

double summeplus(int k)
{
    double s = -1.0;
    double sum = 0.0;
    double equa = 0.0;
    int i = k;
    while (1)
    {
        equa = ((pow(s, i) * i) / (factorial(i + 1)));
        if (fabs(equa) < DBL_EPSILON)
        {
            break;
        }
        sum += equa;
        i++;
    }
    return sum;
}