#include<stdio.h>
#include<string.h>
#include<stdbool.h>


typedef struct Employees{
    int empID;
    char empName[25];
    char designation[25];
    int salary;
}Employees;

void displayEmployees(Employees arr[], int n){
    printf("=========================Employee Data=========================\n");
    printf("Employee ID \t Name \t\t Designation \t Salary\n");
    for(int i = 0; i < n; i++){
        printf("%d  \t\t %s \t\t %s \t\t %-15d\n", arr[i].empID, arr[i].empName, arr[i].designation, arr[i].salary);
    }
    return;
}

void findHighestSalary(Employees arr[], int n, int *t){
    int max = arr[0].salary;
    for(int i = 1; i < n; i++){
        if(arr[i].salary > max){
            arr[i].salary = max;
            (*t) = i;
        }
    }
    return;

}

bool searchEmployee(Employees arr[], int n, int *emptracker){
    int choice;
    printf("Enter 1 for searching by ID or enter 2 for searching by name:");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            int id;
            printf("Enter the ID:");
            scanf("%d", &id);
            for(int i = 0; i < n; i++){
                if(id == arr[i].empID){
                    (*emptracker) = i;
                    return true;
                }
            }
            break;
        case 2:
            getchar();
            char name[25];
            printf("Enter the name of employee:");
            scanf("%[^\n]", name);
            for(int i = 0 ; i < n; i++){
                if(strcmp(name, arr[i].empName) == 0){
                    (*emptracker) = i;
                    return true;
                }
            }
            break;
        default:
            printf("Invalid Input!!");
    }
    return false;
}

void updateSalary(Employees* p, int n){
    for(int i = 0; i < n; i++){
        if((*(p + i)).salary <= 50000){
            float bonus = (*(p+i)).salary * 0.01;
            (*(p+i)).salary += bonus;
            printf("Salary of %s updated to %d", (*(p+i)).empName, (*(p + i)).salary);
        }
    }
    return;

}

int main(){

    int n, track = 0, empTracker = 0, choice;
    printf("Enter the number of employees:");
    scanf("%d", &n);
    getchar();
    
    Employees arr[n];
    
    for(int i = 0; i < n; i++){
        printf("Enter employee name:");
        scanf("%[^\n]", arr[i].empName);
        getchar();
        printf("Enter employee designation:");
        scanf("%[^\n]", arr[i].designation);
        printf("Enter employee ID:");
        scanf("%d", &arr[i].empID);
        printf("Enter employee salary:");
        scanf("%d", &arr[i].salary);
        getchar();
    }

    printf("\n1. For displying employees \n2. For finding highest salary \n3. Searching employee \n4. Applying Bonus\n0. For exit\n");
    do{
        printf("\n1. For displying employees \n2. For finding highest salary \n3. Searching employee \n4. Applying Bonus\n0. For exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                displayEmployees(arr, n);
                break;
            case 2:
                findHighestSalary(arr, n, &track);
                printf("\n%s of ID: %d has the highest salary.\n", arr[track].empName, arr[track].empID);
                break;
            case 3:
            {
                bool result = searchEmployee(arr, n, &empTracker);
                if(result){
                    printf("\nEmployee ID: %d ; Name: %s ; Designation: %s ; Salary: %d\n", arr[empTracker].empID, arr[empTracker].empName, arr[empTracker].designation, arr[empTracker].salary);
                }
                else{
                    printf("\nNo such empoyee found!\n");
                }
                break;
            }
            case 4:
                updateSalary(arr,n);
                break;
            default:
                printf("Invalid Input!");            
        }
    }while(choice != 0);

    return 0;
}