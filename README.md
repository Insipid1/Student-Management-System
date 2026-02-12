# Student-Management-System:
A terminal-based student management system built in **C** that demonstrates core Data Structures and Algorithms concepts including **Linked Lists**, **File Handling**, and **Dynamic Memory Management**.

## Project Overview:
This Mini-project was done to fulfill the assigment requirement of the course we have in the third semester of Computer Science. This Mini-Project was done by our group which consisted of: 
                          <h4>---[Sampada  Poudel(037532-24)](https://github.com/Sampada214)---</h4>
                          <h4>---[Himamshu Poudel(037530-24)](https://github.com/Himamshu205)---</h4>
                          <h4>---[Swasti   Pradhan(037533-24)](https://github.com/swastipradhan)---</h4>
                          <h4>---[Shirish Tamrakar(037549-24)](https://github.com/Insipid1)---</h4>
This project is terminal-based meaning there are no GUI elements used for inputs as well as outputs and Was purely done in C programming language. This project demonstrates linked lists and file handling. 



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
```

### Why Linked List Over Array?
You may wonder "Couldn't array be used for storing the Student's information?" but due to constant addition, updates and removal of students, Array comes short.
Array is very inefficient in deleting the records and addition of records in middle indexes, you would have to change every index for the given change to occur.
While using linked list solves this problem.

We chose **Linked Lists** over arrays for several critical reasons:

1. **Dynamic Size Management**
   - Arrays require predefined size (e.g., `Student students[100]`)
   - Linked lists grow/shrink dynamically as students are added/removed
   - No memory wastage or overflow issues

2. **Efficient Insertions & Deletions**
   - **Array deletion**: O(n) - requires shifting all subsequent elements
   - **Linked list deletion**: O(1) - just update pointers
   - Same advantage for insertions at beginning or middle

3. **Memory Efficiency**
   - Arrays allocate fixed memory regardless of actual usage
   - Linked lists allocate exactly what's needed
   - Example: 1000-size array with 50 students wastes 95% memory
   - 
### Prerequisites
- GCC compiler (MinGW for Windows, GCC for Linux/Mac)
- Terminal/Command Prompt

## How To Run:
### Compilation

**Linux/Mac:**
```bash
gcc -o student main.c student.c -Wall
./student
```

**Windows:**
```bash
gcc -o student.exe main.c student.c -Wall
student.exe
```

### Main Menu
```
╔════════════════════════════════════════════════════════╗
║        STUDENT MANAGEMENT SYSTEM v1.0                  ║
║                 DSA Project 2025                       ║
╚════════════════════════════════════════════════════════╝

┌────────────────────────────────────────────────────────┐
│  MAIN MENU                                             │
├────────────────────────────────────────────────────────┤
│  1. Add New Student                                    │
│  2. Display All Students                               │
│  3. Search Student                                     │
│  4. Update Student                                     │
│  5. Delete Student                                     │
│  6. Save Data                                          │
│  7. Clear All Records                                  │
│  0. Exit                                               │
└────────────────────────────────────────────────────────┘
```

### Example Workflow
1. **Add a student**: Select option 1 and enter student details
2. **View all students**: Select option 2 to see formatted table
3. **Search**: Use option 3 with roll number to find specific student
4. **Update**: Option 4 allows editing existing records
5. **Save**: Always save before exiting to persist data

