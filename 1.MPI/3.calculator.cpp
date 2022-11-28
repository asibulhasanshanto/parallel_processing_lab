#include <iostream>
#include <mpi.h>
using namespace std;

int main(int argc, char **argv)
{
    int a = 10, b = 4, rank;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
    {
        printf("%d + %d = %d\n", a, b, a + b);
    }
    else if (rank == 1)
    {
        printf("%d - %d = %d\n", a, b, a - b);
    }
    else if (rank == 2)
    {
        printf("%d * %d = %d\n", a, b, a * b);
    }
    else if (rank == 3)
    {
        printf("%d / %d = %d\n", a, b, a / b);
    }

    MPI_Finalize();
}