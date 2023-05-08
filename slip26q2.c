#include <stdio.h>
#include <stdlib.h>

int main() {
    int numBlocks, headPosition, numRequests;

    // Accept inputs
    printf("Enter the total number of disk blocks: ");
    scanf("%d", &numBlocks);
    printf("Enter the disk request string (comma-separated): ");
    scanf("%*c"); // Skip newline character
    char requestString[100];
    fgets(requestString, sizeof(requestString), stdin);

    printf("Enter the current head position: ");
    scanf("%d", &headPosition);

    // Parse the disk request string
    int requests[100];
    int i = 0;
    char *token = strtok(requestString, ",\n");
    while (token != NULL) {
        requests[i++] = atoi(token);
        token = strtok(NULL, ",\n");
    }
    numRequests = i;

    // Simulate the FCFS algorithm
    int totalHeadMovements = 0;

    printf("\nHead Movement Order:\n");
    printf("%d ", headPosition);
    for (int i = 0; i < numRequests; i++) {
        int currentRequest = requests[i];
        int headMovement = abs(currentRequest - headPosition);
        totalHeadMovements += headMovement;
        headPosition = currentRequest;
        printf("%d ", headPosition);
    }
    printf("\n");

    printf("\nTotal Head Movements: %d\n", totalHeadMovements);

    return 0;
}
