//3ms (45.95%), 9.12MB (100%)

#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void *a, const void *b);

int minMoves2(int* nums, int numsSize) {
    if (numsSize <= 1) return 0;

    qsort(nums, numsSize, sizeof(int), compare_ints);

    double med = (double)nums[numsSize / 2];
    double varMed = 0;
    
    for (int i = 0; i < numsSize; i++){
        double d = med - nums[i];
        varMed += d < 0 ? -d: d;
    }

    return (int) varMed;
}

// note that this function is not my own work, but instead a standard helper for finding the median of a c array
int compare_ints(const void *a, const void *b) {
    int val_a = *(const int *)a;
    int val_b = *(const int *)b;
    
    if (val_a < val_b) return -1;
    if (val_a > val_b) return 1;
    return 0;
}
