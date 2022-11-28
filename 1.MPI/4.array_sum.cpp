#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int n = 12;
    int np = 5;
    int rank;
    int sections = n / (np - 1);
    int root_process = 0;
    int sub_nums[20];

    // initialize sub nums with zero
    for (int i = 0; i < 20; i++)
    {
        sub_nums[i] = 0;
    }

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;

    if (rank == root_process)
    {
        int nums[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

        // send data
        for (int i = 0; i < np - 1; i++)
        {
            MPI_Send(nums + (sections * i), sections, MPI_INT, i + 1, 25, MPI_COMM_WORLD);
        }

        // recieve the data
        int total = 0;
        for (int i = 0; i < np - 1; i++)
        {
            int out;
            MPI_Recv(&out, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
            total += out;
        }

        printf("Total sum: %d\n", total);
    }
    else
    {
        MPI_Recv(&sub_nums, sections, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        int sum = 0;
        for (int i = 0; i < sections; i++)
        {
            sum += sub_nums[i];
        }
        printf("From %i rank: %d is the sum value.\n", rank, sum);
        MPI_Send(&sum, 1, MPI_INT, 0, 25, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}