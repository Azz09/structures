#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct student {
  char surname[50];
  char name[50];
  char patronymic[50];
  int group;
  int mathematics;
  int physics;
  int chemistry;
};
for (int j = 0; j < count; j++){
if (students[j].chemistry>=3){
students[j].chemistry = students[j].chemistry -1;

typedef struct Node {
  struct student data;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode(struct student student) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Error allocating memory for new node\n");
    return NULL;
  }

  newNode->data = student;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

void insertNode(Node **root, struct student student) {
  if (*root == NULL) {
    *root = createNode(student);
    return;
  }

  Node *current = *root;
  while (true) {
    if (student.group < current->data.group) {
      if (current->left == NULL) {
        current->left = createNode(student);
        break;
      } else {
        current = current->left;
      }
    } else {
      if (current->right == NULL) {
        current->right = createNode(student);
        break;
      } else {
        current = current->right;
      }
    }
  }
}

void inorderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }

  inorderTraversal(root->left);
  printf("%s %s %s %d %d %d %d\n", root->data.surname, root->data.name,
         root->data.patronymic, root->data.group, root->data.mathematics,
         root->data.physics, root->data.chemistry);
  inorderTraversal(root->right);
}

void inputStudents(Node **root, int count) {
  for (int i = 0; i < count; i++) {
    struct student student;

    printf("Enter the student's last name: ");
    scanf("%s", &student.surname);
    printf("Enter the student's name: ");
    scanf("%s", &student.name);
    printf("Enter the student's middle name: ");
    scanf("%s", &student.patronymic);
    printf("Enter the student's group: ");
    scanf("%d", &student.group);
    printf("Enter the math score: ");
    scanf("%d", &student.mathematics);
    printf("Enter a physics grade: ");
    scanf("%d", &student.physics);
    printf("Enter a chemistry grade: ");
    scanf("%d", &student.chemistry);

    insertNode(root, student);
  }
}

void outputStudents(Node *root) {
  inorderTraversal(root);
}

int main() {
  int count = 0;
  Node *root = NULL;

  printf("Enter the number of students: ");
  scanf("%d", &count);

  inputStudents(&root, count);
  outputStudents(root);

  return 0;
}
