#include <stdio.h>
int main()
{
	int x, y;
	scanf_s("%i%i", &x, &y);
	int result = (2 >= y) && (y >= 0) && (5 >= x) && (x >= 0);
	printf("%i", result);
}