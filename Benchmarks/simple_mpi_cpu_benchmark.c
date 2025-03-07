#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (argc < 3) {
        if (rank == 0) {
            printf("Right Usage: %s <outer_loops> <inner_loops>\n", argv[0]);
        }
        MPI_Finalize();
        return 1;
    }

    long outer_loops = atol(argv[1]);
    long inner_loops = atol(argv[2]);

    double start_time = MPI_Wtime();

    volatile double sum = 0.0;

    for (long i = 0; i < outer_loops; i++) {
        for (long j = 0; j < inner_loops; j++) {
            sum += j * 0.0000001; // Simulated computation
        }
    }

    double end_time = MPI_Wtime();
    double elapsed_time = end_time - start_time;

    if (rank == 0) {
        printf("Computation completed. Final sum: %f\n", (double)sum);
        printf("Total time taken: %f seconds\n", elapsed_time);
    }

    MPI_Finalize();
    return 0;
}

