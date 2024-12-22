#include <limits.h>
#include <errno.h>
#include <stdarg.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int input()
{
	int value = 0;
	int result = scanf_s("%d", &value);
	if (result != 1)
	{
		errno = EINVAL;
		perror("Неправильное число");
		exit(1);
	}
	return value;
}

size_t input_size()
{
	int size = input();
	if (size <= 0)
	{
		errno = EDOM;
		perror("Размер массива должен быть строго больше нуля");
		exit(1);
	}
	return (size_t)size;
}

enum fill input_choice()
{
	const int choice = input();
	return ((enum fill)choice);
}

int* get_array(const size_t size)
{
	int* array = (int*)malloc(size * sizeof(int));
	check_array(array);
	return array;
}

void print_array(const int* const array, const size_t size)
{
	check_array(array);
	printf_s("{ ");
	size_t i = 0;
	for (; i < size - 1; ++i)
	{
		printf_s("%d, ", array[i]);
	}
	printf_s("%d }", array[i]);
}

void manual_fill(int* const array, const size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		printf_s("Введите %zu-й элемент", i + 1);
		array[i] = input();
	}
}

void random_fill(int* const array, const size_t size, const int min, const int max)
{
	srand((unsigned int)time((time_t)NULL));
	for (size_t i = 0; i < size; ++i)
	{
		array[i] = rand() % (max - min + 1) + min;
	}
}
int check_array(const int* const array)
{
	if (NULL == array)
	{
		errno = ENOMEM;
		perror("Не выделена память");
		exit(1);
	}
	return 0;
}



void index36(const int* const array, const size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		if (array[i] % 3 == 0 || array[i] % 6 == 0)
		{
			printf_s("%zu\n", i);
		}
	}
}

void sumchet(const int* const array, const size_t size)
{
	int sum = 0;
	for (size_t i = 0; i < size; ++i)
	{
		if (array[i] % 2 == 0)
		{
			sum = sum + array[i];
		}
	}
	printf_s("%d", sum);
}

void zamena(int* const array, const size_t size)
{
	size_t imin;
	size_t imax;
	int max = INT_MIN;
	int min = INT_MAX;
	for (size_t i = 0; i < size; ++i)
	{
		if (array[i] < min)
		{
			imin = i;
			min = array[i];
		}
		if(array[i] > max)
		{
			imax = i;
			max = array[i];
		}
	}
	if (imin > imax)
	{
		for (imax ; imax+1 < imin; ++imax)
		{
			array[imax + 1] = 0;
		}
	}
	if (imin < imax)
	{
		for (imin ; imax+1 < imin; ++imin)
		{
			array[imin + 1] = 0;
		}
	}
}
