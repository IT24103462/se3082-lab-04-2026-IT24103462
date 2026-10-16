#include <stdio.h>
#include <omp.h>

int main() {
    long long sum = 0;
double tstart = omp_get_wtime();

    #pragma omp parallel for
    for (int r = 1; r <= 100000; r++) {

        #pragma omp atomic
        sum = sum + r;
    }
double tstop = omp_get_wtime();
    printf("Sum = %lld\n", sum);
printf("Time = %.9f seconds\n", tstop - tstart);

    return 0;
}
