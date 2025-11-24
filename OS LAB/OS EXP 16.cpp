#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int empId;
    char empName[50];
    float empSalary;
};

int main() {

    FILE *filePtr;
    struct Employee emp;
    int choice;

    filePtr = fopen("employee.dat", "rb+");
    if (filePtr == NULL) {
        filePtr = fopen("employee.dat", "wb+");
        if (filePtr == NULL) {
            printf("Error creating the file.\n");
            return 1;
        }
    }

    do {
        printf("\nEmployee Menu:\n");
        printf("1. Add Employee\n");
        printf("2. Display Employee\n");
        printf("3. Update Employee\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter ID: ");
            scanf("%d", &emp.empId);
            printf("Enter Name: ");
            scanf("%s", emp.empName);
            printf("Enter Salary: ");
            scanf("%f", &emp.empSalary);

            fseek(filePtr, (emp.empId - 1) * sizeof(struct Employee), SEEK_SET);
            fwrite(&emp, sizeof(struct Employee), 1, filePtr);

            printf("Employee added.\n");
            break;

        case 2:
            printf("Enter ID to display: ");
            scanf("%d", &emp.empId);

            fseek(filePtr, (emp.empId - 1) * sizeof(struct Employee), SEEK_SET);
            fread(&emp, sizeof(struct Employee), 1, filePtr);

            printf("\nID: %d\n", emp.empId);
            printf("Name: %s\n", emp.empName);
            printf("Salary: %.2f\n", emp.empSalary);
            break;

        case 3:
            printf("Enter ID to update: ");
            scanf("%d", &emp.empId);

            fseek(filePtr, (emp.empId - 1) * sizeof(struct Employee), SEEK_SET);
            fread(&emp, sizeof(struct Employee), 1, filePtr);

            printf("Enter New Name: ");
            scanf("%s", emp.empName);
            printf("Enter New Salary: ");
            scanf("%f", &emp.empSalary);

            fseek(filePtr, (emp.empId - 1) * sizeof(struct Employee), SEEK_SET);
            fwrite(&emp, sizeof(struct Employee), 1, filePtr);

            printf("Employee updated.\n");
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 4);

    fclose(filePtr);
    return 0;
}

