#include <stdio.h>  
#define MAX_EMPLOYEES 100   // Defines a constant for the maximum number of employees that can be stored

// Structure to store employee data
typedef struct {  
    int emp_id;  // Employee ID (unique identifier)
    float salary;  // Employee salary 
} Employee;  // The structure is named "Employee" for easy reference

int main() {  
    Employee employees [MAX_EMPLOYEES];  // Creates an array to store up to MAX_EMPLOYEES employee records
    int count = 0, choice;  // 'count' tracks the number of stored employees, 'choice' stores the menu option
    
    do {  
        printf("\nFinance Department - Employee Salary Management\n");  // Displays the program title
        printf("1. Add Employee Salary\n");  
        printf("2. Search Employee Salary\n");  
        printf("3. Exit\n");  
        printf("Enter your choice: ");  
        scanf("%d", &choice);  
        
        if (choice == 1) { 
            if (count < MAX_EMPLOYEES) {  // Check if there's space to add another employee
                printf("Enter Employee ID: ");  
                scanf("%d", &employees[count].emp_id);  // Store the entered ID in the employees array
                
                printf("Enter Salary: ");  
                scanf("%f", &employees[count].salary); 
                count++;  // Increase the count of stored employees
              
                printf("Employee salary recorded successfully!\n");  // Confirmation message
            } else {  // If the employee database is full
                printf("Employee database is full!\n");  // Display error message
            }

        } else if (choice == 2) {  
            int id, i, found = 0;  // Declare variables: 'id' for search input, 'i' for loop, 'found' flag to track success
            
            printf("Enter Employee ID to search: ");  
            scanf("%d", &id);  
            
            for (i = 0; i < count; i++) {  // Loop through stored employees
                if (employees[i].emp_id == id) {  // If a matching Employee ID is found
                    printf("Employee ID: %d, Salary: %f\n", employees[i].emp_id, employees[i].salary);  // Display ID and salary
                    found = 1;  // Set found flag to 1 (true)
                    break;  // Exit loop early since the employee is found
                }
            }
            
            if (!found) {  // If employee was not found (found == 0)
                printf("Employee ID not found!\n");  // Display message indicating no match
            }

        } else if (choice == 3) {  // If user selects option 3 (Exit)
            printf("Exiting program.\n");  // Display exit message
        } else {  // If user enters an invalid choice
            printf("Invalid choice! Please try again.\n");  // Display error message
        }
    } while (choice != 3);  // Repeat the loop until the user chooses option 3 (Exit)
    
    return 0;  
}

