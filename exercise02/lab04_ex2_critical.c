#include <stdio.h>
#include <math.h>
#include <omp.h>

int main() {
    long N = 100000000;
    double sum = 0.0;

    double tstart = omp_get_wtime();

    #pragma omp parallel for
    for (long i = 1; i <= N; i++) {
        double value = i - (double)(i * i) + sqrt(2.0 * (i + 1));

        #pragma omp critical
        {
            sum += value;
        }
    }

    double tstop = omp_get_wtime();

    printf("Sum = %.15f\n", sum);
    printf("Time = %.6f seconds\n", tstop - tstart);

    return 0;
}
