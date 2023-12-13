#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "rus");

	int n;
	printf("Введите количество слагаемых: ");
	scanf_s("%i", &n);

	int sum = 0, i;
	for (i = 0; i <= n; ++i)
	{
		if (i % 2 == 0)
		{
			sum -= i;
		}
		else
		{
			sum += i;
		}
	}
	printf("%i", sum);
}