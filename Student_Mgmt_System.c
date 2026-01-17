#include <stdio.h>
#include <string.h> //gets use garna ko lagi
#include <stdlib.h> //malloc use garna ko lagi
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
    return s;
}

void InsertStudent(Node **head, Student student)
{
    Node *newNode = createNode(student);
    if (newNode == NULL)
        return; // Memory allocation failed

    if (*head == NULL)
    {
        // If the list is empty, new node becomes the head
        *head = newNode;
    }
    else
    {
        // Otherwise, insert at the end
        Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf(GREEN "✓ Student added successfully!\n" RESET);
}

// Display all students
void DisplayAll(Node *head)
{
    if (head == NULL)
    {
        printf("No student records found!\n");
        return;
    }

     printf("\n");
    printf("┌──────┬─────────────────────┬─────┬──────────────┬──────┬──────────────────────────┐\n");
    printf("│ Roll │        Name         │ Age │  Department  │ CGPA │          Email           │\n");
    printf("├──────┼─────────────────────┼─────┼──────────────┼──────┼──────────────────────────┤\n");

    Node *temp = head;
    int sn = 1; // serial number
    while (temp != NULL)
    {
        printf("│ %-4d │ %-19s │ %3d │ %-12s │ %.2f │ %-24s │\n",
               
               temp->data.rollNumber,
               temp->data.name,
               temp->data.age,
               temp->data.department,
               temp->data.cgpa,
               temp->data.email);
        temp = temp->next;
        sn++;
    }

    printf("└──────┴─────────────────────┴─────┴──────────────┴──────┴──────────────────────────┘\n");
}

//Searching with roll number.
Node *SearchByRoll(Node *head,int rollno){
    Node *temp=head;
    while(temp!=NULL){
    if(temp->data.rollNumber==rollno){
        printf("Roll Number %d is: %s. \n",rollno,temp->data.name);
        return temp;
    }
    temp=temp->next;
    }
    return NULL; // vetena vaney
}
void DeleteStudentBySN(Node **head, int sn)
{
    if (*head == NULL)
    {
        printf(RED "No student records to delete!\n" RESET);
        return;
    }

    Node *temp = *head;
    Node *prev = NULL;
    int count = 1;

    // Find the node with matching serial number
    while (temp != NULL && count < sn)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        printf(RED "Invalid S.N. '%d'. Student not found.\n" RESET, sn);
        return;
    }

    // Remove the node
    if (prev == NULL) // deleting head
        *head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf(GREEN "✓ Student at S.N. %d deleted successfully!\n" RESET, sn);
}



int main()
{
    int choice;
    Student s;
    Node *head = NULL;
    int del;
    int sn,roll;

    printf("╔════════════════════════════════════════════════════════╗\n");
    printf("║              STUDENT MANAGEMENT SYSTEM                 ║\n");
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
    printf("│  5. Clear all records                                  │\n");
    printf("│  6. Delete Student                                     │\n");
    printf("│  7. Exit                                               │\n");
    printf("└────────────────────────────────────────────────────────┘\n");

    while (1)
    {
        printf("Please select the action you want to perform in accordance to its number:");
        scanf("%d", &choice);

        switch (choice)
        {
        // case haru bhitra function call gara la
        case 1:
            printf(GREEN "----You have selected \" Add New Student\".----\n" RESET);
            s = AddStudInfo();
            InsertStudent(&head, s);

            break;

        case 2:
            printf(GREEN "----You have selected \" Display Students\".----\n" RESET);
            DisplayAll(head);
            break;

        case 3:
            printf(GREEN "----You have selected \" Search Student\".----\n" RESET);
            printf(CYAN"Enter the roll number of the desired student:\t");
            scanf("%d",&roll);
            SearchByRoll(head,roll);
            break;

        case 4:
            printf(GREEN "----You have selected \" Update Student Info\".----\n" RESET);

            break;

        case 5:
            printf(GREEN "----You have selected \" Clear all Records\".----\n" RESET);
            
            break;

        case 6:
            printf(GREEN "----You have selected \" Delete Student\".----\n" RESET);
            printf(YELLOW " ----Are you really sure? (1->Yes,0->No)----\n" RESET);
            scanf("%d", &del);

            if (del == 1)
            {
                printf("Enter S.N. of student to delete: ");
                scanf("%d", &sn);
                DeleteStudentBySN(&head, sn);
                printf(CYAN "----Sucessfully Deleted----" RESET);
            }
            else if (del == 0)
            {
                printf(BLUE "----Canceled Deletion----" RESET);
            }
            else
            {
                printf(RED "----Invalid Input!!!----" RESET);
            }

            break;
        case 7:
            printf(BLUE "___exiting program____" RESET);
            return 0;

        default:
            printf(RED "----Invalid Choice ----" RESET);
            break;
        }
    }

    return 0;
}