// 3ms (80.86%), 20.52MB (23.43%)

#include <stdio.h>
#include <stdlib.h>

// note -- this function is not my original work, but instead a standard function to assist in finding a median in a c array
int compare_ints(const void *a, const void *b);

int minMoves2(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    else if (numsSize == 1) return nums[0];

    qsort(nums, numsSize, sizeof(int), compare_ints);

    float med;
    if (numsSize % 2 == 0){
        med = ((float)nums[numsSize / 2] + (float)nums[numsSize / 2 - 1]) / 2;
    } else {
        med = (float)nums[numsSize / 2 - 1];
    }

    float varMed = 0;
    for (int i = 0; i < numsSize; i++) varMed += abs(med - nums[i]);

    return (int) varMed;
}

int compare_ints(const void *a, const void *b) {
    // 1. Cast void pointers to int pointers
    // 2. Dereference them to get the actual numbers
    int val_a = *(const int *)a;
    int val_b = *(const int *)b;
    
    // 3. Return relationship score
    if (val_a < val_b) return -1;
    if (val_a > val_b) return 1;
    return 0;
}
