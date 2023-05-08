#include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

void displayMatrix(int matrix[MAX_PROCESSES][MAX_RESOURCES], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        printf("P%d ", i);
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void displayAvailable(int available[MAX_RESOURCES], int resources) {
    printf("Available: ");
    for (int i = 0; i < resources; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");
}

void displayNeedMatrix(int allocation[MAX_PROCESSES][MAX_RESOURCES], int max[MAX_PROCESSES][MAX_RESOURCES], int need[MAX_PROCESSES][MAX_RESOURCES], int processes, int resources) {
    printf("Need Matrix:\n");
    for (int i = 0; i < processes; i++) {
        printf("P%d ", i);
        for (int j = 0; j < resources; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int allocation[MAX_PROCESSES][MAX_RESOURCES] = {{2, 3, 2}, {4, 0, 0}, {5, 0, 4}, {4, 3, 3}, {2, 2, 4}};
    int max[MAX_PROCESSES][MAX_RESOURCES] = {{9, 7, 5}, {5, 2, 2}, {1, 0, 4}, {4, 4, 4}, {6, 5, 5}};
    int available[MAX_RESOURCES] = {3, 3, 2};
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int processes = MAX_PROCESSES;
    int resources = MAX_RESOURCES;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Display Allocation and Maximum\n");
        printf("2. Display Need Matrix\n");
        printf("3. Display Available\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Process Allocation Max\n");
                displayMatrix(allocation, processes, resources);
                break;
            case 2:
                displayNeedMatrix(allocation, max, need, processes, resources);
                break;
            case 3:
                displayAvailable(available, resources);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
