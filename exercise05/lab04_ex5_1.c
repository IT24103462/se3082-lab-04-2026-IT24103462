#include <stdio.h>
#include <omp.h>

int main() {
    long long sum = 0;
double tstart = omp_get_wtime();

    #pragma omp parallel
    {
        long long local_sum = 0;

        #pragma omp for
        for (int r = 1; r <= 100000; r++) {
            local_sum += r;
        }

        #pragma omp atomic
        sum += local_sum;
    }
double tstop = omp_get_wtime();
    printf("Sum = %lld\n", sum);
 printf("Time = %.9f seconds\n", tstop - tstart);

    return 0;
}
