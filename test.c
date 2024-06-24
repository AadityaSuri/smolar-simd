#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <omp.h>
#include "smolar.h"


void testSmallAdd() {

    int shape[] = {50, 50};
    Array* a = smRandom(shape, 2);
    Array* b = smRandom(shape, 2);

    double start, end;
    start = omp_get_wtime();
    Array* res = smAdd(a, b);
    end = omp_get_wtime();

    double cpu_time;

    cpu_time = ((double) (end - start)) * 1000;

    assert(res->totalsize == a->totalsize);
    assert(smCheckShapesEqual(a, b));

    #pragma omp parallel for
    for(int i=0; i<res->totalsize; i++) {
        assert(res->data[i] == a->data[i] + b->data[i]);
    }

    printf("smAddSmall: %.5f ms \n", cpu_time);
}


int main() {
    // testSmallAdd(false);
    testSmallAdd();
}