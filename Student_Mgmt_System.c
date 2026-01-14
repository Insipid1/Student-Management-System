#include <stdio.h>
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"

typedef struct Student
{
    int rollNumber;
    char name[50];
    int age;
    char department[30];
    float cgpa;
    char email[50];
} Student;

typedef struct Node
{
    Student data;
    struct Node *next;
} Node;

void AddStudent(Node **head, Student Student)
{
    // insert garney
    printf(GREEN "✓ Student added successfully!\n" RESET);
}

void DeleteRecord(Node **head, Student Student)
{
    // Remove garna
}

int main()
{
    int choice;

    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║        STUDENT MANAGEMENT SYSTEM v1.0                  ║\n");
    printf("║                 DSA Project 2025                       ║\n");
    printf("╚════════════════════════════════════════════════════════╝\n\n");
    // I2 symbols bata lyu corner haru liney vaye or copy paste gara.
    printf("┌────────────────────────────────────────────────────────┐\n");
    printf("│                        MAIN MENU                       │\n");
    printf("├────────────────────────────────────────────────────────┤\n");
    printf("│  1. Add New Student                                    │\n");
    printf("│  2. Display All Students                               │\n");
    printf("│  3. Search Student                                     │\n");
    printf("│  4. Update Student                                     │\n");
    printf("│  5. Delete Student                                     │\n");
    printf("│  6. Exit                                               │\n");
    printf("└────────────────────────────────────────────────────────┘\n");

    printf("Please select the action you want to perform in accordance to its number:");
    scanf("%d", &choice);

    switch (choice)
    {
        //case haru bhitra function call gara la
    case 1:
        printf(GREEN "----You have selected \" Add New Student\".----" RESET);

        break;

    case 2:
        printf(GREEN "----You have selected \" Display Students\".----" RESET);

        break;

    case 3:
        printf(GREEN "----You have selected \" Search Student\".----" RESET);

        break;

    case 4:
        printf(GREEN "----You have selected \" Update Student Info\".----" RESET);

        break;

    case 5:
        printf(GREEN "----You have selected \" Display Students\".----" RESET);

        break;

    case 6:
        printf(GREEN "----You have selected \" Delete Student\".----" RESET);

        break;

    default:
        printf(RED"----Invalid Choice ----"RESET);
        break;
    }

    return 0;
}