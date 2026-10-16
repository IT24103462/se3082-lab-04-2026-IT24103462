#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    long N = 10000000;
    long inside = 0;

    double tstart = omp_get_wtime();

    #pragma omp parallel
    {
        unsigned int seed = 12345 + omp_get_thread_num();

        #pragma omp for
        for (long i = 0; i < N; i++) {
            double x = (double)rand_r(&seed) / RAND_MAX;
            double y = (double)rand_r(&seed) / RAND_MAX;

            if (x * x + y * y <= 1.0) {
                inside++;
            }
        }
    }

    double pi = 4.0 * (double)inside / N;

    double tstop = omp_get_wtime();

    printf("Pi = %.15f\n", pi);
    printf("Points inside = %ld\n", inside);
    printf("Time = %.6f seconds\n", tstop - tstart);

    return 0;
}
