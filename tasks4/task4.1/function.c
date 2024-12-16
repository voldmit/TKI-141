
#include <errno.h>
#include <stdarg.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int input(const char* message)
{
	if (NULL != message)
	{
		puts(message);
	}
	int value = 0;
	int result = scanf_s("%d", &value);
	if (result != 1)
	{
		errno = EINVAL;
		perror("Íåïðàâèëüíîå ÷èñëî");
		exit(1);
	}
	return value;
}

size_t input_size(const char* message)
{
	int size = input(message);
	if (size <= 0)
	{
		errno = EDOM;
		perror("Ðàçìåð ìàññèâà äîëæåí áûòü ñòðîãî áîëüøå 0");
		exit(1);
	}
	return (size_t)size;
}

enum fill input_choice(const char* message)
{
	const int choice = input(message);
	return ((enum fill)choice);
}

int* get_array(const size_t size)
{
	int* array = (int*)malloc(size * sizeof(int));
	check_array(array);
	return array;
}

void print_array(const int* const array, const size_t size, const char* message)
{
	check_array(array);
	if (NULL != message)
	{
		printf_s("%s: ", message);
	}
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
		printf_s("Ââåäèòå %zu-é ýëåìåíò", i + 1);
		array[i] = input(NULL);
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
void check_array(const int* const array)
{
	if (NULL == array)
	{
		errno = ENOMEM;
		perror("Íå âûäåëåíà ïàìÿòü");
		exit(1);
	}
}

void print_array(
	const int* const array,
	const size_t size,
	const char* message)
{
	check_array(array);

	if (NULL != message)
	{
		printf_s("%s: ", message);
	}

	printf_s("{ ");

	size_t i = 0;
	for (; i < size - 1; ++i)
	{
		printf_s("%d, ", array[i]);
	}

	printf_s("%d }", array[i]);
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

