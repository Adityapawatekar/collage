#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

void sstfDiskScheduling(int requestQueue[], int queueSize, int currentHeadPosition) {
    int totalHeadMovements = 0;
    bool visited[queueSize];
    for (int i = 0; i < queueSize; i++) {
        visited[i] = false;
    }

    int currentPosition = currentHeadPosition;
    printf("Serving order: ");

    for (int i = 0; i < queueSize; i++) {
        int shortestSeekTime = INT_MAX;
        int nextIndex = -1;

        for (int j = 0; j < queueSize; j++) {
            if (!visited[j]) {
                int seekTime = abs(requestQueue[j] - currentPosition);
                if (seekTime < shortestSeekTime) {
                    shortestSeekTime = seekTime;
                    nextIndex = j;
                }
            }
        }

        visited[nextIndex] = true;
        totalHeadMovements += shortestSeekTime;
        currentPosition = requestQueue[nextIndex];

        printf("%d ", currentPosition);
    }

    printf("\nTotal Head Movements: %d\n", totalHeadMovements);
}

int main() {
    int diskBlocks, queueSize;
    
    printf("Enter the total number of disk blocks: ");
    scanf("%d", &diskBlocks);

    printf("Enter the size of the request queue: ");
    scanf("%d", &queueSize);

    int requestQueue[queueSize];
    printf("Enter the disk request string:\n");
    for (int i = 0; i < queueSize; i++) {
        scanf("%d", &requestQueue[i]);
    }

    int currentHeadPosition;
    printf("Enter the current head position: ");
    scanf("%d", &currentHeadPosition);

    sstfDiskScheduling(requestQueue, queueSize, currentHeadPosition);

    return 0;
}
