#include <stdio.h>

#define MAX_PROCESSES 100
#define MAX_RESOURCES 100

void calculateNeedMatrix(int processes, int resources, int allocation[MAX_PROCESSES][MAX_RESOURCES], int maximum[MAX_PROCESSES][MAX_RESOURCES], int need[MAX_PROCESSES][MAX_RESOURCES]) {
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

int checkRequest(int process, int resources, int available[], int allocation[MAX_PROCESSES][MAX_RESOURCES], int maximum[MAX_PROCESSES][MAX_RESOURCES], int need[MAX_PROCESSES][MAX_RESOURCES], int request[]) {
    for (int i = 0; i < resources; i++) {
        if (request[i] > need[process][i] || request[i] > available[i]) {
            return 0; // Request cannot be granted immediately
        }
    }
    return 1; // Request can be granted immediately
}

int main() {
    int processes, resources;
    int available[MAX_RESOURCES];
    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int maximum[MAX_PROCESSES][MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int request[MAX_RESOURCES];

    // Accept inputs
    printf("Enter the number of processes: ");
    scanf("%d", &processes);
    printf("Enter the number of resources: ");
    scanf("%d", &resources);

    printf("Enter the number of available instances for each resource:\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &available[i]);
    }

    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the maximum requirement matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &maximum[i][j]);
        }
    }

    // Calculate the need matrix
    calculateNeedMatrix(processes, resources, allocation, maximum, need);

    // Display the need matrix
    printf("The need matrix is:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Check if a given request can be granted immediately or not
    printf("Enter the process number that is making the request: ");
    int process;
    scanf("%d", &process);
    printf("Enter the request vector:\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &request[i]);
    }
    if (checkRequest(process, resources, available, allocation, maximum, need, request)) {
        printf("Request can be granted immediately.\n");
    } else {
        printf("Request cannot be granted immediately.\n");
    }

    return 0;
}