#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "rus");

	int n;

	printf("Введите количество слагаемых: ");
	scanf_s("%i", &n);

	int sum = 0;
	
	for (int i = 1; i <= n; ++i)
	{
		sum += pow(-1, i + 1) * i;
	}
	printf("%i", sum);
}