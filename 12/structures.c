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

    void* (*print)(void*);
    void* (*increase_chemistry_grade)(void*);
} Student;

void* print_student_wrapper(void* void_ptr) {
    struct Student* student = (struct Student*)void_ptr;
    print_student(student);
    return void_ptr;
}

void* increase_chemistry_grade_wrapper(void* void_ptr) {
    struct Student* student = (struct Student*)void_ptr;
    increase_chemistry_grade(student);
    return void_ptr;
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
    if (student->chemistry_grade >= 2) {
        student->chemistry_grade--;
    }
}

int main() {

    // Для простоты создадим массивы для хранения строк фамилий студентов
    char surname1[] = "Pushkin";
    char surname2[] = "Mushkina";

    // Создание массива студентов (вместо динамического списка)
    Student students[2];

    students[0] = (Student){surname1, "Alex", 'M', 20, "Group 1", 4, 3, 5, print_student_wrapper, increase_chemistry_grade_wrapper};
    students[1] = (Student){surname2, "Olga", 'F', 19, "Group 2", 5, 5, 3, print_student_wrapper, increase_chemistry_grade_wrapper};

    // Количество студентов
    int numStudents = 2;

    printf("Исходная информация о студентах:\n");

    // Печать информации о студентах
    for (int i = 0; i < numStudents; i++) {
        print_student_wrapper(&students[i]);
    }

    printf("\nСнижение оценки по химии всем студентам на 1 балл...\n");

    // Снижение оценки по химии
    for (int i = 0; i < numStudents; i++) {
        increase_chemistry_grade_wrapper(&students[i]);
    }

    printf("\nОбновленная информация о студентах:\n");

    // Печать обновленной информации
    for (int i = 0; i < numStudents; i++) {
        print_student_wrapper(&students[i]);
    }

    return 0;
}

