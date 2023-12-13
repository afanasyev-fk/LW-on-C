#include <stdio.h>
#include <math.h>
int main()
{
	double x;
	scanf_s("%lf", &x);
	double sum = sin(x) + pow(x, 3) + (1.0 / (pow(x, 2) + 1));
	printf("Сумма равна %lf", sum);
}