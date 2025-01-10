// #include<stdio.h>
// #include<string.h>

// typedef struct Students{
//   char name[50];
//   int roll;
//   int marks;
// } students;

// void readInformation(students stu[]){
//   for(int i = 0; i<10; i++){
//     printf("Enter name: ");
//     scanf("%s",&stu[i].name);
//     printf("Enter roll: ");
//     scanf("%d",&stu[i].roll);
//     printf("Enter marks: ");
//     scanf("%d",&stu[i].marks);
//   }
// }

// void displayInformation(students stu[]){
//   for(int i = 0; i<10; i++){
//     printf("%s \n%d \n%d",stu[i].name, stu[i].roll, stu[i].marks);
//   }
// }

// int main(){
//   students stu[10];
//   readInformation(stu);
//   displayInformation(stu);
// }

// #include <stdio.h>
// #include <string.h>
// #define MAX_EMPLOYEES 10

// struct Employee {
//     char name[50];
//     char post[50];
//     float salary;
// };

// void filterEmployees(struct Employee employees[], int count, struct Employee filtered[], int *filteredCount) {
//     *filteredCount = 0;
//     for (int i = 0; i < count; i++) {
//         if (employees[i].salary > 10000) {
//             filtered[*filteredCount] = employees[i];
//             (*filteredCount)++;
//         }
//     }
// }

// int main() {
//     struct Employee employees[MAX_EMPLOYEES];
//     struct Employee filteredEmployees[MAX_EMPLOYEES];
//     int filteredCount = 0;
//     for (int i = 0; i < MAX_EMPLOYEES; i++) {
//         printf("Enter details for Employee %d:\n", i + 1);
//         printf("Name: ");
//         scanf("%s", employees[i].name);
//         printf("Post: ");
//         scanf("%s", employees[i].post);
//         printf("Salary: ");
//         scanf("%f", &employees[i].salary);
//     }
//     filterEmployees(employees, MAX_EMPLOYEES, filteredEmployees, &filteredCount);
//     printf("\nEmployees with salary greater than 10,000:\n");
//     for (int i = 0; i < filteredCount; i++) {
//         printf("Name: %s, Post: %s, Salary: %.2f\n", 
//               filteredEmployees[i].name, 
//               filteredEmployees[i].post, 
//               filteredEmployees[i].salary);
//     }
// }


// #include <stdio.h>

// // Define a structure to hold the limits
// struct Limits {
//     int lower;
//     int upper;
// };

// // Function to display numbers between lower and upper limits
// void display(struct Limits limits) {
//     printf("Numbers between %d and %d are:\n", limits.lower, limits.upper);
//     for (int i = limits.lower; i <= limits.upper; i++) {
//         printf("%d ", i);
//     }
// }

// int main() {
//     struct Limits limits;

//     // Ask user for lower and upper limits
//     printf("Enter the lower limit: ");
//     scanf("%d", &limits.lower);
//     printf("Enter the upper limit: ");
//     scanf("%d", &limits.upper);

//     // Call the display function
//     display(limits);

//     return 0;
// }


// #include <stdio.h>

// // Define a structure for student information
// struct student_info {
//     char name[50];
//     int age;
//     char date_of_birth[11]; // Format: DD-MM-YYYY
// };

// // Define a structure for Student
// struct Student {
//     int roll_no;
//     float marks;
//     struct student_info info; // Nested structure
// };

// // Function to input student data
// void inputStudentData(struct Student *student) {
//     printf("Enter roll number: ");
//     scanf("%d", &student->roll_no);
//     printf("Enter marks: ");
//     scanf("%f", &student->marks);
    
//     printf("Enter name: ");
//     scanf(" %[^\n]", student->info.name); // Read string with spaces
//     printf("Enter age: ");
//     scanf("%d", &student->info.age);
//     printf("Enter date of birth (DD-MM-YYYY): ");
//     scanf("%s", student->info.date_of_birth);
// }

// // Function to display student data
// void displayStudentData(struct Student student) {
//     printf("\nStudent Roll No: %d\n", student.roll_no);
//     printf("Marks: %.2f\n", student.marks);
//     printf("Name: %s\n", student.info.name);
//     printf("Age: %d\n", student.info.age);
//     printf("Date of Birth: %s\n", student.info.date_of_birth);
// }

// int main() {
//     struct Student students[3]; // Array of 3 students

//     // Input data for 3 students
//     for (int i = 0; i < 3; i++) {
//         printf("\nEntering details for Student %d:\n", i + 1);
//         inputStudentData(&students[i]);
//     }

//     // Display data for 3 students
//     for (int i = 0; i < 3; i++) {
//         printf("\nDetails of Student %d:\n", i + 1);
//         displayStudentData(students[i]);
//     }

//     return 0;
// }


// #include <stdio.h>

// // Define a structure for Employee
// struct Employee {
//     char name[50];
//     float salary;
//     int hours_per_day;
// };

// // Function to calculate final salary based on hours worked
// float calculateFinalSalary(float salary, int hours) {
//     if (hours >= 12) {
//         return salary + 150; // Increase by $150
//     } else if (hours == 10) {
//         return salary + 100; // Increase by $100
//     } else if (hours == 8) {
//         return salary + 50;  // Increase by $50
//     }
//     return salary; // No increase
// }

// int main() {
//     struct Employee employees[5]; // Array to hold 5 employees

//     // Input data for 5 employees
//     for (int i = 0; i < 5; i++) {
//         printf("Enter details for Employee %d:\n", i + 1);
//         printf("Name: ");
//         scanf(" %[^\n]", employees[i].name); // Read string with spaces
//         printf("Salary: ");
//         scanf("%f", &employees[i].salary);
//         printf("Hours worked per day: ");
//         scanf("%d", &employees[i].hours_per_day);
//     }

//     // Print final salaries of all employees
//     printf("\nFinal Salaries of Employees:\n");
//     for (int i = 0; i < 5; i++) {
//         float final_salary = calculateFinalSalary(employees[i].salary, employees[i].hours_per_day);
//         printf("Name: %s, Final Salary: $%.2f\n", employees[i].name, final_salary);
//     }

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for Employee
struct Employee {
    char name[50];
    float salary;
    int hours_per_day;
};

// Function to find and print the highest salary
void printHighestSalary(struct Employee *employees, int n) {
    if (n <= 0) {
        printf("No employees to evaluate.\n");
        return;
    }

    float highest_salary = employees[0].salary;
    char highest_paid_employee[50];
    strcpy(highest_paid_employee, employees[0].name);

    for (int i = 1; i < n; i++) {
        if (employees[i].salary > highest_salary) {
            highest_salary = employees[i].salary;
            strcpy(highest_paid_employee, employees[i].name);
        }
    }

    printf("The highest salary is: $%.2f by %s\n", highest_salary, highest_paid_employee);
}

int main() {
    int n;

    // Get the number of employees
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n Employee structures
    struct Employee *employees = (struct Employee *)malloc(n * sizeof(struct Employee));
    
    if (employees == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    // Input data for each employee
    for (int i = 0; i < n; i++) {
        printf("\nEntering details for Employee %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", employees[i].name); // Read string with spaces
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
        printf("Hours worked per day: ");
        scanf("%d", &employees[i].hours_per_day);
    }

    // Call the function to print the highest salary
    printHighestSalary(employees, n);

    // Free allocated memory
    free(employees);

    return 0;
}

