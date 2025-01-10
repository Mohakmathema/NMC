/*#include<stdio.h>

typedef struct {
  int x;
  int y;
}Complex;
int main(){
  Complex num1, num2, sum;
    printf("Enter real and imaginary part of first complex number (x + iy):\n");
    scanf("%f %f", &num1.x, &num1.y);
    printf("Enter real and imaginary part of second complex number (x + iy):\n");
    scanf("%f %f", &num2.x, &num2.y);
    sum.x = num1.x + num2.x;  // Add real parts
    sum.y = num1.y + num2.y;  // Add imaginary parts
    printf("Sum = %.2f + %.2fi\n", sum.x, sum.y);
}*/
/*
#include<stdio.h>

typedef struct {
  int x;
  int y;
}Complex;

void sumCmp(Complex num1, Complex num2, Complex *sum){
  sum->x = num1.x + num2.x;
  sum->y = num1.y + num2.y;
}

int main(){
  Complex num1, num2, sum;
  printf("Enter 1st real number and imaginary number: ");
  scanf("%d %d",&num1.x, &num2.y);
  printf("Enter 2nd real number and imaginary number: ");
  scanf("%d %d",&num1.x, &num2.y);
  sumCmp(num1, num2, &sum);
  printf("%d and %d",sum.x, sum.y);
}*/
/*
#include<stdio.h>
#include<string.h>

typedef struct Students{
  char name[50];
  int roll;
  int marks;
} students;

void readInformation(students stu[]){
  for(int i = 0; i<10; i++){
    printf("Enter name: ");
    scanf("%s",&stu[i].name);
    printf("Enter roll: ");
    scanf("%d",&stu[i].roll);
    printf("Enter marks: ");
    scanf("%d",&stu[i].marks);
  }
}

void displayInformation(students stu[]){
  for(int i = 0; i<10; i++){
    printf("%s \n%d \n%d",stu[i].name, stu[i].roll, stu[i].marks);
  }
}

int main(){
  students stu[10];
  readInformation(stu);
  displayInformation(stu);
}*/
/*
#include <stdio.h>
#include <string.h>
#define MAX_EMPLOYEES 10

typedef struct {
    char name[50];
    char post[50];
    float salary;
} Employee;

int filterEmployees(Employee employees[], Employee filtered[]) {
    int count = 0;
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        if (employees[i].salary > 10000) {
            filtered[count] = employees[i]; 
            count++;
        }
    }
    return count; 
}
int main() {
    Employee employees[MAX_EMPLOYEES];
    Employee filtered[MAX_EMPLOYEES];
    int count;
for (int i = 0; i < MAX_EMPLOYEES; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Post: ");
        scanf("%s", employees[i].post);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }
    count = filterEmployees(employees, filtered);
printf("\nEmployees with salary greater than 10,000:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Post: %s, Salary: %.2f\n", filtered[i].name, filtered[i].post, filtered[i].salary);
    }
}*/

/*
#include <stdio.h>

typedef struct
{
    int lowerLimit;
    int upperLimit;
} limits;

void display(limits lim)
{
    int lower_limit = lim.lowerLimit;
    int upper_limit = lim.upperLimit;

    for (int i = lower_limit; i <= upper_limit; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    int lower_limit, upper_limit;

    printf("Enter the lower limit: ");
    scanf("%d", &lower_limit);

    printf("Enter the upper limit: ");
    scanf("%d", &upper_limit);

    limits lim = {lower_limit, upper_limit};

    display(lim);

    return 0;
}*/

/*
#include <stdio.h>

#define MAX_EMPLOYEES 5
typedef struct {
    char name[50];
    float salary;
    int hoursWorked;
    } Employee;

float calculateFinalSalary(float salary, int hoursWorked) {
    if (hoursWorked >= 12) {
        return salary + 150; // Increase by $150 for 12 or more hours
    } else if (hoursWorked == 10) {
        return salary + 100; // Increase by $100 for 10 hours
    } else if (hoursWorked == 8) {
        return salary + 50; // Increase by $50 for 8 hours
    }
    return salary; // No increase for less than 8 hours
}

int main() {
    Employee employees[MAX_EMPLOYEES];
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
        printf("Hours worked per day: ");
        scanf("%d", &employees[i].hoursWorked);
    }
    printf("\nEmployee Final Salaries:\n");
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        float finalSalary = calculateFinalSalary(employees[i].salary, employees[i].hoursWorked);
        printf("Name: %s, Final Salary: $%.2f\n", employees[i].name, finalSalary);
    }
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float salary;
    int hoursWorked; 
} Employee;
void printHighestSalary(Employee *employees, int n) {
    if (n <= 0) {
        printf("No employees to evaluate.\n");
        return;
    }
    float highestSalary = employees[0].salary; 
    char highestSalaryName[50];
    strcpy(highestSalaryName, employees[0].name); 
    for (int i = 1; i < n; i++) {
        if (employees[i].salary > highestSalary) {
            highestSalary = employees[i].salary;
            strcpy(highestSalaryName, employees[i].name);        }
    }
    printf("The employee with the highest salary is %s with a salary of $%.2f\n", highestSalaryName, highestSalary);
}

int main() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    Employee *employees = (Employee *)malloc(n * sizeof(Employee));
    if (employees == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }
    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
        printf("Hours worked per day: ");
        scanf("%d", &employees[i].hoursWorked);
    }
    printHighestSalary(employees, n);
    free(employees);
}

