#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	// Формирование массива из n элементов с помощью датчика случайных чисел
	srand (time(NULL));

	int size;
	printf("Введите количество элементов в массиве: ");
	scanf_s("%i", &size);

	int *arr = (int*)malloc(sizeof(int) * size);

	for (int i = 0; i < size; i++){
		arr[i] = rand() % 100;
	}	

	printf ("Массив: ");
	for (int i = 0; i < size; i++){
		printf("%i ", arr[i]);
	}

	printf ("\n");

	//Удаление max элемента из массива
	int max = 0, index_max = 0;

	for (int i = 0; i < size; i++){
		if (arr[i] > max) {
			max = arr[i];
			index_max = i;
		}
	}

	printf("Удаление: ");
	size--;
	for (int i = index_max; i < size; i++){
		arr[i] = arr[i + 1];
	}

	for (int i = 0; i < size; i++){
		printf("%i ", arr[i]);
	}

	printf("\n");

	//Добавление k элементов в начало массива
	int k = 0;

	printf("Введите количество добавляемых элементов: ");
	scanf_s("%i", &k);

	arr = (int*)realloc(arr,sizeof(int) * size + k) ;

	for (int i = 0; i < size; i++){
		arr[i + k] = arr[i];
	}

	for (int i = 0; i < k; i++){
		arr[i] = rand() % 100;
	}

	for (int i = 0; i < size + k; i++){
		printf("%i ", arr[i]);
	}

	printf("\n");

	// Переворачивание массива
	for (int i = 0; i < (size + k)/2; i++){
		int tmp = arr[i];
		arr[i] = arr[(size + k) - 1 - i];
		arr[(size + k) - 1 - i] = tmp;
	}

	printf("Перевёрнутый массив: ");
	for (int i = 0; i < size + k; i++){
		printf("%i ", arr[i]);
	}

	printf("\n");

	// Поиск первого чётного массива
	for (int i = 0; i < size + k; i++){
		if (arr[i] % 2 == 0){
		printf ("Первый чётный элемент: %i", arr[i]);
		break;
		}
	}

	printf("\n");

	// Сортировка методом простого обмена
	for(int i = 1; i < size + k ; i++){
		for(int j = (size + k) - 1; j >= i; j--){
			if(arr[j] < arr[j-1]){
				int tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}
		}
	}

	printf("Отсортированный массив: ");
	for (int i = 0; i < size + k; i++){
		printf("%i ", arr[i]);
	}
}