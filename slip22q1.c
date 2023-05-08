#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#define ARRAY_SIZE 1000

int main(int argc, char** argv) {
    int rank, size;
    int numbers[ARRAY_SIZE];
    int localSum = 0;
    int globalSum = 0;

    // Initialize MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Generate random numbers
    if (rank == 0) {
        srand(time(NULL));
        for (int i = 0; i < ARRAY_SIZE; i++) {
            numbers[i] = rand() % 1000; // Random numbers between 0 and 999
        }
    }

    // Scatter the numbers to all processes
    MPI_Scatter(numbers, ARRAY_SIZE / size, MPI_INT, numbers, ARRAY_SIZE / size, MPI_INT, 0, MPI_COMM_WORLD);

    // Calculate local sum of odd numbers
    for (int i = 0; i < ARRAY_SIZE / size; i++) {
        if (numbers[i] % 2 != 0) {
            localSum += numbers[i];
        }
    }

    // Sum all local sums using MPI_Reduce
    MPI_Reduce(&localSum, &globalSum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Print the result
    if (rank == 0) {
        printf("Global Sum of Odd Numbers: %d\n", globalSum);
    }

    // Finalize MPI
    MPI_Finalize();

    return 0;
}
