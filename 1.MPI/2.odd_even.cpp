#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char **argv)
{
    int rank;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank % 2 == 0)
    {
        printf("rank:%d Hello\n", rank);
    }
    else
    {
        printf("rank: %d world\n", rank);
    }

    MPI_Finalize();
}