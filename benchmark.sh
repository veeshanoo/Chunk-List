#!/bin/bash

threadNumber=(1 2 4 6 8 10 12)

rm tst.out
for t in ${threadNumber[@]}; do
    echo "Testing for $t thread" >> tst.out
    export "OMP_NUM_THREADS=$t"
    g++ -fopenmp ChunkList.cpp main.cpp -o ex && ./ex >> tst.out
done