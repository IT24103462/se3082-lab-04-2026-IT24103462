#include <stdio.h>
#include <omp.h>

int main() {
    long N = 100000000;
    double step = 1.0 / (double)N;
    double sum = 0.0;

    double tstart = omp_get_wtime();

    #pragma omp parallel shared(N, step, sum)
    {
        double local_sum = 0.0;

        #pragma omp for
        for (long i = 1; i <= N; i++) {
            double x = (i - 0.5) * step;
            local_sum += 1.0 / (1.0 + x * x);
        }

        #pragma omp atomic
        sum += local_sum;
    }

    double pi = 4.0 * step * sum;

    double tstop = omp_get_wtime();

    printf("Pi = %.15f\n", pi);
    printf("Time = %.6f seconds\n", tstop - tstart);

    return 0;
}
