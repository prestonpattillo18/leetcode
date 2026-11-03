// 1ms (42.5%), 9.88MB (82.50%)

#include <stdio.h>

int minMoves(int* nums, int numsSize) {
    int max = nums[0];
    int diff = 0;
        for (int i = 1; i < numsSize; i++){
            if (max < nums[i]){
                diff += (nums[i] - max) * i;
                max = nums[i];
            }
            
            diff += max - nums[i];
        }
    
    return diff;
}
