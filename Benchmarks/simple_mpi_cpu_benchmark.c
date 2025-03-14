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

    // Synchronize all processes before starting the timer
    MPI_Barrier(MPI_COMM_WORLD);
    double start_time = MPI_Wtime();

    volatile double sum = 0.0;
    for (long i = 0; i < outer_loops; i++) {
        for (long j = 0; j < inner_loops; j++) {
            sum += j * 0.0000001;
        }
    }

    double end_time = MPI_Wtime();
    double elapsed_time = end_time - start_time;

    // Gather timing information from all processes to rank 0
    double *all_times = NULL;
    if (rank == 0) {
        all_times = (double*)malloc(size * sizeof(double));
        if (all_times == NULL) {
            fprintf(stderr, "Error: Failed to allocate memory for all_times on rank 0\n");
            MPI_Finalize();
            exit(1);
        }
    }

    // Gather elapsed times from all processes
    int gather_result = MPI_Gather(&elapsed_time, 1, MPI_DOUBLE, all_times, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    if (gather_result != MPI_SUCCESS) {
        fprintf(stderr, "Error: MPI_Gather failed on rank %d\n", rank);
        MPI_Finalize();
        exit(1);
    }

    if (rank == 0) {
        double total_time = 0.0;
        for (int i = 0; i < size; i++) {
            printf("Process %d completed in %f seconds\n", i, all_times[i]);
            total_time += all_times[i];
        }

        double avg_time = total_time / (double)size; // Explicit cast for safety
        printf("\nAverage Execution Time across all processes: %f seconds\n", avg_time);

        free(all_times);
    }

    MPI_Finalize();
    return 0;
}

