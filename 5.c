#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertRow(int ***A, int *rows, int cols, int *app_str, int index_app_str);
int main() {
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

    //Удаление первого четного элемента в массиве
    int chet = 0, index_chet = 0;

    for (int i = 0; i < size; i++){
        if (arr[i] % 2 == 0){
            printf ("Первый чётный элемент: %i", arr[i]);
            chet = arr[i];
			index_chet = i;
            break;
        }
    }
     printf ("\n");

	printf ("Удаление: ");
	size--;
	for (int i = index_chet; i < size; i++){
		arr[i] = arr[i + 1];
	}

	for (int i = 0; i < size; i++){
		printf("%i ", arr[i]);
	}
	printf ("\n");
    printf ("\n");

    //Заполнение двумерного массива случайными числами
    srand (time(NULL));

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

    printf ("Массив: ");
	for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
		    printf("%i ", A[i][j]);
            printf ("\t");
	    }
        printf ("\n\t");
	}
	printf ("\n");

    //Добавление строки с заданным номером
    int index_app_str; 
    int* app_str;

    printf ("Введите номер дополнительной строки: ");
    scanf ("%i", &index_app_str);

   // Добавляем новую строку на заданную позицию
    insertRow(&A, &rows, cols, app_str, index_app_str);

    for (int j = 0; j < cols; j++){
        A[index_app_str][j] = rand() % 100;
    }

    printf ("Массив с доп. строкой: \n");
	for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
		    printf("%i ", A[i][j]);
            printf ("\t");
	    }
        printf ("\n");
    }
}

void insertRow(int ***A, int *rows, int cols, int *app_str, int index_app_str) {
    *A = (int**) realloc(*A, (*rows + 1) * sizeof(int *));
    
    for (int i = *rows; i > index_app_str; i--) {
        (*A)[i] = (*A)[i - 1];
    }
    
    (*A)[index_app_str] = (int*) malloc(cols * sizeof(int));
    
    for (int i = 0; i < cols; i++) {
        (*A)[index_app_str][i] = app_str[i];
    }

    (*rows)++;
}