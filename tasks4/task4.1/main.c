#define USE_LOCALE 0

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#if USE_LOCALE == 1
#include <locale.h>
#endif

#include "function.h"


int main(void)
{
#if USE_LOCALE == 1
	setlocale(LC_ALL, "ru-RU");
#endif 
	puts("Введите размер массива:");
	const size_t size = input_size();
	puts("\n");
	int* array = get_array(size);

	puts("Как Вы хотите заполнить массив?\n%d - ручной ввод, %d - случайный ввод\n",manual,random);

	const enum fill choice = input_choice();
	switch (choice)
	{
	case manual:
	{
		manual_fill(array, size);
		break;
	}
	case random:
	{
		const int min = input("Введите минимальное значение массива");
		const int max = input("Введите максимальное значение массива");
		if (min > max)
		{
			errno = ERANGE;
			perror("Неправильный диапазон");
			exit(1);
		}

		random_fill(array, size, min, max);
		break;
	}
	default:
	{
		errno = ERANGE;
		perror("Нет такого выбора");
		return 1;
	}
	}

	print_array(array, size);


	free(array);
	

	return 0;
}
