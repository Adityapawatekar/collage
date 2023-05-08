[9:48 am, 08/05/2023] Mayrya:  #include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

// Structure to store process information
struct Process {
    char name[3];
    int allocation[MAX_RESOURCES];
    int max[MAX_RESOURCES];
};

// Global variables
int available[MAX_RESOURCES];
struct Process processes[MAX_PROCESSES];

// Function to accept available resources
void acceptAvailable() {
    printf("Enter the number of available resources:\n");
    for (int i = 0; i < MAX_RESOURCES; i++) {
        printf("Resource %d: ", i);
        scanf("%d", &available[i]);
    }
}

// Function to display allocation and max matrices
void displayAllocationMax() {
    printf("Process\tAllocation\tMax\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("%s\t", processes[i].name);
        for (int j = 0; j < MAX_RESOURCES; j++) {
            printf("%d\t\t", processes[i].allocation[j]);
        }
        for (int j = 0; j < MAX_RESOURCES; j++) {
            printf("%d\t", processes[i].max[j]);
        }
        printf("\n");
    }
}

// Function to display the need matrix
void displayNeedMatrix() {
    printf("Process\tNeed\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("%s\t", processes[i].name);
        for (int j = 0; j < MAX_RESOURCES; j++) {
            int need = processes[i].max[j] - processes[i].allocation[j];
            printf("%d\t", need);
        }
        printf("\n");
    }
}

// Function to display the available resources
void displayAvailable() {
    printf("Available resources: ");
    for (int i = 0; i < MAX_RESOURCES; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");
}

// Function to initialize the process data
void initializeProcesses() {
    struct Process p0 = { "P0", {2, 3, 2}, {9, 7, 5} };
    struct Process p1 = { "P1", {4, 0, 0}, {5, 2, 2} };
    struct Process p2 = { "P2", {5, 0, 4}, {1, 0, 4} };
    struct Process p3 = { "P3", {4, 3, 3}, {4, 4, 4} };
    struct Process p4 = { "P4", {2, 2, 4}, {6, 5, 5} };

    processes[0] = p0;
    processes[1] = p1;
    processes[2] = p2;
    processes[3] = p3;
    processes[4] = p4;
}

int main() {
    int choice;
    initializeProcesses();

    do {
        printf("1. Accept Available\n");
        printf("2. Display Allocation and Max\n");
        printf("3. Display Need Matrix\n");
        printf("4. Display Available\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                acceptAvailable();
                break;
            case 2:
                displayAllocationMax();
[9:48 am, 08/05/2023] Mayrya: Q2 #include <stdio.h>
#include <stdlib.h>

// Function to calculate the absolute difference between two numbers
int absDiff(int a, int b) {
    return abs(a - b);
}

// Function to calculate the total number of head movements
int calculateHeadMovements(int *requests, int numRequests, int headPosition) {
    int totalHeadMovements = 0;

    for (int i = 0; i < numRequests; i++) {
        totalHeadMovements += absDiff(headPosition, requests[i]);
        headPosition = requests[i];
    }

    return totalHeadMovements;
}

// Function to display the order of request service
void displayRequestOrder(int *requests, int numRequests) {
    printf("Request Order: ");
    for (int i = 0; i < numRequests; i++) {
        printf("%d ", requests[i]);
    }
    printf("\n");
}

int main() {
    int numBlocks, numRequests;
    int *requests;
    int headPosition, totalHeadMovements;

    printf("Enter the total number of disk blocks: ");
    scanf("%d", &numBlocks);

    printf("Enter the number of disk requests: ");
    scanf("%d", &numRequests);

    // Allocate memory for the requests array
    requests = (int *)malloc(numRequests * sizeof(int));

    printf("Enter the disk request string:\n");
    for (int i = 0; i < numRequests; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &requests[i]);
    }

    printf("Enter the current head position: ");
    scanf("%d", &headPosition);

    totalHeadMovements = calculateHeadMovements(requests, numRequests, headPosition);

    displayRequestOrder(requests, numRequests);
    printf("Total number of head movements: %d\n", totalHeadMovements);

    // Free the memory allocated for the requests array
    free(requests);

    return 0;
}
