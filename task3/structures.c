#include <stdio.h>
#include <stdbool.h>

struct student {
    char surname[50];
    char name[50];
    char patronymic[50];
    int group;
    int mathematics;
    int physics;
    int chemistry;
};

void* outputStudentsWrapper(void* arg) {
    struct student* students = (struct student*)arg;
    int count = *((int*)arg + 1); // Assuming count is stored in the next memory location

    for (int i = 0; i < count; i++) {
        printf("%s %s %s %d %d %d %d\n",
            students[i].surname,
            students[i].name,
            students[i].patronymic,
            students[i].group,
            students[i].mathematics,
            students[i].physics,
            students[i].chemistry);
    }

    return NULL; // Returning NULL since the function doesn't have a specific return value
}

void* inputStudentsWrapper(void* arg) {
    struct student* students = (struct student*)arg;
    int count = *((int*)arg + 1); // Assuming count is stored in the next memory location

    for (int i = 0; i < count; i++) {
        printf("Enter the student's last name: ");
        scanf("%s", students[i].surname);
        printf("Enter the student's name: ");
        scanf("%s", students[i].name);
        printf("Enter the student's middle name: ");
        scanf("%s", students[i].patronymic);
        printf("Enter the student's group: ");
        scanf("%d", &students[i].group);
        printf("Enter the math score: ");
        scanf("%d", &students[i].mathematics);
        printf("Enter a physics grade: ");
        scanf("%d", &students[i].physics);
        printf("Enter a chemistry grade: ");
        scanf("%d", &students[i].chemistry);
    }

    return NULL; // Returning NULL since the function doesn't have a specific return value
}

int main() {
    int count = 0;
    printf("Enter the number of students: ");
    scanf("%d", &count);
    struct student students[count];

    // Pass the student array and count to the wrapper functions
    void* (*outputStudentsPtr)(void*) = outputStudentsWrapper;
    outputStudentsPtr((void*)students, (void*)&count);

    void* (*inputStudentsPtr)(void*) = inputStudentsWrapper;
    inputStudentsPtr((void*)students, (void*)&count);

    return 0;
}
