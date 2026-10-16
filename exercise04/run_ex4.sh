#!/bin/bash

for threads in 1 4 8 12 16 20 24
do
    export OMP_NUM_THREADS=$threads

    echo "===================================="
    echo "Threads: $threads"
    echo "===================================="

    total=0

    for run in {1..10}
    do
        output=$(./lab04_ex4.o)
        time=$(echo "$output" | grep "Time" | awk '{print $3}')

        echo "Run $run: $time seconds"

        if [ $run -ge 4 ]; then
            total=$(echo "$total + $time" | bc)
        fi
    done

    average=$(echo "scale=6; $total / 7" | bc)

    echo "Average (runs 4-10): $average seconds"
done
