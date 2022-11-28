#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char **argv)
{
    int size, rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // cout << "rank: " << rank << " and total processes: " << size << endl;

    printf("Rank : %d of total: %d\n", rank, size);

    MPI_Finalize();
}