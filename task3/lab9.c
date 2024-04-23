#include <stdio.h>
#include <stdlib.h>

void isDivisibleBy9(int n) { 
	if (n%9 == 0){
	   printf("число делится на 9 без остатка");
	} 
	else {
	   printf("число не делится на 9 без остатка");
  } 
}

int countMinima(int arr[], int size) { 
    int minCount = 0; 
    int min = arr[0]; 
    for (int i = 1; i < size; i++) { 
        if (arr[i] < min) { 
            min = arr[i]; 
            minCount = 1; 
    } 
	else if (arr[i] == min) { 
          minCount++;
    } 
  } 
  return minCount; 
 } 
 
 
void findColumnsWithMinima(int matrix[][3], int rows, int columns) { 
printf("Столбцы с минимумами: "); 
for (int j = 0; j < columns; j++) { 
int min = matrix[0][j]; 
for (int i = 1; i < rows; i++) { 
if (matrix[i][j] < min) { 
min = matrix[i][j]; 
} 
} 
for (int i = 0; i < rows; i++) { 
if (matrix[i][j] == min) { 
printf("%d ", j); 
break; 
} 
} 
} 
printf("\n"); 
} 


int* extract_positive_sequences(int* arr, int size, int* new_size) {
    int count = 0;
    int curr_count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            curr_count++;
        } else {
            if (curr_count > 0) {
                count++;
            }
            curr_count = 0;
        }
    }
    int* new_arr = (int*)malloc(count * sizeof(int));
    if (new_arr == NULL) {
    
        printf("Ошибка выделения памяти\n");
        return NULL;
    }
    int index = 0;
    curr_count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            curr_count++;
        } else {
            if (curr_count > 0) {
                new_arr[index++] = curr_count;
                curr_count = 0;
            }
        }
    }
    *new_size = count;
    return new_arr;
}




int main()
{

void (*func1)(int);
int (*func2)(int *,int);
void(*func3)(int (*)[3], int,  int);
int* (*func4)(int*, int, int*);

func1 = isDivisibleBy9;
func2 = countMinima;
func3 = findColumnsWithMinima;
func4 = extract_positive_sequences;


printf("задача 1\n");
printf("Проверка деления на 9 с остатком\n");
  int a;      
  printf("a = ");
  scanf("%d", &a); // вводим a
  func1(a);    // вызов функции: x=a%9
  getchar(); getchar(); // мы использовали scanf(),


printf("задача 2\n");
printf("Подсчёт количества минимумов\n");
  int arr[] = {3,1,4,1,5,9,2,6,5,3,5};
  int size = (sizeof(arr) / sizeof(arr[0]));

  int result = func2(arr,size);
  printf("кол-во минимумов: %d\n", result);



printf("задача 3\n");
printf("Подсчёт количества минимумов в столбце\n");
int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; 
int rows = sizeof(matrix) / sizeof(matrix[0]); 
int columns = sizeof(matrix[0]) / sizeof(matrix[0][0]); 
func3(matrix, rows, columns); 


printf("задача 4\n");
printf("Последовательности положительных чисел\n");
  int arr1[] = {1,2,-3,4,5,-6,7,8,9,-10};  // Пример исходного массива
     size = sizeof(arr1) / sizeof(arr1[0]);

    int new_size;
    int* new_arr = func4(arr1, size, &new_size);

    if (new_arr != NULL) {
        printf("Новый массив:");
        for (int i = 0; i < new_size; i++) {
            printf(" %d", new_arr[i]);
        }
        printf("\n");

        free(new_arr);  // Освобождение динамической памяти
    }






    return 0;
}
