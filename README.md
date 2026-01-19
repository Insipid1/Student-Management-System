# Student-Management-System

This Mini-project was done to fulfill the assigment requirement of the course we have in the third semester of Computer Science. This Mini-Project was done by our group which consisted of: <h4>---[Sampada  Poudel(09)](https://github.com/Sampada214)---</h4>
                          <h4>---[Himamshu Poudel(10)](https://github.com/Himamshu205)---</h4>
                          <h4>---[Swasti   Pradhan(11)](https://github.com/swastipradhan)---</h4>
                          <h4>---[Shirish Tamrakar(30)](https://github.com/Insipid1)---</h4>
This project is terminal-based meaning there are no GUI elements used for inputs as well as outputs and Was purely done in C programming language. This project demonstrates linked lists and file handling. 

You may wonder "Couldn't array be used for storing the Student's information?" but due to constant addition, updates and removal of students, Array comes short.
Array is very inefficient in deleting the records and addition of records in middle indexes, you would have to change every index for the given change to occur.
While using linked list solves this problem. Additionally, Linked list prevent memory overflow due to dynamic memory allocation for nodes.


## Core Functions in This Project

1. **Add New Student**  
    This function helps user add student information (Name, Roll Number, Age, Department, C-GPA, E-Mail)to the program  and stores it temproraily for further          process.
    
2. **Display All Students** <br>
    Display All Student function basically allows users to display all records of the students that have been added in current instance of program execution.\n
    
3. **Search Student**<br>
    As per the function name, This Function allows users to search for a particular student from their roll number.
    
4. **Update Student**<br>
    This function allows users to change/update all the details of an existing student.
    
5. **Clear All Records** <br>
    This function deletes/removes all the records stored in the program.
    
6. **Save Data to a Text File**<br>
    This function asks the user if they want to store the currently saved records of the students in the current instance to a .txt file for future uses.
    
7. **Delete Student**  <br>
    This function deletes record of particular student, which can be picked/selected from their roll number.
    
8. **Exit**<br>
    This basically ends the whole projects.

## 🔧 Technical Implementation

### Data Structures Used

#### Student Structure
```c
typedef struct Student {
    int rollNumber;      // Unique identifier 
    char name[50];       // Student name
    int age;             // Age
    char department[30]; // Department/Major of the students
    float cgpa;          // CGPA (0.0 - 4.0)
    char email[50];      // Email address
} Student;
```

#### Node Structure (Linked List)
```c
typedef struct Node {
    Student data;        // Student information
    struct Node* next;   // Pointer to next node
} Node;
