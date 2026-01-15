#include <stdio.h>
#include<string.h>    //gets use garna ko lagi
#include<stdlib.h>    //malloc use garna ko lagi
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m" // output ko color ko lagi

typedef struct Student
{
    int rollNumber;
    char name[50];
    int age;
    char department[30];
    float cgpa;
    char email[50];
} Student;

typedef struct Node // node ko 1st index 'data'-> sabei information contain garcha
{                   // ani 2nd index le address lai point garcha
    Student data;
    struct Node *next;
} Node;

Node *createNode(Student student)
{ // Naya node ko creation
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        printf(RED "Memory allocation failed!\n" RESET);
        return NULL;
    }

    newNode->data = student;
    newNode->next = NULL;

    return newNode;
}

Student AddStudInfo()
{
Student s;
    
    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNumber);
    
    printf("Enter Name: ");
    getchar(); // getchar is easier than scanf.
    fgets(s.name, 50, stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Remove newline
    
    printf("Enter Age: ");
    scanf("%d", &s.age);
    
    printf("Enter Department: ");
    scanf("%s", s.department);
    
    printf("Enter CGPA: ");
    scanf("%f", &s.cgpa);
    
    printf("Enter Email: ");
    scanf("%s", s.email);

}

void InsertStudent(Node **head, Student Student)
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
    Student s;
    Node *head=NULL;
    int del;

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
    printf("│  5. Display One Student Info                           │\n");
    printf("│  6. Delete Student                                     │\n");
    printf("│  6. Exit                                               │\n");
    printf("└────────────────────────────────────────────────────────┘\n");

    printf("Please select the action you want to perform in accordance to its number:");
    scanf("%d", &choice);

    switch (choice)
    {
        // case haru bhitra function call gara la
    case 1:
        printf(GREEN "----You have selected \" Add New Student\".----" RESET);
        s= AddStudInfo();
        InsertStudent(&head,s);

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
        printf(GREEN "----You have selected \" Delete Student\".----\n" RESET);
        printf(YELLOW" ----Are you really sure? (1->Yes,0->No)----\n"RESET);
        scanf("%d", &del);

        if(del==1)
        {
            printf(CYAN"----Sucessfully Deleted----"RESET);
        }
        else if(del==0)
        {
            printf(BLUE"----Canceled Deletion----"RESET);
        }
        else{
            printf(RED"----Invalid Input!!!----"RESET);
        }

        break;

    default:
        printf(RED "----Invalid Choice ----" RESET);
        break;
    }

    return 0;
}