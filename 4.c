#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main () {

    // Заполнение одномерного массива случайными числами
    srand(time(NULL));

    int size;
    printf("Введите количество элементов в массиве: ");
    scanf("%i", &size);

    int* arr = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++){
       arr[i] = rand() % 100;
    }

    printf ("Исходный массив: ");
	for (int i = 0; i < size; i++){
		printf("%i ", arr[i]);
	}
	printf ("\n");

    //Сортировка пузырьком и проверка чётности
    for (int i = 0; i < size-1; i++) {
            for (int j = 0; j < size-i-1; j++) {
                if (arr[j] % 2 == 0 && arr[j+1] % 2 == 0 && arr[j] > arr[j+1]) {
                    int tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                }
            }
    }

    printf("Отсортированный массив по возрастанию четных элементов: ");
    for (int i = 0; i < size; i++){
		printf("%i ", arr[i]);
	}
	printf ("\n");

    printf ("\n");

    //Заполненние двумерного массива случайными числами
    int rows, cols;
    printf ("Введите кол-во строк в массиве: ");
    scanf("%i", &rows);
    printf ("Введите кол-во  столбцов в массиве: ");
    scanf("%i", &cols);

    int** A = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++){
        A[i] = (int*)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            A[i][j] = rand() % 100;
        }
    }

    printf ("Исходный массив: ");
    printf("\n");
	for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
		    printf("%i ", A[i][j]);
            printf ("\t");
	    }
        printf ("\n");
	}
    
    //Переворачивание четных строк двумерного массива
    for (int i = 0; i < rows; i+=2){
        for (int j = 0; j < cols / 2; j++){
		    int tmp = A[i][j];
		    A[i][j] = A[i][cols - 1 - j];
		    A[i][cols - 1 - j] = tmp;
        }
    }

    printf ("Отсортированный массив: ");
    printf ("\n");
	for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
		    printf("%i ", A[i][j]);
            printf ("\t");
	    }
        printf ("\n");
	}
	printf ("\n");

    //Удалить все гласные буквы из строки
    char str[100];
    char c = getchar();
    int j = 0;

    printf ("Исходная строка: ");
    fgets (str, sizeof(str), stdin);

    for (int i = 0; i < str[i]!='\0'; i++) {
        if (!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y' ||
        str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'Y')) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';

    printf ("Отсортированная строка: ");
    puts (str);

}