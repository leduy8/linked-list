#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
  char *name;
  struct Student *next;
} Student;

Student *createLinkedList(int n, Student *head)
{
  Student *current = NULL;
  if (head != NULL)
  {
    current = head;
    while (current != NULL)
    {
      if (current->next == NULL)
        break;
      current = current->next;
    }
  }

  for (int i = 0; i < n; i++)
  {
    Student *student = (Student *)malloc(sizeof(Student));
    student->next = NULL;
    printf("Student %d\n", i);
    printf("Name: ");
    getchar();
    student->name = (char *)malloc(BUFSIZ * sizeof(char));
    scanf("%[^\n]", student->name);
    student->name = (char *)realloc(student->name, strlen(student->name) + 1);
    if (head == NULL)
    {
      head = student;
      current = student;
    }
    else
    {
      current->next = student;
      current = student;
    }
  }
  return head;
}

Student *addNewNode(Student *head)
{
  Student *student = (Student *)malloc(sizeof(Student));
  student->next = NULL;
  printf("Name: ");
  getchar();
  student->name = (char *)malloc(BUFSIZ * sizeof(Student));
  scanf("%[^\n]", student->name);
  student->name = (char *)realloc(student->name, strlen(student->name) + 1);

  if (head == NULL)
  {
    head = student;
  }
  else
  {
    Student *current = head;

    while (current != NULL)
    {
      if (current->next == NULL)
      {
        current->next = student;
        break;
      }
      current = current->next;
    }
  }
  return head;
}

Student *editNode(Student *head, char *studentName)
{
  if (head == NULL)
  {
    printf("Can't edit, list is null\n");
    return NULL;
  }
  Student *current = head;
  Student *temp = NULL;
  Student *student = (Student *)malloc(sizeof(Student));
  printf("Enter new name: ");
  getchar();
  student->name = (char *)malloc(BUFSIZ * sizeof(char));
  scanf("%[^\n]", student->name);
  student->name = (char *)realloc(student->name, strlen(student->name) + 1);

  if (strcmp(current->name, studentName) == 0)
  {
    student->next = current->next;
    head = student;
    return head;
  }

  while (current != NULL)
  {
    if (strcmp(current->name, studentName) == 0)
    {
      temp->next = student;
      student->next = current->next;
      return head;
    }
    temp = current;
    current = current->next;
  }
}

Student *deleteNode(Student *head, char *studentName)
{
  if (head == NULL)
  {
    printf("Can't delete, list is null\n");
    return NULL;
  }

  Student *current = head;
  Student *temp = NULL;
  if (head->next == NULL)
  {
    head = NULL;
    return head;
  }

  if (strcmp(current->name, studentName) == 0)
  {
    head = current->next;
    free(current);
    return head;
  }

  while (current != NULL)
  {
    if (strcmp(current->name, studentName) == 0)
    {
      temp->next = current->next;
      free(current);
      return head;
    }
    temp = current;
    current = current->next;
  }
}

void findNode(Student *head, char *studentName)
{
  if (head == NULL)
  {
    printf("Can't find, list is null\n");
    return;
  }
  Student *current = head;
  while (current != NULL)
  {
    if (strcmp(current->name, studentName) == 0)
    {
      printf("Found %s\n", studentName);
      return;
    }
    current = current->next;
  }
  printf("%s is not in the list\n", studentName);
}

void displayList(Student *head)
{
  int num = 0;
  Student *current = head;
  while (current != NULL)
  {
    printf("================\n");
    printf("Student %d\n", num++);
    printf("Name: %s\n", current->name);
    current = current->next;
  }
  printf("================\n");
}

void menu(int *choice)
{
  printf("\n");
  printf("1. Add a list of student\n");
  printf("2. Add a new student\n");
  printf("3. Edit student profile by name\n");
  printf("4. Delete a student by name\n");
  printf("5. Find student by name\n");
  printf("6. Display list of student\n");
  printf("7. End\n");
  printf("Your choice: ");
  scanf("%d", choice);
  printf("\n");
}

int main()
{
  Student *head = NULL;
  while (1)
  {
    int choice = 0;
    menu(&choice);
    switch (choice)
    {
    case 1:
    {
      int n = 0;
      printf("Enter number of student: ");
      scanf("%d", &n);
      head = createLinkedList(n, head);
      break;
    }
    case 2:
    {
      head = addNewNode(head);
      break;
    }
    case 3:
    {
      printf("Enter name of student to edit: ");
      getchar();
      char *name = (char *)malloc(BUFSIZ * sizeof(char));
      scanf("%[^\n]", name);
      name = (char *)realloc(name, strlen(name) + 1);
      head = editNode(head, name);
      break;
    }
    case 4:
    {
      printf("Enter name of student to delete: ");
      getchar();
      char *name = (char *)malloc(BUFSIZ * sizeof(char));
      scanf("%[^\n]", name);
      name = (char *)realloc(name, strlen(name) + 1);
      head = deleteNode(head, name);
      break;
    }
    case 5:
    {
      printf("Enter name of student to find: ");
      getchar();
      char *name = (char *)malloc(BUFSIZ * sizeof(char));
      scanf("%[^\n]", name);
      name = (char *)realloc(name, strlen(name) + 1);
      findNode(head, name);
      break;
    }
    case 6:
    {
      displayList(head);
      break;
    }
    default:
    {
      Student *current = head;
      Student *temp = head;

      while (temp != NULL)
      {
        temp = temp->next;
        free(current);
        current = temp;
      }
      exit(0);
    }
    }
  }
}