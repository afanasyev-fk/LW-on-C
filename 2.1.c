#include <stdio.h>
#include <locale.h>

int main() 
{
	setlocale(LC_ALL, "rus");

	int n = 0;
	printf("Введите кол-во целых чисел: ");
	scanf_s("%i", &n);
	
	double sum = 0;
	int a = 0;
	for (int i=0; i < n; i++)
	{
		scanf_s("%i", &a);
		sum += a;
	}
	printf("Среднее арифметическое равно: %lf", (sum / n));
}