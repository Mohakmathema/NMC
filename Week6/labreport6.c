// #include <stdio.h>
// #include <stdlib.h>
// #define MAX_NAME_LENGTH 100

// struct Employee {
//     char empName[MAX_NAME_LENGTH];
//     int age;
//     double salary;
// };
// int main() {
//     struct Employee employees[3];
//     for (int i = 0; i < 3; i++) {
//         printf("Enter details for employee %d:\n", i + 1);
//         printf("Name: ");
//         scanf(" %[^\n]", employees[i].empName);
//         printf("Age: ");
//         scanf("%d", &employees[i].age);
//         printf("Salary: ");
//         scanf("%lf", &employees[i].salary);
//         printf("\n");
//     }
//     FILE *outFile = fopen("employee.txt", "w");
//     if (outFile == NULL) {
//         printf("Error opening file!\n");
//         return 1; 
//     }
//     for (int i = 0; i < 3; i++) {
//         fprintf(outFile, "Employee %d:\n", i + 1);
//         fprintf(outFile, "Name: %s\n", employees[i].empName);
//         fprintf(outFile, "Age: %d\n", employees[i].age);
//         fprintf(outFile, "Salary: %.2f\n", employees[i].salary);
//         fprintf(outFile, "\n"); // New line for better readability
//     }
//     fclose(outFile);
//     printf("Employee information written to D:\\employee.txt successfully.\n");
// }

// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_NAME_LENGTH 100

// // Define the Employee structure
// struct Employee {
//     char empName[MAX_NAME_LENGTH];
//     int age;
//     double salary;
// };

// int main() {
//     // Create an array to hold 3 employees
//     struct Employee employees[3];
//     FILE *inFile = fopen("D:\\employee.txt", "r");

//     if (inFile == NULL) {
//         printf("Error opening file!\n");
//         return 1; // Exit with error code
//     }

//     // Read employee information from the file
//     for (int i = 0; i < 3; i++) {
//         fscanf(inFile, "Employee %*d:\n"); // Skip the "Employee x:" line
//         fscanf(inFile, "Name: %[^\n]\n", employees[i].empName); // Read name
//         fscanf(inFile, "Age: %d\n", &employees[i].age); // Read age
//         fscanf(inFile, "Salary: %lf\n", &employees[i].salary); // Read salary
//         fscanf(inFile, "\n"); // Skip the blank line
//     }

//     fclose(inFile);

//     // Print employee information to the console
//     printf("Employee Information:\n");
//     for (int i = 0; i < 3; i++) {
//         printf("Employee %d:\n", i + 1);
//         printf("Name: %s\n", employees[i].empName);
//         printf("Age: %d\n", employees[i].age);
//         printf("Salary: %.2f\n\n", employees[i].salary);
//     }

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_NAME_LENGTH 100

// // Define the Employee structure
// struct Employee {
//     char empName[MAX_NAME_LENGTH];
//     int age;
//     double salary;
// };

// int main() {
//     struct Employee newEmployee;

//     // Prompt user for new employee details
//     printf("Enter new employee details:\n");

//     printf("Name: ");
//     scanf(" %[^\n]", newEmployee.empName); // Read string with spaces

//     printf("Age: ");
//     scanf("%d", &newEmployee.age);

//     printf("Salary: ");
//     scanf("%lf", &newEmployee.salary);

//     // Open file in append mode
//     FILE *outFile = fopen("D:\\employee.txt", "a");
    
//     if (outFile == NULL) {
//         printf("Error opening file!\n");
//         return 1; // Exit with error code
//     }

//     // Write the new employee information to the file
//     fprintf(outFile, "Employee:\n");
//     fprintf(outFile, "Name: %s\n", newEmployee.empName);
//     fprintf(outFile, "Age: %d\n", newEmployee.age);
//     fprintf(outFile, "Salary: %.2f\n\n", newEmployee.salary);

//     fclose(outFile);
//     printf("New employee information added to D:\\employee.txt successfully.\n");

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main() {
//     int number;
//     char choice[4]; // To store user input for stopping condition

//     // Open files for writing
//     FILE *oddFile = fopen("odd.txt", "w");
//     FILE *evenFile = fopen("even.txt", "w");

//     if (oddFile == NULL || evenFile == NULL) {
//         printf("Error opening files!\n");
//         return 1; // Exit with error code
//     }

//     // Loop to read integers from the user
//     while (1) {
//         printf("Enter an integer (or type 'no' to stop): ");
        
//         // Read user input
//         if (scanf("%d", &number) == 1) {
//             // Check if the number is odd or even and write to respective files
//             if (number % 2 == 0) {
//                 fprintf(evenFile, "%d\n", number); // Write even number
//             } else {
//                 fprintf(oddFile, "%d\n", number); // Write odd number
//             }
//         } else {
//             scanf("%s", choice); // Read the non-integer input
//             if (strcmp(choice, "no") == 0) {
//                 break; // Exit loop if user types "no"
//             } else {
//                 printf("Invalid input. Please enter an integer or 'no' to stop.\n");
//                 scanf("%*s"); // Clear the invalid input
//             }
//         }
//     }

//     // Close the files
//     fclose(oddFile);
//     fclose(evenFile);
    
//     printf("Odd and even numbers have been written to odd.txt and even.txt respectively.\n");

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_LINE_LENGTH 256

// int main() {
//     FILE *oddFile, *evenFile, *numbersFile;
//     char line[MAX_LINE_LENGTH];

//     // Open odd.txt for reading
//     oddFile = fopen("odd.txt", "r");
//     if (oddFile == NULL) {
//         printf("Error opening odd.txt!\n");
//         return 1; // Exit with error code
//     }

//     // Open even.txt for reading
//     evenFile = fopen("even.txt", "r");
//     if (evenFile == NULL) {
//         printf("Error opening even.txt!\n");
//         fclose(oddFile); // Close already opened file
//         return 1; // Exit with error code
//     }

//     // Open numbers.txt for writing
//     numbersFile = fopen("numbers.txt", "w");
//     if (numbersFile == NULL) {
//         printf("Error opening numbers.txt!\n");
//         fclose(oddFile);
//         fclose(evenFile);
//         return 1; // Exit with error code
//     }

//     // Copy content from odd.txt to numbers.txt
//     while (fgets(line, sizeof(line), oddFile) != NULL) {
//         fputs(line, numbersFile); // Write line to numbers.txt
//     }

//     // Copy content from even.txt to numbers.txt
//     while (fgets(line, sizeof(line), evenFile) != NULL) {
//         fputs(line, numbersFile); // Write line to numbers.txt
//     }

//     // Close all files
//     fclose(oddFile);
//     fclose(evenFile);
//     fclose(numbersFile);

//     printf("Contents copied to numbers.txt successfully.\n");

//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
    int number;
    int sum = 0;
    char choice[10]; // To store user input for stopping condition

    // Open sum.txt in append mode
    FILE *sumFile = fopen("sum.txt", "a");
    if (sumFile == NULL) {
        printf("Error opening sum.txt!\n");
        return 1; // Exit with error code
    }

    // Loop to read integers from the user
    while (1) {
        printf("Enter an integer (or type 'done' to finish): ");
        
        // Read user input
        if (scanf("%d", &number) == 1) {
            sum += number; // Add the number to the sum
        } else {
            scanf("%s", choice); // Read the non-integer input
            if (strcmp(choice, "done") == 0) {
                break; // Exit loop if user types "done"
            } else {
                printf("Invalid input. Please enter an integer or 'done' to finish.\n");
                scanf("%*s"); // Clear the invalid input
            }
        }
    }

    // Write the sum to the file
    fprintf(sumFile, "Sum: %d\n", sum);

    // Close the file
    fclose(sumFile);
    
    printf("The sum has been appended to sum.txt successfully.\n");

    return 0;
}
