#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
  char* surname;
  char name[50];
  char gender;
  int age;
  char group[10];
  int math_grade;
  int physics_grade;
  int chemistry_grade;

  void (*print)(struct Student* student);
  void (*increase_chemistry_grade)(struct Student* student);
} Student;

void print_student(Student* student);
void increase_chemistry_grade(Student* student);

int main() {

  // Для простоты создадим массивы для хранения строк фамилий студентов
  char surname1[] = "Pushkin";
  char surname2[] = "Mushkina";

  // Создание массива студентов (вместо динамического списка)
  Student students[2];

  students[0] = (Student){surname1, "Alex", 'M', 20, "Group 1", 4, 3, 5, print_student, increase_chemistry_grade};
  students[1] = (Student){surname2, "Olga", 'F', 19, "Group 2", 5, 5, 3, print_student, increase_chemistry_grade};

  // Количество студентов
//  int numStudents = 2;

  printf("Исходная информация о студентах:\n");

  // Печать информации о студентах без цикла for 
//  for (int i = 0; i < numStudents; i++) {
//    print_student(&students[i]);
//  }
 print_student(&students[0]);
 print_student(&students[1]);

  printf("\nСнижение оценки по химии всем студентам на 1 балл...\n");

  // Снижение оценки по химии
 // for (int i = 0; i < numStudents; i++) {
 //   increase_chemistry_grade(&students[i]);
 // }
 //
 increase_chemistry_grade(&students[0]);
 increase_chemistry_grade(&students[1]);

  printf("\nОбновленная информация о студентах:\n");

  // Печать обновленной информации
//  for (int i = 0; i < numStudents; i++) {
//    print_student(&students[i]);
//  }
 print_student(&students[0]); 
 print_student(&students[1]);
  return 0;
}

void print_student(Student* student) {
  printf("Фамилия: %s\n", student->surname);
  printf("Имя: %s\n", student->name);
  printf("Пол: %c\n", student->gender);
  printf("Возраст: %d\n", student->age);
  printf("Группа: %s\n", student->group);
  printf("Оценка по математике: %d\n", student->math_grade);
  printf("Оценка по физике: %d\n", student->physics_grade);
  printf("Оценка по химии: %d\n", student->chemistry_grade);
  printf("\n");
}

void increase_chemistry_grade(Student* student) {
  if (student->chemistry_grade >= 3) {
    student->chemistry_grade--;
  }
}
