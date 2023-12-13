#include <stdio.h>
#include <locale.h>

int main() 
{
	setlocale(LC_ALL, "rus");

	int sub = 0;
	printf("Введите последовательность целых чисел, которая заканчивается на 0: ");

	int a;

	int sumPlus = 0, sumMinus = 0;

	do
	{
		scanf_s("%i", &a);

		if (a > 0)
		{
			sumPlus++;
		}
		else if (a < 0)
		{
			sumMinus++;
		}
	} while (a != 0);

	if (sumPlus > sumMinus)
	{
		printf("Больше положительных чисел");
	}
	else if (sumPlus == sumMinus)
	{
		printf("Положительных и отрицательных чисел одинакого");
	}
	else
	{
		printf("Больше отрицательных чисел");
	}
}